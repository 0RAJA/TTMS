/*字符串模糊比较的函数定义*/
#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	return a>b ? a:b;
}
int _strcmp(char *s1,char *s2)
{
	int dp[100][100] = {0};
	int len1,len2;
	len1 = strlen(s1),len2 = strlen(s2);
	for(int i = 1; i<=len1; i++)
	{
		for(int j = 1; j<=len2; j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[len1][len2];
}

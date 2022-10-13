#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mini = 999;

	
// select minimum size
int min(int a, int b, int c)
{
	(a < b) ? mini = a : mini = b;
	return (mini < c) ? mini = mini : mini = c;
}

int main()
{
	int ce, ga; // ce is dp table of row, ga is dp table of column
	int dp[100][100];//dp table
	int result[100];
	int total = 0;

	while (scanf("%d %d", &ce, &ga) != EOF) 
	{
		for (int i = 0; i < ce; i++)
		{
			for (int j = 0; j < ga; j++)
			{
				scanf("%d", &dp[ce][ga]); //scan table value
			}
		}

		for (int i = 0; i < ce; i++)
		{
			for (int j = 0; j < ga; j++)
			{
				dp[ce - 1][ga] == dp[ce][ga + 1];//Because the table is rolled up, it moves to the lowest value when moving the next value.
				mini = min(dp[ce + 1][ga - 1], dp[ce + 1][ga], dp[ce + 1][ga + 1]); //Move to the smallest of three values ​​based on one value
				result[j] = mini;
			}
		}
	}

	//print result
		for (int j = 0; j < ga; j++)
		{
			printf("%d", result[j]);
		}
		printf("%d", total);

	return 0;
}
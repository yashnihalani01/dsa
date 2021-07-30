#include <bits/stdc++.h>
using namespace std;
int dp[12][10] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
};
int n = 12;
int m = 10;
int visited[12][10];
void find(int i, int j, int &ans, int steps)
{
	if (visited[i][j] == 1 || dp[i][j] == 0 || dp[i][j] == -1)
		return;
	if (j == 9)
	{
		if (ans > steps)
		{
			ans = steps;
		}
		return;
	}
	visited[i][j] = 1;
	if (i + 1 < n)
	{
		find(i + 1, j, ans, steps + 1);
	}
	if (i - 1 >= 0)
	{
		find(i - 1, j, ans, steps + 1);
	}
	if (j + 1 < m)
	{
		find(i, j + 1, ans, steps + 1);
	}
	if (j - 1 >= 0)
	{
		find(i, j - 1, ans, steps + 1);
	}
	visited[i][j] = 0;

}
int main()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (dp[i][j] == 0)
			{
				if (i - 1 >= 0)
				{
					dp[i - 1][j] = -1;
				}
				if (i + 1 < 12)
				{
					dp[i + 1][j] = -1;
				}
				if (j - 1 >= 0)
				{
					dp[i][j - 1] = -1;
				}
				if (j + 1 < 10)
				{
					dp[i][j+1] = -1;
				}
			}
		}
	}
	int ans = INT_MAX;

	for (int i = 0; i < 12; i++)
	{
		find(i, 0, ans, 0);
	}
	cout << ans;
	return 0;
}
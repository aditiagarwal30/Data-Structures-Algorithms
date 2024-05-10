// DP SOLUTION

#include <bits/stdc++.h>

int solve(int day, int last, vector<vector<int>> &points, int n, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int max_prof = 0;

        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                max_prof = max(max_prof, points[0][i]);
            }
        }
        return max_prof;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int max_p;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int p = points[day][i] + solve(day - 1, i, points, n, dp);
            max_p = max(max_p, p);
        }
    }
    return dp[day][last] = max_p;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, n, dp);
}

// TABULATION

int maximumPoints(vector<vector<int>> &points, int n)
{
    // Code here
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // base conditions
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int profit = points[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], profit);
                }
            }
        }
    }
    return dp[n - 1][3];
}

//  SPACE OPTIMIZATION

int maximumPoints(vector<vector<int>> &points, int n)
{
    // Code here
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // base conditions
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int profit = points[day][i] + dp[day - 1][i];
                    dp[day][last] = max(dp[day][last], profit);
                }
            }
        }
    }
    return dp[n - 1][3];
}
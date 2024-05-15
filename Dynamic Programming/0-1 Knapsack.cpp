// Memoization
#include <bits/stdc++.h>
int f(int ind, int W, vector<int> wt, vector<int> val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[ind] <= W)
            return val[0];
        return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];
    int notTake = 0 + f(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
        take = val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);

    return dp[ind][W] = max(take, notTake);
}
int knapsack(vector<int> wt, vector<int> val, int n, int W)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n - 1, W, wt, val, dp);
}

// Tabulation
#include <bits/stdc++.h>
int knapsack(vector<int> wt, vector<int> val, int n, int W)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base Case
    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notTake = 0 + dp[i - 1][j];
            int take = INT_MIN;
            if (wt[i] <= j)
                take = val[i] + dp[i - 1][j - wt[i]];

            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}

// Space Optimization
#include <bits/stdc++.h>
int knapsack(vector<int> wt, vector<int> val, int n, int W)
{
    // Write your code here
    vector<int> dp(W + 1, 0);

    // Base Case
    for (int i = wt[0]; i <= W; i++)
    {
        dp[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(W + 1, 0);
        for (int j = 0; j <= W; j++)
        {
            int notTake = 0 + dp[j];
            int take = INT_MIN;
            if (wt[i] <= j)
                take = val[i] + dp[j - wt[i]];

            curr[j] = max(take, notTake);
        }
        dp = curr;
    }
    return dp[W];
}
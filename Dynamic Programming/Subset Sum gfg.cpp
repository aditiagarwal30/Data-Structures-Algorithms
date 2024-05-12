// Dynamic Programming

bool solve(int ind, int sum, vector<int> arr, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (ind == 0)
        return (arr[0] == sum);
    if (dp[ind][sum] != -1)
        return dp[ind][sum];

    bool nottake = solve(ind - 1, sum, arr, dp);
    bool take = false;
    if (arr[ind] <= sum)
    {
        take = solve(ind - 1, sum - arr[ind], arr, dp);
    }

    return dp[ind][sum] = (nottake || take);
}
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    bool ans = solve(arr.size() - 1, sum, arr, dp);
    return ans;
}

// Tabulation
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool nottake = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
            {
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = (nottake || take);
        }
    }
    return dp[n - 1][sum];
}

// Space Optimization
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    int n = arr.size();
    vector<bool> dp(sum + 1, false);

    dp[0] = 1;
    dp[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<bool> cur(sum + 1, false);
        cur[0] = true;
        for (int target = 1; target <= sum; target++)
        {
            bool nottake = dp[target];
            bool take = false;
            if (arr[i] <= target)
            {
                take = dp[target - arr[i]];
            }
            cur[target] = (nottake || take);
        }
        dp = cur;
    }
    return dp[sum];
}
// Recursion
int f(int ind, int k, int arr[])
{
    if (ind == 0)
    {
        if (k == 0 && arr[0] == 0)
            return 2;
        if (k == 0 || k == arr[0])
            return 1;
        return 0;
    }

    int nottake = f(ind - 1, k, arr);
    int take = 0;
    if (arr[ind] <= k)
        take = f(ind - 1, k - arr[ind], arr);

    return nottake + take;
}

public:
int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    return f(n - 1, sum, arr) % (int)(1e9 + 7);
}

// Memoization
class Solution
{
    int f(int ind, int k, int arr[], vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (k == 0 && arr[0] == 0)
                return 2;
            if (k == 0 || k == arr[0])
                return 1;
            return 0;
        }

        if (dp[ind][k] != -1)
            return dp[ind][k];

        int nottake = f(ind - 1, k, arr, dp);
        int take = 0;
        if (arr[ind] <= k)
            take = f(ind - 1, k - arr[ind], arr, dp);

        return dp[ind][k] = (nottake + take) % (int)(1e9 + 7);
    }

public:
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
};

// Tabulation
int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= sum)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= sum; s++)
        {
            int nottake = dp[i - 1][s];
            int take = 0;
            if (arr[i] <= s)
                take = dp[i - 1][s - arr[i]];

            dp[i][s] = (nottake + take) % (int)(1e9 + 7);
        }
    }
    return dp[n - 1][sum];
}

// Space Optimized
int perfectSum(int arr[], int n, int sum)
{
    vector<int> dp(sum + 1, 0);

    if (arr[0] == 0)
        dp[0] = 2;
    else
        dp[0] = 1;

    if (arr[0] != 0 && arr[0] <= sum)
        dp[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(sum + 1, 0);
        for (int s = 0; s <= sum; s++)
        {
            int nottake = dp[s];
            int take = 0;
            if (arr[i] <= s)
                take = dp[s - arr[i]];

            curr[s] = (nottake + take) % (int)(1e9 + 7);
        }
        dp = curr;
    }
    return dp[sum];
}
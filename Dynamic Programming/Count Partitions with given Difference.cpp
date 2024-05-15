using namespace std;
// Recursion
int solve(int ind, int &target, vector<int> &nums)
{
    if (ind == 0 and target == 0 and nums[ind] == 0)
        return 2;
    if (target == 0)
        return 1;
    if (ind == 0 and target == arr[0])
        return 1;

    int nottake = solve(ind - 1, target, nums);
    int take = 0;
    if (nums[ind] <= target)
        take = solve(ind - 1, target - nums[ind], nums);
    return take + nottake;
}

int countPartitions(int n, int d, vector<int> &nums)
{
    if (n == 1)
        return (nums[0] == d);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if ((d + sum) % 2 == 1 or (d + sum) < 0)
        return false;

    int target = (sum + d) / 2;
    return (solve(n - 1, target, nums)) % (int)(1e9 + 7);
}

// Memoization
int solve(int ind, int &target, vector<int> &nums, vector<vector<int>> dp)
{
    if (ind == 0 and target == 0 and nums[ind] == 0)
        return 2;
    if (target == 0)
        return 1;
    if (ind == 0 and target == arr[0])
        return 1;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int nottake = solve(ind - 1, target, nums);
    int take = 0;
    if (nums[ind] <= target)
        take = solve(ind - 1, target - nums[ind], nums);
    return dp[ind][target] = take + nottake;
}

int countPartitions(int n, int d, vector<int> &nums)
{
    if (n == 1)
        return (nums[0] == d);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if ((d + sum) % 2 == 1 or (d + sum) < 0)
        return false;

    int target = (sum + d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    return (solve(n - 1, target, nums, dp)) % (int)(1e9 + 7);
}

// Tabulation
int countPartitions(int n, int d, vector<int> &nums)
{
    // Code here
    if (n == 1)
        return (nums[0] == d);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if ((d + sum) % 2 == 1 or (d + sum) < 0)
        return false;

    int target = (sum + d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base Case 1
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    // Base Case 2
    if (nums[0] <= target)
    {
        dp[0][nums[0]] = 1;
    }
    // Base Case 3
    if (nums[0] == 0)
    {
        dp[0][0] = 2;
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int nottake = dp[i - 1][t];
            int take = 0;

            if (t >= nums[i])
                take = dp[i - 1][t - nums[i]];

            dp[i][t] = (take + nottake) % (int)(1e9 + 7);
        }
    }

    return dp[n - 1][target];
}

// Space Optimization
int countPartitions(int n, int d, vector<int> &nums)
{
    // Code here
    if (n == 1)
        return (nums[0] == d);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if ((d + sum) % 2 == 1 or (d + sum) < 0)
        return false;

    int target = (sum + d) / 2;

    vector<int> dp(target + 1, 0);

    // Base Case 1
    dp[0] = 1;

    // Base Case 2
    if (nums[0] <= target)
    {
        dp[nums[0]] = 1;
    }
    // Base Case 3
    if (nums[0] == 0)
    {
        dp[0] = 2;
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(target + 1, 0);
        for (int t = 0; t <= target; t++)
        {
            int nottake = dp[t];
            int take = 0;

            if (t >= nums[i])
                take = d[t - nums[i]];

            curr[t] = (take + nottake) % (int)(1e9 + 7);
        }
        dp = curr;
    }

    return dp[target];
}

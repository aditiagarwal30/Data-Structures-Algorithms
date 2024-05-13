// Tabulation
int minSubsetSumDifference(vector<int> &nums, int n)
{
    // Write your code here.;
    if (n == 1)
        return nums[0];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    // Base Case 1
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    // Base Case 2
    if (nums[0] <= sum)
    {
        dp[0][nums[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 1; t <= sum; t++)
        {
            bool nottake = dp[i - 1][t];
            bool take = false;

            if (t >= nums[i])
            {
                take = dp[i - 1][t - nums[i]];
            }

            dp[i][t] = take || nottake;
        }
    }
    int ans = 1e9;

    for (int s1 = 0; s1 <= sum; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            int s2 = sum - s1;
            int diff = abs(s2 - s1);
            ans = min(ans, diff);
        }
    }
    return ans;
}

// Space Optimization
int minSubsetSumDifference(vector<int> &nums, int n)
{
    // Write your code here.;
    if (n == 1)
        return nums[0];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    vector<bool> dp(sum + 1, false);

    // Base Case 1
    dp[0] = true;

    // Base Case 2
    if (nums[0] <= sum)
    {
        dp[nums[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {
        vector<bool> curr(sum + 1, false);
        for (int t = 0; t <= sum; t++)
        {
            bool nottake = dp[t];
            bool take = false;

            if (t >= nums[i])
            {
                take = dp[t - nums[i]];
            }

            curr[t] = take || nottake;
        }
        dp = curr;
    }
    int ans = 1e9;

    for (int s1 = 0; s1 <= sum; s1++)
    {
        if (dp[s1] == true)
        {
            int s2 = sum - s1;
            int diff = abs(s2 - s1);
            ans = min(ans, diff);
        }
    }
    return ans;
}

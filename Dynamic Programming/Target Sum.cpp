// Recursion
class Solution
{
    int f(int ind, int target, vector<int> &nums)
    {
        if (ind == 0)
        {
            if (nums[0] == target || nums[0] == (-target))
                return 1;
            return 0;
        }

        int add = f(ind - 1, target - nums[ind], nums);
        int sub = f(ind - 1, target + nums[ind], nums);

        return add + sub;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return f(n - 1, target, nums);
    }
};

// Memoization
// use same logic as in "Count Partitions with given Difference"

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int d)
    {
        int n = nums.size();
        if (n == 1)
            return (nums[0] == d || nums[0] == -d);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if ((d + sum) % 2 == 1 or (d + sum) < 0)
            return false;

        int target = (sum + d) / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        if (nums[0] <= target)
            dp[0][nums[0]] = 1;
        if (nums[0] == 0)
            dp[0][0] = 2;

        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= target; t++)
            {
                int nottake = dp[i - 1][t];
                int take = 0;

                if (t >= nums[i])
                    take = dp[i - 1][t - nums[i]];

                dp[i][t] = (take + nottake);
            }
        }
        return dp[n - 1][target];
    }
};

// Space Optimized
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int d)
    {
        int n = nums.size();
        if (n == 1)
            return (nums[0] == d || nums[0] == -d);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if ((d + sum) % 2 == 1 or (d + sum) < 0)
            return false;

        int target = (sum + d) / 2;
        vector<int> dp(target + 1, 0);

        for (int i = 0; i < n; i++)
            dp[0] = 1;
        if (nums[0] <= target)
            dp[nums[0]] = 1;
        if (nums[0] == 0)
            dp[0] = 2;

        for (int i = 1; i < n; i++)
        {
            vector<int> curr(target + 1, 0);
            for (int t = 0; t <= target; t++)
            {
                int nottake = dp[t];
                int take = 0;

                if (t >= nums[i])
                    take = dp[t - nums[i]];

                curr[t] = (take + nottake);
            }
            dp = curr;
        }
        return dp[target];
    }
};
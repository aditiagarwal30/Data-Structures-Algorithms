// Recursive Solution
class Solution
{
    bool solve(int ind, vector<int> &nums, int target)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind < 0)
            return false;

        bool nottake = solve(ind - 1, nums, target);
        bool take = false;

        if (target >= nums[ind])
            take = solve(ind - 1, nums, target - nums[ind]);

        return take || nottake;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        return solve(n - 1, nums, sum / 2);
    }
};

// Memoization
class Solution
{
    bool solve(int ind, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (target == 0)
        {
            return true;
        }
        if (ind < 0 and target > 0)
            return false;
        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool nottake = solve(ind - 1, nums, target, dp);
        bool take = false;

        if (target >= nums[ind])
            take = solve(ind - 1, nums, target - nums[ind], dp);

        return dp[ind][target] = take || nottake;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, nums, target, dp);
    }
};

// Tabulation
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return false;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base Case 1
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        // Base Case 2
        if (nums[0] <= target)
        { // Check if nums[0] is within bounds
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < n; i++)
        {
            for (int t = 1; t <= target; t++)
            {
                bool nottake = dp[i - 1][t];
                bool take = false;

                if (t >= nums[i])
                    take = dp[i - 1][t - nums[i]];

                dp[i][t] = take || nottake;
            }
        }

        return dp[n - 1][target];
    }
};

// Space Optimization
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return false;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;

        int target = sum / 2;

        vector<bool> dp(target + 1, false);

        // Base Case 1
        for (int i = 0; i < n; i++)
        {
            dp[0] = true;
        }
        // Base Case 2
        if (nums[0] <= target)
        { // Check if nums[0] is within bounds
            dp[nums[0]] = true;
        }

        for (int i = 1; i < n; i++)
        {
            vector<bool> curr(target + 1, false);
            for (int t = 1; t <= target; t++)
            {
                bool nottake = dp[t];
                bool take = false;

                if (t >= nums[i])
                    take = dp[t - nums[i]];

                curr[t] = take || nottake;
            }
            dp = curr;
        }

        return dp[target];
    }
};

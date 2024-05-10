class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev = nums[0];
        int prev2 = 0;
        int take, not_take, cur;

        for (int i = 1; i < nums.size(); i++)
        {
            take = nums[i] + prev2;
            not_take = 0 + prev;

            cur = max(take, not_take);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int take, not_take;
        for (int i = 1; i < nums.size(); i++)
        {
            if (i > 1)
                take = nums[i] + dp[i - 2];
            else
                take = nums[i];
            not_take = 0 + dp[i - 1];

            dp[i] = max(take, not_take);
        }
        return dp[nums.size() - 1];
    }
};
class Solution
{
    int solve(int i, vector<int> &nums, vector<int> &dp)
    {
        if (i == 0)
            return dp[0] = nums[0];
        if (i < 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int take = nums[i] + solve(i - 2, nums, dp);
        int not_take = 0 + solve(i - 1, nums, dp);

        return dp[i] = max(take, not_take);
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        solve(nums.size() - 1, nums, dp);
        return dp[nums.size() - 1];
    }
};

class Solution
{
    int solve(int i, vector<int> &nums)
    {
        if (i == 0)
            return nums[0];
        if (i < 0)
            return 0;

        int take = nums[i] + solve(i - 2, nums);
        int not_take = 0 + solve(i - 1, nums);

        return max(take, not_take);
    }

public:
    int rob(vector<int> &nums)
    {
        int ans = solve(nums.size() - 1, nums);
        return ans;
    }
};
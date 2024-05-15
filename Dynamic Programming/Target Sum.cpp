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

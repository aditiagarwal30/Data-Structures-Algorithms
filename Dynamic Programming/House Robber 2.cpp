https : // leetcode.com/problems/house-robber/solutions/5140420/4-solutions-recursion-memoization-tabulation-space-optimization/

        class Solution
{
    int rob1(vector<int> &nums)
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

public:
    int rob(vector<int> &nums)
    {
        vector<int> temp1 = nums, temp2 = nums;

        temp1.erase(temp1.begin()); // considering the array without first house
        temp2.pop_back();           // considering the array without the last house

        // we will either choose first house, or the last house to rob from

        int without_first_house = rob1(temp1);
        int without_last_house = rob1(temp2);

        return max(without_first_house, without_last_house);
    }
};
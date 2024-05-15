// Recursion
class Solution
{
    int f(int ind, int amount, vector<int> &coins)
    {
        if (ind == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        int nottake = f(ind - 1, amount, coins);
        int take = INT_MAX;
        if (amount >= coins[ind])
        {
            take = 1 + f(ind, amount - coins[ind], coins);
        }
        return min(take, nottake);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {

        int ans = f(coins.size() - 1, amount, coins);

        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// Memoization
class Solution
{
    int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }
        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int nottake = f(ind - 1, amount, coins, dp);
        int take = INT_MAX;
        if (amount >= coins[ind])
        {
            take = 1 + f(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = min(take, nottake);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(coins.size() - 1, amount, coins, dp);

        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// Tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base Case
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int val = 0; val <= amount; val++)
            {
                int nottake = dp[ind - 1][val];
                int take = INT_MAX;
                if (val >= coins[ind])
                {
                    take = 1 + dp[ind][val - coins[ind]];
                }
                dp[ind][val] = min(take, nottake);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};

// Space Optimization
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);

        // Base Case
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[i] = i / coins[0];
            else
                dp[i] = 1e9;
        }

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(amount + 1, 0);
            for (int val = 0; val <= amount; val++)
            {
                int nottake = dp[val];
                int take = INT_MAX;
                if (val >= coins[ind])
                {
                    take = 1 + curr[val - coins[ind]];
                }
                curr[val] = min(take, nottake);
            }
            dp = curr;
        }

        int ans = dp[amount];
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};
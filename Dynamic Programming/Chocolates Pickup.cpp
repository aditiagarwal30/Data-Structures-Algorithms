// Recursion
int solve(int row, int a, int b, vector<vector<int>> &matrix, int n, int m)
{
    // out of bounds base case
    if (a < 0 or a >= m or b < 0 or b >= m)
        return -1e8;

    // destination base case
    if (row == n - 1)
    {
        if (a == b)
            return matrix[row][a];
        else
            return matrix[row][a] + matrix[row][b];
    }

    int sum = INT_MIN, maxi = INT_MIN;
    for (int da = -1; da <= 1; da++)
    {
        for (int db = -1; db <= 1; db++)
        {
            if (a == b)
            {
                sum = matrix[row][a] + solve(row + 1, a + da, b + db, matrix, n, m);
            }
            else
            {
                sum = matrix[row][a] + matrix[row][b] + solve(row + 1, a + da, b + db, matrix, n, m);
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    return solve(0, 0, m - 1, grid, n, m);
}

// Tabulation
int solve(int row, int a, int b, vector<vector<int>> &matrix, int n, int m, vector<vector<vector<int>>> &dp)
{
    // out of bounds base case
    if (a < 0 or a >= m or b < 0 or b >= m)
        return -1e8;

    // destination base case
    if (row == n - 1)
    {
        if (a == b)
            return matrix[row][a];
        else
            return matrix[row][a] + matrix[row][b];
    }
    // check for overlapping subproblem
    if (dp[row][a][b] != -1)
        return dp[row][a][b];

    int sum = INT_MIN, maxi = INT_MIN;
    for (int da = -1; da <= 1; da++)
    {
        for (int db = -1; db <= 1; db++)
        {
            if (a == b)
            {
                sum = matrix[row][a] + solve(row + 1, a + da, b + db, matrix, n, m, dp);
            }
            else
            {
                sum = matrix[row][a] + matrix[row][b] + solve(row + 1, a + da, b + db, matrix, n, m, dp);
            }
            maxi = max(maxi, sum);
        }
    }
    return dp[row][a][b] = maxi;
}
int solve(int n, int m, vector<vector<int>> &grid)
{
    // code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m - 1, grid, n, m, dp);
}

// Tabulation
int solve(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    int sum = -1e8, maxi = -1e8;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {

                for (int da = -1; da <= 1; da++)
                {
                    for (int db = -1; db <= 1; db++)
                    {
                        if (j1 + da >= 0 and j1 + da < m and j2 + db >= 0 and j2 + db < n)
                        {
                            if (j1 == j2)
                            {
                                sum = grid[i][j1] + dp[i + 1][j1 + da][j2 + db];
                            }
                            else
                            {
                                sum = grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + da][j2 + db];
                            }
                        }
                        else
                            sum = -1e8;
                        maxi = max(maxi, sum);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}

// SPACE OPTIMIZATION
int solve(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<int>> front(m, vector<int>(m, 0));

    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    int sum = -1e8, maxi = -1e8;

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int da = -1; da <= 1; da++)
                {
                    for (int db = -1; db <= 1; db++)
                    {
                        if (j1 == j2)
                        {
                            sum = grid[i][j1];
                        }
                        else
                        {
                            sum = grid[i][j1] + grid[i][j2];
                        }
                        if (j1 + da >= 0 and j1 + da < m and j2 + db >= 0 and j2 + db < n)
                        {
                            sum = sum + front[j1 + da][j2 + db];
                        }
                        else
                            sum = (-1e8);
                        maxi = max(maxi, sum);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return maxi;
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> front(m, vector<int>(m, 0));

        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    front[j1][j2] = grid[n - 1][j1];
                else
                    front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        int sum = -1e8, maxi = -1e8;

        for (int i = n - 2; i >= 0; i--)
        {
            vector<vector<int>> curr(m, vector<int>(m, 0));
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {

                    for (int da = -1; da <= 1; da++)
                    {
                        for (int db = -1; db <= 1; db++)
                        {
                            if (j1 == j2)
                            {
                                sum = grid[i][j1];
                            }
                            else
                            {
                                sum = grid[i][j1] + grid[i][j2];
                            }
                            if (j1 + da >= 0 and j1 + da < m and j2 + db >= 0 and j2 + db < n)
                            {
                                sum = sum + front[j1 + da][j2 + db];
                            }
                            else
                                sum = (-1e8);
                            maxi = max(maxi, sum);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            curr = front;
        }
        return front[0][m - 1];
    }
}
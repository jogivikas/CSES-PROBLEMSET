class Solution
{
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>> &grid,
              int r1, int c1,
              int r2, int c2)
    {

        // Out of bounds
        if (r1 >= n || c1 >= n ||
            r2 >= n || c2 >= n)
        {
            return -1e9;
        }

        // Thorn
        if (grid[r1][c1] == -1 ||
            grid[r2][c2] == -1)
        {
            return -1e9;
        }

        // Destination
        if (r1 == n - 1 && c1 == n - 1)
        {
            return grid[r1][c1];
        }

        // Already calculated
        int &ans = dp[r1][c1][r2];

        if (ans != -1)
            return ans;

        // Current cherries
        int cherries;

        if (r1 == r2 && c1 == c2)
        {
            cherries = grid[r1][c1];
        }
        else
        {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        // Four possibilities
        int option1 = solve(grid,
                            r1 + 1, c1,
                            r2 + 1, c2);

        int option2 = solve(grid,
                            r1 + 1, c1,
                            r2, c2 + 1);

        int option3 = solve(grid,
                            r1, c1 + 1,
                            r2 + 1, c2);

        int option4 = solve(grid,
                            r1, c1 + 1,
                            r2, c2 + 1);

        return ans = cherries +
                     max({option1, option2,
                          option3, option4});
    }

    int cherryPickup(vector<vector<int>> &grid)
    {
        n = grid.size();

        dp.assign(n,
                  vector<vector<int>>(
                      n,
                      vector<int>(n, -1)));

        return max(0, solve(grid, 0, 0, 0, 0));
    }
};
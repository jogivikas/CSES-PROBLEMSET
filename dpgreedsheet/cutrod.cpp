class Solution
{
public:
    vector<vector<int>> dp;

    int solve(vector<int> &cuts, int i, int j)
    {

        // No cut between i and j
        if (j - i == 1)
            return 0;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        // Try every cut as the FIRST cut
        for (int k = i + 1; k < j; k++)
        {

            int cost = solve(cuts, i, k) + solve(cuts, k, j) + (cuts[j] - cuts[i]);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int> &cuts)
    {

        // Add boundaries
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort cuts
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        dp.assign(m, vector<int>(m, -1));

        return solve(cuts, 0, m - 1);
    }
};
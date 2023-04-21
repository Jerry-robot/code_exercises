#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        if (n < 2)
            return 0;
        vector<int> dp(n + 1, -1);
        dp[0] = 0, dp[1] = 0;

        function<int(int)> dfs1 = [&](int k) -> int
        {
            if (dp[k] != -1)
                return dp[k];

            dp[k] = min(dfs1(k - 1) + cost[k - 1], dfs1(k - 2) + cost[k - 2]);
            return dp[k];
        };

        return dfs1(n);
    }
    int dfs(vector<int> &cost, vector<int> &dp, int k)
    {
        if (dp[k] != -1)
            return dp[k];

        dp[k] = min(dfs(cost, dp, k - 1) + cost[k - 1], dfs(cost, dp, k - 2) + cost[k - 2]);
        return dp[k];
    }
};

int main(int argc, char *argv[])
{
    vector<int> cost = {10, 15, 20};
    Solution solution;
    cout << solution.minCostClimbingStairs(cost) << endl;
    return 0;
}

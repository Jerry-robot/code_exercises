#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 2);
        return dfs(nums, dp, nums.size() - 1);
    }

private:
    //记忆化搜索
    bool dfs(vector<int> &nums, vector<int>&dp, int i)
    {
        if (i < 1)
            return false;
        bool res1 = false, res2 = false;
        if(dp[i]!=2)
            return dp[i];
        if (nums[i] == nums[i - 1])
        {
            if (i == 1)
                return true;
            res1 = dfs(nums, dp, i - 2);
        }
        if (i >= 2)
        {
            if ((nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) ||
                (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2))
            {
                if (i == 2)
                    return true;
                res2 = dfs(nums, dp, i - 3);
            }
        }
        dp[i] = res1 || res2;
        return dp[i];
    }
};

int main(int argc, char *argv[])
{
    // vector<int> nums = {4, 4, 4, 5, 6};
    vector<int> nums = {1,1,1,2};
    Solution solution;
    cout << solution.validPartition(nums) << endl;

    return 0;
}

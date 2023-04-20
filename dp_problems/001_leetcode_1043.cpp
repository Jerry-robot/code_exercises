#include <iostream>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

/** 链接：
 * https://leetcode.cn/problems/partition-array-for-maximum-sum/
 * 给你一个整数数组 arr，请你将该数组分隔为长度 最多 为 k 的一些（连续）子数组。
 * 分隔完成后，每个子数组的中的所有值都会变为该子数组中的最大值。
 * 返回将数组分隔变换后能够得到的元素最大和。本题所用到的测试用例会确保答案是一个 32 位整数。

*/

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        // 暴力回溯
        function<int(int)> dfs = [&](int i) -> int
        {
            if (i < 0)
                return 0;

            int res = 0;
            for (int j = i, mx = 0; j >= 0 && j > i - k; --j)
            {
                mx = max(mx, arr[j]);
                res = max(res, dfs(j - 1) + (i - j + 1) * mx);
            }
            return res;
        };

        // 回溯 + 记忆化搜索
        int n = arr.size();
        int dp[n];
        memset(dp, -1, sizeof(dp));

        function<int(int)> dfs_1 = [&](int i) -> int
        {
            if (i < 0)
                return 0;
            if (dp[i] != -1)
                return dp[i];
            int res = 0;

            for (int j = i, mx = 0; j >= 0 && j > i - k; --j)
            {
                mx = max(mx, arr[j]);
                res = max(res, dfs_1(j - 1) + (i - j + 1) * mx);
            }
            dp[i] = res;
            return res;
        };

        // 递推 + 记忆化数组
        int f[n + 1];
        memset(f, 0, sizeof(f));
        function<void(void)> dfs_2 = [&]() -> void
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = i, mx = 0; j >= 0 && j > i - k; --j)
                {
                    mx = max(mx, arr[j]);
                    f[i + 1] = max(f[i + 1], f[j] + mx * (i - j + 1));
                }
            }
        };

        // return dfs(arr.size() - 1);
        // return dfs_1(arr.size() - 1);
        dfs_2();

        // 递推 + 空间优化
        int ff[k];
        memset(ff, 0, sizeof(ff));
        for (int i = 1; i <= n; ++i)
        {
            int res = 0;
            for (int j = i, mx = 0; j >= 0 && j > i - k; --j)
            {
                mx = max(mx, arr[j]);
                res = max(res, ff[j%k] + mx * (i-j+1));
            }
            ff[(i+1)%k] = res;
        }
        return ff[n%k];

    }

private:
    // 回溯 暴力求解
    int dfs1(vector<int> &arr, int i, int k)
    {
        if (i < 0)
            return 0;

        int res = 0;
        for (int j = i, mx = 0; j >= 0 && j > i - k; --j)
        {
            mx = max(mx, arr[j]);
            res = max(res, dfs1(arr, j - 1, k) + (i - j + 1) * mx);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    // vector<int> arr = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    // int k = 4;

    Solution solution;
    cout << solution.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}

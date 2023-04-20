/**
 * @file 002_leetcode_2369.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;

/** 链接：
 * https://leetcode.cn/problems/filling-bookcase-shelves/
给定一个数组 books ，其中 books[i] = [thicknessi, heighti] 表示第 i 本书的厚度和高度。你也会得到一个整数 shelfWidth 。
按顺序 将这些书摆放到总宽度为 shelfWidth 的书架上。
先选几本书放在书架上（它们的厚度之和小于等于书架的宽度 shelfWidth ），然后再建一层书架。
重复这个过程，直到把所有的书都放在书架上。需要注意的是，在上述过程的每个步骤中，摆放书的顺序与你整理好的顺序相同。
例如，如果这里有 5 本书，那么可能的一种摆放情况是：第一和第二本书放在第一层书架上，
第三本书放在第二层书架上，第四和第五本书放在最后一层书架上。
每一层所摆放的书的最大高度就是这一层书架的层高，书架整体的高度为各层高之和。
以这种方式布置书架，返回书架整体可能的最小高度。


输入：arr = [1,15,7,9,2,5,10], k = 3
输出：84
解释：数组变为 [15,15,15,9,10,10,10]
*/

class Solution
{
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();
        // // 暴力递归
        // function<int(int)> dfs = [&](int i) -> int
        // {
        //     if (i < 0)
        //         return 0;

        //     int res = INT32_MAX;
        //     for (int j = i, cur_length = books[j][0], mx = 0; cur_length <= shelfWidth && j >= 0; --j)
        //     {
        //         mx = max(mx, books[j][1]);
        //         res = min(res, dfs(j - 1) + mx);
        //         if (j == 0)
        //             break;
        //         cur_length += books[j - 1][0];
        //     }
        //     return res;
        // };
        // // return dfs(books.size()-1);

        // // 记忆化搜索
        // int dp[n];
        // memset(dp, -1, sizeof(dp));

        // function<int(int)> dfs_1 = [&](int i) -> int
        // {
        //     if (i < 0)
        //         return 0;
        //     if (dp[i] != -1)
        //         return dp[i];
        //     int res = INT32_MAX;
        //     for (int j = i, cur_length = books[j][0], mx = 0; cur_length <= shelfWidth && j >= 0; --j)
        //     {
        //         mx = max(mx, books[j][1]);
        //         res = min(res, dfs_1(j - 1) + mx);
        //         if (j == 0)
        //             break;
        //         cur_length += books[j - 1][0];
        //     }
        //     dp[i] = res;
        //     return res;
        // };
        // // return dfs_1(books.size()-1);

        // 递推
        int f[n + 1];
        memset(f, 0xf, sizeof(f));
        f[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i, cur_length = books[j][0], mx = 0; cur_length <= shelfWidth && j >= 0; --j)
            {
                mx = max(mx, books[j][1]);
                f[i+1] = min(f[i+1], f[j] + mx);
                if (j == 0)
                    break;
                cur_length += books[j - 1][0];
            }
        }


        return f[n];
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1}, {1, 1}, {1, 1}, {1, 2}};
    int shelfWidth = 4;
    Solution solution;
    cout << solution.minHeightShelves(books, shelfWidth) << endl;
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> dp(n, -1);
        return max(rob1(nums, 0, n-1), rob1(nums, 1, n));
    }

private:
    int rob1(vector<int>& nums, int start, int end)
    {
        int cur = 0, pre = 0, tmp;
        for(int i = start; i<end; ++i){
            tmp = cur;
            cur = max(pre + nums[i], cur);
            pre =tmp;
        }
        return cur;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 2, 3, 1};
    Solution sol;
    cout << sol.rob(nums);
    return 0;
}

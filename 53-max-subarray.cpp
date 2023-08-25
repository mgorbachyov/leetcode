#include <cstdio>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int best = nums[0];
    int sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        sum = max(nums[i], sum + nums[i]);
        best = max(sum, best);
    }

    return best;
}

int main(int argc, char *argv[])
{
    //vector<int> nums = {-2,1,-3,4,-1,2,1,-5,105};
    vector<int> nums = {-2,-1};

    auto res = maxSubArray(nums);
    printf("res: %d\n", res);
    return 0;
}


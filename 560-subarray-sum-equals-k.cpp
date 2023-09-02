#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

static int subarraySum(const vector<int>& nums, int k)
{
    unordered_map<int,int> sums;
    int res = 0;
    int sum = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum == k) {
            ++res;
        }
        auto search = sums.find(sum - k);
        if (search != sums.end()) {
            res += search->second;
        }
        sums[sum]++;
    }

    return res;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,4,0};
    int k = 4;
    int res = subarraySum(nums, k);

    printf("k %d, nums:", k);
    for (int i : nums) {
        printf(" %d", i);
    }
    printf("\nres: %d\n", res);
    return 0;
}


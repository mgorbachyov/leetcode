#include <cstdio>
#include <vector>

using namespace std;

vector<int> search_range(vector<int>& nums, int target)
{
    if (nums.empty()) {
        return {-1, -1};
    }

    int left = 0;
    int right = nums.size() - 1;
    if (nums[left] == target && nums[right] == target) {
        return {left,right};
    }

    while (left < right) {
        int pos = left + ((right - left) >> 1);
        if (nums[pos] < target) {
            left = pos + 1;
        } else {
            right = pos;
        }
    }

    if (nums[left] != target) {
        return {-1,-1};
    }

    int res_left = left;

    right = nums.size() - 1;
    while (left < right) {
        int pos = left + ((right - left) >> 1);
        if (nums[pos] <= target) {
            left = pos + 1;
        } else {
            right = pos;
        }
    }

    if (nums[right] != target) {
        --right;
    }

    return {res_left, right};
}

int main(int argc, char *argv[])
{
    vector<int> nums = {5,7,7,8,8,10};

    for (int i : nums) {
        printf(" %d", i);
    }
    printf("\n");

    for (int i : { 8, 6, 0, 5, 10, 11 }) {
        auto res = search_range(nums, i);
        printf("i = %d, res: %d, %d\n", i, res[0], res[1]);
    }
    return 0;
}


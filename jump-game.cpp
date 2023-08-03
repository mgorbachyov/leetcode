#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

static bool can_jump(vector<int>& nums)
{
    if (nums.size() == 1) {
        return true;
    }
#if 0
    vector<bool> can(nums.size(), false);
    can[nums.size() - 1] = true;
    size_t pos = nums.size() - 2;
    while (true) {
        if (nums[pos] >= (nums.size() - pos - 1)) {
            can[pos] = true;
        } else {
            for (int val = nums[pos]; val; --val) {
                if (can[pos + val]) {
                    can[pos] = true;
                    break;
                }
            }
        }
        if (pos) {
            pos--;
        } else {
            break;
        }
    }
    return can[0];
#endif
    size_t next_can = nums.size() - 1;
    for (size_t pos = nums.size() - 2; pos; --pos) {
        if (nums[pos] >= (next_can - pos)) {
            next_can = pos;
        }
    }
    return nums[0] >= next_can;
}

int main(int argc, char* argv[])
{
    //vector<int> nums {2,3,1,1,4};
    //vector<int> nums {3,2,1,0,4};

    vector<int> nums;
    for (size_t n = 9997; n; n--) {
        nums.push_back(n);
    }
    nums.push_back(0);
    nums.push_back(0);

    printf("%d\n", can_jump(nums));
    return 0;
}


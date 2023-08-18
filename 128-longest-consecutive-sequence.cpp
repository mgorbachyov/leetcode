#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

static int longest_consecutive(const vector<int>& nums)
{
    unordered_set<int> hash;
    for (int i : nums) {
        hash.insert(i);
    }
    int longest = 0;
    for (int i : hash) {
        if (hash.find(i - 1) != hash.end()) {
            continue;
        }
        int cur = i;
        while (hash.find(cur + 1) != hash.end()) {
            ++cur;
        }
        longest = max(longest, cur - i + 1);
    }
    return longest;
}

int main(int argc, char *argv[])
{
    //vector<int> nums = {};
    vector<int> nums = {100,4,200,1,3,2};
    //vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    printf("%d\n", longest_consecutive(nums));
    return 0;
}


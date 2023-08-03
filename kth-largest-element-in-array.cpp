#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

static int findKthLargest(vector<int>& nums, int k)
{
    priority_queue<int> q;

    for (const auto n : nums) {
        q.push(n);
    }

    for (int i = 1; i < k; ++i) {
        q.pop();
    }

    return q.top();
}

int main(int argc, char* argv[])
{
    int k;
    sscanf(argv[1], "%d", &k);

    vector<int> nums {3,2,3,1,2,4,5,5,6};
    //vector<int> nums {3,2,1,5,6,4};

    printf("%d-th largest: %d\n", k, findKthLargest(nums, k));
    return 0;
}


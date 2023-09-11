#include <cstdio>
#include <vector>

using namespace std;

static int trap(const vector<int>& height)
{
    int res = 0;

    vector<int> max_left(height.size());
    vector<int> max_right(height.size());
    int i;

    max_left[0] = 0;
    for (i = 1; i < height.size(); ++i) {
        max_left[i] = max(max_left[i - 1], height[i - 1]);
    }

    max_right[height.size() - 1] = 0;
    for (i = height.size() - 2; i >= 0; --i) {
        max_right[i] = max(max_right[i + 1], height[i + 1]);
    }

    for (i = 1; i < height.size() - 1; ++i) {
        res += max(0, min(max_left[i], max_right[i]) - height[i]);
    }

    return res;
}

int main(int argc, char *argv[])
{
    //vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4,2,0,3,2,5};

    int res = trap(height);
    printf("res: %d\n", res);
    return 0;
}


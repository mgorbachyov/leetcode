#include <cstdio>
#include <vector>

using namespace std;

static vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> prev;
    vector<vector<int>> res;

    prev.push_back({});

    for (int n : nums) {
        res.clear();
        for (auto v : prev) {
            v.push_back(n);
            res.push_back(v);
            size_t last = v.size() - 1;
            for (size_t i = 0; i < last; ++i) {
                v[last] = v[i];
                v[i] = n;
                res.push_back(v);
                v[i] = v[last];
                v[last] = n;
            }
        }
        prev.swap(res);
    }

    return prev;
}

int main(int argc, char **argv)
{
    //vector<int> nums = {1,2,3};
    vector<int> nums = {2,3,4,1};

    auto res = permute(nums);

    printf("res:\n");
    for (const auto& v : res) {
        for (int i : v) {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}


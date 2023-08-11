#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<vector<int>> combination_sum(vector<int>& candidates, int target)
{
    if (candidates.empty()) {
        return {};
    }

    vector<vector<int>> res;

    sort(begin(candidates), end(candidates));

    function<void(vector<int>, size_t, int)> check = [&](vector<int> in, size_t pos, int sum) {
        if (sum == target) {
            res.push_back(in);
            return;
        }
        if (pos == candidates.size()) {
            return;
        }
        int c = candidates[pos];
        if (sum + c > target) {
            return;
        }

        check(in, pos + 1, sum);
        while (sum <= target) {
            in.push_back(c);
            sum += c;
            check(in, pos + 1, sum);
        }
    };
    check({}, 0, 0);
    return res;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("usage: %s target\n", argv[0]);
        return 1;
    }

    int target = 0;
    if (sscanf(argv[1], "%d", &target) != 1) {
        printf("failed to get int from '%s'\n", argv[1]);
        return 1;
    }

    vector<int> candidates = {2,3,6,7};
    auto res = combination_sum(candidates, target);
    for (const auto& v : res) {
        for (int i : v) {
            printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}


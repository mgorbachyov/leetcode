#include <cstdio>
#include <vector>
//#include <algorithm>
#include <map>

using namespace std;

static vector<vector<int>> merge(const vector<vector<int>>& intervals)
{
#if 0
    struct {
        bool operator()(const vector<int> &a, const vector<int> &b) const { return a[0] < b[0]; }
    } customLess;

    sort(intervals.begin(), intervals.end(), customLess);

    for (auto it = intervals.begin(); it != intervals.end(); ++it) {
        auto pos = it + 1;
        while (pos != intervals.end() && (*it)[1] >= (*pos)[0]) {
            (*it)[1] = max((*it)[1], (*pos)[1]);
            pos = intervals.erase(pos);
        }
    }

    return intervals;
#endif
    map<int, int> e2s;

    for (const auto &v : intervals) {
        int start = v[0];
        int end = v[1];
        auto it = e2s.lower_bound(start);
        while (it != e2s.end() && it->second <= end) {
            start = min(it->second, start);
            end = max(it->first, end);
            it = e2s.erase(it);
        }
        e2s[end] = start;
    }

    vector<vector<int>> res(e2s.size());
    size_t i = 0;
    for (const auto &p : e2s) {
        res[i++] = { p.second, p.first };
    }
    return res;
}

int main(int argc, char *argv[])
{
    //vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals = {{1,4},{2,3},{5,6}};

    auto show = [](const char *msg, const vector<vector<int>> &in) {
        printf("%s:", msg);
        for (const auto &v : in) {
            printf(" %d,%d", v[0], v[1]);
        }
        printf("\n");
    };

    show("original", intervals);
    auto res = merge(intervals);
    show("merged", res);

    return 0;
}


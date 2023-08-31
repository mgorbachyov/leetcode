#include <cstdio>
#include <vector>
#include <functional>
#include <unordered_set>
#include <utility>

using namespace std;

static int orangesRotting(vector<vector<int>>& grid)
{
    size_t m = grid.size();
    size_t n = grid[0].size();

    vector<pair<int,int>> rot_from;

    size_t fresh = 0;
    size_t i, j;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if (grid[i][j] == 1) ++fresh;
            if (grid[i][j] == 2) {
                rot_from.push_back(make_pair(i, j));
            }
        }
    }

    if (fresh == 0) return 0;

    int t = 0;
    while (!rot_from.empty()) {
        ++t;
        vector<pair<int,int>> rot_next;
        auto rot = [&](int x, int y) {
            if (grid[x][y] == 1) {
                grid[x][y] = 2 + t;
                --fresh;
                rot_next.push_back(make_pair(x, y));
             }
        };

        for (const auto& entry : rot_from) {
            i = entry.first;
            j = entry.second;

            int pos = i - 1;
            if (pos >= 0) {
                rot(pos, j);
            }

            pos = i + 1;
            if (fresh && pos < m) {
                rot(pos, j);
            }

            pos = j - 1;
            if (fresh && pos >= 0) {
                rot(i, pos);
            }

            pos = j + 1;
            if (fresh && pos < n) {
                rot(i, pos);
            }

            if (fresh == 0) {
                return t;
            }
        }
        rot_from.swap(rot_next);
    }

    return -1;
}

int main(int argc, char *argv[])
{
    //vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    //vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
    //vector<vector<int>> grid = {{0,2}};
    vector<vector<int>> grid = {{2,1,1},{1,1,1},{0,1,2}};

    auto show = [](const char* msg, vector<vector<int>> &grid) {
        printf("%s:\n", msg);
        for (const auto &v : grid) {
            for (auto i : v) {
                printf(" %d", i);
            }
            printf("\n");
        }
    };

    show("original grid", grid);
    int res = orangesRotting(grid);
    show("rotten grid", grid);
    printf("res: %d\n", res);
    return 0;
}


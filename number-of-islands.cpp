#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

int num_islands(vector<vector<char>>& grid)
{
    size_t m = grid.size();
    size_t n = grid[0].size();

    function<bool(size_t, size_t)> paint = [&](size_t i, size_t j) {
        if (i >= m || j >= n || grid[i][j] != '1') {
            return false;
        }
        grid[i][j] = 'p';
        paint(i - 1, j);
        paint(i + 1, j);
        paint(i, j - 1);
        paint(i, j + 1);
        return true;
    };

    int color = 0;
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (paint(i, j)) {
                ++color;
            }
        }
    }

    return color;
}

int main(int argc, char* argv[])
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    printf("%d\n", num_islands(grid));
    return 0;
}


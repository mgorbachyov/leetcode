#include <cstdio>
#include <vector>

using namespace std;

static int minPathSum(vector<vector<int>>& grid)
{
    size_t row_max = grid.size() - 1;
    size_t col_max = grid[0].size() - 1;

    size_t delta;

    for (delta = 1; delta <= row_max; ++delta) {
        grid[row_max - delta][col_max] += grid[row_max - delta + 1][col_max];
    }

    for (delta = 1; delta <= col_max; ++delta) {
        grid[row_max][col_max - delta] += grid[row_max][col_max - delta + 1];
    }

    for (size_t row_delta = 1; row_delta <= row_max; ++row_delta) {
        size_t row = row_max - row_delta;
        for (delta = 1; delta <= col_max; ++delta) {
            size_t col = col_max - delta;
            grid[row][col] += min(grid[row + 1][col], grid[row][col + 1]);
        }
    }

    return grid[0][0];
}

int main(int argc, char *argv[])
{
    //vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    //vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    vector<vector<int>> grid = {{1}};

    int res = minPathSum(grid);
    printf("res: %d\n", res);

    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            printf(" %d", grid[i][j]);
        }
        printf("\n");
    }
    return 0;
}


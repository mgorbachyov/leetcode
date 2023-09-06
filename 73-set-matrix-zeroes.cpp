#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

static void setZeroes(vector<vector<int>>& matrix)
{
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    const size_t row_bytes = n * sizeof(int);
    size_t row, col;

    bool row0_zero = false;
    for (col = 0; col < n; ++col) {
        if (matrix[0][col] == 0) {
            row0_zero = true;
            break;
        }
    }

    for (row = 1; row < m; ++row) {
        bool row_zero = false;
        for (col = 0; col < n; ++col) {
            if (matrix[row][col] == 0) {
                row_zero = true;
                matrix[0][col] = 0;
            }
        }
        if (row_zero) {
            memset(&matrix[row][0], 0, row_bytes);
            //for (col = 0; col < n; ++col) {
            //    matrix[row][col] = 0;
            //}
        }
    }

    for (col = 0; col < n; ++col) {
        if (matrix[0][col] == 0) {
            for (row = 1; row < m; ++row) {
                matrix[row][col] = 0;
            }
        }
    }

    if (row0_zero) {
        memset(&matrix[0][0], 0, row_bytes);
        //for (col = 0; col < n; ++col) {
        //    matrix[0][col] = 0;
        //}
    }
}

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = {{1,1,0,1},{3,0,5,2},{1,3,1,5}};
    //vector<vector<int>> matrix = {{1,1,1},{3,0,5},{1,3,1}};

    auto show = [](const char *msg, const vector<vector<int>> &matrix) {
        printf("%s:\n", msg);
        for (const auto& v : matrix) {
            for (int n : v) {
                printf(" %d", n);
            }
            printf("\n");
        }
    };

    show("original", matrix);
    setZeroes(matrix);
    show("after", matrix);

    return 0;
}


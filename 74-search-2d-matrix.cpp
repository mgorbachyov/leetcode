#include <cstdio>
#include <vector>

using namespace std;

static bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    size_t top = 0;
    size_t bottom = matrix.size() - 1;
    size_t left = 0;
    size_t right = matrix[0].size() - 1;

    if (target < matrix[0][0] || target > matrix[bottom][right]) {
        return false;
    }

    size_t row = top;
    while (top < bottom) {
        row = top + ((bottom - top + 1) >> 1);
        if (target < matrix[row][0]) {
            bottom = row - 1;
        } else if (target > matrix[row][right]) {
            top = row + 1;
        } else {
            goto got_row;
        }
    }
    row = top;

got_row:
    const vector<int> &v = matrix[row];
    size_t col = left;
    while (left < right) {
        col = left + ((right - left + 1) >> 1);
        if (target > v[col]) {
            left = col + 1;
        } else if (target < v[col]) {
            right = col - 1;
        } else {
            return true;
        }
    }

    return left == right && v[left] == target;
}

int main(int argc, char *argv[])
{
    //vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix = {{1,1},{3,3}};
    //vector<vector<int>> matrix = {{1}};

    auto res = searchMatrix(matrix, 2);
    printf("res: %d\n", res);
    return 0;
}


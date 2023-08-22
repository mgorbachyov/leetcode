#include <cstdio>
#include <vector>

using namespace std;

static vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> res;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    int left = 0;
    int top = 0;
    int i;
    while (true) {
        if (left == right) {
            for (i = top; i <= bottom; ++i) {
                res.push_back(matrix[i][left]);
            }
            break;
        }
        if (top == bottom) {
            for (i = left; i <= right; ++i) {
                res.push_back(matrix[top][i]);
            }
	    break;
        }
        for (i = left; i < right; ++i) {
            res.push_back(matrix[top][i]);
        }
        for (i = top; i < bottom; ++i) {
            res.push_back(matrix[i][right]);
        }
        for (i = right; i > left; --i) {
            res.push_back(matrix[bottom][i]);
        }
        for (i = bottom; i > top; --i) {
            res.push_back(matrix[i][left]);
        }
        top++;
        bottom--;
        left++;
        right--;
	if (top > bottom || left > right) {
	    break;
	}
    }
    return res;
}

int main(int argc, char *argv[])
{
    //vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    //vector<vector<int>> matrix = {{1}};
    //vector<vector<int>> matrix = {{1,2}};
    //vector<vector<int>> matrix = {{1},{2}};
    //vector<vector<int>> matrix = {{1,2},{3,4},{5,6}};
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    auto show = [](const vector<int> &v) {
        for (int i : v) {
            printf(" %d", i);
        }
        printf("\n");
    };

    for (auto v : matrix) {
        show(v);
    }

    auto res = spiralOrder(matrix);
    printf("result size %lu:", res.size());
    show(res);
    return 0;
}


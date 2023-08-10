#include <cstdio>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int tmp;
    int *first;
    int *p;
    size_t n = matrix.size();
    size_t side_len;
    for (size_t circle = 0; circle < (n >> 1); ++circle) {
        side_len = n - 2 * circle;
        for (size_t i = 0; i < side_len - 1; i++) {
            first = &matrix[circle][circle + i];

            p = &matrix[circle + i][circle + side_len - 1];
            tmp = *p;
            *p = *first;
            *first = tmp;

            p = &matrix[circle + side_len - 1][circle + side_len - 1 - i];
            tmp = *p;
            *p = *first;
            *first = tmp;

            p = &matrix[circle + side_len - 1 - i][circle];
            tmp = *p;
            *p = *first;
            *first = tmp;
        }
    }
}

int main(int argc, char* argv[])
{
    //vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    //vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> matrix = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};

    auto print_matrix = [](const vector<vector<int>>& matrix) {
        for (const auto& row : matrix) {
            for (auto i : row) {
                printf(" %d", i);
            }
            printf("\n");
        }
    };

    printf("before:\n");
    print_matrix(matrix);

    rotate(matrix);

    printf("after:\n");
    print_matrix(matrix);
    return 0;
}


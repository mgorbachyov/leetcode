#include <cstdio>
#include <vector>

using namespace std;

static int unique_paths(int m, int n)
{
    vector<vector<int>> v(m, vector<int> (n));
    int i;
    int j;

    for (i = 0; i < m; ++i) {
        v[i][n - 1] = 1;
    }

    for (j = 0; j < n; ++j) {
        v[m - 1][j] = 1;
    }

    for (i = m - 2; i >= 0; --i) {
        for (j = n - 2; j >= 0; --j) {
            v[i][j] = v[i + 1][j] + v[i][j + 1];
        }
    }

    printf("m %d, n %d\n", m, n);
    for (const auto& raw : v) {
        for (auto x : raw) {
            printf(" %d", x);
        }
        printf("\n");
    }

    return v[0][0];
}

int main(int argc, char *argv[])
{
    unique_paths(3,7);
    unique_paths(3,2);
    unique_paths(1,1);
    return 0;
}


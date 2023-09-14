#include <cstdio>
#include <string>
#include <vector>
#include <functional>

using namespace std;

static vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> sol;
    vector<int> busy_col(n);
    vector<int> busy_diag_up(2 * n - 1);
    vector<int> busy_diag_down(2 * n - 1);

    function<void(int)> search = [&](int row){
        if (row == n) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (busy_col[i] || busy_diag_up[row + i] || busy_diag_down[row - i + n - 1]) {
                continue;
            }
            string str(n, '.');
            str[i] = 'Q';
            sol.push_back(str);
            busy_col[i] = 1;
            busy_diag_up[row + i] = 1;
            busy_diag_down[row - i + n - 1] = 1;
            search(row + 1);
            sol.resize(sol.size() - 1);
            busy_col[i] = 0;
            busy_diag_up[row + i] = 0;
            busy_diag_down[row - i + n - 1] = 0;
        }
    };

    search(0);

    return res;
}

int main(int argc, char *argv[])
{
    auto res = solveNQueens(9);

    printf("res size %lu\n", res.size());
    for (const auto &s : res) {
        printf("solution:\n");
        for (const auto &str : s) {
            printf("%s\n", str.c_str());
        }
    }

    return 0;
}


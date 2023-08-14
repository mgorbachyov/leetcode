#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> prices = {7,1,5,3,6,4};

    int profit = 0;
    int buy = prices[0];
    int tmp;
    for (size_t i = 0; i < prices.size(); ++i) {
        if (prices[i] < buy) {
            buy = prices[i];
            continue;
        }
        tmp = prices[i] - buy;
        if (tmp > profit) {
            profit = tmp;
        }
    }

    printf("my: profit %d\n", profit);
    return 0;
}


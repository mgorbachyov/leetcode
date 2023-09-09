#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

static vector<int> dailyTemperatures(vector<int>& temperatures)
{
    stack<pair<int, size_t>> st;
    for (size_t i = 0; i < temperatures.size(); ++i) {
        while (!st.empty() && st.top().first < temperatures[i]) {
            temperatures[st.top().second] = i - st.top().second;
            st.pop();
        }
        st.push(make_pair(temperatures[i], i));
    }

    while (!st.empty()) {
        temperatures[st.top().second] = 0;
	st.pop();
    }

    return temperatures;
}

int main(int argc, char *argv[])
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    auto show = [](const char *msg, const vector<int>& v) {
        printf("%s:", msg);
        for (int n : v) {
            printf(" %d", n);
        }
        printf("\n");
    };

    show("temperatures", temperatures);
    auto res = dailyTemperatures(temperatures);
    show("res", res);
    return 0;
}


#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> partitionLabels(const string &s)
{
    vector<int> res;

    unordered_map<char, size_t> last;
    size_t i;
    for (i = 0; i < s.size(); ++i) {
        if (last.find(s[i]) == last.end()) {
            last[s[i]] = s.find_last_of(s[i]);
        }
    }

    size_t start = 0;
    while (start < s.size()) {
        size_t end = start;
        for (i = start; i <= end; ++i) {
            end = max(last[s[i]], end);
        }
        res.push_back(end - start + 1);
        start = end + 1;
    }

    return res;
}

int main(int argc, char *argv[])
{
    string s = "ababcbacadefegdehijhklij";
    //string s = "eccbbbbdec";
    //string s = "eecea";

    auto res = partitionLabels(s);
    printf("res:\n");
    size_t pos = 0;
    for (int i : res) {
        printf(" %d '%s'\n", i, s.substr(pos, i).c_str());
        pos += i;
    }
    return 0;
}


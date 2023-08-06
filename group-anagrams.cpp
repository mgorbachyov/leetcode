#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

static vector<vector<string>> group_anagrams(vector<string>& strs)
{
    unordered_map<size_t, vector<string>> groups;
    auto hasher = hash<string>{};
    for (const auto& s : strs) {
        string w(s);
        sort(w.begin(), w.end());
        size_t h = hasher(w);
        groups[h].push_back(s);
    }

    vector<vector<string>> res;
    res.resize(groups.size());
    size_t i = 0;
    for (auto& [key, val] : groups) {
        res[i].swap(val);
        ++i;
    }
    return res;
}

int main(int argc, char* argv[])
{
    //vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs = { "a" };
    auto res = group_anagrams(strs);
    for (const auto& gr : res) {
        for (const auto& s : gr) {
            printf(" %s", s.c_str());
        }
        printf("\n");
    }
    return 0;
}


#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

static vector<int> findAnagrams(string s, string p)
{
    if (p.size() > s.size()) {
        return {};
    }

    char p_freqs[26] = { 0 };
    char freqs[26] = { 0 };

    for (auto i = 0; i < p.size(); ++i) {
        p_freqs[p[i] - 'a']++;
        freqs[s[i] - 'a']++;
    }

    auto show = [&](const char *msg, char *p) {
        printf("%s:", msg);
        for (auto i = 0; i < 26; ++i) printf(" %d", *(p + i));
        printf("\n", msg);
    };

    show("p_freqs", p_freqs);

    vector<int> res;
    int i = 0;
    while (i <= s.size() - p.size()) {
        printf("%d\n", i);
        show("freqs", freqs);
        if (memcmp(p_freqs, freqs, 26) == 0) {
            res.push_back(i);
        }

        freqs[s[i] - 'a']--;
        ++i;
        int last = i + p.size() - 1;
        if (last < s.size()) {
            freqs[s[last] - 'a']++;
        }
    }

    return res;
}

int main(int argc, char *argv[])
{
    string s = "cbaebabacd";
    string p = "cab";
    //string s = "abab";
    //string p = "ab";

    auto res = findAnagrams(s, p);
    for (auto i : res) {
        printf(" %d", i);
    }
    printf("\n");

    return 0;
}


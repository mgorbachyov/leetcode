#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>

using namespace std;

string longest_palindrome(string s)
{
    if (s.empty()) {
        return s;
    }

    string res = s.substr(0, 1);

    if (s.size() < 2) {
        return res;
    }

    bool cache[s.size()][s.size()];
    memset(cache, 0, s.size() * s.size());
    for (size_t len = 2; len <= s.size(); ++len) {
        for (size_t first = 0; first <= s.size() - len; ++first) {
            if ((s[first] == s[first + len - 1]) && (len < 4 || cache[len - 4][first + 1])) {
                if (len > res.size()) {
                    res = s.substr(first, len);
                }
                cache[len - 2][first] = true;
            }
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        assert(!"invalid usage");
    }

    printf("%s\n", longest_palindrome(argv[1]).c_str());
    return 0;
}


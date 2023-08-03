#include <cstdio>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string longest_palindrome(string s)
{
    vector<int8_t> values(s.size() * s.size());
    memset(values.data(), -1, values.size());

    auto value = [&](size_t first, size_t len) -> int8_t& {
        return values[first * s.size() + len - 1];
    };

    std::function<bool(size_t, size_t)> is_palindrome = [&](size_t first, size_t len) -> bool {
        if (len <= 1) {
            return true;
        }
        if (value(first, len) != -1) {
            return value(first, len);
        }
        if ((s[first] == s[first + len - 1]) && is_palindrome(first + 1, len - 2)) {
            value(first, len) = 1;
            return true;
        }
        value(first, len) = 0;
        return false;
    };

    for (size_t len = s.size(); len; --len) {
        for (size_t first = 0; first <= s.size() - len; ++first) {
            if (is_palindrome(first, len)) {
                return s.substr(first, len);
            }
        }
    }

    return "";
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        assert(!"invalid usage");
    }

    printf("%s\n", longest_palindrome(argv[1]).c_str());
    return 0;
}


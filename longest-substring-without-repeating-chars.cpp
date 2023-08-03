#include <cstdio>
#include <string>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.empty()) {
        return 0;
    }

    size_t left = 0;
    size_t res = 1;
    size_t right = 1;

    set<char> chars;
    chars.insert(s[0]);

    while ((left + res < s.size()) && (right < s.size())) {
        char new_char = s[right];
        if (chars.count(new_char)) {
            while (s[left] != new_char) {
                chars.erase(s[left]);
                ++left;
            }
            chars.erase(s[left]);
            ++left;
        } else {
            chars.insert(new_char);
            if (chars.size() > res) {
                res = chars.size();
            }
            ++right;
        }
    }

    return res;
}

int main(int argc, char* argv[])
{
    printf("%s => %d\n", argv[1], lengthOfLongestSubstring(argv[1]));
    return 0;
}


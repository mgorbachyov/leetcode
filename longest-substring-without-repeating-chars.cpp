#include <cstdio>
#include <string>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (s.empty()) {
        return 0;
    }

    size_t first = 0;
    size_t res = 1;
    size_t len = 1;

    set<char> chars;
    chars.insert(s[0]);

    while (first + res < s.size()) {
        char new_char = s[first + len];
        if (chars.count(new_char)) {
            ++first;
	    len = 1;
	    chars.clear();
            chars.insert(s[first]);
        } else {
            chars.insert(new_char);
            ++len;
	    if (len > res) {
	        res = len;
	    }
        }
    }

    return res;
}

int main(int argc, char* argv[])
{
    printf("%s => %d\n", argv[1], lengthOfLongestSubstring(argv[1]));
    return 0;
}


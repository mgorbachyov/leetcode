#include <cstdio>
#include <string>

using namespace std;

static string minWindow(string s, string t)
{
    if (t.size() > s.size()) {
        return "";
    }

    size_t t_freq[60] = { 0 };
    auto tf = [&t_freq](char c) -> size_t& {
        return t_freq[c - 'A'];
    };

    size_t ss_freq[60] = { 0 };
    auto ssf = [&ss_freq](char c) -> size_t& {
        return ss_freq[c - 'A'];
    };

    for (char c : t) {
        tf(c)++;
    }

    size_t left = 0;
    size_t right = 0;
    size_t match = 0;
    size_t res_start = 0;
    size_t res_len = 0;

    char c = s[left];
    if (tf(c) > 0 && ssf(c) < tf(c)) {
        ++match;
    }
    ssf(c)++;

    while (left <= s.size() - t.size()) {
        if (match < t.size()) {
            ++right;
            if (right == s.size()) {
                break;
            }
            c = s[right];
            if (tf(c) > 0 && ssf(c) < tf(c)) {
                ++match;
            }
            ssf(c)++;
        } else {
            size_t size = right - left + 1;
            if (res_len == 0 || size < res_len) {
                res_start = left;
                res_len = size;
            }

            c = s[left];
            if (tf(c) > 0 && ssf(c) <= tf(c)) {
                --match;
            }
            ssf(c)--;
            ++left;
        }
    }

    if (!res_len) {
        return "";
    }
    return s.substr(res_start, res_len);
}

int main(int argc, char *argv[])
{
    //string s = "ADOBECODEBANC";
    //string t = "ABC";
    string s = "a";
    string t = "b";

    printf("s '%s'\nt '%s'\n", s.c_str(), t.c_str());
    auto res = minWindow(s, t);
    printf("res '%s'\n", res.c_str());
    return 0;
}


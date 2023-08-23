#include <cstdio>
#include <string>
#include <stack>

using namespace std;

static string decodeString(string s)
{
    struct entry_t {
        size_t k;
        string str;
    };
    stack<entry_t> st;
    entry_t entry;
    st.push(entry);

    size_t pos;
    size_t i = 0;
    while (i < s.size()) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            st.top().str.push_back(s[i]);
            ++i;
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            entry_t entry;
            entry.k = stoi(s.substr(i), &pos);
            st.push(entry);
            i += pos + 1; // skip '['
            continue;
        }
	pos = st.top().k;
        string tmp(std::move(st.top().str));
        st.pop();
	string &s = st.top().str;
	s.reserve(s.size() + pos * tmp.size());
        while (pos--) {
            s.append(tmp);
        }
        ++i;
    }

    return st.top().str;
}

int main(int argc, char *argv[])
{
    //string s = "3[a]2[bc]";
    string s = "3[a2[c2[ew]q]]";
    //string s = "2[abc]3[cd]ef";

    printf("'%s'\n", decodeString(s).c_str());
    return 0;
}


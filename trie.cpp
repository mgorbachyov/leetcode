#include <cstdio>
#include <cassert>
#include <cstdint>
#include <string>
#include <map>
#include <optional>

using namespace std;


class Trie {
private:
    using entry_t = map<uint8_t, void*>;
    entry_t _root;

public:
    Trie() { }

    void insert(string word) {
        if (word[word.size() - 1] != 0) {
            word += '\0';
        }
        entry_t *cur = &_root;
        for (size_t i = 0; i < word.size(); i++) {
            auto itr = cur->find(word[i]);
	    if (itr == end(*cur)) {
                void *next = word[i] ? new entry_t() : nullptr;
                cur->emplace(word[i], next);
                cur = (entry_t*)next;
            } else {
                cur = (entry_t*)(itr->second);
            }
	}
    }

    bool search(string word) {
        if (word[word.size() - 1] != 0) {
            word += '\0';
        }
        entry_t *cur = &_root;
        for (size_t i = 0; i < word.size(); i++) {
            auto itr = cur->find(word[i]);
	    if (itr == end(*cur)) {
                return false;
            }
            cur = (entry_t*)(itr->second);
        }
        return true;
    }

    bool startsWith(string prefix) {
        entry_t *cur = &_root;
        for (size_t i = 0; i < prefix.size(); i++) {
            auto itr = cur->find(prefix[i]);
	    if (itr == end(*cur)) {
                return false;
            }
            cur = (entry_t*)(itr->second);
            if (!cur) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    Trie* obj = new Trie();
    obj->insert(argv[1]);
    obj->insert("a");
    obj->insert("aa");
    obj->insert("appa");
    obj->insert("app");
    printf("'%s' search '%s': %d, startsWith '%s': %d\n", argv[1], argv[2], (int)(obj->search(argv[2])), argv[2], (int)(obj->startsWith(argv[2])));
    return 0;
}


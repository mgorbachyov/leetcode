#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace std;

static vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int,int> n2freq;
    for (int n : nums) {
        auto search = n2freq.find(n);
        if (search == n2freq.end()) {
            n2freq[n] = 1;
        } else {
            search->second += 1;
        }
    }

    map<int,unordered_set<int>> freq2n;
    for (const auto& p : n2freq) {
        freq2n[p.second].insert(p.first);
    }

    vector<int> res;
    for (auto it = freq2n.crbegin(); it != freq2n.crend(); ++it) {
        for (auto n : it->second) {
            res.push_back(n);
            if (res.size() == k) {
                return res;
            }
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    //vector<int> nums = {1,1,1,2,2,3};
    //vector<int> nums = {0,0,0,0,0,0,0,0,1,1,1,2,2,3,4,5};
    vector<int> nums = {1};

    auto show = [](const char *msg, const vector<int> &v) {
        printf("%s", msg);
        for (int i : v) {
            printf(" %d", i);
        }
        printf("\n");
    };

    show("nums:", nums);
    show("topKFrequent:", topKFrequent(nums, 1));
    return 0;
}


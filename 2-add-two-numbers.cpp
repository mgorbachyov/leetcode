#include <cstdio>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static ListNode* add_two_numbers(ListNode* l1, ListNode* l2)
{
    int extra = 0;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *res = nullptr;
    ListNode *prev = nullptr;
    while (p1 || p2 || extra) {
        int val = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + extra;
        ListNode *p = new ListNode(val % 10);
        if (prev) {
            prev->next = p;
        }
        if (!res) {
            res = p;
        }
        prev = p;
        extra = val / 10;
        if (p1) {
            p1 = p1->next;
        }
        if (p2) {
            p2 = p2->next;
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    vector<int> v1 = {9,9,9,9,9,9,9};
    vector<int> v2 = {9,9,9,9};
    //vector<int> v1 = {3,4,2};
    //vector<int> v2 = {4,6,5};
    //vector<int> v1 = {9};
    //vector<int> v2 = {1};

    ListNode *l1 = nullptr;
    for (int i : v1) {
        ListNode *p = new ListNode(i, l1);
        l1 = p;
    }

    ListNode *l2 = nullptr;
    for (int i : v2) {
        ListNode *p = new ListNode(i, l2);
        l2 = p;
    }

    ListNode *sum = add_two_numbers(l1, l2);
    while (sum) {
        printf(" %d\n", sum->val);
        sum = sum->next;
    }

    auto free_list = [](ListNode *l) {
        while (l) {
            ListNode *p = l;
            l = l->next;
            delete p;
        }
    };

    for (auto p : {l1, l2, sum}) {
        free_list(p);
    }
    return 0;
}


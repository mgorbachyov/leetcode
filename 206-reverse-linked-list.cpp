#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static ListNode* reverseList(ListNode* head)
{
    ListNode *prev = nullptr;
    ListNode *node = nullptr;

    while (head) {
        node = head;
        head = head->next;
        node->next = prev;
        prev = node;
    }
    return node;
}

int main(int argc, char *argv[])
{
    //vector<int> v = {1,2,3,4,5};
    vector<int> v = {};

    ListNode *head = nullptr;

    std::for_each(v.crbegin(), v.crend(), [&head](const int n) {
        ListNode *node = new ListNode(n, head);
        head = node;
    });

    auto show = [](const char *msg, ListNode *node) {
        printf("%s:", msg);
        while (node) {
            printf(" %d", node->val);
            node = node->next;
        }
        printf("\n");
    };

    show("orig", head);
    auto res = reverseList(head);
    show("reverted", res);
    return 0;
}


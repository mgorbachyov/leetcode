#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* ptrs[30] = { 0 };
    ListNode *node = head;
    size_t size = 0;
    while (node) {
        ptrs[size] = node;
        ++size;
        node = node->next;
    }
    if (n < size) {
        size_t prev = size - n - 1;
        node = ptrs[prev];
        node->next = node->next->next;
        delete ptrs[prev + 1];
    } else {
        head = ptrs[1];
    }
    return head;
}

int main(int argc, char *argv[])
{
    assert(argc == 2);
    int n = 0;
    assert(sscanf(argv[1], "%d", &n) == 1);

    vector<int> nums = {1,2,3,4,5};

    ListNode *head = nullptr;
    for (size_t i = nums.size(); i; --i) {
        ListNode *tmp = new ListNode(nums[i - 1], head);
        head = tmp;
    }

    auto show = [](ListNode *node) {
        while (node) {
            printf(" %d", node->val);
            node = node->next;
        }
        printf("\n");
    };

    show(head);
    show(removeNthFromEnd(head, n));

    while (head) {
        auto tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}


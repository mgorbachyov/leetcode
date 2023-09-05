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

static ListNode* swapPairs(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode stub;
    ListNode *prev = &stub;
    ListNode *node = head;
    while (node && node->next) {
        ListNode *tmp = node;
        ListNode *tail = node->next->next;
        node = node->next;
        node->next = tmp;
        prev->next = node;
        tmp->next = tail;
        prev = tmp;
        node = tail;
    }

    return stub.next;
}

int main(int argc, char *argv[])
{
    vector<int> nums = {1,2,3,4,5};

    ListNode *head = nullptr;

    for (auto i = nums.size(); i > 0; --i) {
        ListNode *cur = new ListNode(nums[i - 1], head);
        head = cur;
    }

    auto show = [](const char *msg, ListNode *node) {
        printf("%s:", msg);
        for (; node != nullptr; node = node->next) {
            printf(" %d", node->val);
        }
        printf("\n");
    };

    show("original", head);
    ListNode *res = swapPairs(head);
    show("after swap", res);

    return 0;
}


#include <cstdio>
#include <vector>
#include <functional>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    unordered_map<int, size_t> dist;
    for (size_t i = 0; i < inorder.size(); ++i) {
        dist[inorder[i]] = i;
    }

    using res_t = pair<TreeNode*,size_t>;

    function<res_t(size_t, size_t, size_t)> add = [&](size_t i, size_t first, size_t last) -> res_t {
        if (i >= preorder.size()) {
            return {nullptr,0};
        }

        int val = preorder[i];
        size_t pos = dist[val];

        if (pos < first || pos > last) {
            return {nullptr,0};
        }

        TreeNode *node = new TreeNode(val);
        auto lres = add(i + 1, first, pos);
        auto rres = add(i + 1 + lres.second, pos, last);
        node->left = lres.first;
        node->right = rres.first;
        return {node, lres.second + rres.second + 1};
    };

    auto res = add(0, 0, inorder.size() - 1);
    printf("size %lu\n", res.second);
    return res.first;
}

int main(int argc, char *argv[])
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    //vector<int> preorder = {1,2};
    //vector<int> inorder = {1,2};
    //vector<int> preorder = {1};
    //vector<int> inorder = {1};

    auto res = buildTree(preorder, inorder);

    function<void(TreeNode*)> show_pre = [&](TreeNode *node) {
        if (!node) { printf(" null"); return; }
        printf(" %d", node->val);
        show_pre(node->left);
        show_pre(node->right);
    };

    function<void(TreeNode*)> show_in = [&](TreeNode *node) {
        if (!node) { printf(" null"); return; }
        show_in(node->left);
        printf(" %d", node->val);
        show_in(node->right);
    };

    printf("result preorder:\n");
    show_pre(res);
    printf("\n");

    printf("result inorder:\n");
    show_in(res);
    printf("\n");

    return 0;
}


#include <cstdio>
#include <vector>
#include <functional>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root)
{
    if (!root) {
        return true;
    }

    static function<int(TreeNode*)> tree_max = [](TreeNode *node) {
        int val;
        while (node) {
            val = node->val;
            node = node->right;
        }
        return val;
    };

    static function<int(TreeNode*)> tree_min = [](TreeNode *node) {
        int val;
        while (node) {
            val = node->val;
            node = node->left;
        }
        return val;
    };

    if (root->left) {
        if (!isValidBST(root->left) || (tree_max(root->left) >= root->val)) {
            return false;
        }
    }
    if (root->right) {
        if (!isValidBST(root->right) || (tree_min(root->right) <= root->val)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    //vector<int> in = {2,1,3};
    //vector<int> in = {5,1,4,0,0,3,6};
    vector<int> in = {3,1,5,0,0,4,6};
    size_t size = 0;

    function<TreeNode* (size_t)> create_tree = [&](size_t i) {
        TreeNode *node = nullptr;
        if (i < in.size() && in[i]) {
            ++size;
            node = new TreeNode(in[i]);
            node->left = create_tree(2 * i + 1);
            node->right = create_tree(2 * i + 2);
        }
        return node;
    };

    function<void(TreeNode*)> show_tree = [&](TreeNode *node) {
        if (node) {
            show_tree(node->left);
            printf(" %d", node->val);
            show_tree(node->right);
        }
    };

    TreeNode *root = create_tree(0);

    printf("%d, size %lu\n", isValidBST(root), size);
    show_tree(root);
    printf("\n");
    return 0;
}


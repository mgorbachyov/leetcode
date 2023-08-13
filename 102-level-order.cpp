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

static vector<vector<int>> level_order(TreeNode* root)
{
    vector<vector<int>> res;

    function<void(TreeNode*, size_t)> traverse = [&](TreeNode *node, size_t level) {
        if (!node) {
            return;
        }

        if (res.size() < level + 1) {
            res.push_back({node->val});
        } else {
            res[level].push_back(node->val);
        }

        traverse(node->left, level + 1);
        traverse(node->right, level + 1);
    };

    traverse(root, 0);

    return res;
}

int main(int argc, char* argv[])
{
    vector<int> in = {3,9,20,0,0,15,7};
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

    TreeNode *root = create_tree(0);

    auto res = level_order(root);
    for (const auto& lvl : res) {
        for (auto i : lvl) {
            printf(" %d", i);
        }
        printf("\n");
    }

    return 0;
}


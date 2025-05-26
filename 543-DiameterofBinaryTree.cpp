struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int diameter = 0;

    int depth(TreeNode* root) {
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return diameter;
    }
};

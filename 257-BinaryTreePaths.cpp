#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    void dfs(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;
        if (!root->left && !root->right) {
            result.push_back(path + to_string(root->val));
            return;
        }
        path += to_string(root->val) + "->";
        dfs(root->left, path, result);
        dfs(root->right, path, result);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};

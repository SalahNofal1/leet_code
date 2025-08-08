/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
 string ans = "~"; 
    
    void dfs(TreeNode* node, string& path) {
        if (!node) return;
        
    
        path.push_back('a' + node->val);
        
        if (!node->left && !node->right) {
            
            string candidate = path;
            reverse(candidate.begin(), candidate.end());
            if (candidate < ans) ans = candidate;
        }
        
        dfs(node->left, path);
        dfs(node->right, path);
        
        path.pop_back(); 
    }
    
public:
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return ans;
    }
};
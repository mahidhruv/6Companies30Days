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
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode*> stk1, stk2;
        while (!stk1.empty() || !stk2.empty() || root1 || root2) {
            while (root1) {
                stk1.push(root1);
                root1 = root1->left;
            }
            while (root2) {
                stk2.push(root2);
                root2 = root2->left;
            }
            if (stk2.empty() || (!stk1.empty() && stk1.top()->val <= stk2.top()->val)) {
                root1 = stk1.top();
                ans.push_back(root1->val);
                stk1.pop();
                root1 = root1->right;
            }
            else {
                root2 = stk2.top();
                ans.push_back(root2->val);
                stk2.pop();
                root2 = root2->right;
            }
        }

        return ans;
    }
};
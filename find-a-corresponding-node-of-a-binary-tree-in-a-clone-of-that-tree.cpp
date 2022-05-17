/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int T = target->val ;

        queue<TreeNode*> q;
        TreeNode* ans ; 
        q.push(cloned);

        while( q.size() ){
            auto rt = q.front();
            q.pop();

            if( rt->val == T ){
                ans = rt;
                return rt;
            }

            if( rt->left ) q.push( rt->left );
            if( rt->right ) q.push( rt->right );
        }

        return ans ;
    }
};
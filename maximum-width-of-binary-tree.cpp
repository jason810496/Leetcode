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
    long long ans = 0;
    const long long INF = 1e18;
    vector<pair<long long,long long>> mem;
    int widthOfBinaryTree(TreeNode* root) {
        helper(root,0,0);
        return ans;
    }

    void helper(TreeNode * root,int dep,long long cur){
        if( !root ) return ;
        if( mem.size() == dep ){
            mem.push_back( { INF , -INF } );
        }

        mem[dep].first = min( mem[dep].first , cur );
        mem[dep].second = max( mem[dep].second , cur );
        ans = max( ans , mem[dep].second - mem[dep].first + 1LL );

        if( root->left ) helper(root->left,dep+1,(cur-mem[dep].first)*2LL+1LL);
        if( root->right ) helper(root->right,dep+1,(cur-mem[dep].first)*2LL+2LL);
    }
};
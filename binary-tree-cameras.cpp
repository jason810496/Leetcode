#include<bits/stdc++.h>
using namespace std;

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
    #define NO_CAMERA 0 
    #define HAS_CAMERA 1
    #define NO_NEEDED 2

    int ans=0;

    int DFS(TreeNode *root){
        if( !root) return NO_NEEDED;

        int L = DFS(root->left) , R = DFS(root->right);

        if( L==NO_CAMERA || R==NO_CAMERA ){
            ans++;
            return HAS_CAMERA;
        }
        else if( L==HAS_CAMERA || R==HAS_CAMERA ){
            return NO_NEEDED;
        }
        else{
            return NO_CAMERA;
        }
    }
    int minCameraCover(TreeNode* root) {
        if( DFS(root) == NO_CAMERA ){
            ans++;
        }

        return ans;
    }
};
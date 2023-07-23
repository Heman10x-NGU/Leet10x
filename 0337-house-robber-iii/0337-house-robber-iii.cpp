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
    // int robSum(TreeNode* root,unordered_map<TreeNode*,int>& dp) {
    //     if(!root){
    //       return 0;
    //     }
    //     if(dp.find(root)!=dp.end()){
    //       return dp[root];
    //     }
    //     int val=0;
    //     if(root->left!=NULL){
    //       val += robSum(root->left->left,dp) + robSum(root->left->right,dp);
    //     }
    //     if(root->right != NULL){
    //       val += robSum(root->right->left,dp) + robSum(root->right->right,dp);
    //     }

    // return dp[root]=max(val+root->val,robSum(root->left,dp)+robSum(root->right,dp));
    // }

    vector<int> robSum(TreeNode* root){
      if(!root){
        return {0,0};
      }

      vector<int> left=robSum(root->left);
      vector<int> right=robSum(root->right);
      vector<int> res(2,0);
      //res[0] = when we dont ROB THE ROOT,
      //res[1] = when we do ROB THE ROOT,
      res[0]=max(left[0],left[1]) + max(right[0],right[1]);
      res[1]=root->val + left[0] + right[0]; //meaning take root robbed and right and left not robbed
      return res;
    }
    int rob(TreeNode* root){
        // unordered_map<TreeNode*, int> dp;
        // return robSum(root,dp);

        //this was dp solution simple store ans for every node

        //now try greedy

        vector<int> res=robSum(root);

        //res[0] = when we dont ROB THE ROOT,
        //res[1] = when we do ROB THE ROOT,
        return max(res[0],res[1]);
    }
};
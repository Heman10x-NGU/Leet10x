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
    
    int solve(TreeNode* root,int& maxsum){
        if(!root){
          return 0;
        }

      int left=solve(root->left,maxsum); // take info from left anf right
      int right=solve(root->right,maxsum);

      int got_answer=left + right + root->val; // in this case we wont return
      // as we already got the answer

      int only_one_good=max(left,right) +root->val;
  	  // choice 2 onle taking one of left or right and will go up
      // for the rest path
      int only_root=root->val;
      // choice 3 only take root

      maxsum=max({maxsum,only_root,got_answer,only_one_good});
      //taking max of all three choices
      return max(only_one_good,only_root);
      // dont return the answer we already considered,
      // as it wont bve part of other answers
    }
    int maxPathSum(TreeNode* root) {
      int maxsum=INT_MIN;
        solve(root,maxsum);

        return maxsum;
    }
};
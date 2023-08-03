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
    //1 means I am covered i dont have cameraa, but i am covered
    //0 means i have camera and i am covered as i have camera
    //-1 means i NEED camera
    int solve(TreeNode* root,int& cameras){

      if(!root){
        return 1; // NULL node dosent Have camera but also dosent need so 1
      }

      int leftChild=solve(root->left,cameras);
      int rightChild=solve(root->right,cameras);

      ///now we check 

      //if either of my child needs camera i will have to put a camera on me

      if(leftChild == -1 || rightChild==-1){
        cameras++;
        return 0; // as i have put a cam on me
      }

      // if they dont need cam then if either of them have cam then i dont need

      if(leftChild==0 || rightChild==0){
        return 1; // meaning i dont have cam but i dont need as i am covered
      }

      // if my children dont have camera but they are covered, then i will NEED
      // camera

      return -1;
    }
    int minCameraCover(TreeNode* root) {
        int cameras=0;
        if(solve(root,cameras)==-1){ //if in the end root needs cam so we icnrease it 
          cameras++;
        }
        return cameras;
    }
};
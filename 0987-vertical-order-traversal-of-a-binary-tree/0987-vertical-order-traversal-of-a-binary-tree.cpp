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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        //{vertical,{level,{multiple nodes on that level}}}
        // used multiset as nodes can be of same value 
        // we cannot discard same valued nodes

        queue<pair<TreeNode*,pair<int,int>>> q;
        // {node,{vertical,level}};
        q.push({root,{0,0}});

        while(!q.empty()){
          auto p=q.front();
          q.pop();
          TreeNode* cur=p.first;
          int x=p.second.first; // vertical
          int y=p.second.second; //level
          nodes[x][y].insert(cur->val);
          //at vertical x and level y we inserted the nodes val
          // in multiset which can be same val as other nodes

          // now simple do level order 
          if(cur->left){
            q.push({cur->left,{x-1,y+1}});
            //vertical decreased and level always increases as
            // we are going down
          }
          if(cur->right){
            q.push({cur->right,{x+1,y+1}});
          }
        }

        vector<vector<int>> ans;
        for(auto p:nodes){
          vector<int> col;
          for(auto it:p.second){
            col.insert(col.end(),it.second.begin(),it.second.end());
          }
          ans.push_back(col);
          //pushed multiset for each vertical
        }
        return ans;
        // map<int,map<int,multiset<int>>> nodes;
        //     queue<pair<TreeNode*,pair<int,int>>> todo;
        //     todo.push({root,{0,0}});
        //     while(!todo.empty()){
        //             auto p=todo.front();
        //             todo.pop();
        //             TreeNode* cur=p.first;
        //             int x=p.second.first,y=p.second.second;
        //             nodes[x][y].insert(cur->val);
        //             if(cur->left){
        //                     todo.push({cur->left,{x-1,y+1}});
        //             }
        //             if(cur->right){
        //                     todo.push({cur->right,{x+1,y+1}});
        //             }}
        //     vector<vector<int>> ans;
        //     for(auto p: nodes){
        //             vector<int> col;
        //             for(auto it:p.second){                                                                   col.insert(col.end(),it.second.begin(),it.second.end());
        //             }
        //             ans.push_back(col);
        //     }
            
        //     return ans;
    }
};
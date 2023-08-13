/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
          return "";
        }
        string tree="";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

          TreeNode* cur=q.front();
          q.pop();
          if(cur==NULL){
            tree.append("#,");
          }
          else{
            tree.append(to_string(cur->val) + ",");

            // dont use + operator as that makes new string everytime
            //takes too much memory
            //append simply takes, the string and modifies it
          }
          if(cur!=NULL){
            //as a leaf node will have two #s as children
            q.push(cur->left);
            q.push(cur->right);
          }
        }
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
          return NULL;
        }
        stringstream s(data);

        //done in order to iterate the string by the comma ","
        string str;

        getline(s,str,',');

        //whenever this is called it will iterate to the
        //next element after "," and put that string into str

        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

          TreeNode* cur=q.front();
          q.pop();

          getline(s,str,',');
          //now it will go to the next string after","
          //and store it in str

          if(str=="#"){
            cur->left=NULL;
          }
          else{
            //if it wasnt # create new node and put int val of str
            TreeNode* leftNode=new TreeNode(stoi(str));
            cur->left=leftNode;
            q.push(leftNode);
            //push it in queue for further processing
          }

          //for current node its left part is processed

          getline(s,str,',');
          //now for the right node of current node

          if(str=="#"){
            cur->right=NULL;
          }
          else{
            TreeNode* rightNode=new TreeNode(stoi(str));
            cur->right=rightNode;
            q.push(rightNode);
          }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//Insert into a Binary Search Tree
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr=root;
        while(true){
            if(curr->val<val){
                if(curr->right!=NULL){
                    curr=curr->right;
                }else{
                    curr->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left!=NULL){
                    curr=curr->left;
                }else{
                    curr->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;

    }
};

//Binary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            vector<int> level;

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

//Maximum Depth of Binary Tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);

        return 1+max(l,r);
    }
};

//Balanced Binary Tree
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root)!=-1;
    }

    int depth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int l=depth(root->left);
        if(l==-1) return -1;

        int r=depth(root->right);
        if(r==-1) return -1;

        if(abs(l-r)>1) return -1;

        return 1+max(l,r);
    }
};

//Search in a Binary Search Tree
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val){
            root=val<root->val?root->left:root->right;
        }
        return root;
    }
};

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

//Binary Tree Inorder Traversal
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& arr){
        if(root==NULL){
            return;
        }
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

// Maximum Depth of Binary Tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);

        return 1+max(l,r);
    }
};

// Invert Binary Tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        TreeNode* left=invertTree(root->left);
        TreeNode* right=invertTree(root->right);

        root->left=right;
        root->right=left;
      
        return root;

    }
};

//alidate Binary Search Tree
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX);
    }

    bool valid(TreeNode* root,long long min,long long max){
        if(root==NULL) return true;
        if(root->val>=max|| root->val<=min) return false;
        
        return valid(root->left,min,root->val) && valid(root->right,root->val,max);

    }
};

//Kth Smallest Element in a BST
class Solution {
public:
    int c=0;
    int ans=-1;
    void inorder(TreeNode* root, int k){

        if(root==NULL){
            return;
        }
        inorder(root->left,k);

        c++;
        if(c==k){
            ans=root->val;
            return;
        }

        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};

// Same Tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
            return false;
        }

        return ((p->val==q->val) &&  isSameTree(p->left,q->left) && isSameTree(p->right,q->right));
    }
};

//Symmetric Tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return func(root->left,root->right);
    }

    bool func(TreeNode* left,TreeNode* right){
        if(left==NULL && right==NULL){
            return true;
        }
        if(left == NULL || right == NULL){
        return false;
        }
        return  (left->val==right->val)&& func(left->left,right->right) && func(left->right,right->left);
    }
};

//Path Sum
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }

        if(root->left==NULL && root->right==NULL){
            return targetSum==root->val;
        }

        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};


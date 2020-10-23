class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(p==root ||  q==root){
            return root;
        }
        TreeNode * left=lowestCommonAncestor(root->left,p,q);
        TreeNode * right=lowestCommonAncestor(root->right,p,q);
        if(left!=NULL && right!=NULL){
            return root;
        }
        if(left==NULL && right==NULL){
            return NULL;
        }
        if(left!=NULL && right==NULL){
            return left;
        }
        if(left==NULL && right!=NULL){
            return right;
        }
        return root;
    }
};

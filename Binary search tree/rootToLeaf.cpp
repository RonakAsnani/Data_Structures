#include<vector>
#include "BSTClass.h"

void helper(BinaryTreeNode<int>* root,int k,vector<int> v){
    if(!root) return;

    if(!root->left && !root->right){
        if(k- root->data == 0){
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }
            cout<<root->data<<endl;
        }
        return;
    }
    v.push_back(root->data);
    helper(root->left,k-root->data,v);
    helper(root->right,k-root->data,v);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
	
    vector<int> v;
    
    helper(root, k, v);
}
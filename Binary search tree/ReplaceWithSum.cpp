#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#include "BinaryTree.h"
using namespace std;


void printlevelwise(BinaryTreeNode<int>* root){
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        if(front != NULL){
            q.pop();
            cout<<front->data<<":";
            if(front->left){
                q.push(front->left);
                cout<<"L"<<front->left->data;
            }
            if(front->right){
                q.push(front->right);
                cout<<"R"<<front->right->data;
            }
            cout<<endl;
            }
    }
        

}

BinaryTreeNode<int>* takeinputlevelwise(){
    int rootData;
    cout<<"Enter root data: "<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        cout<<"Enter left child of "<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            q.push(child);
        }
        cout<<"Enter right child of "<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            q.push(child);
        }
    }
    return root;
}

int LCA(BinaryTreeNode<int>* root,int k1,int k2){
    if(!root) return -1;
    if(root->data == k1 || root->data == k2){
        return root->data;
    }
    if(root->data > k1 && root->data > k2){
        return LCA(root->left,k1,k2);
    }
    if(root->data < k1 && root->data < k2){
        return LCA(root->right,k1,k2);
    }
    int l = LCA(root->left, k1, k2);
        int r = LCA(root->right, k1, k2);
        if (l == -1 && r == -1)
        {
            return -1;
        }
        else if (l != -1 && r == -1)
        {
            return l;
        }
        else if (r != -1 && r == -1)
        {
            return r;
        }
        else
        {
            return root->data;
        }
}

int con(BinaryTreeNode<int>* root,int up){
    if(!root) return up;
    //if(!root->right) root->data;

    
   // root->data += up;
     up = con(root->right,up);
    
    up += root->data;
    root->data = up;
    up = con(root->left,up);
    return up;
    
}

int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();
    printlevelwise(root);
    con(root,0);
    printlevelwise(root);

    return 0;
}
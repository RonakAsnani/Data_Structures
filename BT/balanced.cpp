#include<iostream>
#include<queue>
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

void preorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

pair<bool,int> balanced(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<bool,int> p;
        p.first = true;
        p.second = 0;
        return p;

    }
    //cout<<depth<<endl;
    pair<bool,int> leftpair;
    pair<bool,int> rightpair;
    if(root->left){
         leftpair = balanced(root->left);
    }
    if(root->right){
        rightpair = balanced(root->right);
    }
    
    
    if(abs(leftpair.second - rightpair.second) <= 1){
        pair<bool,int> p;
        p.first = true;
        p.second = 1 + max(leftpair.second,rightpair.second);
        return p;
    }else{
        pair<bool,int> p;
        p.first = false;
        p.second = 1 + max(leftpair.second,rightpair.second);
        return p;
    }

    
    
    
}


int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();
    // int x;
    // cin>>x;
    cout<<balanced(root).first;
    
    return 0;
}
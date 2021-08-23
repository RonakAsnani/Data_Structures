#include<iostream>
#include<queue>
#include<stack>
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

// void preorder(BinaryTreeNode<int>* root){
//     if(root == NULL){
//         return;
//     }
//     cout<<root->data<<" ";
//     preorder(root->left);
//     preorder(root->right);

// }

void preorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> s;
    s.push(root);
    while(!s.empty()){
        BinaryTreeNode<int>* curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        if(curr->right){
            s.push(curr->right);
        }
        if(curr->left){
            s.push(curr->left);
        }
    }
    

    
}


int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();

    preorder(root);
    
    return 0;
}
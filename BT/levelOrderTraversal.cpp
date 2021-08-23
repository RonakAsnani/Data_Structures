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

void printlevelwise2(BinaryTreeNode<int>* root){
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front == NULL){
            if(q.empty()){
                return;
            }else{
                cout<<endl;
               q.push(NULL);
            }
        }else{
            cout<<front->data<<" ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
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

int sum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    
    int ans = root->data;
    ans += sum(root->left);
    ans += sum(root->right);
    return ans;
}


int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();
    // int x;
    // cin>>x;
    printlevelwise2(root);
    
    return 0;
}
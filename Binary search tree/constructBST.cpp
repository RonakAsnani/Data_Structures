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

bool search(BinaryTreeNode<int>* root,int x){
    if(root == NULL){
        return false;
    }
    if(root->data  == x){
        return true;
    }
    if(root->data > x){
        return search(root->left,x);
    }else{
        return search(root->right,x);
    }

    
}
BinaryTreeNode<int>* construct(int* a,int st,int en){
    while(en >= st){
        int mid = st + (en-st)/2;
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(a[mid]);
        root->left = construct(a,st,mid-1);
        root->right = construct(a,mid+1,en);
        return root;
    }
    return NULL;
}

int main(){
    int n;
    cin>>n;
    int* a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    printlevelwise(construct(a,0,n-1));
    return 0;
}
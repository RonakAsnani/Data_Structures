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

pair<bool,bool> LCA(BinaryTreeNode<int>* root,int k1,int k2,int &final){
    pair<bool,bool> p;
    p.first = false;
    p.second = false;
    if(!root) return p;
    if(root->data == k1) p.first = true;
    if(root->data == k2) p.second = true;

    pair<bool,bool> lp = LCA(root->left,k1,k2,final);
    pair<bool,bool> rp = LCA(root->right,k1,k2,final);

    if(lp.first || rp.first) p.first = true;
    if(lp.second || rp.second) p.second = true;

    if((lp.first && lp.second) || (rp.first && rp.second)){
        return p;
    }
    if(p.first && p.second){
        final = root->data;
    }
    return p;
}


int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();
    int k1,k2;
    cin>>k1>>k2;
    int final = -1;
    LCA(root,k1,k2,final);
    cout<<final<<endl;

    return 0;
}
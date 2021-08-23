#include<iostream>
#include<queue>
// #include<cmath>
#include<climits>
#include<utility>
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

int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left),height(root->right));
}
int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int one = diameter(root->left);
    int two = diameter(root->right);
    int three = height(root->left) + height(root->right);
    return max(one,max(two,three));
}

pair<int,int> minmax(BinaryTreeNode<int>* root){

    queue<BinaryTreeNode<int>*> q;
    int ma = INT_MIN;
    int mi = INT_MAX;
    if(root == NULL){
        pair<int,int> p;
        p.first = mi;
        p.second = ma;
        return p;
    }
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        ma = max(ma,front->data);
        mi = min(mi,front->data);
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
        q.push(front->right);
        }
    }
    pair<int,int> ans;
    ans.first = mi;
    ans.second = ma;
    return ans;
}

int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();
    pair<int,int> ans = minmax(root);
    cout<<ans.first<<" "<<ans.second;
    
    return 0;
}
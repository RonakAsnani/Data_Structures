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


vector<int> all(BinaryTreeNode<int>* root){
    vector<int> v;
    if(!root) return v;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        v.push_back(front->data);
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    } 
    return v;

}

int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();
    int x;
    cin>>x;
    vector<int> v = all(root);
    sort(v.begin(),v.end());
    int st = 0, en = v.size()-1;
    while(st <= en){
        if(v[st] + v[en] == x){
            cout<<v[st]<<" "<<v[en]<<endl;
            en--;
        }else if(v[st] + v[en] < x){
            st++;
        }else{
            en--;
        }
    }
    return 0;
}
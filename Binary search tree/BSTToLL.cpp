#include<iostream>
#include<queue>
#include "BinaryTree.h"
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
    }
};

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

pair<Node*,Node*> BSTToLL(BinaryTreeNode<int>* root){
    pair<Node*,Node*> p;
    
    if(!root){
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    pair<Node*,Node*> lp = BSTToLL(root->left);
    pair<Node*,Node*> rp = BSTToLL(root->right);

    Node* newnode = new Node(root->data);
    
    if(lp.second == NULL){
        p.first = newnode;
        newnode->next = rp.first;
    }else{
        lp.second->next = newnode;
    newnode->next = rp.first;
    p.first = lp.first;
    }
    if(rp.first == NULL){
        p.second = newnode;
    }else{
        p.second = rp.second;
    }
    p.second->next = NULL;
    
    return p;

}

int main(){
    BinaryTreeNode<int>* root = takeinputlevelwise();
    pair<Node*,Node*> p = BSTToLL(root);
    //cout<<"fre"<<endl;
    Node* head = p.first;

    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}


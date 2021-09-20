#include "BinaryTree.h"
#include<queue>
#include<iostream>
#include <cstddef>
using namespace std;
class BST{
    BinaryTreeNode<int>* root;

    public:
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    private:

        BinaryTreeNode<int>* delete1(BinaryTreeNode<int>* root,int x){
            if(!root){
                return NULL;
            }
            if(root->data > x){
                root->left = delete1(root->left,x);
                return root;
            }else if(root->data < x){
                root->right = delete1(root->right,x);
                return root;
            }else{
                if(!root->left && !root->right){
                    delete root;
                    return NULL;
                }else if(root->left == NULL){
                    BinaryTreeNode<int>* temp = root->right;
                    root->right = NULL;
                    delete root;
                    return temp;
                }else if(!root->right){
                    BinaryTreeNode<int>* temp = root->left;
                    root->left = NULL;
                    delete root;
                    return temp;
                }else{
                    BinaryTreeNode<int>* minnode = root->right;
                    while(minnode->left != NULL){
                        minnode = minnode->left;
                    }
                    int rightmin = minnode->data;
                    root->data = rightmin;
                    root->right  = delete1(root->right,rightmin);
                    return root;
                }
            }
        }
    public:
    void deleteData(int data){
        root = delete1(root,data);
    }
    private:
    BinaryTreeNode<int>* insert1(BinaryTreeNode<int>* root,int x){
        if(!root){
            BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(x);
            return newnode;
        }
        if(root->data > x){
            root->left = insert1(root->left,x);
            return root;
        }
        root->right = insert1(root->right,x);
        return root;
    }
    public:
    void insert(int data){
        this->root = insert1(root,data);
    }
    private:
    bool hasData1(BinaryTreeNode<int>* root,int x){
        if(!root) return false;
        if(root->data  = x){
            return true;
        }else if(root->data > x){
            return hasData1(root->left,x);
        }else{
            return hasData1(root->right,x);
        }
    }
    public:
    bool hasData(int data){
        return hasData1(root,data);

    }
    void printlevelwise(){
    
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
};
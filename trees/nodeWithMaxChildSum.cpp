#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* takeinputlevelwise(){
    int rootData;
    cout<<"Enter root data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter num of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int child;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>child;
            TreeNode<int>* childNode = new TreeNode<int>(child);
            front->children.push_back(childNode);
            pendingNodes.push(childNode);
        }
    }
    return root;

}
    void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        cout<<q.front()->data<<": ";
        TreeNode<int>* front = q.front();
        q.pop();
        for(int i=0;i<front->children.size();i++){
            cout<<front->children[i]->data<<",";
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}

TreeNode<int>* countNum(TreeNode<int>* root){
    if(root == NULL){
      
        return 0;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    TreeNode<int>* t = root;
    int ans = -9999;
    while(!q.empty()){
        int x =0;
        TreeNode<int>* temp = q.front();
        q.pop();
        x += temp->data;
        for(int i=0;i<temp->children.size();i++){
            x += temp->children[i]->data;
            q.push(temp->children[i]);
        }
        if(x > ans){
            ans = x;;
            t =temp;
        }
    }
    return t;
}

int main(){
    TreeNode<int>* root = takeinputlevelwise();

    cout<<countNum(root)->data;


    return 0;
}
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

TreeNode<int>* second(TreeNode<int>* root){
    if(root == NULL){  
        return NULL;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    TreeNode<int>* t = new TreeNode<int>(0);
    int low = 0;
    while(!q.empty()){
      
        TreeNode<int>* temp = q.front();
        q.pop();
        if(temp->data > t->data){
            t = temp;
            
        }
        // if(temp->data < m && temp->data > m2){
        //     m2 = temp->data;
        //     t = temp;
        // }
        for(int i=0;i<temp->children.size();i++){
          
            q.push(temp->children[i]);
        }
    }
    return t;
}

int main(){
    TreeNode<int>* root = takeinputlevelwise();

    TreeNode<int>* ans  = second(root);
    if(ans == NULL){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans->data<<endl;
    return 0;


    return 0;
}
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

bool check(TreeNode<int>* root1,TreeNode<int>* root2){
    if(root1 == NULL && root2 ==  NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->data != root2->data || root1->children.size() != root2->children.size()){
        return false;
    }
    bool ans= true;
    for(int i=0;i<root1->children.size();i++){
        // if(root1->children[i]->data != root2->children[i]->data){
        //     return false;
        // }
        ans  = ans && check(root1->children[i],root2->children[i]);
    }
    return ans;
    
    
}

int main(){
    TreeNode<int>* root1 = takeinputlevelwise();
    TreeNode<int>* root2 = takeinputlevelwise();

    cout<<check(root1,root2);


    return 0;
}
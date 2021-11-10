#include<bits/stdc++.h>
#include "TrieNode.h"
using namespace std;


class Trie{
    TrieNode * root;

    public:
    Trie(){
        root = new TrieNode('\0 ');
    }
    private:
    void insert(string s,TrieNode* node){
         if(s.empty()){
             node->isTerminal = true;
             return;
         }
         if(node->children[s[0]-'a'] != NULL){
             insert(s.substr(1),node->children[s[0]-'a']);
         }else{
             node->children[s[0]-'a'] = new TrieNode(s[0]);
             insert(s.substr(1),node->children[s[0]-'a']); 
         }
         
    }

    bool search(TrieNode* root,string s){
        if(s.empty()){
            return root->isTerminal;
        }
        int index = s[0] - 'a';
        if(root->children[index] == NULL){
            return false;

        }
        return search(root->children[index],s.substr(1));

    }

    void remove(TrieNode* root,string s){
        if(s.size()==0){
            root->isTerminal = false;
            return;
        }
        int index = s[0] -'a';
        TrieNode* child;
        if(root->children[index] == NULL){
            return;
        }
        remove(root->children[index],s.substr(1));
        bool flag = true;
       child = root->children[index];
       if(child->isTerminal == false){
           bool flag = true;
        for(int i=0;i<26;i++){
            if(child->children != NULL){
                flag = false;
                break;
            }
        }
        if(flag){
            delete child;
            root->children[index] = NULL; 
        }
       }
    }
    public:
    void insertWord(string s){
        insert(s,root);
    }

    bool search(string s){
        return search(root,s);
        
    }

    void remove(string s){
        remove(root,s);
    }
};
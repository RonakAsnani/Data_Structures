#include <bits/stdc++.h>
using namespace std;
#include "Trie.h"

void printComplete(TrieNode *root, string word)
{
    if (word.size() == 0)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                cout << root->children[i];
                printComplete(root->children[i], word);
            }
            else
            {
                return;
            }
        }
    }
    int index = word[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        return;
    }
    else
    {
        cout << root->children[index];
        printComplete(root->children[index], word.substr(1));
    }
}

int main()
{

    return 0;
}
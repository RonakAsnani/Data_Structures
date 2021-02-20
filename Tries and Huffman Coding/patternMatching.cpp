/*Pattern Matching
Given a list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not.
Return true or false.
Input Format :
Line 1 : Integer n
Line 2 : n words (separated by space)
Line 3 : Pattern p (a string)
Output Format :
true ot false
Sample Input 1 :
4
abc def ghi cba
de
Sample Output 2 :
true
Sample Input 2 :
4
abc def ghi hg
hi
Sample Output 2 :
true
Sample Input 3 :
4
abc def ghi hg
hif
Sample Output 3 :
false
*/

// correct but not running

#include <bits/stdc++.h>
using namespace std;
//#include "TrieNode.h"

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;
    Trie()
    {
        root = new TrieNode('\0');
    }

    bool insertPattern(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else
        {
            child = root->children[index];
        }
        return insertPattern(child, word.substr(1));
    }
    void insert(string word)
    {
        if (insertPattern(root, word))
        {
            this->count++;
        };
    }

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] == NULL)
        {
            return false;
        }
        else
        {
            child = root->children[index];
            search(child, word.substr(1));
        }
        return false;
    }
    bool ser(string word)
    {
        return search(root, word);
    }

    bool patternMatch(vector<string> v, string pattern)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                insert(v[i].substr(j));
            }
        }
        return ser(pattern);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;
    vector<string> v;

    string str;
    ;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        v.push_back(input);
    }
    // string str;
    cin >> str;

    cout << t.patternMatch(v, str);
}

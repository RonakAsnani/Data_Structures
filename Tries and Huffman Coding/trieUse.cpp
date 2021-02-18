#include <bits/stdc++.h>
using namespace std;
#include "Trie.h"
//#include "TrieNode.h"

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.searchWord("and") << endl;

    t.removeWord("and");
    cout << t.searchWord("and") << endl;
    return 0;
}
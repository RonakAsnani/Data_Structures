#include <bits/stdc++.h>
using namespace std;

int main()
{
    // in maps
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    unordered_map<string, int>::iterator it = ourmap.begin();
    while (it != ourmap.end())
    {
        cout << "key: " << it->first << " "
             << "value: " << it->second << endl;
        it++;
    }
    // find
    unordered_map<string, int>::iterator it2 = ourmap.find("abc");
    ///check // ourmap.erase(it2, it2 + 4);

    // vectors
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it1 = v.begin();
    while (it1 != v.end())
    {
        cout << *it1 << " ";
        it1++;
    }
    return 0;
}
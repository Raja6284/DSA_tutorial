#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

    // creation of unordered map
    unordered_map<string, int> m;

    // insertion
    // 1
    pair<string, int> p1 = make_pair("raja", 5);
    m.insert(p1);

    // 2
    pair<string, int> p2("kumar", 10);
    m.insert(p2);

    // 3
    m["Rajaji"] = 1;

    // 4
    m["Rajaji"] = 2;

    // accessing the element of the map
    cout << m["raja"] << endl;
    cout << m.at("kumar") << endl;

    cout << m["unknown"] << endl;
    // cout << m.at("unknown") << endl;

    // finding the size of the array
    cout << m.size() << endl;

    // to check presence
    // if present return 1, if absent return 0
    cout << m.count("raja") << endl;
    cout << m.count("bro") << endl;

    // erase
    m.erase("kumar");
    cout << m.size() << endl;

    // Traversing the map
    for (auto i : m)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;

    // Traversing the map using iterator
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    // unordered_map will print the element in random order
    // ordered_map will print the element in preserved ordre
    // ordered_map is based on BST

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k = 5;
    vector<int> v;
    v = {8, 9, 6, 2, 3, 7, 4, 96, 52, 46, 83};
    int n = v.size();

    sort(v.begin(), v.end());

    cout << "sorted array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        if (i == k)
        {   //by default the vecotr has 0-basec index
            cout << k << "th smallest element is " << v[i - 1] << endl;
            cout << k << "th largest element is " << v[n - i] << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void fn()
{
    char c;
    cin >> c;
    string s;
    cin >> s;
    cin >> s;
    vector<string> v;
    string ts = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '|')
        {
            v.push_back(ts);
            ts.clear();
        }
        else
            ts.push_back(s[i]);
    }
    if (ts.size())
        v.push_back(ts);
    sort(v.begin(), v.end());
    if (c != v[0][0])
    {
        cout << "Not left recursive!\n\n";
        return;
    }
    cout << c << " -> " << v[1] << c << "'\n";
    cout << c << "'" << " -> ";
    for (int i = 1; i < v[0].size(); i++)
        cout << v[0][i];
    cout << c << "' | " << (char)238 << endl
         << endl;
}
int main()
{
    int n;
    cout << "Enter the number of Expression: ";
    cin >> n;
    while (n--)
    {
        fn();
    }
}

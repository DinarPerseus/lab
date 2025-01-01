#include <bits/stdc++.h>
using namespace std;
string p(string x, string y)
{
    string prefix = "";
    for (int i = 0; i < min(x.size(), y.size()); i++)
    {
        if (x[i] != y[i])
            break;
        else
            prefix.push_back(x[i]);
    }
    return prefix;
}
bool fn(char c, vector<string> &v, char &nc)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
    {
        string pre = p(v[i], v[i + 1]);
        if (pre.size() > 1)
        {
            cout << nc << " -> " << pre << c << " | " << (char)238 << endl;
            string x = "";
            x.push_back(nc);
            for (int k = pre.size(); k < v[i].size(); k++)
                x.push_back(v[i][k]);
            v[i] = x;
            x.clear();
            x.push_back(nc);
            for (int k = pre.size(); k < v[i + 1].size(); k++)
                x.push_back(v[i + 1][k]);
            v[i + 1] = x;
            nc++;
            return 1;
        }
    }
    return 0;
}
int main()
{
    char c;
    cin >> c;
    string s;
    cin >> s;
    cin >> s;
    cout << endl;
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
    char x = 'A';
    while (fn(c, v, x))
        ;
    cout << c << " -> ";
    for (auto y : v)
        cout << y << " | ";
    cout << (char)238 << endl;
}
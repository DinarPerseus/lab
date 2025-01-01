#include <bits/stdc++.h>
#define fo(i, n) for (int i = 0; i < n; i++)
using namespace std;
int op(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return 1;
    else
        return 0;
}
void printStack(stack<string> st)
{
    if (st.empty())
        return;
    string x = st.top();
    st.pop();
    printStack(st);
    cout << x << " ";
}
void printStackReverse(stack<string> st)
{
    if (st.empty())
        return;
    string x = st.top();
    st.pop();
    cout << x << " ";
    printStackReverse(st);
}
int main()
{
    stack<string> st, ins;
    vector<string> in;
    string s;
    getline(cin, s);
    fo(i, s.size())
    {
        string t = "";
        while (i < s.size() && s[i] != ' ')
            t.push_back(s[i++]);
        in.push_back(t);
    }
    for (int i = in.size() - 1; i >= 0; i--)
        ins.push(in[i]);
    map<string, string> g;
    g["E+E"] = "E";
    g["E*E"] = "E";
    g["id"] = "E";
    cout << left << setw(20) << "STACK"
         << setw(30) << "INPUT"
         << "ACTION" << "\n";
    cout << string(60, '-') << "\n";
    while (ins.size())
    {
        cout << "$";
        printStack(st);
        cout << setw(20 - st.size()) << "";
        printStackReverse(ins);
        cout << setw(30 - ins.size()) << "$";
        if (st.empty())
        {
            st.push(ins.top());
            cout << "Shift" << "\n";
            ins.pop();
        }
        else
        {
            if (g[st.top()].size())
            {
                string t = st.top();
                cout << "Reduce " << g[st.top()] << " -> " << t << "\n";
                st.pop();
                st.push(g[t]);
                continue;
            }
            string x = "";
            stack<string> tempStack = st;
            while (tempStack.size())
            {
                x = tempStack.top() + x;
                tempStack.pop();
            }
            if (g[x].size())
            {
                cout << "Reduce " << g[x] << " -> " << x << "\n";
                while (st.size())
                    st.pop();
                st.push(g[x]);
            }
            else
            {
                if (op(st.top()) == op(ins.top()))
                {
                    cout << "ERROR\n";
                    return 0;
                }
                st.push(ins.top());
                ins.pop();
                cout << "Shift" << "\n";
            }
        }
    }
    while (st.size() > 1)
    {
        cout << "$";
        printStack(st);
        cout << setw(20 - st.size()) << "";
        printStackReverse(ins);
        cout << setw(30 - ins.size()) << "$";
        if (g[st.top()].size())
        {
            string t = st.top();
            cout << "Reduce " << g[st.top()] << " -> " << t << "\n";
            st.pop();
            st.push(g[t]);
            continue;
        }
        string x = "";
        stack<string> tempStack = st;
        while (tempStack.size())
        {
            x = tempStack.top() + x;
            tempStack.pop();
        }
        if (g[x].size())
        {
            cout << "Reduce " << g[x] << " -> " << x << "\n";
            while (st.size())
                st.pop();
            st.push(g[x]);
        }
        else
        {
            cout << "ERROR\n";
            return 0;
        }
    }
    cout << "$";
    printStack(st);
    cout << setw(20 - st.size()) << "";
    printStackReverse(ins);
    cout << setw(30 - ins.size()) << "$\n";
    return 0;
}
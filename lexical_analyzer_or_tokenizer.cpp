#include <bits/stdc++.h>
using namespace std;
vector<string> tokens;
vector<string> sep = {" ", ",", "(", ")", "{", "}", "[", "]", ";"};
vector<string> op = {"+", "-", "*", "/", "%", "=", "!", "<", ">", "&", "|", "^", "~"};
vector<string> key = {"auto", "break", "case", "char", "const", "continue",
                      "default", "do", "double", "else", "enum", "extern",
                      "float", "for", "goto", "if", "int", "long", "register",
                      "return", "short", "signed", "sizeof", "static", "struct",
                      "switch", "typedef", "union", "unsigned", "void",
                      "volatile", "while"};
bool is_sep(string &c)
{
    bool f = 0;
    for (auto x : sep)
    {
        f |= (c == x);
        if (f)
            return f;
    }
    return f;
}
bool is_op(string &c)
{
    bool f = 0;
    for (auto x : op)
    {
        f |= (c == x);
        if (f)
            return f;
    }
    return f;
}
bool is_key(string &s)
{
    bool f = 0;
    for (auto x : key)
    {
        f |= (s == x);
        if (f)
            return f;
    }
    return f;
}
bool is_id(string &s)
{
    bool f = 1;
    f &= (!(s[0] >= '0' && s[0] <= '9'));
    for (int i = 0; i < s.size(); i++)
    {
    Code:
        f &= ((32 | s[i] >= 'a' && 32 | s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_');
    }
    return f;
}
bool is_num(string &s)
{
    bool f = 1;
    for (int i = 0; i < s.size(); i++)
    {
        f &= ((s[i] >= '0' && s[i] <= '9') || s[i] == '.');
    }
    return f;
}
void split(string &s)
{
    string temp_token = "";
    for (int i = 0; i < s.size(); i++)
    {
        string tt = "";
        tt.push_back(s[i]);
        if (is_sep(tt) || is_op(tt))
        {
            if (temp_token.size())
                tokens.push_back(temp_token);
            temp_token = s[i];
            if (s[i] != ',' && s[i] != ' ')
            {
                tokens.push_back(temp_token);
            }
            temp_token = "";
        }
        else
        {
            temp_token.push_back(s[i]);
        }
    }
    if (temp_token.size())
        tokens.push_back(temp_token);
}
void ctg()
{
    int number_of_tokens[6]{};
    for (auto token : tokens)
    {
        if (is_key(token))
        {
            number_of_tokens[0]++;
        }
        else if (is_op(token))
        {
            number_of_tokens[1]++;
        }
        else if (is_sep(token))
        {
            number_of_tokens[2]++;
        }
        else if (is_num(token))
        {
            number_of_tokens[3]++;
        }
        else if (is_id(token))
        {
            number_of_tokens[4]++;
        }
        else
        {
            number_of_tokens[5]++;
        }
    }
    cout << "Number of Keyword: " << number_of_tokens[0] << endl;
    cout << "Number of Operator: " << number_of_tokens[1] << endl;
    cout << "Number of Punctuator: " << number_of_tokens[2] << endl;
    cout << "Number of Constant: " << number_of_tokens[3] << endl;
    cout << "Number of Identifier: " << number_of_tokens[4] << endl;
    cout << "Number of Literal: " << number_of_tokens[5] << endl;
}
int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    while (getline(cin, s))
        split(s);
    ctg();
    return 0;
}


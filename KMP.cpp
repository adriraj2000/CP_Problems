#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = s.length();
    vector<int> pre(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pre[i - 1]; //Last subsequent matched prefix length

        //If it does not matches
        while (j > 0 && s[i] != s[j])
        {
            j = pre[j - 1];
        }

        //If it is a match then increase the prefix count
        if (s[i] == s[j])
        {
            j++;
        }
        pre[i] = j;
    }
    return pre;
}

int main()
{
    string s = "abcbcglx";
    string t = "bcgl";
    vector<int> lps = prefix_function(t);

    int i = 0, j = 0;
    int pos = -1;

    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++, j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == t.size())
        {
            pos = i - j;
            break;
        }
    }
    cout << pos << "\n";
}

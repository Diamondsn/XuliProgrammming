#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

string t = "ASDFGH";

int help(string &t1, string &t2)
{
    int res = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < 6; i++)
        mp[t2[i]] = i;
    int j = 0;
    for (int i = 0; i < t1.size(); i++)
    {
        res += abs(mp[t1[i]] - j);
        j = mp[t1[i]];

    }
    return res;
}
void dfs(string &s, int &res, string &tmp)
{
    if (tmp.size() == 6)
    {
        res = min(res, help(s, tmp));
        return;
    }
    for (int i = 0; i < 6; i++)
    {
        if (t[i] != 'N')
        {
            string t1 = tmp;
            char t2 = t[i];
            tmp += t[i];
            t[i] = 'N';
            dfs(s, res, tmp);
            tmp = t1;
            t[i] = t2;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n-- > 0)
    {
        string s;
        cin >> s;
        int res = INT_MAX;
        string tmp = "";
        dfs(s, res, tmp);
        cout << res << endl;
    }
    system("pause");
    return 0;
}

// 输入
// 3
// H
// ASDFGH
// ASDFDSAG
// 输出
// 0
// 5
// 8
#include <bits/stdc++.h>
using namespace std;
#define int long long

int fa[100];

int find(int u)
{
    if(fa[u] == u)return u;
    return fa[u] = find(fa[u]);
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        if(s[0].size() != s[1].size()) {
            cout <<"NO" << endl;
            continue;
        }
        for(int i = 0; i < 26; i++)
        {
            fa[i] = i;
        }
        for(int i = 0; i < s[0].size(); i++)
        {
            int x1 = find(s[0][i] - 'a');
            int x2 = find(s[1][i] - 'a');
            if(x1 != x2)
            {
                fa[x1] = x2;
            }
        }
//        for(int i = 0; i < 26; i++)
//            cout << fa[i] << " ";
//        cout << endl;
        if(s[1].size() != s[2].size()) {
            cout << "YES" << endl;
            continue;
        }
        string ss;
        string sss;
        for(auto i : s[2])
            ss.push_back('a' + find(i - 'a'));
        for(auto i : s[0])
            sss.push_back('a' + find(i - 'a'));
        if(ss == sss) {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}
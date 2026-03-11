#include "bits/stdc++.h"
using namespace std;
#define int long long
int m, x, y;
string s[2];
vector<vector<int>> sta;
int flag;
void dfs(int hang, int lie, int fx) {
//    system("pause");
//    for(auto i : sta) {
//        for(int j : i)
//            cout << j << " ";
//        cout << endl;
//    }
//    cout << hang << " " << lie << " " << fx << endl;
    if(hang == 2 && lie == y && fx == 2) {
        flag = 1;
        return;
    }
    if(lie < 0 || lie >= m)
        return;
    if(hang < 0 || hang >= 2)
        return;

    if(s[hang][lie] == 'I') {
        if(fx == 2 || fx == -2) {
            if(sta[hang][lie] == 2)
                return;
            int temp = sta[hang][lie];
            sta[hang][lie] = 1;
            dfs(hang + fx / 2, lie, fx);
            sta[hang][lie] = temp;
        }
        else {
            if(sta[hang][lie] == 1)
                return;
            int temp = sta[hang][lie];
            sta[hang][lie] = 2;
            dfs(hang, lie + fx, fx);
            sta[hang][lie] = temp;
        }
    }
    else {
        if(fx == 2 || fx == -2) {
            if(sta[hang][lie] == 2 || sta[hang][lie] == 3)
                return;
            int temp = sta[hang][lie];
            sta[hang][lie] = 1;
            dfs(hang, lie + 1, 1);
            sta[hang][lie] = 4;
            dfs(hang, lie - 1, -1);
            sta[hang][lie] = temp;
        }
        else if(fx == -1) {
            if(sta[hang][lie] == 4 || sta[hang][lie] == 3)
                return;
            int temp = sta[hang][lie];
            sta[hang][lie] = 1;
            dfs(hang - 1, lie, -2);
            sta[hang][lie] = 2;
            dfs(hang + 1, lie, 2);
            sta[hang][lie] = temp;
        }
        else {
            if(sta[hang][lie] == 1 || sta[hang][lie] == 2)
                return;
            int temp = sta[hang][lie];
            sta[hang][lie] = 3;
            dfs(hang + 1, lie, 2);
            sta[hang][lie] = 4;
            dfs(hang - 1, lie, -2);
            sta[hang][lie] = temp;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> m >> x >> y;
        x--;
        y--;
        sta.resize(2,vector<int>(m,0));
        cin >> s[0] >> s[1];
        flag = 0;
        dfs(0, x, 2);
        if(flag == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

/*
 3
 3 1 3
 ILL
 LLI
 1 1 1
 I
 I
 3 1 3
 IIL
 LLI
 */
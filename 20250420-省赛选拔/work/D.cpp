#include "bits/stdc++.h"
using namespace std;
#define int long long
vector<int> a, b;
string c;
int p;
int n, m;
int anscnt;
void dfs(int aa) {
    if(anscnt > 0)
        return;
    if(aa == n && p == c.size()) {
        for(auto i : a)
            cout << i;
        cout << " ";
        for(auto i : b)
            cout << i;
        cout << endl;
        anscnt++;
        return;
    }
    for(int i = 0; i <= 9; i++) {
        int flag = 1;
        for(int j = 0; j < m; j++) {
            int num = i * b[j];
            if(num < 10) {
                if(num == c[p] - '0')
                    p++;
                else {
                    flag = 0;
                    break;
                }
            }
            else {
                if(p < c.size() - 1) {
                    if(num / 10 == c[p] - '0' && num % 10 == c[p + 1] - '0')
                        p += 2;
                    else {
                        flag = 0;
                        break;
                    }
                }
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1) {
            a.push_back(i);
            dfs(aa + 1);
            a.erase(a.begin() + a.size() - 1);
        }
    }
}
signed main() {
    int t;
    cin >> t;
    while(t--) {
        anscnt = 0;
        cin >> n >> m;
        cin >> c;
        for(int i = 1; i <= 9; i++) {
            a.resize(0);
            a.push_back(i);
            b.resize(0);
            p = 0;
            int flag = 1;
//            cout << "i: " << i << endl;
            for(int j = 0; j < m; j++) {
                if(p >= c.size()) {
                    flag = 0;
                    break;
                }
                int num = c[p] - '0';
                if(num % i == 0) {
                    b.push_back(num / i);
                    p++;
                }
                else if(p < c.size() - 1) {
                    num *= 10;
                    num += c[p + 1] - '0';
                    if(num % i == 0) {
                        b.push_back(num / i);
                        p += 2;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                }
                else {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) {
//                cout << a[0] << endl;
//                for(auto ii : b)
//                    cout << ii << " ";
//                cout << endl;
                dfs(1);
            }
        }
        if(anscnt == 0)
            cout << "Impossible" << endl;
    }
    return 0;
}
/*
4
2 2
8101215
3 4
100000001000
2 2
80101215
3 4
1000000010000
 */
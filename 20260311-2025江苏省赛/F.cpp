#include "bits/stdc++.h"
using namespace std;
#define int long long
struct Node {
    int time;
    int wacnt = 0;
    int pass = 0;
    int pdflag = 0;
};
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        int s;
        cin >> s;
        map<char, Node> mapp;
        map<char, int> pding;
        int timesum = 0;
        int accnt = 0;
        for (int i = 0; i < s; i++) {
            int t;
            char p;
            string v;
            cin >> t >> p >> v;
            if (v == "pd") {
                if (mapp[p].pdflag == 0 && mapp[p].pass == 0) {
                    pding[p] = t;
                    mapp[p].pdflag = 1;
                }
            }
            else if (v == "ac") {
                if (mapp[p].pass == 0) {
                    timesum += mapp[p].wacnt * 20 + t;
                    mapp[p].pass = 1;
                    accnt++;
                }
            }
            else {
                if (mapp[p].pass == 0)
                    mapp[p].wacnt++;
            }
        }
        if (accnt + pding.size() < a)
            cout << -1 << endl;
        else {
            if (accnt + pding.size() == a) {
                int temp = timesum;
                for (auto i : pding) {
                    temp += i.second + mapp[i.first].wacnt * 20;
                }
                if (temp >= b)
                    cout << -1 << endl;
                else
                    cout << pding.size() << endl;
            }
            else {
                vector<int> temp;
                for (auto i : pding) {
                    temp.push_back(i.second + mapp[i.first].wacnt * 20);
                }
                sort(temp.begin(), temp.end());
                int cnt = 0;
                for (int i = 0; i < temp.size(); i++) {
                    if (accnt > a)
                        break;
                    if (accnt == a && timesum < b)
                        break;
                    cnt++;
                    accnt++;
                    timesum += temp[i];
                }
                cout << cnt << endl;
            }
        }
    }
}

/*
1
11 6 900
13
11 C ac
34 J ac
52 D rj
61 D ac
193 A rj
207 A rj
220 G ac
245 A pd
247 A pd
262 H pd
299 A pd
299 C pd
299 K pd
*/
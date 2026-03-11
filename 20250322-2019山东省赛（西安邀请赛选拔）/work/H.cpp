#include "bits/stdc++.h"
using namespace std;
#define int long long
typedef pair<int,int> PII;
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        priority_queue<PII,vector<PII>,greater<PII>> q;
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            q.push({l, r});
        }
//        cout << n << endl;
        int cnt = 0;
        while(!q.empty()) {
//            cout << q.size() << endl;
            int p = q.top().first;
            q.pop();
            cnt++;
            while(q.size() && q.top().first <= p) {
                PII temp = q.top();
                q.pop();
                if(temp.second > p)
                    q.push({p + 1, temp.second});
            }
//            cout << cnt << endl;
        }
        cout << cnt << endl;
    }
    return 0;
}
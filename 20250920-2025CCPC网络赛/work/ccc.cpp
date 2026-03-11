#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> ncnt;
        set<int> used, noused;
        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if(i > 0) {
                ncnt[num % k]++;
                noused.insert(num % k);
            }
            else
                used.insert(num % k);
        }
        if(noused.count(k - *used.begin()))
            used.insert(k - *used.begin());
        noused.erase(k - *used.begin());
        ncnt.erase(k - *used.begin());
        int ans = 0;
        while(!ncnt.empty()) {
            int l = *used.begin(), r = *used.rbegin();
            while(l < r) {
                int mid = (l + r) / 2;
                int num = *used.lower_bound(mid);
                if(noused.lower_bound(k - num) != noused.end())
                    r = mid;
                else
                    l = mid + 1;
            }
            int num = *used.lower_bound(l);
            if(noused.lower_bound(k - num) == noused.end()) {
                int temp = *noused.begin();
                num = *used.begin();
                ans += (num + temp) % k;
                used.insert(temp);
                ncnt[temp]--;
                if(ncnt[temp] == 0) {
                    ncnt.erase(temp);
                    noused.erase(temp);
                }
                if(noused.count(k - temp))
                    used.insert(k - temp);
                noused.erase(k - temp);
                ncnt.erase(k - temp);
            }
            else {
                int temp = *noused.lower_bound(k - num);
                ans += (num + temp) % k;
                used.insert(temp);
                ncnt[temp]--;
                if(ncnt[temp] == 0) {
                    ncnt.erase(temp);
                    noused.erase(temp);
                }
                if(noused.count(k - temp))
                    used.insert(k - temp);
                noused.erase(k - temp);
                ncnt.erase(k - temp);
            }
//            for(auto i : used)
//                cout << i << " ";
//            cout << endl;
//            for(auto i : noused)
//                cout << i << " ";
//            cout << endl;
//            cout << ans << endl << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
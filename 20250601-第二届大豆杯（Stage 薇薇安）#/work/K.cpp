#include "bits/stdc++.h"
using namespace std;
#define int long long
int check(int num) {
    int cnt = 0;
    for(int i = 1; i * i <= num; i++) {
        if(num % i == 0)
            cnt++;
    }
    if(cnt <= 1)
        return 0;
    return 1;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    set<int> usednum;
    vector<int> path;
    int n;cin>>n;
    path.push_back(n);
    cout << n << " ";
    usednum.insert(n);
    for(int i = 0; i < 100; i++) {
        int mi;
        if(i % 3 == 2)
            mi = path[i - 2];
        else
            mi = path[i];
        for(int num = mi; num <= 10000; num++) {

            if(__gcd(num, path[i]) != 1)
                continue;
            if(usednum.count(num))
                continue;
            if(check(num) == 0)
                continue;
            path.push_back(num);
            int flag = 0;
            for(int l = 0; l < path.size(); l++) {
                for(int r = l; r < path.size(); r++) {
                    int sum = 0;
                    for(int ii = l; ii <= r; ii++)
                        sum += path[ii];
                    if(check(sum) == 0) {
                        path.pop_back();
                        flag = 1;
                        continue;
                    }
                }
            }
            if(flag == 0) {
                cout << num << " ";
                usednum.insert(num);
                break;
            }
        }
    }
    return 0;
}

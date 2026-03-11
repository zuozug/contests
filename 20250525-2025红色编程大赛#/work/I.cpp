#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l;
    cin >> n >> l;
    int minn = -1, maxx = -1;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int timel = num, timer = l + 1 - num;
        if(timel > timer)
            swap(timel, timer);
        minn = max(minn, timel);
        maxx = max(maxx, timer);
    }
    cout << minn << " " << maxx << endl;
    return 0;
}

/*
 2 4
 1 3
 */
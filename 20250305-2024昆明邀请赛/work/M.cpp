#include<bits/stdc++.h>
using namespace std;
#define ll __int128

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int xo, yo, r;
        cin >> xo >> yo >> r;
        vector<int> x(n), y(n);
        for(int i = 0; i < n; i++)
            cin >> x[i] >> y[i];
        int pl = 0, pr = 1;
        ll sum = 0;
        while (check(pl, pr)) {
            pr++;
        }


        for(; pl < n; pl++) {
            while (check(pl, pr)) {
                if(pr == n - 1)
                    pr = 0;
                else
                    pr++;
            }
            if(pr == 0)
                pr = n - 1;
            else
                pr--;
            sum += cal(pl, pr);
        }

    }
}


#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sum /= n;
        vector<int> l, r;
        int suml = 0;
        int sumr = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] < sum)
                suml += sum - a[i];
            else if(a[i] > sum)
                sumr += a[i] - sum;
        }
        cout << sumr << endl;

    }
    return 0;
}
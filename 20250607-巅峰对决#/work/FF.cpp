#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    if(n % 2 == 1) {
        cout << n / 2 + 1 << endl;
        for(int i = 1; i <= n / 2 + 1; i++)
            cout << i << " ";
    }
    else {
        if(n == 2 || n == 4)
            cout << -1 << endl;
        else if(n == 6)
            cout << 3 << endl << "1 10 100" << endl;
        else {
            cout << (n - 3) / 2 + 2 << endl;
            for(int i = 1; i <= (n - 3) / 2 + 1; i++)
                cout << i << " ";
            cout << (n - 3) / 2 + 3 << endl;
        }
    }
    return 0;
}
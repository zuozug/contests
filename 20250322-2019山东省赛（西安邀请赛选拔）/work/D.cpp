#include "bits/stdc++.h"
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a, b;
        cin >> a >> b;
        int aa, bb;
        if(b < a) {
            if(s[0] == '1')
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }
        else {
            int num = b - a + 2;
            num %= n;
            if(num == 0)
                num = n;
            if(s[num - 1] == '1')
                cout <<2 << endl;
            else
                cout << 1 << endl;
        }
        for(int i = 0; i < b; i++)
            cin >> aa >> bb;
    }
    return 0;
}
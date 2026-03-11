#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        stack<int> st;
        stack<int> len;
        while(n--) {
            int num;
            cin >> num;
            while(true) {
                if(st.empty() || num < st.top()) {
                    st.push(num);
                    len.push(1);
                    break;
                }
                if(num == st.top()) {
                    int temp = len.top();
                    len.pop();
                    len.push(temp + 1);
                    break;
                }
                //num > st.top()
                if(st.size() == 1) {
                    st.pop();
                    st.push(num);
                    int temp = len.top();
                    ans += temp;
                    len.pop();
                    len.push(temp + 1);
                    break;
                }
                int mid = st.top(), midlen = len.top();
                st.pop();
                len.pop();
                int l = st.top(), r = num, llen = len.top();
                st.pop();
                len.pop();
                if(l < r) {
                    ans += midlen;
                    len.push(midlen + llen);
                    st.push(l);
                }
                else if(l == r) {
                    ans += midlen;
                    st.push(l);
                    len.push(midlen + llen + 1);
                    break;
                }
                else {
                    ans += midlen;
                    st.push(l);
                    len.push(llen);
                    st.push(r);
                    len.push(midlen + 1);
                    break;
                }
            }
        }
        int sum = 0;
        while(!len.empty()) {
            sum += len.top();
            ans += sum;
            len.pop();
        }
        cout << ans << endl;
    }
    return 0;
}
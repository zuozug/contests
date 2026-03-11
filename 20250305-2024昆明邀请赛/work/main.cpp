#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int n, k;
bool cmp(int a, int b)
{
    return ceil(a * 1.0 / k) * k - a < ceil(b * 1.0 / k) * k - b;
}

void solve()
{

    cin>>n>>k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    sort(a.begin(), a.end(), cmp);

    int m;
    cin>>m;

    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        int a1 = ceil(a[i] * 1.0 / k) * k;
        m -= a1 - a[i];
        if(m >= 0)ans += ceil(a[i] * 1.0 / k);
        else ans += a[i] / k;
    }

    if(m >= 0)ans += m / k;
    cout<<ans<<endl;
}

int main() {
    int t = 1;
    cin>>t;

    while(t--)
    {
        solve();
    }
}
/*
2
3 10
239 141 524
6
2 1
300 100
1000
 */

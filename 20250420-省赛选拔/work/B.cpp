#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    ll n;
    cin>>n;
    if(n == 0)
    {
        cout<<1<<endl;
        return;
    }
    ll a = n;
    set<int> s;
    while(n)
    {
        s.insert(n % 10);
        n /= 10;
    }
    if(s.size() > 3)cout<<3<<endl;
    else cout<<s.size()<<endl;
}

int main()
{
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}
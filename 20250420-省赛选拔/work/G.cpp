#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    n--;
    int cnt = 0;
    for(int i = 0; i <= n; i++)
    {
        if(s[i] != s[n - i])cnt++;

    }
    if(cnt > 1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    int t = 1;
//    cin>>t;
    while(t--)
    {
        solve();
    }
}
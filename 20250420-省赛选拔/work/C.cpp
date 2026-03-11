#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;cin>>n;
    if(n%2==0){
        cout<<-1<<'\n';
    }
    else {
        vector<int> a(n),b(n),c(n,0);
        for(int i=0;i<n;i++){
            cout<<i<<" ";
            a[i]=i;
        }
        cout<<'\n';
        b[0]=n-1;
        cout<<n-1<<" ";
        for(int i=1;i<n;i++){
            cout<<i-1<<" ";
            b[i]=i-1;
        }
        cout<<'\n';
        for(int i=0;i<n;i++){
            c[i]=(a[i]+b[i])%n;
            cout<<c[i]<<" ";
        }
        cout<<'\n';
    }
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

/*
 5
 1
 1
 2
 1 2
 3
 1 3 2
 4
 1 3 2 4
 5
 3 4 5 2 1
 */
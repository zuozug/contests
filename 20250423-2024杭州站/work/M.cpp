#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

void solve()
{
    LL n,k;cin>>n>>k;
    vector<LL> a(n);
    LL mi=1e9;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
    }
    if(n==1){
        cout<<k<<" "<<k*(k+1)/2<<'\n';
        return ;
    }
    LL r=0;
    for(int i=0;i<n;i++){
        r=__gcd(r,a[i]-mi);
    }

    if(r==0){
        cout<<k<<" "<<k*(k+1)/2<<'\n';
        return ;
    }
    set<LL> s;
    for(int i=1;i*i<=r;i++){
        if(r%i==0){
            s.insert(i);
            s.insert(r/i);
        }
    }
    sort(a.begin(),a.end());
//    auto t1=s.lower_bound(mi);
//    auto t2=s.upper_bound(mi+k);
    LL cnt=0,ans=0;
    for(auto si:s){
        LL t = si-mi;
        if(t>=1 && t<=k){
            bool f=1;
            for(int i=1;i<n-1;i++){
                LL t1=a[i]+t;
                LL t2=a[i+1]+t;
                if(t2%t1!=0){
                    f=0;break;
                }
            }
            if(!f)continue;
            cnt++;
            ans+=t;
        }
    }
//    for(;t1!=t2;t1++){
////        cout<<(*t1)<<" ";
//        if((*t1)==mi)continue;
//        cnt++;
//        ans+=(*t1-mi);
//    }
////    cout<<'\n';
    cout<<cnt<<" "<<ans<<'\n';
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
 3
 5 10
 7 79 1 7 1
 2 1000000000
 1 2
 1 100
 1000000000
 */
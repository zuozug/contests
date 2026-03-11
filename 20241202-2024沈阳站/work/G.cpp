#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int,int> PII;
using i128=__int128;

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}
PII add(PII a,PII b){
    int r=gcd(a.second,b.second);
    int t=a.second/r*b.second;

    int t1=t/a.second;
    int t2=t/b.second;
    PII ans={a.first*t1+b.first*t2,t};
    int rr=gcd(ans.first,ans.second);
    ans.first/=rr;
    ans.second/=rr;
//    cout<<t
    return ans;
}
void fun(PII &ans){
    ans.second*=2;
    int rr=gcd(ans.first,ans.second);
    ans.first/=rr;
    ans.second/=rr;
}
void solve(){
    int n;cin>>n;
    vector<PII> a(n);
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
        x[i]=a[i].first;
    }
    sort(all(x));
    x.erase(unique(all(x)),x.end());

    if(x.size()<3){
        cout<<"? "<<x[0]<<" "<<1<<endl;
        cout.flush();
        int p,q;cin>>p>>q;
        PII t={p,q};
        int len=x[1]-x[0];
        PII res={p*(len),q};
        fun(res);
        cout<<"! "<<res.first<<" "<<res.second<<endl;
        cout.flush();
        return ;
    }


    int last=x[0];
    PII res={0,0};
    vector<PII> temp(x.size()+1);
    for(int i=1;i<x.size()-1;i++){
        cout<<"? "<<x[i]<<" "<<1<<endl;
        cout.flush();
        int p,q;cin>>p>>q;
        PII t={p,q};
        temp[i]=t;
        PII ans={p*(x[i]-last),q};
//        cout<<ans.first<<" "<<ans.second<<endl;
        if(res.second!=0)res = add(res,ans);
        else res=ans;
        last=x[i];
    }
    last = x[x.size()-1];
    for(int i=x.size()-2;i;i--){
        PII t=temp[i];
        PII ans={t.first*(last-x[i]),t.second};
        res = add(res,ans);
        last=x[i];
    }
    fun(res);
    cout<<"! "<<res.first<<" "<<res.second<<endl;
    cout.flush();
}
signed main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
#define all(x) x.begin(),x.end()

void solve(){
    int n,m,k;cin>>n>>m>>k;
    vector<string> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int cnt=0;
    string temp="";
    for(int i=0;i<k;i++) {
        temp += a[0][i];
    }
    int ansn=0,ansm=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            string t="";
            for(int st=j*k;st<(j+1)*k;st++){
                t+=a[i][st];
            }
            if(temp!=t){
                cnt++;
                ansn=i+1;
                ansm=j+1;
            }
        }
    }
    if(cnt==1){
        cout<<ansn<< " "<<ansm<<"\n";
    }
    else {
        cout<<1<<" "<<1<<'\n';
    }
}
signed main() {
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}

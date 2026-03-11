#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

void solve(){
    string s;cin>>s;
    int ans=0;
    bool f=0;
    for(int i=0;i<s.size()-1;i++){
        int cnt=1;
        if(s[i]==s[i+1]){
            int j=i;
            while(j<s.size() && s[j]==s[j+1])j++,cnt++;

            if(cnt%2==0){
                if(s[i]==s[s.size()-1])continue;
                string t=s.substr(0,i+1);
                s.erase(0,i+1);
//                cout<<t<<" "<<s<<'\n';
                s+=t;
                break;
            }
            i=j;
        }
    }
//    cout<<s<<'\n';
    for(int i=0;i<s.size()-1;i++){
        int cnt=1;
        if(s[i]==s[i+1]){
            int j=i;
            while(j<s.size() && s[j]==s[j+1])j++,cnt++;
            i=j;
            ans+=cnt/2;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    int t = 1;
    cin>>t;

    while(t--)
    {
        solve();
    }
}


#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

void solve(){
    string s;cin>>s;
    int ans=0;
    bool f=0;
    int tag=0;
    string s1=s,s2=s;
    for(int i=0;i<s.size()-1;i++){
        int cnt=1;
        if(s[i]==s[i+1]){
            int j=i;
            while(j<s.size() && s[j]==s[j+1])j++,cnt++;

            if(cnt%2==0){
                tag++;
                if(tag==1){
                    string t=s1.substr(0,i+1);
                    s1.erase(0,i+1);
//                cout<<t<<" "<<s<<'\n';
                    s1+=t;
                }
                else if(tag==2){
                    string t=s2.substr(0,i+1);
                    s2.erase(0,i+1);
//                cout<<t<<" "<<s<<'\n';
                    s2+=t;
                }
                else break;
            }
            i=j;
        }
    }
//    cout<<s<<'\n';

    for(int i=0;i<s1.size()-1;i++){
        int cnt=1;
        if(s1[i]==s1[i+1]){
            int j=i;
            while(j<s1.size() && s1[j]==s1[j+1])j++,cnt++;
            i=j;
            ans+=cnt/2;
        }
    }
    int res=0;
    for(int i=0;i<s2.size()-1;i++){
        int cnt=1;
        if(s2[i]==s2[i+1]){
            int j=i;
            while(j<s2.size() && s2[j]==s2[j+1])j++,cnt++;
            i=j;
            res+=cnt/2;
        }
    }
    cout<<min(ans,res)<<'\n';
}

int main() {
    int t = 1;
    cin>>t;

    while(t--)
    {
        solve();
    }
}


#include <bits/stdc++.h>
using namespace  std;
#define int long long
typedef long long LL;
#define all(x) x.begin(),x.end()
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int> s1(26,0);
    int id=0;
    vector<char> ans;
    while(id<s.size()){
        s1[s[id]-'a']++;
        if(s1[s[id]-'a']==5){
            ans.push_back(s[id]);
//            cout<<s[id]<<'\n';
            id++;
            break;
        }
        id++;
    }
    for(int i=0;i<26;i++)s1[i]=0;
    while(id<s.size()){
        s1[s[id]-'a']++;
        if(s1[s[id]-'a']==7){
            ans.push_back(s[id]);
//            cout<<s[id]<<'\n';
            id++;
            break;
        }
        id++;
    }
    for(int i=0;i<26;i++)s1[i]=0;
    while(id<s.size()){
        s1[s[id]-'a']++;
        if(s1[s[id]-'a']==5){
            ans.push_back(s[id]);
//            cout<<s[id]<<'\n';
            id++;
            break;
        }
        id++;
    }
    if(ans.size()==3){
        for(int i=0;i<5;i++){
            cout<<ans[0];
        }
        for(int i=0;i<7;i++){
            cout<<ans[1];
        }
        for(int i=0;i<5;i++){
            cout<<ans[2];
        }
    }
    else {
        cout<<"none\n";
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

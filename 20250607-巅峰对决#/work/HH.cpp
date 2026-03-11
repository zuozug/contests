#include <bits/stdc++.h>
using namespace  std;
#define int long long
typedef long long LL;
#define all(x) x.begin(),x.end()
void solve(){
    int m,x,y;cin>>m>>x>>y;
    x--,y--;
    string s1,s2;cin>>s1>>s2;
    if(s1[x]==s2[y] && s1[x]=='I'){
        if(x==y){
            puts("YES");
            return ;
        }
    }
    if(s1[x]=='I' && s2[x]=='I'){
        puts("NO");
        return ;
    }
    if((s1[x]=='I' && s2[x]=='L' )|| (s1[x]=='L' && s2[x]=='I')){
        if(x==y){
            puts("NO");
            return ;
        }
        if(x<y){
            queue<array<int,3>> q;
            if(s1[x]=='I')q.push({1,x,2});
            else q.push({1,x,1});

            while(q.size()){
                auto [id,c,d]=q.front();
                q.pop();
                if(id==2 && c==y){
                    if(s2[y]=='I' && d==2){
                        puts("YES");
                        return ;
                    }
                    if(s2[y]=='L' && d==1){
                        puts("YES");
                        return ;
                    }
                }
                if(d==0 && id==2 && s1[c]=='L'){
                    q.push({1,c,1});
                }
                if(d==1){
                    if(id==1 && s1[c+1]=='I')q.push({1,c+1,1});
                    if(id==1 && s1[c+1]=='L')q.push({1,c+1,2});
                    if(id==2 && s2[c+1]=='I')q.push({2,c+1,1});
                    if(id==2 && s2[c+1]=='L')q.push({2,c+1,0});
                }
                if(d==2 &&id ==1){
                    if(s2[c]=='L')q.push({2,c,1});
                    if(s2[c]=='I')q.push({2,c,2});
                }
            }
            puts("NO");
            return ;
        }
        else {
            queue<array<int,3>> q;
            if(s1[x]=='I')q.push({1,x,2});
            else q.push({1,x,3});

            while(q.size()){
                auto [id,c,d]=q.front();
                q.pop();
                if(id==2 && c==y){
                    if(s2[y]=='I' && d==2){
                        puts("YES");
                        return ;
                    }
                    if(s2[y]=='L' && d==3){
                        puts("YES");
                        return ;
                    }
                }
                if(d==0 && id==2 && s1[c]=='L'){
                    q.push({1,c,3});
                }
                if(d==3){
                    if(id==1 && s1[c-1]=='I')q.push({1,c-1,3});
                    if(id==1 && s1[c-1]=='L')q.push({1,c-1,2});
                    if(id==2 && s2[c-1]=='I')q.push({2,c-1,3});
                    if(id==2 && s2[c-1]=='L')q.push({2,c-1,0});
                }
                if(d==2 &&id ==1){
                    if(s2[c]=='L')q.push({2,c,3});
                    if(s2[c]=='I')q.push({2,c,2});
                }
            }
            puts("NO");
            return ;
        }
    }
    if(s1[x]=='L' && s2[x]=='I'){
        if(x==y){
            puts("NO");
            return ;
        }
        queue<array<int,3>> q;
        if(s1[x]=='I')q.push({1,x,2});
        else {
            q.push({1,x,1});
            q.push({1, x, 3});
        }

        while(q.size()){
            auto [id,c,d]=q.front();
            q.pop();
            if(id==2 && c==y){
                if(s2[y]=='I' && d==2){
                    puts("YES");
                    return ;
                }
                if(s2[y]=='L' && (d==1 || d==3)){
                    puts("YES");
                    return ;
                }
            }
            if(d==0 && id==2 && s1[c]=='L'){
                q.push({1,c,3});
                q.push({1,c,1});
            }
            if(d==3){
                if(id==1 && s1[c-1]=='I')q.push({1,c-1,3});
                if(id==1 && s1[c-1]=='L')q.push({1,c-1,2});
                if(id==2 && s2[c-1]=='I')q.push({2,c-1,3});
                if(id==2 && s2[c-1]=='L')q.push({2,c-1,0});
            }
            if(d==2 &&id ==1){
                if(s2[c]=='L') {
                    q.push({2, c, 3});
                    q.push({2,c,1});
                }
                if(s2[c]=='I')q.push({2,c,2});
            }
        }

        puts("NO");
        return ;

    }

}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
3
 3 1 3
 ILL
 LLI
 1 1 1
 I
 I
 3 1 3
 IIL
 LLI
 */
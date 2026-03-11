#include "bits/stdc++.h"
using namespace std;
#define int long long
const int mod= 998244353;
const int N=1e6+10;

signed main() {+
            ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        string s;cin>>s;

        vector<vector<int>> dp(n+1,vector<int>(6,0));
        //digit a A 1 l I
        if(s[0]>='0' && s[0]<='9' && s[0]!='1'){
            dp[0][0]=1;
        }
        if(s[0]>='a' && s[0]<='z' && s[0]!='l'){
            dp[0][1]=1;
        }
        if(s[0]>='A' && s[0]<='Z' && s[0]!='I'){
            dp[0][2]=1;
        }
        if(s[0]=='?'){
            dp[0][0]=9;
            dp[0][1]=25,dp[0][2]=25;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='?'){
                if(s[i-1]=='1' && s[i+1]=='1'){
                    dp[i][0]=(dp[i-1][3]*9)%mod;
                    dp[i][3]=dp[i-1][3];
                }
                else if(s[i-1]=='1' && isdigit(s[i+1])){
                    dp[i][0]=(dp[i-1][3]*9)%mod;
                    dp[i][3]=dp[i-1][3];
                }
                else if(s[i+1]=='1' && isdigit(s[i-1])){
                    dp[i][0]=(dp[i-1][0]*9)%mod;
                    dp[i][3]=dp[i-1][0];
                }
                else if(isdigit(s[i-1]) && isdigit(s[i+1])){
                    dp[i][0]=(dp[i-1][0]*9)%mod;
                    dp[i][1]=(dp[i-1][0]*25)%mod;
                    dp[i][2]=(dp[i-1][0]*25)%mod;
                    dp[i][3]=dp[i-1][0];
                }



                if(s[i-1]=='l' && s[i+1]=='l'){
                    dp[i][1]=(dp[i-1][4]*25)%mod;
                    dp[i][4]=dp[i-1][4];
                }
                else if(s[i-1]=='l' && s[i+1]>='a' && s[i+1]<='z'){
                    dp[i][1]=(dp[i-1][4]*25)%mod;
                    dp[i][4]=dp[i-1][4];
                }
                else if(s[i+1]=='l' && s[i-1]>='a' && s[i-1]<='z'){
                    dp[i][1]=(dp[i-1][4]*25)%mod;
                    dp[i][4]=dp[i-1][4];
                }
                else if(s[i+1]>='a' && s[i+1]<='z'&& s[i-1]>='a' && s[i-1]<='z'){
                    dp[i][0]=(dp[i-1][4]*9)%mod;
                    dp[i][1]=(dp[i-1][4]*25)%mod;
                    dp[i][2]=(dp[i-1][4]*25)%mod;
                    dp[i][4]=dp[i-1][4];
                }


                if(s[i-1]=='I' && s[i+1]=='I'){
                    dp[i][2]=(dp[i-1][5]*25%mod;
                    dp[i][5]=dp[i-1][5];
                }
                else if(s[i-1]=='I' && s[i+1]>='A' && s[i+1]<='Z'){
                    dp[i][2]=(dp[i-1][5]*25)%mod;
                    dp[i][5]=dp[i-1][5];
                }
                else if(s[i+1]=='I' && s[i-1]>='A' && s[i-1]<='Z'){
                    dp[i][2]=(dp[i-1][5]*25)%mod;
                    dp[i][5]=dp[i-1][5];
                }
                else if(s[i+1]>='A' && s[i+1]<='Z'&& s[i-1]>='A' && s[i-1]<='Z'){
                    dp[i][0]=(dp[i-1][5]*9)%mod;
                    dp[i][1]=(dp[i-1][5]*25)%mod;
                    dp[i][2]=(dp[i-1][5]*25)%mod;
                    dp[i][5]=dp[i-1][5];
                }
                int temp=0;
                for(int j=0;j<6;j++){
                    temp=(temp+dp[i-1][j])%mod;
                }
                if(s[i-1]=='?' && s[i+1]=='?'){
                    dp[i][0]=(temp*9)%mod;
                    dp[i][1]=(temp*25)%mod;
                    dp[i][2]=(temp*25)%mod;
                }



            }
            else if(isdigit(s[i])){
                dp[i][0]=(dp[i][0]+dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%mod;
            }
            else if(s[i]>='a' &&s[i]<='z'){
                dp[i][1]=(dp[i][1]+dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
            }
            else if(s[i]>='A' &&s[i]<='Z'){
                dp[i][2]=(dp[i][2]+dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][5])%mod;
            }
        }
    }
    return 0;
}
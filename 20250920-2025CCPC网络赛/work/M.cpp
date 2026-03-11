#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<157<<endl;
    for(int j=1;j<=31;j++){
        cout<<"add "<<32<<endl;
        for(int i=j;i<=1023;i+=32){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i=j-1;i<=1023;i+=32){
            cout<<i<<" ";
        }
        cout<<endl;
        for(int i=j;i<=1023;i+=32){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=31;i++){
        cout<<"add "<<32<<endl;
        for(int j=32*i;j<32*(i+1);j++){
            cout<<j<<" ";
        }

        cout<<endl;
        for(int j=31;j<=1023;j+=32){
            cout<<j<<" ";
        }
        cout<<endl;
        for(int j=32*i;j<32*(i+1);j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<=31;i++){
        cout<<"mul "<<32<<endl;
        for(int j=i*32;j<32*(i+1);j++){
            cout<<j<<" ";
        }
        cout<<endl;
        for(int j=i*32+1024;j<32*(i+1)+1024;j++){
            cout<<j<<" ";
        }
        cout<<endl;
        for(int j=i*32+1024;j<32*(i+1)+1024;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=31;i++){
        cout<<"max "<<32<<endl;
        for(int j=32*i+1024;j<32*(i+1)+1024;j++){
            cout<<j<<" ";
        }
        cout<<endl;
        for(int j=31+1024;j<=1023+1024;j+=32){
            cout<<j<<" ";
        }
        cout<<endl;
        for(int j=32*i+1024;j<32*(i+1)+1024;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<=31;i++){
        cout<<"sub "<<32<<endl;
        for(int j=i*32;j<32*(i+1);j++){
            cout<<j<<" ";
        }
        cout<<endl;
        for(int j=i*32+1024;j<32*(i+1)+1024;j++){
            cout<<j<<" ";
        }
        cout<<endl;
        for(int j=i*32+1024;j<32*(i+1)+1024;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include <iostream>
using namespace  std;

int main() {
    int n;cin>>n;
    if(n==1)cout<<1<<'\n';
    else if(n>10)cout<<-1<<'\n';
    else {
        cout<<10;
        for(int i=2;i<=n-1;i++){
            cout<<i;
        }
    }

    return 0;
}

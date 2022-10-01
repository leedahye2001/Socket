#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){ //n줄
        for(int j=1;j<=i;j++){ //i행에서 i개
            cout<<"*";
        }
        cout<<'\n';
    }

    return 0;
}
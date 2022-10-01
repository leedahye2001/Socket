#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout.precision(12);
    cout<<fixed;
    cout<<(double)a/b<<endl;
    return 0;
}
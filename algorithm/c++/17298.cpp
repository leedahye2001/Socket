#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
stack<int> a;
int arr[1000001];
int nge[1000001];

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=n-1;i>=0;i--){
        while(!a.empty()&&a.top()<=arr[i]){
            a.pop();
        }

        if(a.empty()){
            nge[i]=-1;
        }
        else{
            nge[i]=a.top();
        }
        a.push(arr[i]);
    }
    
    for(int i=0;i<n;i++){
        cout<<nge[i]<<" ";
    }

    return 0;
}
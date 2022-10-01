#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n,k;

int main(){
    cin>>n>>k;
    
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    
    cout<<"<";
    
    while(!q.empty()){
        for(int i=0;i<k-1;i++){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front();
        q.pop();
        
        if(!q.empty()){
            cout<<", ";
        }
    }
    cout<<">"<<endl;
    
    return 0;
}
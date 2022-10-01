#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    stack<int> S;
    string str;
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
    cin>>str;

    if(str=="push")
    {
        int x;
        cin>>x;
        S.push(x);
    }
    else if(str=="pop"){
        if(S.empty()){
            cout<<"-1"<<endl;
        }
        else{
        cout<<S.top()<<endl;
        S.pop();
        }
    }
    else if(str=="top"){
        if(S.empty()){
            cout<<"-1"<<endl;
        }
        else{
            cout<<S.top()<<endl;
        }
    }
    else if(str=="empty"){
        if(S.empty()){
            cout<<"1"<<endl;
        }
        else{
            cout<<"0"<<endl;
        }
    }
    else if(str=="size"){
    cout<<S.size()<<endl;
        }
    }
    return 0;
}
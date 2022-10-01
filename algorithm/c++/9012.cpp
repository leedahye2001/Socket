#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool Ps(string str){
    stack<char> VPS;
    int length=str.length(); //괄호의 길이
    for(int i=0;i<length;i++){
        char c=str[i];
        if(c=='('){
            VPS.push(c);
        }
        else{
            if(VPS.empty()){
                return false;
            }
            else{
                VPS.pop();
            }
        }
    }
    return VPS.empty();
}

int main(){
    
    int t; //입력받는 개수
    cin>>t;
    
    for(int i=0;i<t;i++){
        string str; //괄호
        cin>>str;
        if(Ps(str)){
           cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
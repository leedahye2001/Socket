#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);

    string st("");
    cin>>st;
    
    stack<char> edit;
    stack<char> real;

    for(int i=0;i<st.size();++i){
        edit.push(st[i]);
    }

    int num;
    cin>>num;
    
    for(int i=0;i<num;++i){
        char c1(' ');
        cin>>c1;
        
        if(c1=='L'){
            if(!edit.empty()){
                real.push(edit.top());
                edit.pop();
            }
        }
        else if(c1=='D'){
            if(!real.empty()){
                edit.push(real.top());
                real.pop();
            }
        }
        else if(c1=='B'){
            if(!edit.empty()){
                edit.pop();
            }
        }
        else if(c1=='P'){
            char str(' ');
            cin>>str;

            edit.push(str);
        }
    }

    while(!edit.empty()){
        real.push(edit.top());
        edit.pop();
    }

    while(!real.empty()){
        cout<<real.top();
        real.pop();
    }

    return 0;
}
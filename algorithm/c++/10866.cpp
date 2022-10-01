#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    deque<int> d;
    string str;

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>str;
        if(str=="push_front"){
            int x;
            cin>>x;
            d.push_front(x);
        }
        else if(str=="push_back"){
            int x;
            cin>>x;
            d.push_back(x);
        }
        else if(str=="pop_front"){
            if(d.empty()){
                cout<<"-1"<<endl;
            }
            else{
                cout<<d.front()<<endl;
                d.pop_front();
            }
        }
        else if(str=="pop_back"){
            if(d.empty()){
                cout<<"-1"<<endl;
            }
            else{
                cout<<d.back()<<endl;
                d.pop_back();
            }
        }
        else if(str=="size"){
            cout<<d.size()<<endl;
        }
        else if(str=="empty"){
            if(d.empty()){
                cout<<"1"<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        else if(str=="front"){
            if(d.empty()){
                cout<<"-1"<<endl;
            }
            else{
                cout<<d.front()<<endl;
            }
        }
        else if(str=="back"){
            if(d.empty()){
                cout<<"-1"<<endl;
            }
            else{
                cout<<d.back()<<endl;
            }
        }
    }


    return 0;
}
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    int k;
    cin>>k;
    
    stack<int> st;

    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        if(n==0){
            st.pop();
        }
        else{
            st.push(n);
        }
    }

    int sum=0;
    int size=st.size();
    for(int i=0;i<size;i++){
        sum+=st.top();
        st.pop();
    }
    cout<<sum<<endl;
    return 0;
}
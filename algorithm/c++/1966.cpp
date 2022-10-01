#include <iostream>
#include <queue>
using namespace std;

int main(){
    int test_case; 
    cin>>test_case;
    
    for(int i=0;i<test_case;i++){
        int count;
        int n,m;     //문서의 개수, 궁금한 문서 위치
        count=0;
        cin>>n>>m;
        
        priority_queue<int> pq;
        queue< pair<int, int> > q;
        
        for(int j=0;j<n;j++){
            int imt;
            cin>>imt; //중요도
            
            q.push({ j, imt });
            pq.push(imt);
        }

        while(!q.empty()){
            int loc = q.front().first;    //위치
            int value = q.front().second; //값
            q.pop();
            
            //값 비교
            if(pq.top()==value){
                pq.pop();
                ++count;

                if(loc==m){
                    cout<<count<<endl;
                    break;
                }
            }
            else
                q.push({ loc, value });
        }
        
    }

    return 0;
}
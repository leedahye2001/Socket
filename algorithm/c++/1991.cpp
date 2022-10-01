#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n;
char p,l,r;
int parent[26][2];

void preorder(char root){
    if(root=='.'){
        return;
    }
    else{
        cout<<root;
        preorder(parent[root-'A'][0]);
        preorder(parent[root-'A'][1]);
    }
}

void inorder(char root){
    if(root=='.'){
        return;
    }
    else{
        inorder(parent[root-'A'][0]);
        cout<<root;
        inorder(parent[root-'A'][1]);
    }
}

void postorder(char root){
    if(root=='.'){
        return;
    }
    else{
        postorder(parent[root-'A'][0]);
        postorder(parent[root-'A'][1]);
        cout<<root;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p>>l>>r;
        parent[p-'A'][0]=l;
        parent[p-'A'][1]=r;
    }
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
    cout<<"\n";

    return 0;
}
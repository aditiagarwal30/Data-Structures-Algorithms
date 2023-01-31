#include<iostream>
using namespace std;

int main(){
    vector<int> a,b;
    int n,m;
    cin>>n,m;
    int ele;
    for(int i=0;i<n;i++){
        cin>>ele;
        a.push_back(ele);
    } 
    for(int i=0;i<m;i++){
        cin>>ele;
        b.push_back(ele);
    }   

    int temp= b[0];

    for(int i=0;i<n;i++){
        if(a[i]==temp){
            
        }
    }
}
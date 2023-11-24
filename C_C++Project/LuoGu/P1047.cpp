#include<iostream>
using namespace std;

int main(){
    int l,m,u,v,c=0,a[10010]={0};
    cin>>l>>m;

    for(int i=0;i<m;i++){
        cin>>u>>v;
        for(int j=u;j<=v;j++){
            a[j]=1;
        }
    }

    for(int k=0;k<=l;k++){
        if (a[k]==0){
            c++;
        }
    }
    cout<<c;
    return 0;
}
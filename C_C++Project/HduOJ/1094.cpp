#include<iostream>
using namespace std;
int main(){
	int n,x,sum=0;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>x;
			sum+=x;
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}

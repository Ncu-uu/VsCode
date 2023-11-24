#include<iostream>
using namespace std;
int main(){
	int n,m,x,sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>x;
			sum+=x;
		}
		cout<<sum<<endl<<endl;
		sum=0;
	}
	return 0;
}

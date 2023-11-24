#include<iostream>
using namespace std;

int main(){
	int n,sum=0;
	while(cin>>n&&n!=0){
		for(int i=0;i<n;i++){
			int j;
			cin>>j;
			sum+=j;
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}

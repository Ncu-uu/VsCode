#include<iostream>
#include<cmath>
using namespace std;
#define PI acos(-1.0) 

int main(){
	int n,i;
	cin>>n;
	while(n--){
		cin>>i;
		cout<<(int)(((log(2*PI*i)/2+i*log(i)-i)/log(10))+1)<<endl;
	}
	return 0;
}

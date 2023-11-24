#include <iostream>
using namespace std;

int gcd(int a,int b){
	if (a<b)
	{
		int temp=a;
		a=b;
		b=temp;
	}
	while (b) {
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int a,b;
	while (cin>>a>>b) 
		cout<<((a*b)/gcd(a,b))<<endl;
	return 0;
}
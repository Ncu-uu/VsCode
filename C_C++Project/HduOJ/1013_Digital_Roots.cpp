#include<iostream>
using namespace std;

int main(){
	int i,sum=0;
	string s;
	while(getline(cin,s)&&s[0]!='0')
	{
		for(unsigned int i=0;i<s.length();i++){
			sum+=s[i]-'0';
		}
		
		while(sum>=10){
			i=0;
			while(sum){
				i+=sum%10;
				sum/=10;
			}
			sum=i;
		}
		
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}

//int main(){
//	long long n,r=0,sum=0;
//	while(cin>>n&&n!=0)
//	{
//		do
//		{
//			while(n)
//			{
//				sum+=(n%10);
//				n/=10;
//			}
//			r=sum;
//			if(r>=10)
//			{
//				n=r;
//				sum=0;
//			}
//		}while(r>=10);
//		cout<<r<<endl;
//		sum=0;
//	}
//	return 0;
//}

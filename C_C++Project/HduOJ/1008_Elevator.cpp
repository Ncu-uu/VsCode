#include <iostream>
using namespace std;

const int UP=6;
const int DOWN=4;
const int STOP=5;

int main()
{
	int n,request,lrequest=0,time=0;
	while (cin>>n && n!=0) 
	{
		while (n--) 
		{
			cin>>request;
			if (request >= lrequest)
			{
				time+=(request - lrequest) * UP;
				time+=STOP;
			}
			if (request < lrequest)
			{
				time+=(lrequest - request) * DOWN;
				time+=STOP;
			}
			lrequest=request;
		}
		cout<<time<<endl;
		time=0;lrequest=0;
	}
	return 0;
}
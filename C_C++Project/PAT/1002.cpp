#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double k,a[1001]={0};
	int ic,n,oc=0;
	
	cin>>ic;
	for (int i = 0; i < ic; ++i)
	{
		cin>>n>>k;
		a[n]+=k;
	}
	cin>>ic;
	for (int i = 0; i < ic; ++i)
	{
		cin>>n>>k;
		a[n]+=k;
	}
	for (int i = 0; i < 1001; ++i)
	{
		if (a[i]!=0)
		{
			oc++;
		}
	}
	cout<<oc;
	for (int i = 1000; i >=0; i--)
	{
		if (a[i]!=0)
		{
			cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<a[i];
		}
	}	
	return 0;
}
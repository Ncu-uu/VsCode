#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,sum=0;
	while (cin>>n) {
		for (int i = 1; i <= n; ++i)
		{
			sum+=i;
		}
		cout<<sum<<endl<<endl;
		sum=0;
	}
	return 0;
}
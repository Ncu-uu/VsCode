#include<iostream>
using namespace std;

int main(){

    int a[9][9]={0},sum1=0,sum2=0,n,x,y,z;
    cin>>n;

    do
    {
       cin>>x>>y>>z;
       a[x-1][y-1]=z;

    } while (x!=y!=z!=0);



    if (sum1>=sum2)
    {
        cout<<sum1;
    }
    else cout<<sum2;
    return 0;
}
    
    //  for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //        cout<<a[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<sum1<<' '<<sum2;


    // for (int i = 0; i < n; i++)
    // {
    //     sum1 += a[0][i];
    //     a[0][i]=0;
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     sum1 += a[i][n-1];
    //     a[i][n-1]=0;
    // } 
    // for (int i = 0; i < n; i++)
    // {
    //     sum2 += a[i][0];
    //     a[i][0]=0;
    // }
    // for (int i = 1; i < n; i++)
    // {
    //     sum2 += a[n-1][i];
    //     a[n-1][i]=0;
    // }
    



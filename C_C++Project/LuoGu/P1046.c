#include<stdio.h>

int main(){
    int a[10],h,c=0;
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&h);
    for(int i=0;i<10;i++){
        if((h+30)>=a[i])
          c++;
    }
    printf("%d",c);
    return 0;
}
//     int a[10],h,c=0;
//    for(int i=0;i<10;i++){
//     scanf("%d",&a[i]);
//    }
//    scanf("%d",&h);
//    for(int i=0;i<10;i++){
//     if((h+30)>=a[i])
//       c++;
//    }
//    printf("%d",c);
//    return 0;


// int a[10],i,k,n=0;
//     for(i=0;i<10;i++){
//         scanf("%d",&a[i]);
//     }
//     scanf("%d",&k);
//     for(i=0;i<10;i++){
//         if(a[i]<=k+30){
//             n++;
//         }
//     }
//     printf("%d",n);
//     return 0;







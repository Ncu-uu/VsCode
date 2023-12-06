import java.util.Scanner;
public class wxxwall {

   public static void main(String[] args) {
        int n;
        Scanner input=new Scanner(System.in);
       System.out.print("输入关系矩阵的长度: ");
       n=input.nextInt();
       int[][] warshall=new int[n][n];
       System.out.println("输入关系矩阵:");
       for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
               warshall[i][j]=input.nextInt();
       setWarshell(warshall);
       System.out.println("传递闭包的自反闭包:");
       display(warshall);
   }
   //打印矩阵
   public static void display(int[][] warshall){
       for (int i = 0; i < warshall.length; i++) {
           for (int j=0;j<warshall.length;j++){
               System.out.print(warshall[i][j]+" ");
           }
           System.out.println();
       }
   }
   //warshall算法实现
   public static void setWarshell(int[][]warshall){
       for (int k = 0; k < warshall.length; k++) {
           for (int i = 0; i < warshall.length; i++) {
               for (int j = 0; j < warshall.length; j++) {
                   if(i==j) warshall[i][j]=1;
                   warshall[i][j]|=warshall[i][k]*warshall[k][j];
               }
           }
       }
   }
}
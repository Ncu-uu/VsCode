import java.util.Scanner;
public class wxxcow {

   public static void main(String[] args) {
       int n, m;
       Scanner input = new Scanner(System.in);
       n = input.nextInt();
       m = input.nextInt();
       int[][] warshall = new int[n][n];
       for (int i = 0; i < n; i++)
           for (int j = 0; j < n; j++)
               warshall[i][j] =0;
       for(int i=0;i<m;i++){
           int a,b;
           a=input.nextInt();
           b=input.nextInt();
           warshall[a-1][b-1]=1;
       }
       setWarshell(warshall);
       int ans = 0;
       for (int i = 0; i < n; i++) {
           int sum = 0;
           for (int j = 0; j < n; j++) {
               sum += warshall[i][j];
               sum += warshall[j][i];
           }
           if (sum == n - 1) ans++;
       }
       System.out.println(ans);
   }

   //warshall算法实现
   public static void setWarshell(int[][] warshall) {
       for (int k = 0; k < warshall.length; k++) {
           for (int i = 0; i < warshall.length; i++) {
               for (int j = 0; j < warshall.length; j++) {
                   warshall[i][j] |= warshall[i][k] * warshall[k][j];
               }
           }
       }
   }
}
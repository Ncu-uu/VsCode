import java.util.Scanner;
public class wxxwall {

   public static void main(String[] args) {
        int n;
        Scanner input=new Scanner(System.in);
       System.out.print("�����ϵ����ĳ���: ");
       n=input.nextInt();
       int[][] warshall=new int[n][n];
       System.out.println("�����ϵ����:");
       for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
               warshall[i][j]=input.nextInt();
       setWarshell(warshall);
       System.out.println("���ݱհ����Է��հ�:");
       display(warshall);
   }
   //��ӡ����
   public static void display(int[][] warshall){
       for (int i = 0; i < warshall.length; i++) {
           for (int j=0;j<warshall.length;j++){
               System.out.print(warshall[i][j]+" ");
           }
           System.out.println();
       }
   }
   //warshall�㷨ʵ��
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
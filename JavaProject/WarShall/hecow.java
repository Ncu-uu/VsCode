import java.util.Scanner;
public class hecow {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();
        int[][] graph = new int[n + 1][n + 1];
        for (int i = 0; i < m; i++) {
            int a = input.nextInt();
            int b = input.nextInt();
            graph[a][b] = 1;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (graph[i][k] == 1 && graph[k][j] == 1) {
                        graph[i][j] = 1;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 1; i <= n; i++) {
            boolean isRanked = true;
            for (int j = 1; j <= n; j++) {
                if (i != j && graph[i][j] == 0 && graph[j][i] == 0) {
                    isRanked = false;
                    break;
                }
            }
            if (isRanked) {
                count++;
            }
        }
        System.out.println(count);
        input.close();
    }
}
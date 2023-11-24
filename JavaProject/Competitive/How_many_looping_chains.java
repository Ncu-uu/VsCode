import java.util.Scanner;

public class How_many_looping_chains {

  public static int find(int x, int[] parent) {
    if(parent[x] != x) {
      parent[x] = find(parent[x], parent);
    }
    return parent[x];
  }

  public static void unite(int x, int y, int[] parent) {
    x = find(x, parent);
    y = find(y, parent);
    if(x != y) {
      parent[y] = x; 
    }
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    int[] parent = new int[n];
    for(int i = 0; i < n; i++) {
      parent[i] = i;
    }

    for(int i = 0; i < n; i++) {
      int a = sc.nextInt();
      unite(i, a-1, parent);
    }

    int ret = 0;
    for(int i = 0; i < n; i++) {
      if(parent[i] == i) ret++;
    }

    System.out.println(ret);
  }
}
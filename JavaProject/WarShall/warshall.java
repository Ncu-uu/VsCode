
public class wallshall {
    public static void main(String[] args) {
        int n = 5; // 代表元素集合的大小
        boolean[][] relationMatrix = new boolean[n][n]; // 关系矩阵

        // 初始化关系矩阵
        relationMatrix[0][1] = true;
        relationMatrix[1][2] = true;
        relationMatrix[2][3] = true;
        relationMatrix[3][4] = true;

        // 输出原始关系矩阵
        System.out.println("原始关系矩阵：");
        printMatrix(relationMatrix);

        // 计算传递闭包
        boolean[][] transitiveClosure = computeTransitiveClosure(relationMatrix);

        // 计算自反闭包
        boolean[][] reflexiveClosure = computeReflexiveClosure(transitiveClosure);

        // 输出自反闭包
        System.out.println("自反闭包：");
        printMatrix(reflexiveClosure);
    }

    // 计算传递闭包
    public static boolean[][] computeTransitiveClosure(boolean[][] relationMatrix) {
        int n = relationMatrix.length;
        boolean[][] transitiveClosure = new boolean[n][n];

        // 复制关系矩阵到传递闭包矩阵
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transitiveClosure[i][j] = relationMatrix[i][j];
            }
        }

        // 使用 Warshall 算法计算传递闭包
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
                }
            }
        }

        return transitiveClosure;
    }

    // 计算自反闭包
    public static boolean[][] computeReflexiveClosure(boolean[][] relationMatrix) {
        int n = relationMatrix.length;
        boolean[][] reflexiveClosure = new boolean[n][n];

        // 复制传递闭包矩阵到自反闭包矩阵
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reflexiveClosure[i][j] = relationMatrix[i][j];
            }
        }

        // 添加自反关系
        for (int i = 0; i < n; i++) {
            reflexiveClosure[i][i] = true;
        }

        return reflexiveClosure;
    }

    // 打印矩阵
    public static void printMatrix(boolean[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] ? "1 " : "0 ");
            }
            System.out.println();
        }
    }
}

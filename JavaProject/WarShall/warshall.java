
public class wallshall {
    public static void main(String[] args) {
        int n = 5; // ����Ԫ�ؼ��ϵĴ�С
        boolean[][] relationMatrix = new boolean[n][n]; // ��ϵ����

        // ��ʼ����ϵ����
        relationMatrix[0][1] = true;
        relationMatrix[1][2] = true;
        relationMatrix[2][3] = true;
        relationMatrix[3][4] = true;

        // ���ԭʼ��ϵ����
        System.out.println("ԭʼ��ϵ����");
        printMatrix(relationMatrix);

        // ���㴫�ݱհ�
        boolean[][] transitiveClosure = computeTransitiveClosure(relationMatrix);

        // �����Է��հ�
        boolean[][] reflexiveClosure = computeReflexiveClosure(transitiveClosure);

        // ����Է��հ�
        System.out.println("�Է��հ���");
        printMatrix(reflexiveClosure);
    }

    // ���㴫�ݱհ�
    public static boolean[][] computeTransitiveClosure(boolean[][] relationMatrix) {
        int n = relationMatrix.length;
        boolean[][] transitiveClosure = new boolean[n][n];

        // ���ƹ�ϵ���󵽴��ݱհ�����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                transitiveClosure[i][j] = relationMatrix[i][j];
            }
        }

        // ʹ�� Warshall �㷨���㴫�ݱհ�
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
                }
            }
        }

        return transitiveClosure;
    }

    // �����Է��հ�
    public static boolean[][] computeReflexiveClosure(boolean[][] relationMatrix) {
        int n = relationMatrix.length;
        boolean[][] reflexiveClosure = new boolean[n][n];

        // ���ƴ��ݱհ������Է��հ�����
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                reflexiveClosure[i][j] = relationMatrix[i][j];
            }
        }

        // ����Է���ϵ
        for (int i = 0; i < n; i++) {
            reflexiveClosure[i][i] = true;
        }

        return reflexiveClosure;
    }

    // ��ӡ����
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

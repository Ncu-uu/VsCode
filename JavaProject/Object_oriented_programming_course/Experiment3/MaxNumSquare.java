/*

import java.util.Scanner;


public class MaxNumSquare
{
    public static void main(String[] args)
    {
        int[][] matrix = creatMatrix();
        int[] result = findMax(matrix);
        System.out.println("The maximun square submatrix is at(" +
                result[1] + ", " + result[2] + ") with size " + result[0]);
    }

    public static int[][] creatMatrix()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of rows in the matrix: ");

        int number = input.nextInt();

        System.out.println("Enter the matrix row by row: ");

        int[][] matrix = new int[number][number];

        for (int row = 0; row < number; row++)
        {
            for (int column = 0; column < number; column++)
            {
                matrix[row][column] = input.nextInt();
            }
        }
        return matrix;
    }

    public static int[] findMax(int[][] matrix)
    {
        int[] result = new int[3];
//        result[0] = 0;
//        result[1] = 0;
//        result[2] = 0;
        for (int row = 0; row < matrix.length - 1; row++)
        {
            for (int column = 0; column < matrix[0].length - 1; column++)
            {
                int record = findLength(matrix, row, column);

                if (record > result[0])
                {
                    result[0] = record;
                    result[1] = row;
                    result[2] = column;
                }
            }
        }
        return result;
    }

    public static int findLength(int[][] matrix, int row, int column)
    {
        //最重要的就是这句判断，保证每一个元素都要在 matrix 中
        if ((matrix[row][column] == 0) || (matrix[row + 1][column + 1] == 0))
        {
            return 0;
        }

        int length = 0;

        boolean succ = false;
        while (!succ)
        {
            if ((row + length >= matrix.length) || (column + length >= matrix.length))
            {
                return length;
            }

            for (int r = row; r < row + length; r++)
            {
//                System.out.println(row + " " + column + " " + length);
                if (matrix[r][column + length] != 1)
                {
                    return length;
                }
            }

            for (int c = column; c < column + length; c++)
            {
                if (matrix[row + length][c] != 1)
                {
                    return length;
                }
            }
            length++;
        }
        System.out.println(length);
        return length;
    }
}
 */

import java.util.Scanner;

public class MaxNumSquare {
    public static void main(String[] args) {
        int[][] matrix = createMatrix(); // 创建一个二维数组表示一个矩阵
        int[] result = findMax(matrix); // 查找最大子矩阵的大小和位置
        System.out.println("The maximun square submatrix is at(" +
                result[1] + ", " + result[2] + ") with size " + result[0]);
    }

    public static int[][] createMatrix() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of rows in the matrix: ");
        int number = input.nextInt();
        System.out.println("Enter the matrix row by row: ");
        int[][] matrix = new int[number][number]; // 创建一个指定大小的二维数组
        for (int row = 0; row < number; row++) { // 遍历行
            for (int column = 0; column < number; column++) { // 遍历列
                matrix[row][column] = input.nextInt(); // 将输入的数字存入二维数组中
            }
        }
        return matrix; // 返回创建的二维数组
    }

    public static int[] findMax(int[][] matrix) {
        int[] result = new int[3]; // 创建一个长度为3的整型数组用于存储最大子矩阵的信息

        for (int row = 0; row < matrix.length - 1; row++) { // 遍历行
            for (int column = 0; column < matrix[0].length - 1; column++) { // 遍历列
                int record = findLength(matrix, row, column); // 查找当前子矩阵的大小

                if (record > result[0]) { // 如果当前子矩阵比之前的最大子矩阵还要大
                    result[0] = record; // 更新最大子矩阵的大小
                    result[1] = row; // 更新最大子矩阵的左上角坐标
                    result[2] = column; // 更新最大子矩阵的右下角坐标
                }
            }
        }
        return result; // 返回最大子矩阵的信息
    }

    public static int findLength(int[][] matrix, int row, int column) { // 查找当前子矩阵的大小
        int length = 0; // 初始化当前子矩阵的大小为0

//        System.out.println("length:" + length); // 调试信息，yongyuhsuhcuhu用于输出每一个length

        boolean succ = false; // 是否成功的标志位，初始化为false
        while (!succ) { // 只要没有成功，就继续循环
            if ((row + length >= matrix.length) || (column + length >= matrix.length)) { // 如果超出了边界，说明找到了最大的子矩阵，返回大小即可
                return length; // 返回当前子矩阵的大小
            }

            for (int r = row; r < row + length; r++) { // 在当前行及其后面的行中查找是否存在1
//                System.out.println("r:" + r + " c:" + column + " length:" + length); // 调试信息
                if (matrix[r][column + length] != 1) { // 如果不存在1,说明当前子矩阵不合法，需要继续查找下一个子矩阵
                    return length; // 继续查找下一个子矩阵的大小
                }
            }
            for (int c = column; c < column + length; c++) { // 在当前列及其后面的列中查找是否存在1
                if (matrix[row + length][c] != 1) { // 如果不存在1,说明当前子矩阵不合法，需要继续查找下一个子矩阵
                    return length; // 继续查找下一个子矩阵的大小
                }
            }
            length++; // 每次查找成功后，当前子矩阵的大小加1,继续查找下一个子矩阵的大小
        }
        System.out.println(length); // 如果所有子矩阵都失败了，说明最大的子矩阵就是当前这个，输出其大小即可
        return length; // 最后返回最大子矩阵的大小
    }
}
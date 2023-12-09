import java.util.Scanner;
import java.util.Random;

public class BasicTraining {
    public void addition() {
        Scanner input = new Scanner(System.in);
        System.out.println("小朋友，欢迎来到加法训练营！");
        System.out.println("这次你要挑战几道题呢？");
        System.out.println("请输入题目数量：");
        int num = input.nextInt();
        while(num <= 0){
            System.out.println("题目数量必须大于0，请重新输入：");
            num = input.nextInt();
        }
        System.out.println("要挑战多少以内的加法呢？");
        int range = input.nextInt();

        while(range <= 2){
            System.out.println("加法范围必须大于2，请重新输入：");
            range = input.nextInt();
        }

        System.out.println("本次训练共有" + num + "道题，加法范围是1-" + range + "。");

        System.out.println("按下Enter键开始答题：");
        input.nextLine();
        input.nextLine();

        long startTime = System.currentTimeMillis();
        int correctNum = 0;

        for (int i = 0; i < num; i++) {
            if(giveOneAddition(range)){
                correctNum++;
            }
        }

        long endTime = System.currentTimeMillis();
        long spendtime = (endTime - startTime) / 1000;

        System.out.println("本次训练结束，你一共答对了" + correctNum + "道题，用时" + spendtime + "秒。");
    }

    public boolean giveOneAddition(int range){
        Scanner input = new Scanner(System.in);
        Random rand = new Random();
        int addend1 = rand.nextInt(range - 1) + 1;
        int addend2 = rand.nextInt(range - addend1) + 1;
        int result = addend1 + addend2;

        System.out.println(addend1 + " + " + addend2 + " = ");

        int answer = input.nextInt();
        if(answer == result){
            System.out.println("恭喜你，答对了！");
            return true;
        }else{
            System.out.println("很遗憾，答错了！");
            System.out.println("正确答案是：" + result);
            return false;
        }
    }

}

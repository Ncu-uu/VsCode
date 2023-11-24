import org.w3c.dom.ls.LSOutput;

import java.util.ArrayList;
/*
public class Voter {
    public String Name;
    public int MaxVoterNumber ;
    public String VotingOpinion;
    public static int count;
    public static ArrayList<Voter> voters = new ArrayList<Voter>();
    public int countYes=0;
    public int countNo=0;

    public Voter(String name, int maxVoterNumber, String votingOpinion) {
        Name = name;
        MaxVoterNumber = maxVoterNumber;
        VotingOpinion = votingOpinion;
        count++;
    }

    public String getName() {
        return Name;
    }

    public static int getCount() {
        return count;
    }

    public static void setCount(int count) {
        Voter.count = count;
    }
}
*/

public class Voter {
private String name; // 姓名
private int maxVote; // 最大投票数
private int curVote; // 当前投票数
private String voteOpinion; // 投票意见
private static int count; // 当前投票总数
private static ArrayList<Voter> voters = new ArrayList<Voter>(); // 已经投票的选民列表

public Voter(String name, int maxVote, String voteOpinion) {
    this.name = name;
    this.maxVote = maxVote;
    this.voteOpinion = voteOpinion;
}

public void vote() {
    // 判断是否已经投过票
    if (voters.contains(this)) {
        System.out.println(name + " 您不允许重复投票。");
//        return;
    }

    // 判断是否能够投票
    if (curVote >= maxVote) {
        System.out.println(name + " 您已经投满票了。");
//        return;
    }
    // 投票
    curVote++;
    count++;
    voters.add(this);
    System.out.println(name + " 感谢您的投票。");
}

public static void printResult() {
    System.out.println("当前投票数为：" + count);
    System.out.println("参与投票的选民和结果如下:");
    int yesCount = 0;
    int noCount = 0;
    for (Voter voter : voters) {
        System.out.println(voter.getName() + " 的意见是 " + voter.getVoteOpinion());
        if (voter.getVoteOpinion().equals("Yes")) {
            yesCount++;
        } else {
            noCount++;
        }
    }
    System.out.println("结果: Yes: " + yesCount + "，No: " + noCount);
}

public String getName() {
    return name;
}

public int getMaxVote() {
    return maxVote;
}
public int getCurVote() {
    return curVote;
}
public String getVoteOpinion() {
    return voteOpinion;
}
}
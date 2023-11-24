import java.util.ArrayList;

//public class TestVoter {
//    private static ArrayList<Voter> voters = new ArrayList<Voter>();
//    public static void main(String[] args) {
//        voters.add(new Voter("王明",1,"Yes"));
//        voters.add(new Voter("李丽",1,"Yes"));
//        voters.add(new Voter("赵亮",1,"Yes"));
//        System.out.println();
//    }
//}

public class TestVoter {
public static void main(String[] args) {
Voter v1 = new Voter("王明", 1, "Yes");
Voter v2 = new Voter("李丽", 2, "Yes");
Voter v3 = new Voter("赵亮", 1, "No");

    v1.vote();
    v1.vote();
    v2.vote();
    v3.vote();

    Voter.printResult();
}
}

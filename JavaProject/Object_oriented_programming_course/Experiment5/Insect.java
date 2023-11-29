
public class Insect extends Animal implements Talent {
    private String characteristic;
    private int legsNum;

    public Insect(int id, String category, String characteristic, int legsNum) {
        super(id, category);
        this.characteristic = characteristic;
        this.legsNum = legsNum;
    }

    @Override
    public void showTalent() {
        System.out.println("天赋：有粘性的脚可以爬");
    }

    public void InsectCharacteristic() {
        System.out.println("特有行为：会用嘴巴咬食物");
    }
}

public class Bird extends Animal implements Talent {
    private String characteristic;
    private boolean canFly;

    public Bird(int id, String category, String characteristic, boolean canFly) {
        super(id, category);
        this.characteristic = characteristic;
        this.canFly = canFly;
    }

    @Override
    public void showTalent() {
        System.out.println("天赋：会飞行");
    }

    public void BirdCharacteristic() {
        System.out.println("特有行为：会用嘴巴啄食");
    }
}
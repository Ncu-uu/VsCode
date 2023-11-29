
public class Fish extends Animal implements Talent {
    private String characteristic;
    private boolean canBreath;

    public Fish(int id, String category, String characteristic, boolean canBreath) {
        super(id, category);
        this.characteristic = characteristic;
        this.canBreath = canBreath;
    }

    @Override
    public void showTalent() {
        System.out.println("天赋：会游泳");
    }

    public void FishCharacteristic() {
        System.out.println("特有行为：可以用鳃呼吸");
    }
}
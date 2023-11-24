public class Reptile extends Animal implements Talent {
    private String characteristic;
    private boolean canSwim;

    public Reptile(int id, String category, String characteristic, boolean canSwim) {
        super(id, category);
        this.characteristic = characteristic;
        this.canSwim = canSwim;
    }

    @Override
    public void showTalent() {
        System.out.println("天赋：有防御机制");
    }

    public void ReptileCharacteristic() {
        System.out.println("特有行为：可以蜷曲起来");
    }
}

public class Main
{
    public static void main(String[] args)
    {
        Animal[] animals = new Animal[100];
        for (int i = 0; i < 100; i++) {
            int id = i + 1;
            String category = "";
            Talent talent = null;
            switch ((int) (Math.random() * 4)) {
                case 0:
                    category = "鸟类";
                    Bird bird = new Bird(id, category, "有羽毛", true);
                    bird.BirdCharacteristic();
                    talent = bird;
                    break;
                case 1:
                    category = "昆虫类";
                    Insect insect = new Insect(id, category, "有六只脚", 6);
                    insect.InsectCharacteristic();
                    talent = insect;
                    break;
                case 2:
                    category = "爬行类";
                    Reptile reptile = new Reptile(id, category, "有鳞片", true);
                    reptile.ReptileCharacteristic();
                    talent = reptile;
                    break;
                case 3:
                    category = "鱼类";
                    Fish fish = new Fish(id, category, "有鳞片", true);
                    fish.FishCharacteristic();
                    talent = fish;
                    break;
            }
            animals[i] = (Animal) talent;
            System.out.println("我是" + animals[i].getClass().getSimpleName());
            animals[i].showMessage();
            talent.showTalent();
            System.out.println();
        }
    }
}
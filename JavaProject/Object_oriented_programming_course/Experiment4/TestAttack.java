// 定义一个TestAttack类
public class TestAttack {
    public static void main(String[] args) {
// 创建一个Titan对象和一个Zues对象
        Titan titan = new Titan();
        Zues zues = new Zues();

        // 进入战斗循环
        while (true){
            // Zues攻击Titan
            zues.battle(titan);
            // 判断Titan是否已经失败
            if (zues.Energy>=0&&titan.Energy<=0){
                System.out.println("Titan的Energy值为"+titan.getEnergy()+"，已经失败，获胜者是Zues!");
                break;
            }

            // Titan攻击Zues
            titan.battle(zues);
            // 判断Zues是否已经失败
            if(titan.Energy>=0&&zues.Energy<=0){
                System.out.println("Zues的Energy值为"+zues.getEnergy()+"，已经失败，获胜者是Titan!");
                break;
            }
        }
    }
}
/*
public class TestAttack {
    public static void main(String[] args) {
        Titan titan = new Titan();
        Zues zues = new Zues();
        while (true){
            zues.battle(titan);
            if (zues.Energy>=0&&titan.Energy<=0){
                System.out.println("Titan的Energy值为"+titan.getEnergy()+"，已经失败，获胜者是Zues!");
                break;
            }
            titan.battle(zues);
            if(titan.Energy>=0&&zues.Energy<=0){
                System.out.println("Zues的Energy值为"+zues.getEnergy()+"，已经失败，获胜者是Titan!");
                break;
            }

        }
    }
}

 */

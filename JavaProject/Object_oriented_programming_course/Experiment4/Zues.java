// 定义一个Zues类
public class Zues {
    // 定义一个Energy属性，初始值为1000
    public int Energy = 1000;

    // 定义一个无参构造方法
    public Zues(){
    }

    // 定义一个有参构造方法，用于设置Energy属性的初始值
    public Zues(int energy){
        this.Energy = energy;
    }

    // 定义一个setEnergy方法，用于设置Energy属性的值
    public void setEnergy(int energy){
        this.Energy = energy;
    }

    // 定义一个getEnergy方法，用于获取Energy属性的值
    public int getEnergy(){
        return this.Energy;
    }

    // 定义一个battle方法，用于攻击Titan
    public void battle(Titan t){
        // 产生一个0~70之间的随机数作为攻击值
        int attack = (int) (Math.random() * 71);
        // 计算Titan的剩余能量值
        t.setEnergy(t.getEnergy()-attack);
        // 输出攻击结果
        System.out.println("Zues攻击Titan，产生"+attack+"点攻击值，Titan当前Energy值为"+t.getEnergy());
    }
}
/*
public class Zues {
    public int Energy = 1000;

    public Zues(){
    }
    public Zues(int energy){
        this.Energy = energy;
    }
    public void setEnergy(int energy){
        this.Energy = energy;
    }
    public int getEnergy(){
        return this.Energy;
    }
    public void battle(Titan t){
        int attack = (int) (Math.random() * 71);
        t.setEnergy(t.getEnergy()-attack);
        System.out.println("Zues攻击Titan，产生"+attack+"点攻击值，Titan当前Energy值为"+t.getEnergy());
    }
}

 */


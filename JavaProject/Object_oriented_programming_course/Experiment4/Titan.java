// 定义一个Titan类
public class Titan {
    // 定义一个Energy属性，初始值为800
    public int Energy = 800;

    // 定义一个无参构造方法
    Titan(){
    }

    // 定义一个有参构造方法，用于设置Energy属性的初始值
    public Titan(int energy){
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

    // 定义一个battle方法，用于攻击Zues
    public void battle(Zues z){
        // 产生一个10~100之间的随机数作为攻击值
        int attack = (int)(Math.random() * 91)+10;
        // 计算Zues的剩余能量值
        z.setEnergy(z.getEnergy()-attack);
        // 输出攻击结果
        System.out.println("Titan攻击Zues，产生"+attack+"点攻击值，Zues当前Energy值为"+z.getEnergy());
    }
}
/*
public class Titan {
    public int Energy = 800;
    Titan(){
    }
    public Titan(int energy){
        this.Energy = energy;
    }
    public void setEnergy(int energy){
        this.Energy = energy;
    }
    public int getEnergy(){
        return this.Energy;
    }
    public void battle(Zues z){
        int attack = (int)(Math.random() * 91)+10;
        z.setEnergy(z.getEnergy()-attack);
       System.out.println("Titan攻击Zues，产生"+attack+"点攻击值，Zues当前Energy值为"+z.getEnergy());
   }
}

 */

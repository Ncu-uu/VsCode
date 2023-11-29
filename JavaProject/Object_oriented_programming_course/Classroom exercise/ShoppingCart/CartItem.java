// ShoppingCart库下的CartItem类
package ShoppingCart;

// CartItem类
public class CartItem {
    // 私有变量，存储商品的属性
    private String id; // 商品ID
    private String name; // 商品名称
    private double price; // 商品单价
    private int quantity; // 商品数量

    // 构造函数，初始化商品属性
    public CartItem(String id, String name, double price, int quantity) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    // 获取商品ID
    public String getId() {
        return id;
    }

    // 设置商品ID
    public void setId(String id) {
        this.id = id;
    }

    // 获取商品名称
    public String getName() {
        return name;
    }

    // 设置商品名称
    public void setName(String name) {
        this.name = name;
    }

    // 获取商品单价
    public double getPrice() {
        return price;
    }

    // 设置商品单价
    public void setPrice(double price) {
        this.price = price;
    }

    // 获取商品数量
    public int getQuantity() {
        return quantity;
    }

    // 设置商品数量
    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    // 获取商品总价
    public double getTotalPrice() {
        return price * quantity;
    }

    // 转成字符串输出
    public String toString() {
        return (id+ "\t\t" + name + " \t" + price + " \t" +  quantity + " \t\t" + getTotalPrice());
    }
}

/*
package ShoppingCart;
public class CartItem {
    private String id;
    private String name;
    private double price;
    private int quantity;

    public CartItem(String id, String name, double price, int quantity) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public double getTotalPrice() {
        return price * quantity;
    }

    public String toString() {
        return (id+ "\t\t" + name + " \t" + price + " \t" +  quantity + " \t\t" + getTotalPrice());
    }
}
*/
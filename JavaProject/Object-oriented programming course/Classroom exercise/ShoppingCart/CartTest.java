package ShoppingCart; // 声明包名

public class CartTest { // 声明一个类CartTest
    public static void main(String[] args) { // 声明主方法
        ShoppingCart myCart = new ShoppingCart("张三"); // 创建一个购物车对象myCart并赋值
        myCart.addItem(new CartItem("001",  "水杯", 20.0, 1)); // 向myCart购物车中添加商品
        myCart.addItem(new CartItem("002",  "牙刷", 15.0, 2));
        myCart.addItem(new CartItem("003",  "牙膏", 10.0, 1));
        myCart.addItem(new CartItem("004",  "毛巾", 28.0, 1));

        System.out.println(myCart.toString()); // 输出购物车信息

        myCart.setQuantity(0, 4); // 修改购物车第一个商品的数量
        System.out.println(myCart.toString()); // 再次输出购物车信息

        myCart.removeItem(0); // 删除购物车第一个商品
        System.out.println(myCart.toString()); // 再次输出购物车信息

        myCart.clearCart(); // 清空购物车
        System.out.println(myCart.toString()); // 输出清空后的购物车信息
    }
}
/*
package ShoppingCart;

public class CartTest {
    public static void main(String[] args) {
        ShoppingCart myCart = new ShoppingCart("张三");
        myCart.addItem(new CartItem("001",  "水杯", 20.0, 1));
        myCart.addItem(new CartItem("002",  "牙刷", 15.0, 2));
        myCart.addItem(new CartItem("003",  "牙膏", 10.0, 1));
        myCart.addItem(new CartItem("004",  "毛巾", 28.0, 1));

        System.out.println(myCart.toString());

        myCart.setQuantity(0, 4);
        System.out.println(myCart.toString());

        myCart.removeItem(0);
        System.out.println(myCart.toString());

        myCart.clearCart();
        System.out.println(myCart.toString());
    }
}
*/
package ShoppingCart;
public class ShoppingCart {
    // 定义购物车类，包含用户名、购物车商品、商品数量、商品总价等属性
    private String userName;
    private CartItem[] items;
    private int count;
    private double totalPrice;

    // 构造方法，传入用户名并初始化商品数组、数量和总价
    public ShoppingCart(String userName) {
        this.userName = userName;
        this.items = new CartItem[5];
        this.count = 0;
        this.totalPrice = 0;
    }

    // getter和setter方法，用于获取和设置用户名、商品、商品数量和商品总价等属性值
    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public CartItem[] getItems() {
        return items;
    }

    public void setItems(CartItem[] items) {
        this.items = items;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public double getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(double totalPrice) {
        this.totalPrice = totalPrice;
    }

    // 添加商品方法，如果商品已存在则增加数量并累加总价，否则将商品加入购物车
    public void addItem(CartItem item) {
        boolean found = false;
        for (int i = 0; i < count; i++) {
            if (items[i].getId().equals(item.getId())) {
                items[i].setQuantity(items[i].getQuantity() + item.getQuantity());
                found = true;
                break;
            }
        }
        if (!found) {
            items[count++] = item;
        }
        totalPrice += item.getTotalPrice();
    }

    // 移除商品方法，将指定索引位置的商品移除并减少数量和总价
    public void removeItem(int index) {
        CartItem item = items[index];
        for (int i = index; i < count - 1; i++) {
            items[i] = items[i + 1];
        }
        items[count - 1] = null;
        count--;
        totalPrice -= item.getTotalPrice();
    }

    // 修改商品数量方法，将指定索引位置的商品数量修改为新值，并更新总价
    public void setQuantity(int index, int quantity) {
        CartItem item = items[index];
        totalPrice -= item.getTotalPrice();
        item.setQuantity(quantity);
        totalPrice += item.getTotalPrice();
    }

    // 清空购物车方法，将商品数组、数量和总价全部设置为初始值
    public void clearCart() {
        for (int i = 0; i < count; i++) {
            items[i] = null;
        }
        count = 0;
        totalPrice = 0;
    }

    // toString方法，用于输出购物车的信息，包括所有商品的信息和购物车总价
    public String toString() {
        if (count == 0)
        {
            System.out.println();
            return userName + "的购物车是空的！";
        } else
        {
            StringBuilder sb = new StringBuilder();
            sb.append(userName).append("的购物车如下：\n");
            sb.append("id\t\t商品名\t单价\t\t数量\t\t总价\n");
            for (int i = 0; i < count; i++)
            {
                sb.append(items[i].toString()).append("\n");
            }
            sb.append("合计:").append(totalPrice);
            System.out.println();
            return sb.toString();
        }
    }
}
/*package ShoppingCart;
public class ShoppingCart {
    private String userName;
    private CartItem[] items;
    private int count;
    private double totalPrice;

    public ShoppingCart(String userName) {
        this.userName = userName;
        this.items = new CartItem[5];
        this.count = 0;
        this.totalPrice = 0;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public CartItem[] getItems() {
        return items;
    }

    public void setItems(CartItem[] items) {
        this.items = items;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public double getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(double totalPrice) {
        this.totalPrice = totalPrice;
    }

    public void addItem(CartItem item) {
        boolean found = false;
        for (int i = 0; i < count; i++) {
            if (items[i].getId().equals(item.getId())) {
                items[i].setQuantity(items[i].getQuantity() + item.getQuantity());
                found = true;
                break;
            }
        }
        if (!found) {
            items[count++] = item;
        }
        totalPrice += item.getTotalPrice();
    }

    public void removeItem(int index) {
        CartItem item = items[index];
        for (int i = index; i < count - 1; i++) {
            items[i] = items[i + 1];
        }
        items[count - 1] = null;
        count--;
        totalPrice -= item.getTotalPrice();
    }

    public void setQuantity(int index, int quantity) {
        CartItem item = items[index];
        totalPrice -= item.getTotalPrice();
        item.setQuantity(quantity);
        totalPrice += item.getTotalPrice();
    }

    public void clearCart() {
        for (int i = 0; i < count; i++) {
            items[i] = null;
        }
        count = 0;
        totalPrice = 0;
    }

    public String toString() {
        if (count == 0)
        {
            System.out.println();
            return userName + "的购物车是空的！";
        } else
        {
            StringBuilder sb = new StringBuilder();
            sb.append(userName).append("的购物车如下：\n");
            sb.append("id\t\t商品名\t单价\t\t数量\t\t总价\n");
            for (int i = 0; i < count; i++)
            {
                sb.append(items[i].toString()).append("\n");
            }
            sb.append("合计:").append(totalPrice);
            System.out.println();
            return sb.toString();
        }
    }
}

*/
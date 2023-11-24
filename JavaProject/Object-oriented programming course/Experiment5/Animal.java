public class Animal
{
    private int id;
    private String category;

    public Animal(int id, String category)
    {
        this.id = id;
        this.category = category;
    }
    public void showMessage()
    {
        System.out.println("编号：" + id);
        System.out.println("类别：" + category);
    }
}
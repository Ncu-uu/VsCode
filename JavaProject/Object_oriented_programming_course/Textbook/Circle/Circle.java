package Circle;
public class Circle
{
    private double Radius;
    private static int NumberOfObjects;
    public Circle()
    {
        this(1.0);
        NumberOfObjects++;
//        Radius = 1;
    }
    public Circle(double radius)
    {
        NumberOfObjects++;
        Radius = radius;
    }

    public double getRadius()
    {
        return Radius;
    }
    public void setRadius(double newRadius)
    {
//        Radius = newRadius;
        Radius = (newRadius >= 0) ? newRadius : 0;
    }

    public static int getNumberOfObjects()
    {
        return NumberOfObjects;
    }


    public double getArea()
    {
        return Math.PI * Math.pow(Radius,2);
    }

    double getPerimeter()
    {
        return 2 * Math.PI * Radius;
    }

    public static void PrintCircle(Circle circle)
    {
        System.out.println("The perimeter of the circle is " + circle.getPerimeter());
        System.out.println("The area of the circle is " + circle.getArea());
    }

    public static void PrintArea(Circle circle,int times)
    {
        System.out.println("Radius \t\tArea");
        while (times>=1)
        {
            System.out.println(circle.getRadius() + " \t\t" + circle.getArea());
            circle.setRadius(circle.getRadius()+1);
            times--;
        }

//        System.out.println(circle.getRadius());
    }
}

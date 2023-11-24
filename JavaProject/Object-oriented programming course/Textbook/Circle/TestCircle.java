package Circle;

public class TestCircle
{
    public static void main(String[] args)
    {

        System.out.println(Circle.getNumberOfObjects());

        System.out.println();

        Circle circle1 = new Circle();
        Circle circle2 = new Circle(3);
        Circle circle3 = new Circle(5);

        Circle.PrintArea(circle1,5);

        Circle.PrintCircle(circle1);
//        Circle.PrintArea(circle2,5);
//        Circle.PrintArea(circle3,5);

//        Circle.PrintCircle(circle1);
//        Circle.PrintCircle(circle2);
//        Circle.PrintCircle(circle3);



//        System.out.println(circle1.getArea());
//        System.out.println(circle2.getArea());



//        circle2.setRadius(2);
//        System.out.println(circle2.getRadius());



//        System.out.println(Math.PI);

//        System.out.println(circle2.getArea());
//
//        System.out.println(circle3.getPerimeter());
//
//        System.out.println();
//
//        System.out.println(Circle.getNumberOfObjects());
    }
}

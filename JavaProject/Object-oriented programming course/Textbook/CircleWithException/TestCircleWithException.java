package CircleWithException;

public class TestCircleWithException {
    public static void main(String[] args) {
        try {
            CircleWithException c1 = new CircleWithException(5);

            System.out.println("c1:"+ c1.getArea());

            CircleWithException c2 = new CircleWithException();

            System.out.println("c2:" + c2.getArea());

            CircleWithException c3 = new CircleWithException(-3.0);

            System.out.println(c3.getArea());
        }

        catch (IllegalArgumentException ex){
            System.out.println(ex);

        }
        System.out.println("numberOfObjects:" + CircleWithException.getNumberOfObjects());


    }
}

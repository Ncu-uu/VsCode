package CircleWithException;

public class CircleWithException
{
    private double radius;

    private static int numberOfObjects = 0;

    public CircleWithException(double radius) {
        setRadius(radius);
        numberOfObjects++;
    }
    public CircleWithException() {
        this(1.0);
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) throws IllegalArgumentException {
            if (radius >= 0){
                this.radius = radius;
            }
            else throw new IllegalArgumentException("Radius cannot be negative");
    }

    public static int getNumberOfObjects() {
        return numberOfObjects;
    }

    public double getArea(){
        return Math.PI * Math.pow( this.radius , 2.0 );
    }
}


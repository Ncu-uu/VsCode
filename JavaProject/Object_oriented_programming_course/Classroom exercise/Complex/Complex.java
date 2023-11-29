package Complex;
// 实现了Cloneable接口和Comparable接口，表示该类可以被克隆，可以进行比较
public class Complex implements Cloneable, Comparable<Complex> {

    // 定义了两个私有成员变量，分别表示实部和虚部
    private double realPart;
    private double imaginaryPart;

    // 无参构造函数，将实部和虚部都初始化为0
    public Complex() {
        this.realPart = 0;
        this.imaginaryPart = 0;
    }

    // 有参构造函数，传入实部，将虚部初始化为0
    public Complex(double realPart) {
        this.realPart = realPart;
        this.imaginaryPart = 0;
    }

    // 有参构造函数，传入实部和虚部
    public Complex(double realPart, double imaginaryPart) {
        this.realPart = realPart;
        this.imaginaryPart = imaginaryPart;
    }

    // 加法运算，返回一个新的Complex对象
    public Complex add(Complex another) {
        double real = this.realPart + another.realPart;
        double imaginary = this.imaginaryPart + another.imaginaryPart;
        return new Complex(real, imaginary);
    }

    // 减法运算，返回一个新的Complex对象
    public Complex subtract(Complex another) {
        double real = this.realPart - another.realPart;
        double imaginary = this.imaginaryPart - another.imaginaryPart;
        return new Complex(real, imaginary);
    }

    // 乘法运算，返回一个新的Complex对象
    public Complex multiply(Complex another) {
        double real = this.realPart * another.realPart - this.imaginaryPart * another.imaginaryPart;
        double imaginary = this.realPart * another.imaginaryPart + this.imaginaryPart * another.realPart;
        return new Complex(real, imaginary);
    }

    // 除法运算，返回一个新的Complex对象
    public Complex divide(Complex another) {
        double denominator = another.realPart * another.realPart + another.imaginaryPart * another.imaginaryPart;
        double real = (this.realPart * another.realPart + this.imaginaryPart * another.imaginaryPart) / denominator;
        double imaginary = (this.imaginaryPart * another.realPart - this.realPart * another.imaginaryPart) / denominator;
        return new Complex(real, imaginary);
    }

    // 返回该复数的模
    public double abs() {
        return Math.sqrt(this.realPart * this.realPart + this.imaginaryPart * this.imaginaryPart);
    }

    // 返回实部
    public double getRealPart() {
        return this.realPart;
    }

    // 返回虚部
    public double getImaginaryPart() {
        return this.imaginaryPart;
    }

    // 重写toString方法，返回该复数的字符串表示形式
    @Override
    public String toString() {
        if (this.imaginaryPart == 0) {
            return String.valueOf(this.realPart);
        } else {
            return this.realPart + " + " + this.imaginaryPart + "i";
        }
    }

    // 重写clone方法，返回一个新的Complex对象
    @Override
    public Complex clone() {
        return new Complex(this.realPart, this.imaginaryPart);
    }

    // 重写compareTo方法，比较两个复数的模的大小
    @Override
    public int compareTo(Complex another) {
        if (this.abs() > another.abs()) {
            return 1;
        } else if (this.abs() < another.abs()) {
            return -1;
        } else {
            return 0;
        }
    }
}

/*
package Complex;
public class Complex implements Cloneable, Comparable<Complex> {
    private double realPart;
    private double imaginaryPart;

    public Complex() {
        this.realPart = 0;
        this.imaginaryPart = 0;
    }

    public Complex(double realPart) {
        this.realPart = realPart;
        this.imaginaryPart = 0;
    }

    public Complex(double realPart, double imaginaryPart) {
        this.realPart = realPart;
        this.imaginaryPart = imaginaryPart;
    }

    public Complex add(Complex another) {
        double real = this.realPart + another.realPart;
        double imaginary = this.imaginaryPart + another.imaginaryPart;
        return new Complex(real, imaginary);
    }

    public Complex subtract(Complex another) {
        double real = this.realPart - another.realPart;
        double imaginary = this.imaginaryPart - another.imaginaryPart;
        return new Complex(real, imaginary);
    }

    public Complex multiply(Complex another) {
        double real = this.realPart * another.realPart - this.imaginaryPart * another.imaginaryPart;
        double imaginary = this.realPart * another.imaginaryPart + this.imaginaryPart * another.realPart;
        return new Complex(real, imaginary);
    }

    public Complex divide(Complex another) {
        double denominator = another.realPart * another.realPart + another.imaginaryPart * another.imaginaryPart;
        double real = (this.realPart * another.realPart + this.imaginaryPart * another.imaginaryPart) / denominator;
        double imaginary = (this.imaginaryPart * another.realPart - this.realPart * another.imaginaryPart) / denominator;
        return new Complex(real, imaginary);
    }

    public double abs() {
        return Math.sqrt(this.realPart * this.realPart + this.imaginaryPart * this.imaginaryPart);
    }

    public double getRealPart() {
        return this.realPart;
    }

    public double getImaginaryPart() {
        return this.imaginaryPart;
    }

    @Override
    public String toString() {
        if (this.imaginaryPart == 0) {
            return String.valueOf(this.realPart);
        } else {
            return this.realPart + " + " + this.imaginaryPart + "i";
        }
    }

    @Override
    public Complex clone() {
        return new Complex(this.realPart, this.imaginaryPart);
    }

    @Override
    public int compareTo(Complex another) {
        if (this.abs() > another.abs()) {
            return 1;
        } else if (this.abs() < another.abs()) {
            return -1;
        } else {
            return 0;
        }
    }
}

 */

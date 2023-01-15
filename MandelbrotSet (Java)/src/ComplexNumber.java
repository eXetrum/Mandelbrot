//import com.sun.javafx.binding.StringFormatter;

import java.util.Formatter;

public class ComplexNumber {
    private double r, i;

    public ComplexNumber() {
        r = 0;
        i = 0;
    }

    public ComplexNumber(double _r, double _i) {
        r = _r;
        i = _i;
    }

    public ComplexNumber(ComplexNumber rhs) {
        this.r = rhs.r;
        this.i = rhs.i;
    }

    public void finalize() throws Throwable{
        super.finalize();
    }

    public void setR(double r) {
        this.r = r;
    }

    public void setI(double i) {
        this.i = i;
    }

    public double getR() {
        return r;
    }

    public double getI() {
        return i;
    }

    public String toString() {
        Formatter f = new Formatter();
        f.format("%.2f%s%.2f%s", r, (i >= +0 ? "+" : ""), i, "i");
        return f.toString();
    }

    ComplexNumber add(ComplexNumber rhs) {
        ComplexNumber cn = new ComplexNumber(this);
        cn.r += rhs.r;
        cn.i += rhs.i;
        return cn;
    }

    ComplexNumber sub(ComplexNumber rhs) {
        ComplexNumber cn = new ComplexNumber(this);
        cn.r -= rhs.r;
        cn.i -= rhs.i;
        return cn;
    }

    ComplexNumber mult(ComplexNumber rhs) {
        ComplexNumber cn = new ComplexNumber();
        cn.r = rhs.r * this.r - rhs.i * this.i;
        cn.i = rhs.r * this.i + rhs.i * this.r;
        return cn;
    }

    ComplexNumber div(ComplexNumber rhs) {
        ComplexNumber cn = new ComplexNumber();
        cn.r = (rhs.r * this.r + rhs.i * this.i) / (rhs.r * rhs.r + rhs.i * rhs.i);
        cn.i = (rhs.r * this.i - rhs.i * this.r) / (rhs.r * rhs.r + rhs.i * rhs.i);
        return cn;
    }

    double mag () {
        return Math.sqrt(r * r + i * i);
    }

    ComplexNumber conj () {
        ComplexNumber cn = new ComplexNumber(this);
        if(cn.i != 0)
            cn.i *= -1;
        return cn;
    }

    ComplexNumber sqrt () {
        ComplexNumber cn = new ComplexNumber();
        cn.r = Math.sqrt((r + Math.sqrt(r * r + i * i)) / 2);
        cn.i = Math.signum(i) * Math.sqrt((-r + Math.sqrt(r * r + i * i)) / 2);
        return cn;
    }

    boolean equals (ComplexNumber rhs) {
        if(rhs == null)
            return false;
        if(rhs.r != r)
            return false;
        if(rhs.i != i)
            return false;
        return true;
    }

}

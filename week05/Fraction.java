import java.util.Scanner;

public class Fraction {
    int numberator;
    int denominator;
    Fraction(){
        this.numberator = 0;
        this.denominator = 1;
    }
    Fraction(int num, int den){
        this.numberator = num;
        this.denominator = den;
    }
    Fraction(Fraction f){
        this.numberator = f.numberator;
        this.denominator = f.denominator;
    }
    public void setNumberator(int x){
        this.numberator = x;
    }
    public void setDenominator(int x){
        this.denominator = x;
    }
    public int getNumberator(){
        return this.numberator;
    }
    public int getDenominator(){
        return this.denominator;
    }
    private int Gcd(int a, int b){
        if (b == 0) return a;
        return Gcd(b, a % b);
    }
    private void Simply(){
        int gcd = Gcd(this.numberator, this.denominator);
        this.setNumberator(this.numberator / gcd);
        this.setDenominator(this.denominator / gcd);
    }
    public Fraction add(Fraction f){
        Fraction result = new Fraction();
        result.numberator = this.numberator * f.denominator + f.numberator * this.denominator;
        result.denominator = this.denominator * f.denominator;
        result.Simply();
        return result;
    }
    public Fraction sub(Fraction f){
        Fraction result = new Fraction();
        result.numberator = this.numberator * f.denominator - f.numberator * this.denominator;
        result.denominator = this.denominator * f.denominator;
        result.Simply();
        return result;
    }
    public Fraction mul(Fraction f){
        Fraction result = new Fraction();
        result.numberator = this.numberator * f.numberator;
        result.denominator = this.denominator * f.denominator;
        result.Simply();
        return result;
    }
    public Fraction div(Fraction f){
        Fraction result = new Fraction();
        result.numberator = this.numberator * f.denominator;
        result.denominator = this.denominator * f.numberator;
        result.Simply();
        return result;
    }
    public void reducer(){
        this.numberator -= this.denominator;
        this.Simply();
    }
    @Override
    public String toString(){
        if (this.denominator == 1)
            return this.numberator + "";
        else if (this.denominator == -1){
            if (this.numberator > 0)
                return "-" + this.numberator;
            if (this.numberator < 0)
                return (-this.numberator) + "";
        }
        else if (this.numberator * this.denominator > 0)
            return Math.abs(this.numberator) + "/" + Math.abs(this.denominator);
        return "-" + Math.abs(this.numberator) + "/" + Math.abs(this.denominator);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numb, den;
        System.out.println("Nhap phan so 1:");
        System.out.print("Nhap tu so: ");
        numb = sc.nextInt();
        System.out.print("Nhap mau so: ");
        den = sc.nextInt();
        Fraction f1 = new Fraction(numb, den);
        System.out.println("Nhap phan so 2:");
        System.out.print("Nhap tu so: ");
        numb = sc.nextInt();
        System.out.print("Nhap mau so: ");
        den = sc.nextInt();
        System.out.println("");
        Fraction f2 = new Fraction(numb, den);
        System.out.println(f1 + " + " + f2 + " = " + f1.add(f2));
        System.out.println(f1 + " - " + f2 + " = " + f1.sub(f2));
        System.out.println(f1 + " * " + f2 + " = " + f1.mul(f2));
        System.out.println(f1 + " / " + f2 + " = " + f1.div(f2));
        System.out.print(f1 + "-- = ");
        f1.reducer();
        System.out.println(f1);
        System.out.print(f2 + "-- = ");
        f2.reducer();
        System.out.println(f2);
    }
}

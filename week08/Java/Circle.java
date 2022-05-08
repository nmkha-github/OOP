package Lab6_Inheritance;

public class Circle {
    protected double radius;
    protected String color;

    public Circle() {
        this.radius = 1;
        this.color = "red";
    }

    public Circle(double radius) {
        this.radius = radius;
        this.color = "red";
    }

    public Circle(double radius, String color) {
        this.radius = radius;
        this.color = color;
    }

    public double getRadius() {
        return this.radius;
    }

    public String getColor() {
        return this.color;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public void setColor(String color) {
        this.color = color;
    }
    
    public double getArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }

    @Override
    public String toString() {
        return "Cirlce{radius =  " + this.radius + ", color = " + this.color + "}"; 
    }

    public static void main(String[] args){
        Circle a = new Circle(3, "blue");
        System.out.println(a.toString());
        System.out.println("Area = " + a.getArea());

        System.out.println("Change radius = 5 and color = yellow");
        a.setRadius(5);
        a.setColor("yellow");
        System.out.println(a.toString());
        System.out.println("Area = " + a.getArea());
    }
}
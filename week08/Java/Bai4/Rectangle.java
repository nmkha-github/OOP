package Bai4;
public class Rectangle extends Shape{
    private double width, length;
    Rectangle(){
        this.width = 1.0;
        this.length = 1.0;
    }
    Rectangle(double width, double length){
        this.width = width;
        this.length = length;
    }
    Rectangle(double width, double length, String color, boolean filled){
        this.width = width;
        this.length = length;
        setColor(color);
        setFilled(filled);
    }
    double getWidth(){
        return width;
    }
    void setWidth(double width){
        this.width = width;
    }
    double getLength(){
        return length;
    }
    void setLength(double length){
        this.length = length;
    }
    double getArea(){
        return this.length * this.width;
    }
    double getPerimeter(){
        return 2 * (this.length + this.width);
    }
    @Override
    public String toString(){
        return "Rectangle{width= " + width + ", height= " + length + ", color= " + getColor() + "}";
    }
    public static void main(String[] args) {
        Rectangle r = new Rectangle(12.3, 13.4);
        System.out.println(r);
    }
}
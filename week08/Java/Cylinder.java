package Lab6_Inheritance;

public class Cylinder extends Circle{
    private double height;

    public Cylinder(){
        super();
        this.height = 1;
    }
    
    public Cylinder(double radius){
        super(radius);
        this.height = 1;
    }

    public Cylinder(double radius, double height){
        super(radius);
        this.height = height;
    }

    public Cylinder(double radius, double height, String color){
        super(radius, color);
        this.height = height;
    }

    public double getHeight(){
        return this.height;
    }

    public void setHeight(double height){
        this.height = height;
    }

    public double getVolume(){
        return super.getArea()*this.height;
    }

    @Override
    public String toString(){
        return "Cylinder{" + super.toString() + ", height: " + height + "}";
    }

    public static void main(String[] args){
        Cylinder a = new Cylinder();
        System.out.println(a.toString());
        System.out.println("Volume = " + a.getVolume());

        Cylinder b = new Cylinder(2, 10, "orange");
        System.out.println(b.toString());
        System.out.println("Volume = " + b.getVolume());
    }
}


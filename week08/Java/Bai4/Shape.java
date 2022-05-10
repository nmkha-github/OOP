
public class Shape {
    private String color;
    private boolean filled;

    Shape() {
        this.color = "red";
        this.filled = true;
    }

    Shape(String color, boolean filled) {
        this.color = color;
        this.filled = filled;
    }

    String getColor() {
        return this.color;
    }

    void setColor(String color) {
        this.color = color;
    }

    Boolean isFilled() {
        return this.filled;
    }

    void setFilled(Boolean filled) {
        this.filled = filled;
    }

    @Override
    public String toString() {
        return "Shape{" + "color= " + color + ", " + "isFilled=" + filled + "}";
    }

    public static void main(String[] args) {
        Shape a = new Shape();
        System.out.println(a);
    }
}
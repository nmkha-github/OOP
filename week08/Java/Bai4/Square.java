
public class Square extends Rectangle {
    Square() {
    }

    Square(double side) {
        setLength(side);
        setWidth(side);
    }

    Square(double side, String color, boolean filled) {
        setLength(side);
        setWidth(side);
        setColor(color);
        setFilled(filled);
    }

    double getSide() {
        return getWidth();
    }

    void setSide(double side) {
        setWidth(side);
        setLength(side);
    }

    @Override
    public String toString() {
        return "Square{" + getSide() + ", " + getColor() + ", " + isFilled() + "}";
    }

    public static void main(String[] args) {
        Square square = new Square(3, "Blue", false);
        System.out.println(square);
    }
}

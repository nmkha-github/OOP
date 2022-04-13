import java.util.Scanner;

public class Point2D{
    float x, y;
    Point2D(){
        this.y = this.x = 0.0f;
    }
    Point2D(float x, float y) {
        this.x = x;
        this.y = y;
    }
    Point2D(Point2D p){
        this.x = p.x;
        this.y = p.y;
    }
    public float getX() {
        return x;
    }
    public float getY() {
        return y;
    }
    public void setX(float x) {
        this.x = x;
    }
    public void setY(float y) {
        this.y = y;
    }
    @Override
    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap hoanh do diem x = ");
        float x = sc.nextFloat();
        System.out.print("Nhap tung do diem y = ");
        float y = sc.nextFloat();
        Point2D A = new Point2D(x, y);
        System.out.println("\nToa do diem vua nhap: " + A);
        System.out.println("Hoanh do x = " + A.getX());
        System.out.println("Tung do y = " + A.getY());

        System.out.print("\nNhap hoanh do can thay doi x = ");
        x = sc.nextFloat();
        A.setX(x);
        System.out.println("Toa do diem thay doi: " + A);

        System.out.print("\nnNhap tung do can thay doi y = ");
        y = sc.nextFloat();
        A.setY(y);
        System.out.println("Toa do diem thay doi: " + A);
    }
}

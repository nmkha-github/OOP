public class Point3D extends Point2D{
    protected float z;
    public Point3D(){
        this.z = 0;
    }
    public Point3D(float x, float y, float z){
        setXY(x, y);
        this.z = z;
    }
    public float getZ(){
        return this.z;
    }
    public void setZ(float z){
        this.z = z;
    }
    public float[] getXYZ(){
        return new float[] {this.x, this.y, this.z};
    }
    public void setXYZ(float x, float y, float z){
        this.x = x;
        this.y = y;
        this.z = z;
    }
    @Override
    public String toString(){
        return "(" + this.x + ", " + this.y + ", " + this.z + ")";
    }
    public static void main(String[] args) {
        Point3D a = new Point3D();
        System.out.println(a);
    }
}
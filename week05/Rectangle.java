
public class Rectangle
 {
     private
     float width;
     float length;
     public
     Rectangle()
     {
         this.width=1.0f;
         this.length=1.0f;
     }

     Rectangle(float width,float length)
     {
         this.width=width;
         this.length=length;
     }

     public float getLength()
    {
         return length;
     }

     public float getWidth() 
     {
         return width;
     }

     public void setLength(float length) 
     {
         this.length = length;
     }

     public void setWidth(float width) 
     {
         this.width = width;
     }

     public String toString()
     {
         String a="Rectangle["+this.width+","+this.length+"]";
        return a;
     }
     

    public static void main(String[] args) throws Exception {
        Rectangle ABCD=new Rectangle(5,10);
        System.out.println(ABCD.toString());
    }
}

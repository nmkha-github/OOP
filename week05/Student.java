package Lab4;
import java.util.Scanner;

public class Student {
    private int id;
    private String firstName;
    private String lastName;

    public Student(int id, String firstName, String lastName){
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public int getID(){
        return this.id;
    }

    public String getFirstName(){
        return this.firstName;
    }

    public String getLastName(){
        return this.lastName;
    }

    public void setID(int ID){
        this.id = ID;
    }

    public void setFirstName(String firstName){
        this.firstName = firstName;
    }

    public void setLastName(String lastName){
        this.lastName = lastName;
    }

    public String getName(){
        return "Name: " + this.firstName + " " + this.lastName;
    }

    public String toString(){
        return "Student[id=" + this.id + ", firstName=" + this.firstName + ", lastName=" + this.lastName + "]";
    }

    public static void main(String[] args){
        Student s1 = new Student(20120252,"Anh", "Pham");
        Student s2;
        Scanner sc = new Scanner(System.in);
        System.out.println("id=");
        int id = Integer.parseInt(sc.nextLine());
        
        System.out.println("fistName=");
        String fn = sc.nextLine();
        
        System.out.println("lastName=");
        String ln = sc.nextLine();
        sc.close();

        s2 = new Student(id,fn,ln);
        System.out.println(s1);
        System.out.println(s2);
    }
}

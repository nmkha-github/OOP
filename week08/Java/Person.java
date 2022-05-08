package Lab6_Inheritance;

public class Person {
    protected String name;
    protected String address;

    public Person(){
        this.name = "";
        this.address = "";
    }

    public Person(String name, String address){
        this.name = name;
        this.address = address;
    }

    public String getName() {
        return this.name;
    }

    public String getAddress() {
        return this.address;
    }

    public void setAddress(String address){
        this.address = address;
    }

    @Override
    public String toString(){
        return "Person{name = " + name + ", address = " + address + "}";
    }
}
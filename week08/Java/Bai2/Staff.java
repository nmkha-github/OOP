
public class Staff extends Person {
    private String school;
    private double pay;

    public Staff(String name, String address, String school, double pay) {
        super(name, address);
        this.school = school;
        this.pay = pay;
    }

    public String getSchool() {
        return this.school;
    }

    public void setSchool(String school) {
        this.school = school;
    }

    public double getPay() {
        return this.pay;
    }

    public void setPay(double pay) {
        this.pay = pay;
    }

    @Override
    public String toString() {
        return "Staff{" + super.toString() + ", school = " + school + ", pay = " + pay + "}";
    }

    public static void main(String[] args) {
        Staff a = new Staff("Nguyen Van A", "36 Cong Hoa, p.4, q.Tan Binh, tp.HCM", "DH Khoa hoc Tu nhien", 5000000);
        System.out.println(a.toString());
    }
}

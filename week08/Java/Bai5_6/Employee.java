
public class Employee {
    private String ID;
    String fullName;
    int yearJoined;
    double coefficientsSalary;
    int numDaysOff;

    public Employee() {
        this.ID = "0";
        this.fullName = "";
        this.yearJoined = 2020;
        this.coefficientsSalary = 1.0;
        this.numDaysOff = 0;
    }

    Employee(String ID1, String fullName1, double coefficientsSalary1) {
        this.ID = ID1;
        this.fullName = fullName1;
        this.yearJoined = 2020;
        this.coefficientsSalary = coefficientsSalary1;
        this.numDaysOff = 0;
    }

    Employee(String ID1, String fullName1, int yearJoined1, double coefficientsSalary1, int numDaysOff1) {
        this.ID = ID1;
        this.fullName = fullName1;
        this.yearJoined = yearJoined1;
        this.coefficientsSalary = coefficientsSalary1;
        this.numDaysOff = numDaysOff1;
    }

    public String getID() {
        return ID;
    }

    public void setID(String iD) {
        ID = iD;
    }

    public String getFullName() {
        return fullName;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public int getYearJoined() {
        return yearJoined;
    }

    public void setYearJoined(int yearJoined) {
        this.yearJoined = yearJoined;
    }

    public double getCoefficientsSalary() {
        return coefficientsSalary;
    }

    public void setCoefficientsSalary(double coefficientsSalary) {
        this.coefficientsSalary = coefficientsSalary;
    }

    public int getNumDaysOff() {
        return numDaysOff;
    }

    public void setNumDaysOff(int numDaysOff) {
        this.numDaysOff = numDaysOff;
    }

    public double getSenioritySalary() {
        if (2022 - yearJoined >= 5) {
            return coefficientsSalary = coefficientsSalary / 100 * (2022 - yearJoined);
        }
        return coefficientsSalary;

    }

    public String considerEmulation() {
        if (numDaysOff <= 1)
            return "Grade A";
        if (numDaysOff <= 2)
            return "Grade B";
        if (numDaysOff > 3)
            return "Grade C";
        return "";
    }

    public double getSalary() {
        double salary = 1150;
        if (numDaysOff <= 1)
            return salary + salary * (this.coefficientsSalary * 1.0f) + this.getSenioritySalary();
        if (numDaysOff <= 2)
            return salary + salary * (this.coefficientsSalary * 0.75f) + this.getSenioritySalary();
        if (numDaysOff > 3)
            return salary + salary * (this.coefficientsSalary * 0.5f) + this.getSenioritySalary();
        return salary;
    }

    public class Manager extends Employee {
        private String Position;
        String Department;
        double salaryCoefficientPosition;

        public Manager() {
            this.setID("0");
            this.setFullName("");
            this.setYearJoined(2020);
            this.setCoefficientsSalary(1.0);
            this.setNumDaysOff(0);
            this.Position = "Head of the office";
            this.Department = "Administrative office";
            this.salaryCoefficientPosition = 5.0;
        }

        Manager(String ID1, String fullName1, double coefficientsSalary1, String Position1,
                double salaryCoefficientPosition1) {
            this.setID(ID1);
            this.setFullName(fullName1);
            this.setYearJoined(2020);
            this.setCoefficientsSalary(coefficientsSalary1);
            this.setNumDaysOff(0);
            this.Position = Position1;
            this.Department = "";
            this.salaryCoefficientPosition = salaryCoefficientPosition1;

        }

        Manager(String ID1, String fullName1, int yearJoined1, double coefficientsSalary1, int numDaysOff1,
                String Position1, String Department1, double salaryCoefficientPosition1) {
            this.setID(ID1);
            this.setFullName(fullName1);
            this.setYearJoined(yearJoined1);
            this.setCoefficientsSalary(coefficientsSalary1);
            this.setNumDaysOff(numDaysOff1);
            this.Position = Position1;
            this.Department = Department1;
            this.salaryCoefficientPosition = salaryCoefficientPosition1;
        }

        public String considerEmulation() {
            return "Grade A";
        }

        public double bonusByPosition() {
            return 1150 * this.salaryCoefficientPosition;
        }

        public double getSalary() {
            return 1150 + 1150 * (this.coefficientsSalary + 1.0) + this.getSenioritySalary() + this.bonusByPosition();
        }

    }

    public static void main(String[] args) {
        Employee a = new Employee("20120244", "Hoang Tuan Anh", 2020, 0.5, 0);
        System.out.println(a.fullName);
    }
}

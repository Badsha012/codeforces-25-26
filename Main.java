class Student {
    String name;
    int roll;

    // Constructor to initialize Student attributes
    public Student(String name, int roll) {
        this.name = name;
        this.roll = roll;
    }
}

class Result extends Student {
    double marks;

    // Constructor calls the superclass constructor
    public Result(String name, int roll, double marks) {
        super(name, roll);
        this.marks = marks;
    }

    // Method to display all information
    public void display() {
        System.out.println("--- Student Information ---");
        System.out.println("Name: " + name);
        System.out.println("Roll: " + roll);
        System.out.println("Marks: " + marks);
    }
}

public class Main {
    public static void main(String[] args) {
        Result studentResult = new Result("Alayna", 101, 85.5);
        studentResult.display();
    }
}
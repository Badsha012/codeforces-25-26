import java.util.Scanner;


class Person {
    protected String name;
    protected int age;
    protected String address;


    public Person(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    
    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
    }
}


class Student extends Person {
    private int rollNumber;
    private String department;
    private double marks;

  
    public Student(String name, int age, String address,
                   int rollNumber, String department, double marks) {
        super(name, age, address);
        this.rollNumber = rollNumber;
        this.department = department;
        this.marks = marks;
    }

    
    public String calculateGrade() {
        if (marks >= 80) return "A+";
        else if (marks >= 70) return "A";
        else if (marks >= 60) return "B";
        else if (marks >= 50) return "C";
        else return "F";
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Department: " + department);
        System.out.println("Marks: " + marks);
        System.out.println("Grade: " + calculateGrade());
    }
}


class Teacher extends Person {
    private int teacherID;
    private String subject;
    private double salary;


    public Teacher(String name, int age, String address,
                   int teacherID, String subject, double salary) {
        super(name, age, address);
        this.teacherID = teacherID;
        this.subject = subject;
        this.salary = salary;
    }

    
    public double calculateSalary() {
        double bonus = salary * 0.10; 
        return salary + bonus;
    }

    
    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Teacher ID: " + teacherID);
        System.out.println("Subject: " + subject);
        System.out.println("Base Salary: " + salary);
        System.out.println("Total Salary (with bonus): " + calculateSalary());
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        
        System.out.println("Enter Student Information:");
        System.out.print("Name: ");
        String sName = sc.nextLine();
        System.out.print("Age: ");
        int sAge = sc.nextInt();
        sc.nextLine();
        System.out.print("Address: ");
        String sAddress = sc.nextLine();
        System.out.print("Roll Number: ");
        int roll = sc.nextInt();
        sc.nextLine();
        System.out.print("Department: ");
        String dept = sc.nextLine();
        System.out.print("Marks: ");
        double marks = sc.nextDouble();

        Student student = new Student(sName, sAge, sAddress, roll, dept, marks);

        System.out.println("\n----------------------");

      
        sc.nextLine(); 
        System.out.println("Enter Teacher Information:");
        System.out.print("Name: ");
        String tName = sc.nextLine();
        System.out.print("Age: ");
        int tAge = sc.nextInt();
        sc.nextLine();
        System.out.print("Address: ");
        String tAddress = sc.nextLine();
        System.out.print("Teacher ID: ");
        int tID = sc.nextInt();
        sc.nextLine();
        System.out.print("Subject: ");
        String subject = sc.nextLine();
        System.out.print("Salary: ");
        double salary = sc.nextDouble();

        Teacher teacher = new Teacher(tName, tAge, tAddress, tID, subject, salary);

        System.out.println("\n========= STUDENT DETAILS =========");
        student.displayInfo();

        System.out.println("\n========= TEACHER DETAILS =========");
        teacher.displayInfo();

        sc.close();
    }
}
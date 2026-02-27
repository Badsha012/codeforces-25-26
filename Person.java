
class Person {
    protected String name;
    protected int age;

  
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

   
    public void disp() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}


class Student extends Person {
    private double grade;

   
    public Student(String name, int age, double grade) {
        super(name, age);
        this.grade = grade;
    }

  
    public void performance() {
        System.out.println("Grade: " + grade);
        if (grade >= 90) {
            System.out.println("Performance: Excellent");
        } 
        else if (grade >= 75) {
            System.out.println("Performance: Good");
        } 
        else {
            System.out.println("Performance: Needs Improvement");
        }
    }
}


class Teacher extends Person {
    private String[] subjects;

 
    public Teacher(String name, int age, String[] subjects) {
        super(name, age);
        this.subjects = subjects;
    }

    
    public void displaySubjects() {
        System.out.println("Subjects Taught:");
        for (int i = 0; i < subjects.length; i++) {
            System.out.println((i + 1) + ". " + subjects[i]);
        }
    }
}


public class Main {
    public static void main(String[] args) {

        Student s1 = new Student("Rahim", 18, 92);
        Student s2 = new Student("Karim", 19, 80);
        Student s3 = new Student("Ayesha", 17, 70);

      
        String[] sub1 = {"Math", "Physics", "ICT"};
        String[] sub2 = {"English", "History", "Geography", "Civics", "Literature"};

        Teacher t1 = new Teacher("Mr. Hasan", 40, sub1);
        Teacher t2 = new Teacher("Ms. Sara", 35, sub2);

        System.out.println("===== STUDENT DETAILS =====");
        s1.disp();
        s1.performance();
        System.out.println();

        s2.disp();
        s2.performance();
        System.out.println();

        s3.disp();
        s3.performance();
        System.out.println();

        System.out.println("===== TEACHER DETAILS =====");
        t1.disp();
        t1.displaySubjects();
        System.out.println();

        t2.disp();
        t2.displaySubjects();
    }
}
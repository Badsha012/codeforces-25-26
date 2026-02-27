class Person {
    Person() {
        System.out.println("Person created");
    }
}

class Teacher extends Person {
    Teacher() {
        System.out.println("Teacher created");
    }
}

public class Start {
    public static void main(String[] args) {
        Teacher t = new Teacher();
    }
}
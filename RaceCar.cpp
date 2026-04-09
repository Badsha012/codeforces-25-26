// Step 1: Abstract class
abstract class RaceCar {
    protected String modelName;     // model name
    private int enginePower;        // private field

    // Constructor
    public RaceCar(String modelName, int enginePower) {
        this.modelName = modelName;
        this.enginePower = enginePower;
    }

    // Getter for enginePower
    public int getEnginePower() {
        return enginePower;
    }

    // Abstract method
    abstract void displayInfo();
}

// Step 2: FormulaCar subclass
class FormulaCar extends RaceCar {

    public FormulaCar(String modelName, int enginePower) {
        super(modelName, enginePower);
    }

    // Implement abstract method
    void displayInfo() {
        System.out.println("Formula Car Model: " + modelName);
        System.out.println("Engine Power: " + getEnginePower() + " HP");
        System.out.println();
    }
}

// Step 3: SportsCar subclass
class SportsCar extends RaceCar {

    public SportsCar(String modelName, int enginePower) {
        super(modelName, enginePower);
    }

    // Implement abstract method
    void displayInfo() {
        System.out.println("Sports Car Model: " + modelName);
        System.out.println("Engine Power: " + getEnginePower() + " HP");
        System.out.println();
    }
}

// Step 4: Main class
public class Main {
    public static void main(String[] args) {

        // Creating objects
        FormulaCar f1 = new FormulaCar("Ferrari F1-75", 1000);
        SportsCar s1 = new SportsCar("Lamborghini Aventador", 770);

        // Calling displayInfo()
        f1.displayInfo();
        s1.displayInfo();
    }
}
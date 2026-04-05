// Step A: Create an abstract class
abstract class RaceCar {
    protected String modelName;
    // Private field for engine power (Encapsulation)
    private int enginePower;

    public RaceCar(String modelName, int enginePower) {
        this.modelName = modelName;
        this.enginePower = enginePower;
    }

    // Getter method to allow subclasses to access the private enginePower
    public int getEnginePower() {
        return enginePower;
    }

    // Abstract method to be implemented by subclasses
    public abstract void displayInfo();
}

// Step B: Create FormulaCar subclass
class FormulaCar extends RaceCar {
    public FormulaCar(String modelName, int enginePower) {
        super(modelName, enginePower);
    }

    @Override
    public void displayInfo() {
        System.out.println("--- Formula Car Details ---");
        System.out.println("Model Name  : " + modelName);
        System.out.println("Engine Power: " + getEnginePower() + " HP");
        System.out.println();
    }
}

// Step B: Create SportsCar subclass
class SportsCar extends RaceCar {
    public SportsCar(String modelName, int enginePower) {
        super(modelName, enginePower);
    }

    @Override
    public void displayInfo() {
        System.out.println("--- Sports Car Details ---");
        System.out.println("Model Name  : " + modelName);
        System.out.println("Engine Power: " + getEnginePower() + " HP");
        System.out.println();
    }
}

// Step C & D: Main class to instantiate and display objects
public class RaceCarDemo {
    public static void main(String[] args) {
        // Create one FormulaCar object
        RaceCar f1 = new FormulaCar("Red Bull RB20", 1000);

        // Create one SportsCar object
        RaceCar gt = new SportsCar("Lamborghini Huracán", 640);

        // Call their displayInfo() methods
        f1.displayInfo();
        gt.displayInfo();
    }
}
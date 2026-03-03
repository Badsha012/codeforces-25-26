import java.util.Scanner;

public class AmoguConverter {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the number of test cases
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                String w = sc.next();
                
                // Remove the last 2 characters ("us") and add "i"
                String plural = w.substring(0, w.length() - 2) + "i";
                
                System.out.println(plural);
            }
        }
        sc.close();
    }
}
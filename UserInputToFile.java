import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class UserInputToFile {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter your Name: ");
        String name = sc.nextLine();
        
        System.out.print("Enter your Phone: ");
        String phone = sc.nextLine();
        
        // "true" দেওয়ার কারণে আগের লেখা মুছবে না, নিচে নিচে নতুন লেখা যোগ হবে (Append)
        try {
            FileWriter fw = new FileWriter("user_info.txt", true); 
            fw.write("Name: " + name + ", Phone: " + phone + "\n");
            fw.close(); // ফাইল বন্ধ করা জরুরি
            
            System.out.println("Data saved successfully in user_info.txt!");
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
        
        sc.close();
    }
}
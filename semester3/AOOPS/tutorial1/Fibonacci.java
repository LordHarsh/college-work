// Java program to print the Fibonacci series up to a given number of terms
import java.util.Scanner;
public class Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of terms: ");
        int n = sc.nextInt();
        int a = 0, b = 1, c;
        System.out.println("The Fibonacci series is: ");
        System.out.print(a + " " + b);
        for (int i = 3; i <= n; i++) {
            c = a + b;
            System.out.print(" " + c);
            a = b;
            b = c;
        }
    }
}

// Java program to find sum of two numbers
import java.util.Scanner;

class SumTwo {
    public static void main(String args[]) {
        int a, b, sum;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
        a = sc.nextInt();
        System.out.print("Enter second number: ");
        b = sc.nextInt();
        sum = a + b;
        System.out.println("Sum of two numbers: " + sum);
    }
}
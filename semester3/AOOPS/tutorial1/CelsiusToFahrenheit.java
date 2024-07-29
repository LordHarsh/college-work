// Java program to convert temperature from Celsius to Fahrenheit
import java.util.Scanner;
public class CelsiusToFahrenheit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the temperature in Celsius: ");
        double celsius = sc.nextDouble();
        double fahrenheit = (celsius * 9 / 5) + 32;
        System.out.printf("The temperature in Fahrenheit is %.2f degrees.", fahrenheit);
    }
}

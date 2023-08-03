// Java program to compute the area of a circle
import java.util.Scanner;
public class CircleArea {
    public static void main(String[] agrs){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        double radius = sc.nextDouble();
        double area = Math.PI * radius * radius;
        System.out.printf("The area of the circle is %.2f sq. units", area);
    }
}

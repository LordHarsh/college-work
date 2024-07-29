//Write a java program to find sum of the ascii values of each character
import java.util.*;
public class SumAscii {
    public static void main(String[] args) {
        System.out.println("Enter a string: ");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int sum = 0;
        for(int i=0; i<str.length(); i++){
            sum += (int)str.charAt(i);
        }
        System.out.println("Sum of ascii values: " + sum);
        sc.close();
    }
}

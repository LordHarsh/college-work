// Write a java program to find sum of the second last digits of given given three numbers
import java.util.*;
public class SumLastSecondDigit {
    public static void main(String agrs[]){
        System.out.println("Enter three numbers: ");
        Scanner sc = new Scanner(System.in);
        int[] numbers = new int[3];
        for(int i=0; i<3; i++){
            numbers[i] = sc.nextInt();
        }
        int sum = 0;
        for(int i=0; i<3; i++){
            int num = numbers[i];
            num = num / 10;
            int secondLastDigit = num % 10;
            sum += secondLastDigit;
        }
        System.out.println("Sum of the second last digits of the given numbers: " + sum);
        sc.close();
    }
}

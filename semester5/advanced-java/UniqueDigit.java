// Write a java program to find the unique digit in the given number
import java.util.*;
public class UniqueDigit {
    public static void main(String[] args) {
        System.out.println("Enter a number: ");
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int[] digits = new int[10];
        while(number > 0){
            int digit = number % 10;
            digits[digit]++;
            number = number / 10;
        }
        for(int i=0; i<10; i++){
            if(digits[i] == 1){
                System.out.println("Unique digit: " + i);
                break;
            }
        }
        sc.close();
    }
}

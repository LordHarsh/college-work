// write a java program to find the sum of even digits in a given number
import java.util.*;
class SumEvenDigits {
    public static void main(String agrs[]){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int sum = 0;
        while (num != 0){
            if((num%10)%2 == 0)
                sum = sum + (num%10); //12 5
            num = num/10;
        }
        System.out.println("Sum is: "+ sum);
        sc.close();
    }
}
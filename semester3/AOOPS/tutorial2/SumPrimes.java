// JAVA program to find the sum of all primes that are not greater than N.
import java.util.Scanner;
public class SumPrimes {
    public static void main(String[] agrs){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of N: ");
        int N = sc.nextInt();
        int sum = 0;
        for (int i = 2; i <= N; i++) {
            int flag = 0;
            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                sum += i;
            }
        }
        System.out.println("The sum of all primes that are not greater than " + N + " is " + sum);
    }
}

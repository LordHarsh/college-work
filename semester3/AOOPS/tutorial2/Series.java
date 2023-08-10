// JAVA program to calculate the Sum of series (1 + 2+ 3+ ….. n,
// 1+1/2+1/3+……1/n, 1^2 + 2^2+ 3^2 +……n^2.
import java.util.Scanner;
public class Series {
    public static void main(String[] agrs) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        System.out.printf("The sum of the series 1 + 2 + 3 + ... + %d is %d\n", n, sum);
        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += 1.0/i;
        }
        System.out.printf("The sum of the series 1 + 1/2 + 1/3 + ... + 1/%d is %f\n", n, sum);
        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i*i;
        }
        System.out.printf("The sum of the series 1^2 + 2^2 + 3^2 + ... + %d^2 is %d\n", n, sum);
    }
}

// JAVA program to construct the following pattern, using a nested for loop. 
//        * 
//       * * 
//      * * *
//     * * * * 
//    * * * * *
import java.util.Scanner;
public class Pattern {
    public static void main(String agrs[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            for (int j = n - i; j > 0; j--) {
                System.out.print(" ");
            }
            for (int k = 1; k <= i; k++) {
                System.out.print("* ");
            }
            System.out.print("\n");
        }
    }
}

// You are given an array A of size N that contains integers. Here, N is an even number. 
// You are required to perform the following operations
// a) Take the first digit of every number
// b) Generate a number by using the digits
// c) Reverse the number
// d) Print the newly generated number divisible by 5
import java.util.Scanner;
public class DigitManupilation {
    int firstDigit(int num) {
        while(num > 9) {
            num /= 10;
        }
        return num;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DigitManupilation obj = new DigitManupilation();
        System.out.print("Enter the number of elements in the array: ");
        int N = sc.nextInt();
        int[] A = new int[N];
        int[] firstDigitArr = new int[N];
        System.out.print("Enter the elements of the array: ");
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            firstDigitArr[i] = obj.firstDigit(A[i]);
        }
        int newNum = 0;
        for (int i = N-1; i >= 0; i--) {
            newNum = newNum * 10 + firstDigitArr[i];
        }
        if (newNum % 5 == 0) {
            System.out.printf("The new number %d is divisible by 5", newNum);
        } else {
            System.out.printf("The new number %d is not divisible by 5", newNum);
        }
    }
}

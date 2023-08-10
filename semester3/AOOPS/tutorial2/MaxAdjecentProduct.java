// program that reads an array of integers and outputs the maximum product of
// two adjacent elements in the given array of numbers
import java.util.Scanner;
public class MaxAdjecentProduct {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int maxProduct = arr[0] * arr[1];
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] * arr[i + 1] > maxProduct) {
                maxProduct = arr[i] * arr[i + 1];
            }
        }
        System.out.println("The maximum product of two adjacent elements in the given array of numbers is " + maxProduct);
    }
}
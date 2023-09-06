// program to find the percentage of uppercase letters, lowercase letters, digits and 
// special characters in a given string. Not to use length ( ) function.
import java.util.Scanner;
public class StringDetail {
    public static void main(String agrs[]){
        System.out.print("Enter the string: ");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        char[] charArr = str.toCharArray();
        int count = 0;
        int upper = 0, lower = 0, digit = 0, special = 0;
        for (char ch: charArr ) {
            count++;
            if (ch >= 65 && ch <= 90) {
                upper++;
            } else if (ch >= 97 && ch <= 122) {
                lower++;
            } else if (ch >= 48 && ch <= 57) { 
                digit++;
            } else {
                special++;
            }
        }
        System.out.println("The percentage of uppercase letters in the given string is " + (upper * 100) / count + "%");
        System.out.println("The percentage of lowercase letters in the given string is " + (lower * 100) / count + "%");
        System.out.println("The percentage of digits in the given string is " + (digit * 100) / count + "%");
        System.out.println("The percentage of special characters in the given string is " + (special * 100) / count + "%");
    }
}

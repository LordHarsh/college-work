// JAVA program to check the validity of password input by users. Validation:
// a) At least 1 letter between [a-z] and 1 letter between [A-Z]. 
// b) At least 1 number between [0-9]. 
// c) At least 1 character from [$#@]. 
// d) Minimum length 6 characters. 
// e) Maximum length 16 characters.
import java.util.Scanner;
public class Password {
    public static void main(String[] agrs){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the password: ");
        String password = sc.nextLine();
        int upper = 0, lower = 0, digit = 0, special = 0;
        if (password.length() >= 6 && password.length() <= 16) {
            for (int i = 0; i < password.length(); i++) {
                char ch = password.charAt(i);
                if (ch >= 65 && ch <= 90) {
                    upper++;
                } else if (ch >= 97 && ch <= 122) {
                    lower++;
                } else if (ch >= 48 && ch <= 57) {
                    digit++;
                } else if (ch == '$' || ch == '#' || ch == '@') {
                    special++;
                }
            }
            if (upper >= 1 && lower >= 1 && digit >= 1 && special >= 1) {
                System.out.println("The password is valid.");
            } else {
                System.out.println("The password is invalid.");
            }
        } else {
            System.out.println("The password is invalid.");
        }
    }
}

// Write a java program to find sum of the ascii values of vowels only
import java.util.*;
public class SumVowels {
    public static void main(String[] args) {
        System.out.println("Enter a string: ");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int sum = 0;
        for(int i=0; i<str.length(); i++){
            char ch = str.charAt(i);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
                sum += (int)ch;
            }
        }
        System.out.println("Sum of ascii values of vowels: " + sum);
        sc.close();
    }
}

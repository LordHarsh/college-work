// JAVA program to find numbers between 100 and 400 (both included) where 
// each digit of a number is an even number. The numbers obtained should be printed in 
// a comma-separated sequence
public class EvenNumbers {
    public static void main(String[] agrs){
        for (int i = 100; i <= 400; i++) {
            int num = i;
            boolean isEven = true;
            while (num > 0) {
                int digit = num % 10;
                if (digit % 2 != 0) {
                    isEven = false;
                    break;
                }
                num /= 10;
            }
            if (isEven) {
                System.out.printf("%d, ", i);
            }
        }
    }
}

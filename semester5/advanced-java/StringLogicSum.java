//Write a java program to find sum of the ascii values of each character
import java.util.*;
public class StringLogicSum {
    public static void main(String[] args) {
        System.out.println("Enter a string: ");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int sum = 0;
        str = str.toUpperCase();
        for(int i=0; i<str.length(); i++){
            sum += ((int)str.charAt(i) - 64);
        }
        System.out.println("Sum of ascii values: " + sum);
        sc.close();
    }
}


// ./mvnw spring-boot:run  -Dspring-boot.run.arguments="--AUTH0_CLIENT_ID=s2ZvbjNwz2r2X9UmcTbvyNVt6LpoeLQR --AUTH0_CLIENT_SECRET=QJU8bXUblqEMcZe4BydZZ-a_bCDiVBVcvzCBog6TVN9NLtnv5nn5OBjMaZHdO_lT"
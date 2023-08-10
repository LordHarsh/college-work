// JAVA program to convert month name to a number of days

import java.util.Scanner;

public class MonthNames {
    public static void main(String[] agrs) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the month");
        String name = sc.next().toLowerCase();
        switch (name) {
            case "january":
            case "march":
            case "may":
            case "july":
            case "august":
            case "october":
            case "december":
                System.out.println("There are 31 days in " + name);
                break;
            case "april":
            case "june":
            case "september":
            case "november":
                System.out.println("There are 30 days in " + name);
                break;
            case "february":
                System.out.println("There are 28 days in " + name);
                break;
            default:
                System.out.println("Invalid month name");
        }

    }
}


public class FindSum {
    public static void main(String agrs[]){
        int arr1[] = new int[]{0, 2, 5, 4};
        int arr2[] = new int[]{9, 2, 6};
        int t = 6;
        int num1 = 0;
        int num2 = 0;
        for (int i = arr1.length-1; i >= 0; i--){
            num1 = num1*10 + arr1[i];
        }
        for (int i = arr2.length-1; i >= 0; i--){
            num2 = num2*10 + arr2[i];
        }
        System.out.println(num1+num2);
    }    
}

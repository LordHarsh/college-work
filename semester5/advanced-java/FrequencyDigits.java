import java.io.*;
public class FrequencyDigits {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter a number: ");
        String str = br.readLine();
        int[] freq = new int[10];
        for(int i=0; i<str.length(); i++){
            freq[str.charAt(i) - '0']++;
        }
        for(int i=0; i<10; i++){
            if(freq[i] != 0){
                System.out.println("Frequency of " + i + ": " + freq[i]);
            }
        }
    }
}

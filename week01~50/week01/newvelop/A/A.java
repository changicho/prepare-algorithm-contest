import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
 
public class Main {
public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        for (int i = 0; i < count; i++) {
            Integer[] arr = Arrays.stream(br.readLine().split(" ")).map(v -> Integer.parseInt(v)).toArray(Integer[]::new);
            boolean isValid = arr[0] <= arr[1] && arr[1] % arr[0] == 0;
            int b = (int) (arr[1] / arr[0]);
 
            if (isValid) {
                System.out.println("1 " + b);
            } else {
                System.out.println("0 0");
            }
        }
}
}
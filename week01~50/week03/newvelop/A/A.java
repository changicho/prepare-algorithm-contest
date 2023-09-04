
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int total = Integer.parseInt(br.readLine());
        for (int t = 0; t < total; t++) {
            br.readLine();
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            int odd = 0;
            int even = 0;
            for (int n : arr) {
                if (n % 2 == 0) {
                    even++;
                } else {
                    odd++;
                }
            }
            System.out.println(Math.min(odd, even));
        }
    }
}

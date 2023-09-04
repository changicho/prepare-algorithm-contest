
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class G {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 0; t < tcase; t++) {
            long[] input = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
            long[] arr = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
            int result = 0;
            for (int i = 0; i < arr.length - input[1]; i++) {
                int index = i + 1;
                while (index < arr.length && arr[index - 1] < arr[index] * 2) {
                    index++;
                }

                if (index - i > input[1]) {
                    result += (index - i - input[1]);
                }
                i = index - 1;
            }
            System.out.println(result);
        }
    }
}

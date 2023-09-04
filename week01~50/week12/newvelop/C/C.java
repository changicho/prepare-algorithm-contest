
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            Integer n = Integer.parseInt(br.readLine());
            String s = "";
            int cur = 9;
            while (n > 0) {
                if (n <= cur) {
                    s = n + s;
                    n = 0;
                } else {
                    n -= cur;
                    s = cur + s;
                    cur --;
                }
            }
            System.out.println(s);
        }
    }
}

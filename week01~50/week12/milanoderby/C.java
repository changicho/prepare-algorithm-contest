import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            int s = Integer.parseInt(br.readLine());

            StringBuilder answer = new StringBuilder();
            for (int j = 9; j >= 1; j--) {
                if (s == 0) {
                    break;
                }

                if (j <= s) {
                    s -= j;
                    answer.append(j);
                }
            }

            bw.write(answer.reverse() + "\n");
        }
        bw.flush();
    }
}


import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.List;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File("a.txt")), StandardCharsets.UTF_8));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            int size = Integer.parseInt(br.readLine());
            char[][] resultArr = new char[size][size];
            char[] in = br.readLine().toCharArray();
            char[] out = br.readLine().toCharArray();

            for (int i = 0; i < resultArr.length; i++) {
                boolean flag = true;
                for (int j = i; j >= 0; j --) {
                    if (!flag) {
                        resultArr[i][j] = 'N';
                        continue;
                    }

                    if (i == j) {
                        resultArr[i][j] = 'Y';
                        continue;
                    }

                    if (out[j + 1] == 'Y' && in[j] == 'Y') {
                        resultArr[i][j] = 'Y';
                        continue;
                    }

                    flag = false;
                    resultArr[i][j] = 'N';
                }

                flag = true;
                for (int j = i + 1; j < resultArr.length; j++) {
                    if (!flag) {
                        resultArr[i][j] = 'N';
                        continue;
                    }

                    if (out[j - 1] == 'Y' && in[j] == 'Y') {
                        resultArr[i][j] = 'Y';
                        continue;
                    }

                    flag = false;
                    resultArr[i][j] = 'N';
                }
            }

            System.out.println("Case #" + t +":");
            pw.println("Case #" + t +":");
            for (int i = 0; i <resultArr.length; i++) {
                pw.println(resultArr[i]);
                System.out.println(resultArr[i]);
            }
            pw.flush();
            pw.flush();
        }
    }
}

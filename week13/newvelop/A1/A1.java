
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(new FileOutputStream(new File("a1.txt")), StandardCharsets.UTF_8));
        int tcase = Integer.parseInt(br.readLine());
        List<Integer> vowel = List.of('A' - 'A', 'E' - 'A', 'I' - 'A', 'O' - 'A', 'U' - 'A');
        for (int t = 1; t <= tcase; t++) {
            String s = br.readLine();
            int[] arr = new int[26];
            int maxC = -1;
            int maxCIndex = -1;
            int maxV = -1;
            int maxVIndex = -1;
            for (int i = 0; i < s.length(); i++) {
                int index = s.charAt(i) - 'A';
                arr[index] ++;
                if (vowel.contains(index)) {
                    if (maxV < arr[index]) {
                        maxV = arr[index];
                        maxVIndex = index;
                    }
                } else {
                    if (maxC < arr[index]) {
                        maxC = arr[index];
                        maxCIndex = index;
                    }
                }
            }
            int result = Integer.MAX_VALUE;
            int temp = 0;
            for (int i = 0; i < 26; i++) {
                if (maxCIndex != -1 && i == maxCIndex) {
                    continue;
                } else if (vowel.contains(i)) {
                    temp += arr[i];
                } else {
                    temp += arr[i] * 2;
                }
            }

            result = Math.min(result, temp);
            temp = 0;
            for (int i = 0; i < 26; i++) {
                if (maxVIndex != -1 && i == maxVIndex) {
                    continue;
                } else if (vowel.contains(i)) {
                    temp += arr[i] * 2;
                } else {
                    temp += arr[i];
                }
            }
            result = Math.min(result, temp);
            System.out.println("Case #" + t +": " + result);
            pw.println("Case #" + t +": " + result);
            pw.flush();
        }
    }
}

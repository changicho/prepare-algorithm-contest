import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Answer {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        String s = br.readLine();
        int result = 0;
        int hIndex = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'P') {
                if (i == 0) {
                    int rightMax = Math.min(s.length(), arr[1] + 1);
                    for (int start = 0; start < rightMax; start++) {
                        if (s.charAt(start) == 'H') {
                            hIndex = start;
                            result ++;
                            break;
                        }
                    }
                    continue;
                }

                if (i == s.length() - 1) {
                    int left = Math.max(Math.max(0, hIndex + 1), i - arr[1]);
                    for (int start = left; start < s.length(); start++) {
                        if (s.charAt(start) == 'H') {
                            hIndex = start;
                            result ++;
                            break;
                        }
                    }
                    continue;
                }

                if (hIndex >= i + arr[1]) {
                    continue;
                } else {
                    int left = Math.max(Math.max(0, hIndex + 1), i - arr[1]);
                    int rightMax = Math.min(s.length(), arr[1] + 1 + i);
                    for (int start = left; start < rightMax; start++) {
                        if (s.charAt(start) == 'H') {
                            hIndex = start;
                            result ++;
                            break;
                        }
                    }
                }

            }
        }
        System.out.println(result);
    }
}

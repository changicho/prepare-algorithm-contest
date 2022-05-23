package google.k2022;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

public class C1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int totalCase = Integer.parseInt(br.readLine());
        for (int t = 0; t < totalCase; t++) {
            br.readLine();
            String s = br.readLine();
            boolean hasLower = false;
            boolean hasUpper = false;
            boolean hasNum = false;
            boolean hasSpecial = false;
            String result = s;
            List<Character> list = List.of('#', '@', '*', '&');
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c >= 'a' && c <= 'z') {
                    hasLower = true;
                } else if (c >= 'A' && c<= 'Z') {
                    hasUpper = true;
                } else if (c >= '0' && c<= '9') {
                    hasNum = true;
                } else if (list.contains(c)) {
                    hasSpecial = true;
                }
            }

            if (!hasLower) {
                result += 'a';
            }

            if (!hasUpper) {
                result += 'A';
            }

            if (!hasNum) {
                result += '0';
            }

            if (!hasSpecial) {
                result += '#';
            }
            //1111234567
            //1111234567@Rc
            if (result.length() < 7) {
                while (result.length() < 7) {
                    result += 'a';
                }
            }

            System.out.println("Case #" + (t + 1) + ": " + result);
        }
    }
}

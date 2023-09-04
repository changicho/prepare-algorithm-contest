package codeforce.y2022.d0516_0522;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class c_1674c {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        for (int i = 0; i < count; i++) {
            String s = br.readLine();
            String t = br.readLine();
            if (t.contains("a") && t.length() > 1) {
                System.out.println(-1);
            } else if (t.equals("a")) {
                System.out.println(1);
            } else {
                long result = 1L;
                for (int j = 0; j < s.length(); j++) {
                    result *= 2;
                }
                System.out.println(result);
            }
        }
    }
}

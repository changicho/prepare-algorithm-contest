package codeforce.y2022.d0516_0522;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class c_1674b {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        for (int i = 0; i < count; i++) {
            String s = br.readLine();
            int temp = (s.charAt(0) - 'a') * 25;
            if (s.charAt(0) < s.charAt(1)) {
                temp += s.charAt(1) - 'a';
            } else {
                temp += s.charAt(1) - 'a' + 1;
            }
            System.out.println(temp);
        }
    }
}

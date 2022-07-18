
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tcase = Integer.parseInt(br.readLine());
        for (int t = 1; t <= tcase; t++) {
            String s = br.readLine();
            Set<Character> set = new HashSet<>();
            int result = 0;
            for (char c : s.toCharArray()) {
                if (set.contains(c)) {
                    continue;
                } else {
                    if (set.size() == 3) {
                        result++;
                        set.clear();
                    }
                    set.add(c);
                }
            }
            System.out.println(result + 1);
        }
    }
}

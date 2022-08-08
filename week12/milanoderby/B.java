import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testCase = Integer.parseInt(br.readLine());

        for (int i = 0; i < testCase; i++) {
            int n = Integer.parseInt(br.readLine());

            Stack<Integer> integerStack = new Stack<>();
            StringTokenizer tokenizer = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int num = Integer.parseInt(tokenizer.nextToken());
                integerStack.push(num);
            }

            Set<Integer> integerSet = new HashSet<>();
            while (!integerStack.isEmpty()) {
                int num = integerStack.peek();
                if (integerSet.contains(num)) {
                    break;
                }

                integerSet.add(num);
                integerStack.pop();
            }

            bw.write(integerStack.size() + "\n");
        }
        bw.flush();
    }
}

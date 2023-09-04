import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class Main {
    private static int MAX_SECONDS = 10000;
    public static void main(String[] args) throws  IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int testCase = 0; testCase < T; testCase++) {
            int N = Integer.parseInt(br.readLine());
            char[][] board = new char[N][N];

            boolean[] isPossibleRow = new boolean[N];
            boolean[] isPossibleCol = new boolean[N];

            int[] countOfXToFillRow = new int[N];
            int[] countOfXToFillCol = new int[N];

            for (int i = 0; i < N; i++) {
                isPossibleRow[i] = true;
                isPossibleCol[i] = true;
                countOfXToFillRow[i] = N;
                countOfXToFillCol[i] = N;
            }

            for (int i = 0; i < N; i++) {
                String line = br.readLine();
                for (int j = 0; j < N; j++) {
                    board[i][j] = line.charAt(j);
                    if (board[i][j] == 'O') {
                        isPossibleRow[i] = false;
                        isPossibleCol[j] = false;
                    } else if (board[i][j] == 'X') {
                        countOfXToFillRow[i]--;
                        countOfXToFillCol[j]--;
                    }
                }
            }

            int minCountOfXToFill = Integer.MAX_VALUE;
            for (int i = 0; i < N; i++) {
                if (isPossibleRow[i]) {
                    minCountOfXToFill = Math.min(minCountOfXToFill, countOfXToFillRow[i]);
                }

                if (isPossibleCol[i]) {
                    minCountOfXToFill = Math.min(minCountOfXToFill, countOfXToFillCol[i]);
                }
            }

            if (minCountOfXToFill == Integer.MAX_VALUE) {
                bw.append("Case #" + (testCase + 1) + ": Impossible\n");
                continue;
            }

            if (minCountOfXToFill > 1) {
                int countOfSetToPlaceX = 0;
                for (int i = 0; i < N; i++) {
                    if (isPossibleRow[i] && minCountOfXToFill == countOfXToFillRow[i]) {
                        countOfSetToPlaceX++;
                    }

                    if (isPossibleCol[i] && minCountOfXToFill == countOfXToFillCol[i]) {
                        countOfSetToPlaceX++;
                    }
                }
                bw.append("Case #" + (testCase + 1) + ": " + minCountOfXToFill + " " + countOfSetToPlaceX + "\n");
                continue;
            }

            Set<Integer> countOfSetToPlaceX = new HashSet<>();
            for (int i = 0; i < N; i++) {
                if (! (isPossibleRow[i] && countOfXToFillRow[i] == minCountOfXToFill)) {
                    continue;
                }

                for (int j = 0; j < N; j++) {
                    if (board[i][j] == '.') {
                        countOfSetToPlaceX.add(100*i + j);
                        break;
                    }
                }
            }

            for (int j = 0; j < N; j++) {
                if (! (isPossibleCol[j] && countOfXToFillCol[j] == minCountOfXToFill)) {
                    continue;
                }

                for (int i = 0; i < N; i++) {
                    if (board[i][j] == '.') {
                        countOfSetToPlaceX.add(100*i + j);
                        break;
                    }
                }
            }
            bw.append("Case #" + (testCase + 1) + ": " + minCountOfXToFill + " " + countOfSetToPlaceX.size() + "\n");
        }
        bw.flush();
    }
}

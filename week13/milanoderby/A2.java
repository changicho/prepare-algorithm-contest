import java.io.*;

public class Main {
    private static int MAX_SECONDS = 10000;
    public static void main(String[] args) throws  IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int i = 0; i < T; i++) {
            String S = br.readLine();
            int K = Integer.parseInt(br.readLine());
            int[][] distance = new int[26][26];
            initDistance(distance);

            for (int j = 0; j < K; j++) {
                String AB = br.readLine();
                int src = AB.charAt(0) - 'A';
                int dest = AB.charAt(1) - 'A';
                distance[src][dest] = 1;
            }

            floydWarshall(distance);
            int minimumSeconds = getMinimumSecondsToMakeConsistent(S, distance);
            bw.append("Case #" + (i + 1) + ": " + minimumSeconds + "\n");
        }
        bw.flush();
    }

    private static int getMinimumSecondsToMakeConsistent(String S, int[][] distance) {
        int minimumSeconds = MAX_SECONDS;
        for (int i = 0; i < 26; i++) {
            int seconds = 0;
            for (int j = 0; j < S.length(); j++) {
                if (distance[S.charAt(j) - 'A'][i] == MAX_SECONDS) {
                    seconds = MAX_SECONDS;
                    break;
                }
                seconds += distance[S.charAt(j) - 'A'][i];
            }

            minimumSeconds = Math.min(minimumSeconds, seconds);
        }

        return minimumSeconds == MAX_SECONDS ? -1 : minimumSeconds;
    }

    private static void initDistance(int[][] distance) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) {
                    distance[i][j] = 0;
                } else {
                    distance[i][j] = MAX_SECONDS;
                }
            }
        }
    }

    private static void floydWarshall(int[][] distance) {
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
}

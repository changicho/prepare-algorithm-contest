package com.madcoder.atcoder.abc434;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 * https://atcoder.jp/contests/abc434/tasks/abc434_c
 */
public class C {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCase = Integer.parseInt(br.readLine());
        for (int i = 0; i < testCase; i++) {
            StringTokenizer tokenizer = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(tokenizer.nextToken());
            int startHeight = Integer.parseInt(tokenizer.nextToken());

            int currentTime = 0;
            Interval currentPosition = new Interval(startHeight, startHeight);

            boolean isPossible = true;
            for (int j = 0; j < N; j++) {
                tokenizer = new StringTokenizer(br.readLine());
                int nextTime = Integer.parseInt(tokenizer.nextToken());
                int lowerBound = Integer.parseInt(tokenizer.nextToken());
                int upperBound = Integer.parseInt(tokenizer.nextToken());

                int movableHeight = nextTime - currentTime;
                currentPosition = new Interval(currentPosition.getStart() - movableHeight, currentPosition.getEnd() + movableHeight);

                if (upperBound < currentPosition.getStart() || lowerBound > currentPosition.getEnd()) {
                    isPossible = false;
                }

                int lowerHeight = Math.max(currentPosition.getStart(), lowerBound);
                int upperHeight = Math.min(currentPosition.getEnd(), upperBound);
                currentPosition = new Interval(lowerHeight, upperHeight);

                currentTime = nextTime;
            }

            if (isPossible) {
                bw.write("Yes\n");
            } else {
                bw.write("No\n");
            }
        }
        bw.flush();
    }

    private static class Interval {
        private int start;
        private int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }
    }
}
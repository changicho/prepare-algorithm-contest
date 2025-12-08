package com.madcoder.atcoder.abc434;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/**
 * https://atcoder.jp/contests/abc434/tasks/abc434_b
 */
public class B {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(tokenizer.nextToken());
        int M = Integer.parseInt(tokenizer.nextToken());

        int[] sumOfSize = new int[M + 1];
        int[] countOfBirdType = new int[M + 1];

        for (int i = 0; i < N; i++) {
            tokenizer = new StringTokenizer(br.readLine());
            int birdType = Integer.parseInt(tokenizer.nextToken());
            int sizeOfBird = Integer.parseInt(tokenizer.nextToken());

            countOfBirdType[birdType]++;
            sumOfSize[birdType] += sizeOfBird;
        }

        for (int i = 1; i <= M; i++) {
            if (countOfBirdType[i] == 0) {
                bw.write(0 + "\n");
            } else {
                double answer = (double) sumOfSize[i] / countOfBirdType[i];
                bw.write(answer + "\n");
            }
        }
        bw.flush();
    }
}
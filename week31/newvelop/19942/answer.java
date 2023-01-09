
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class Answer {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int[][] arr = new int[count][5];
        for (int i = 0; i < count; i++) {
            arr[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        int result = Integer.MAX_VALUE;
        List<Integer> resultList = new ArrayList<>();

        for (int i = 0; i < arr.length; i++) {
            int[] curIngredients = new int[4];
            List<Integer> tempList = new ArrayList<>();
            tempList.add(i + 1);
            int temp = cal(input, arr, i, curIngredients, tempList);
            if (result > temp) {
                resultList = tempList;
                result = temp;
            }
        }
        Collections.sort(resultList);

        if (result == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(result);
            System.out.println(resultList.stream().map(v -> v.toString()).collect(Collectors.joining(" ")));
        }
    }

    public static int cal(int[] input, int[][] arr, int index, int[] curIngredients, List<Integer> resultList) {
        if (index == arr.length) {
            return Integer.MAX_VALUE;
        }

        preProcessing(curIngredients, arr, index);

        if (checkEnough(input, curIngredients)) {
            postProcessing(curIngredients, arr, index);
            return arr[index][arr[index].length - 1];
        }

        int result = Integer.MAX_VALUE;

        List<Integer> nextList = new ArrayList<>();

        for (int i = index + 1; i < arr.length; i++) {
            List<Integer> tempList = new ArrayList<>();
            tempList.add(i + 1);
            int temp = cal(input, arr, i, curIngredients, tempList);
            if (temp == Integer.MAX_VALUE) {
                continue;
            } else if (result > temp + arr[index][arr[index].length - 1]) {
                result = temp + arr[index][arr[index].length - 1];
                nextList = tempList;
            } else if (result == temp + arr[index][arr[index].length - 1]) {
                if (isSecondFaster(nextList, tempList)) {
                    nextList = tempList;
                }
            }

        }

        resultList.addAll(nextList);
        postProcessing(curIngredients, arr, index);

        return result;
    }

    public static boolean checkEnough(int[] input, int[] curIngredients) {
        for (int i = 0; i < input.length; i++) {
            if (input[i] > curIngredients[i]) {
                return false;
            }
        }
        return true;
    }

    public static void preProcessing(int[] curIngredients, int[][] arr, int index) {
        curIngredients[0] += arr[index][0];
        curIngredients[1] += arr[index][1];
        curIngredients[2] += arr[index][2];
        curIngredients[3] += arr[index][3];
    }

    public static void postProcessing(int[] curIngredients, int[][] arr, int index) {
        curIngredients[0] -= arr[index][0];
        curIngredients[1] -= arr[index][1];
        curIngredients[2] -= arr[index][2];
        curIngredients[3] -= arr[index][3];
    }

    public static boolean isSecondFaster(List<Integer> first, List<Integer> second) {
        Collections.sort(first);
        Collections.sort(second);

        String firstStr = first.stream().map(v -> v.toString()).collect(Collectors.joining(" "));
        String secondStr = second.stream().map(v -> v.toString()).collect(Collectors.joining(" "));

        if (firstStr.compareTo(secondStr) > 0) {
            return true;
        }
        return false;
    }
}

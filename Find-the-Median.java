import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'findMedian' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    static Random rand = new Random();

    static int partition(List<Integer> arr, int left, int right) {
        int pivotIndex = left + rand.nextInt(right - left + 1);
        Collections.swap(arr, pivotIndex, right);

        int pivot = arr.get(right);
        int i = left;

        for (int j = left; j < right; j++) {
            if (arr.get(j) <= pivot) {
                Collections.swap(arr, i, j);
                i++;
            }
        }
        Collections.swap(arr, i, right);
        return i;
    }

    static int quickselect(List<Integer> arr, int left, int right, int k) {
        if (left == right) return arr.get(left);

        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k) {
            return arr.get(pivotIndex);
        } else if (pivotIndex > k) {
            return quickselect(arr, left, pivotIndex - 1, k);
        } else {
            return quickselect(arr, pivotIndex + 1, right, k);
        }
    }

}


public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.findMedian(arr);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}

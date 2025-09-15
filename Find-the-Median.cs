using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'findMedian' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    static Random rand = new Random();
    
    static void Swap(List<int> arr, int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int Partition(List<int> arr, int left, int right)
    {
        int pivotIndex = left + rand.Next(right - left + 1);
        Swap(arr, pivotIndex, right);

        int pivot = arr[right];
        int i = left;

        for (int j = left; j < right; j++)
        {
            if (arr[j] <= pivot)
            {
                Swap(arr, i, j);
                i++;
            }
        }
        Swap(arr, i, right);
        return i;
    }

    static int QuickSelect(List<int> arr, int left, int right, int k)
    {
        if (left == right)
            return arr[left];

        int pivotIndex = Partition(arr, left, right);

        if (pivotIndex == k)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k)
        {
            return QuickSelect(arr, left, pivotIndex - 1, k);
        }
        else
        {
            return QuickSelect(arr, pivotIndex + 1, right, k);
        }
    }

    public static int findMedian(List<int> arr)
    {
        int n = arr.Count;
        int midIndex = n / 2;
        //return QuickSelect(new List<int>(arr), 0, n - 1, midIndex);
        return QuickSelect(arr, 0, n - 1, midIndex);
    }


    public static int findMedian2(List<int> arr)
    {
        arr.Sort();
        return arr[arr.Count / 2];
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        int n = Convert.ToInt32(Console.ReadLine().Trim());

        List<int> arr = Console.ReadLine().TrimEnd().Split(' ').ToList().Select(arrTemp => Convert.ToInt32(arrTemp)).ToList();

        int result = Result.findMedian(arr);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}

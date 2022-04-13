// 
// Logic
// Take in the array. Sort the array in descending order.
// Since array index starts from 0.
// Then kth number will be found from k-1 index.
// 
// Time complexity = O(n log n)
// 
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class Main{
	public static void main(String[] args){
		int n, k;
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		k = s.nextInt();
		Integer arr[] = new Integer[n];
		for(int i=0; i<n; i++){
			arr[i] = s.nextInt();
		}
		Arrays.sort(arr, Collections.reverseOrder());
		System.out.println(arr[k-1]);
	}
}

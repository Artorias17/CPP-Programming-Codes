/*
 * Logic:
 * Since the all the values of the friend array is a value that is subtracted from a constant value
 * which is the last value of the main array. We only need to check if the main array is in ascending order
 * or not. If it is in ascending order then its friend array will be in descending order.
 *
 * Time complexity = O(n)
 */

import java.util.Scanner;
public class Main{
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int[] arr = new int[n];
		boolean isSorted = true;
		for(int i=0; i<n; i++){
	        arr[i] = s.nextInt();
	        if(i != 0){
	            if(arr[i-1] > arr[i]) {
	                isSorted = false;
	                break;
	            }
	        }
		}
		if(isSorted) System.out.println("Yes");
		else System.out.println("No");
		
	}
}

package Java;

import java.util.Scanner;

public class Bai6{
    public static int find(int arr[], int k){
        for (int i = 0; i < arr.length; i++)
            if (arr[i] == k) return i;
        return -1;
    }
    public static void main(String[] args) {
        Array a = new Array();
        a.input();
        a.output();
        System.out.print("\nNhap gia tri can tim: ");
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        System.out.println("Vi tri gia tri " + k + " la: " + find(a.arr, k));
    }
}
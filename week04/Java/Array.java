package Java;

import java.util.Scanner;
public class Array {
    public int arr[], n;
    Array(){
        arr = new int[0];
    }
    Array(int n, int val){
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = val;
    }
    Array(int b[], int n){
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = b[i];
    }
    public int length(){
        return n;
    }
    public void input(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so luong phan tu n = ");
        n = sc.nextInt();
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("arr[" + i + "] = ");
            arr[i] = sc.nextInt();
        }
    }
    public void output(){
        for (int i = 0; i < n; i++) System.out.print(arr[i] + " ");
    }
}

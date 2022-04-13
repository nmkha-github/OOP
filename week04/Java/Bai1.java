package week04.Java;
import java.util.Scanner;

public class Bai1 {
    public static int[] input(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so luong phan tu n = ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("arr[" + i + "] = ");
            arr[i] = sc.nextInt();
        }
        return arr;
    }
    public static void output(int arr[]){
        for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
        System.out.print("\n");
    }
    public static int findMax(int arr[]){
        int temp = arr[0];
        for(int i = 0; i < arr.length; i++){
            if (arr[i] > temp){
                temp = arr[i];
            }
        }
        return temp;
    }
    public static void main(String[] args) {
        int[] a = input();
        System.out.println("Mang da nhap:");
        output(a);
        System.out.println("--------------------Cau1------------------");
        System.out.println("Max = " + findMax(a));
    }
}

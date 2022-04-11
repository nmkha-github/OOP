import java.util.Scanner;

public class Bai6{
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
    public static int find(int arr[], int k){
        for (int i = 0; i < arr.length; i++)
            if (arr[i] == k) return i;
        return -1;
    }
    public static void main(String[] args) {
        int a[] = input();
        System.out.println("Mang da nhap: ");
        output(a);
        System.out.println("--------------------Cau6------------------");
        System.out.print("Nhap gia tri can tim: ");
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        System.out.println("Vi tri gia tri " + k + " la: " + find(a, k));
    }
}
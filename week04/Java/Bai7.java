
import java.util.Scanner;

public class Bai7 {
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
        System.out.println("");
    }
    public static void square(int arr[]){
        for(int i=0; i<arr.length; i++) arr[i] = arr[i] * arr[i];
    }
    public static void main(String[] args) {
        int a[] = input();
        System.out.println("Mang ban dau:");
        output(a);
        System.out.println("--------------------Cau7------------------");
        square(a);
        System.out.println("Mang sau khi binh phuong:");
        output(a);
    }
}

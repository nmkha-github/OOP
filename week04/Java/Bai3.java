import java.util.Scanner;

public class Bai3
{
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
    public static int Cau3(int a[])
    {
        int sum=0;
    for(int i:a)
    {
        if(i%2==0)
        sum+=i;
    }
        return sum;
    }
    public static void main(String[] args) {
        int a[]= input();
        System.out.println("Mang da nhap:");
        output(a);
        System.out.println("--------------------Cau3------------------");
        System.out.print("Tong phan tu chan la: ");
        System.out.println(Cau3(a));
    }
}

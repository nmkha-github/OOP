import java.util.Scanner;

public class Bai5
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

    public static boolean isPrime(int a)
    {
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
        return false;
    }
    return true;
    }

    public static int Cau5(int a[])
    {
    int count =0;
    for(int i=0;i<a.length;i++)
    {
        if(isPrime(a[i])==true)
        count++;
    }
    return count;
    }
    public static void main(String[] args) {
        int a[]= input();
        System.out.println("Mang da nhap:");
        output(a);
        System.out.println("--------------------Cau5------------------");
        System.out.println("Co " + Cau5(a) + " so nguyen to trong mang.");
    }
}

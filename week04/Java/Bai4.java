import java.util.Scanner;

public class Bai4
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

    public static int Cau4(int a[],int x)
    {
        int count=0;
        for(int i:a)
        {
        if(i==x)
        count++;
        }
        return count;
    }
    public static void main(String[] args) {
        int a[]= input();
        System.out.println("Mang da nhap:");
        output(a);
        System.out.print("Nhap gia tri can dem: ");
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println("--------------------Cau4------------------");
        System.out.println("So lan xuat hien cua " + x + ": ");
        System.out.println(Cau4(a, x));
    }
}

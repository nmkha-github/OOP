import java.util.Scanner;
public class Array {
    public int a[], n;
    Array(){
        a = new int[0];
    }
    Array(int n, int val){
        a = new int[n];
        for (int i = 0; i < n; i++) a[i] = val;
    }
    Array(int b[], int n){
        a = new int[n];
        for (int i = 0; i < n; i++) a[i] = b[i];
    }
    public int length(){
        return n;
    }
    public void input(){
        System.out.print("Nhap so luong phan tu n = ");
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("a[" + i + "] = ");
            a[i] = sc.nextInt();
        }
        sc.close();
    }
    public void output(){
        for (int i = 0; i < n; i++) System.out.print(a[i] + " ");
    }
}

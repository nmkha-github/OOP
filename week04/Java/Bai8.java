package Java;
import java.math.BigDecimal;
import java.util.Scanner;
public class Bai8 {
    public static BigDecimal[] input(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap so luong phan tu n = ");
        int n = sc.nextInt();
        BigDecimal arr[] = new BigDecimal[n];
        for (int i = 0; i < n; i++) {
            System.out.print("arr[" + i + "] = ");
            arr[i] = sc.nextBigDecimal();
        }
        return arr;
    }
    public static void output(BigDecimal arr[]){
        for (int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
    }
    public static BigDecimal findMax(BigDecimal []arr){
        BigDecimal maxx = arr[0];
        for (int i = 0; i < arr.length; i++) 
            if (maxx.compareTo(arr[i]) < 0) maxx = arr[i];
        return maxx;
    }
    public static void main(String[] args) {
        BigDecimal a[] = input();
        System.out.println("Mang da nhap:");
        output(a);
        System.out.println("\nPhan tu lon nhat: " + findMax(a));
    }
}

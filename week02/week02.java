import java.util.Scanner;

import javax.sql.rowset.CachedRowSet;

class OOP
{
    public static void Cau1()
    {
        System.out.println("Ten: Hoang Tuan Anh");
        System.out.println("Ngay sinh: 10/07/2002");
        System.out.println("MSSV: 20120244");
    }

    public static int Cau2()
    {
        Scanner Nhap=new Scanner(System.in);
        System.out.println("Nhap chieu dai: ");
        int dai=Nhap.nextInt();
        System.out.println("Nhap chieu rong");
        int rong=Nhap.nextInt();
        return dai*rong;
    }
    public static float Cau3_F2C()
    {
        System.out.println("Nhap do F: ");
        Scanner Nhap=new Scanner(System.in);
        float F=Nhap.nextFloat();
        return (F-32)*5/9;
    }
    public static float Cau3_C2F()
    {
        System.out.println("Nhap do F: ");
        Scanner Nhap=new Scanner(System.in);
        float C=Nhap.nextFloat();
        return (C*9/5)+32;
    }
    public static int Cau4()
    {
        System.out.println("Nhap 3 so: ");
        Scanner Nhap=new Scanner(System.in);
        int a=Nhap.nextInt();
        int b=Nhap.nextInt();
        int c=Nhap.nextInt();
        int min=a;
        if (min>b)
        min=b;
        if(min>c)
        min=c;
        return min;
    }
    public static boolean Cau5()
    {
        System.out.println("Nhap so: ");
        Scanner Nhap=new Scanner(System.in);
        int a=Nhap.nextInt();
        if(a%2==0)
        return true;
        else return false;
    }
    public static int Cau6a()
    {
        System.out.println("Nhap n: ");
        Scanner Nhap=new Scanner(System.in);
        int n=Nhap.nextInt();
        int ketqua=0;
        for(int i=1;i<=n;i++)
        {
            ketqua+=i;
        }
        return ketqua;
    }
    
    public static int Cau6c()
    {
        System.out.println("Nhap n: ");
        Scanner Nhap=new Scanner(System.in);
        int n=Nhap.nextInt();
        int ketqua=0;
        for(int i=0;i<=n;i++)
        {
            ketqua+=2^i;
        }
        return ketqua;
    }
    public static float Cau6d()
    {
        System.out.println("Nhap n: ");
        Scanner Nhap=new Scanner(System.in);
        int n=Nhap.nextInt();
        float ketqua=0;
        for(int i=2;i<=n;i+=2)
        {
            ketqua+=1/i;
        }
        return ketqua;
    }
    public static int Cau6e()
    {
        System.out.println("Nhap n: ");
        Scanner Nhap=new Scanner(System.in);
        int n=Nhap.nextInt();
        int ketqua=0;
        for(int i=1;i<=n;i++)
        {
            ketqua+=i^2;
        }
        return ketqua;
    }

    public static int Input()
    {
        System.out.println("---Menu---: ");
        System.out.println("1. Coca");
        System.out.println("2. Pepsi ");
        System.out.println("3. Sprite ");
        System.out.println("4. Snack ");
        System.out.println("5. Shutdown machine");
        System.out.println("Nhap so: ");
        System.out.println("Nhap n: ");
        Scanner Nhap=new Scanner(System.in);
        int n=Nhap.nextInt();
        return n;

    }
    public static void Cau15()
    {
        int n=0;
        Scanner Nhap=new Scanner(System.in);
        do{
            n=Input();
            switch (n){

            case 1:
            System.out.println("Coca co gia $1. Nhap so tien: ");
            int money1=Nhap.nextInt();
            if(money1<1)
            System.out.println("Khong du tien");
            else 
            {
                System.out.println("Tien du: ");
                System.out.print(money1-1);
            }
            break;

            case 2:
            System.out.println("Pepsi co gia $2. Nhap so tien: ");
            int money2=Nhap.nextInt();
            if(money2<2)
            System.out.println("Khong du tien");
            else 
            {
                System.out.println("Tien du: ");
                System.out.print(money2-2);
            }
            break;

            case 3:
            System.out.println("Sprite co gia $3. Nhap so tien: ");
            int money3=Nhap.nextInt();
            if(money3<3)
            System.out.println("Khong du tien");
            else 
            {
                System.out.println("Tien du: ");
                System.out.print(money3-3);
            }
            break;

            case 4:
            System.out.println("Snack co gia $4. Nhap so tien: ");
            int money4=Nhap.nextInt();
            if(money4<4)
            System.out.println("Khong du tien");
            else 
            {
                System.out.println("Tien du: ");
                System.out.print(money4-4);
            }
            break;

            case 5:
            return;
            default:
            System.out.println("Nhap sai vui long nhap lai");
            break;
            
            }

        } while (n==1||n==2||n==3||n==4||n==5);
    }

public static void main(String[] args)
{
    
}

}

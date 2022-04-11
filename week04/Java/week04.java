public class week04
 {
     public static int Cau3(int a[])
     {
        System.out.println("--------------------Cau3------------------");
         int sum=0;
        for(int i:a)
        {
            if(i%2==0)
            sum+=i;
        }
         return sum;
     }

     public static int Cau4(int a[],int x)
     {
        System.out.println("--------------------Cau4------------------");
         int count=0;
         for(int i:a)
         {
            if(i==x)
            count++;
         }
         return count;
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
        System.out.println("--------------------Cau5------------------");
        int count =0;
        for(int i=0;i<a.length;i++)
        {
            if(isPrime(a[i])==true)
            count++;
        }
        return count;
     }
    public static void main(String[] args) {
        int a[]={1,2,3,4,5,6};
        System.out.println(Cau3(a));
        System.out.println(Cau4(a,3));
        System.out.println(Cau5(a));
    }
}

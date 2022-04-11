public class Bai1 {
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
        int[] a = {5, 3, 4, 8, 1, 10, 9};
        System.out.println("{5, 3, 4, 8, 1, 10, 9}");
        System.out.println("Max = " + findMax(a));
    }
}

import java.util.Scanner;

class ExecutaOrdenaPublic {
    public static void main() {
        Scanner scnr = new Scanner(System.in);
        int n1 = scnr.nextInt();
        int n2 = scnr.nextInt();
        int n3 = scnr.nextInt();
        
        OrdenaPublic ordena = new OrdenaPublic();
        ordena.crescente(n1, n2,n3);
    }
}
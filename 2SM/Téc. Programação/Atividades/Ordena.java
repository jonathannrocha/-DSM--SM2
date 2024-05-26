import java.util.Scanner;

class Ordena {
    public static void main() {
        Scanner scnr = new Scanner(System.in);
        int n1 = scnr.nextInt();
        int n2 = scnr.nextInt();
        int n3 = scnr.nextInt();
        
        int[] lista = {n1, n2, n3};
        
        for(int a=0; a < lista.length;a++) {
           for(int b=0; b < lista.length -1;b++) {
               if(lista[b] > lista[b+1]) {
                   int aux = lista[b];
                   lista[b] = lista[b+1];
                   lista[b+1] = aux;
               }
           }
        }
        
        for(int c=0; c < lista.length;c++) {
           System.out.println(lista[c]);
        }
    }
}
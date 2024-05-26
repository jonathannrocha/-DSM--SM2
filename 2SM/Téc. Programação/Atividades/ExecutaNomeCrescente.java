import java.util.Scanner;

class ExecutaNomeCrescente {
    public static void main() {
        Scanner scnr = new Scanner(System.in);
        int n1 = scnr.nextInt();
        int n2 = scnr.nextInt();
        int n3 = scnr.nextInt();
        String nome = scnr.next();
        nomeOrdena ordena = new nomeOrdena(nome);
        ordena.mostarNomeCrescente(n1, n2,n3);
    }
}
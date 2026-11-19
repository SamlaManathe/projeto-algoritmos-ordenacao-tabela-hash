import algoritmos_ordenacao.*;
import interfaces.IAlgoritmoOrdenacao;
import java.util.Scanner;
import utils.Utils;

public class App {

/*=============================================
                TAINARA - MENU
==============================================*/

public static void main(String[] args) {         
        Scanner scanner = new Scanner(System.in);
        int opcao = 0;

        int TAMANHO_VETOR = 10;
        int LIMITE_SUPERIOR = 10;

        
        int[] vetorOriginal = Utils.gerarVetor(TAMANHO_VETOR, LIMITE_SUPERIOR);

        do {
            System.out.println("\n==========================================================================");
            System.out.println("                  MENU PRINCIPAL - ORDENAÇÃO DE DADOS   ");
            System.out.println("==========================================================================\n");
            System.out.println("1 - Bubble Sort");
            System.out.println("2 - Insertion Sort");
            System.out.println("3 - Selection Sort");
            System.out.println("4 - Merge Sort");
            System.out.println("5 - Quick Sort");
            System.out.println("6 - Sair do programa");
            System.out.print("\nEscolha uma opção: ");

            
            if (!scanner.hasNextInt()) {
                System.out.println("\n[ERRO] Entrada inválida! Por favor, digite apenas números de 1 a 6.");
                scanner.next(); 
                continue;
            }

            opcao = scanner.nextInt();
            IAlgoritmoOrdenacao algoritmo = null;
            String nomeAlgoritmo = "";
            int[] vetorTrabalho = vetorOriginal.clone();

            switch (opcao) {
                case 1:
                    algoritmo = new BubbleSort();
                    nomeAlgoritmo = "Bubble Sort";
                case 2:
                    algoritmo = new InsertionSort();
                    nomeAlgoritmo = "Insertion Sort";
                    break;
                case 3:
                    algoritmo = new SelectionSort();
                    nomeAlgoritmo = "Selection Sort";
                    break;
                case 4:
                    algoritmo = new MergeSort();
                    nomeAlgoritmo = "Merge Sort";
                    break;
                case 5:
                    algoritmo = new QuickSort();
                    nomeAlgoritmo = "Quick Sort";
                    break;
                case 6:
                    System.out.println("\nA encerrar o programa... Até logo!\n");
                    System.out.println("==========================================================================");
                    System.out.println("                                ENCERRADO   ");
                    System.out.println("==========================================================================\n");
                    break;
                default:
                    System.out.println("\n[ERRO] Opção inválida! Escolha um número entre 1 e 6.");
                    break;
            }

            
            if (algoritmo != null) {
                System.out.print("\nVetor Original:\n");
                Utils.imprimirVetor(vetorOriginal);
                System.out.println();

                algoritmo.ordenarVetor(vetorTrabalho);

                System.out.print("\n" + nomeAlgoritmo + " (Ordenado):\n");
                Utils.imprimirVetor(vetorTrabalho);
                System.out.println();
            }

        } while (opcao != 6);

        scanner.close();
    }
}

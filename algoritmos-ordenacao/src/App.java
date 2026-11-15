import ed2.projeto.algoritmosordenacao.BubbleSort;
import ed2.projeto.algoritmosordenacao.IAlgoritmoOrdenacao;
import ed2.projeto.algoritmosordenacao.InsertionSort;
import ed2.projeto.algoritmosordenacao.MergeSort;
import ed2.projeto.algoritmosordenacao.QuickSort;
import ed2.projeto.algoritmosordenacao.SelectionSort;
import ed2.projeto.algoritmosordenacao.Utils;

public class App {
    public static void main(String[] args) {

        int TAMANHO_VETOR = 10;
        int LIMITE_SUPERIOR = 1000;

        int[] vetorOriginal = Utils.gerarVetor(TAMANHO_VETOR, LIMITE_SUPERIOR);

        System.out.print("Vetor Original:\n");
        Utils.imprimirVetor(vetorOriginal);
        System.out.println();

        // IMPORTANTE: Separar cada um abaixo em opções do menu feito com switch case

        // Bubble Sort
        IAlgoritmoOrdenacao bubbleSort = new BubbleSort();
        int[] vetorBubble = vetorOriginal.clone();
        bubbleSort.ordenarVetor(vetorBubble);

        System.out.print("\nBubble Sort:\n");
        Utils.imprimirVetor(vetorBubble);
        System.out.println();

        // Insertion Sort
        IAlgoritmoOrdenacao insertionSort = new InsertionSort();
        int[] vetorInsertion = vetorOriginal.clone();
        insertionSort.ordenarVetor(vetorInsertion);

        System.out.print("\nInsertion Sort:\n");
        Utils.imprimirVetor(vetorInsertion);
        System.out.println();

        // Merge Sort
        IAlgoritmoOrdenacao mergeSort = new MergeSort();
        int[] vetorMerge = vetorOriginal.clone();
        mergeSort.ordenarVetor(vetorMerge);

        System.out.print("\nMerge Sort:\n");
        Utils.imprimirVetor(vetorMerge);
        System.out.println();

        // Quick Sort
        IAlgoritmoOrdenacao quickSort = new QuickSort();
        int[] vetorQuick = vetorOriginal.clone();
        quickSort.ordenarVetor(vetorQuick);

        System.out.print("\nQuick Sort:\n");
        Utils.imprimirVetor(vetorQuick);
        System.out.println();

        // Selection Sort
        IAlgoritmoOrdenacao selectionSort = new SelectionSort();
        int[] vetorSelection = vetorOriginal.clone();
        selectionSort.ordenarVetor(vetorSelection);

        System.out.print("\nSelection Sort:\n");
        Utils.imprimirVetor(vetorSelection);
        System.out.println();
    }
}

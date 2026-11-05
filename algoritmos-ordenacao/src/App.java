import ed2.projeto.algoritmosordenacao.BubbleSort;
import ed2.projeto.algoritmosordenacao.IAlgoritmoOrdenacao;
import ed2.projeto.algoritmosordenacao.InsertionSort;
import ed2.projeto.algoritmosordenacao.MergeSort;
import ed2.projeto.algoritmosordenacao.QuickSort;
import ed2.projeto.algoritmosordenacao.SelectionSort;
import ed2.projeto.algoritmosordenacao.Utils;

public class App {
    public static void main(String[] args) {
        int[] vetorOriginal = Utils.gerarVetor(10, 1000);

        System.out.print("\nVetor original:");
        Utils.imprimirVetor(vetorOriginal);
        System.out.println();

        IAlgoritmoOrdenacao[] algoritmos = {
            new BubbleSort(),
            new InsertionSort(),
            new MergeSort(),
            new QuickSort(),
            new SelectionSort()
        };

        for (IAlgoritmoOrdenacao algoritmo : algoritmos) {
            int[] vetorOrdenado = vetorOriginal.clone();
            algoritmo.ordenarVetor(vetorOrdenado);

            System.out.print(algoritmo + ":");
            Utils.imprimirVetor(vetorOrdenado);
            System.out.println();
        }
    }
}

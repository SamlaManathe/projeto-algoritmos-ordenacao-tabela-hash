package utils;

import java.util.Random;

/**
 * 
 * @author Hilario Tomaz Alves de Oliveira
 *
 */

public class Utils {

  private static final int LIMITE_EXIBICAO = 100;

  private Utils() {

  }
  
  // Métodos

  /*=============================================
              DANIEL - IMPRIMIR VETORES
  ==============================================*/
  
  public static void imprimirVetor(int[] vetor) {
    
    // Verifica se o vetor é vazio (fail fast)
    if (vetor == null || vetor.length == 0) {
      System.out.println("Vetor = {} (vazio)");
      return;
    }

    int tamanhoTotal = vetor.length;
    int limite = Math.min(tamanhoTotal, LIMITE_EXIBICAO);

    if (tamanhoTotal > LIMITE_EXIBICAO) {
      System.out.println("Aviso: exibindo apenas os primeiros " + LIMITE_EXIBICAO + " elementos (total: " + tamanhoTotal + ").");
    }

    System.out.print("Vetor = {");
    for (int i = 0; i < limite; i++) {
      System.out.print(vetor[i]);
      if (i < (limite - 1)) {
        System.out.print(", ");
        if ((i + 1) % 20 == 0) {
          System.out.print("\n      ");
        }
      }
    }
    
    if (tamanhoTotal > LIMITE_EXIBICAO) {
      System.out.print(", ...");
    }
    System.out.print("}");
  }

  /*=============================================
                SAMLA - GERAR VETOR
  ==============================================*/
  
  public static int[] gerarVetor(int tamanhoVetor, int limiteSuperior) {
	
	  Random random = new Random();
	
	  int[] vetor = new int[tamanhoVetor];
	
    for(int i = 0; i < tamanhoVetor; i++) {
	    	
	    int numero = random.nextInt( limiteSuperior );
	 
	    vetor[i] = numero;
	  
    } // FOR VETOR

    System.out.println();
	    
    return vetor;
    
  }

}

#include <stdio.h>
#include <stdlib.h>

void inicializaMatriz(int numVertice, int matriz_adj[numVertice][numVertice]){	//Inicializacao da mnatriz, fazendo com que toda lacuna receba 0.
	int i,j;
	for (i=0; i<numVertice; i++){
		for(j=0; j<numVertice; j++){
			matriz_adj[i][j]=0;
		}
	}
}


void insercao_matriz(int numVertice, int matriz_adj[numVertice][numVertice], int origem, int destino){	// Funcao de inserir elementos na matriz
	matriz_adj[origem][destino]=1;	// Origem é a linha da matriz e destino é a coluna, recebe 1. 
	matriz_adj[destino][origem]=1;	// Por se tratar de um grafo convencional, o seu inverso tambem receberá 1.
}

void mostra_matriz(int numVertice, int matriz_adj[numVertice][numVertice]){ // Funao de mostrar a matriz
	int i,j;
	printf("\n    Matriz de Adjacencia\n");
	for(i=0; i<numVertice; i++)		// Percorrendo a linha da matriz de adjacencia
	{
		for(j=0; j<numVertice; j++)	// Percorrendo a coluna da matriz de adjacencia
		{
			printf(" |%d|", matriz_adj[i][j]);
		}
		printf("\n");
	}
}

void remove_aresta(int numVertice, int matriz_adj[numVertice][numVertice], int origem, int destino){ // Funcao de remover uma ligacao (aresta).
	matriz_adj[origem][destino]=0;		// Para remover uma ligacao coloca-se apenas 0.
	matriz_adj[destino][origem]=0;		// Acontece a mesma coisa no seu inverso.
	printf("\nRemocao (%d, %d) concluida!\n", origem, destino);
}

void imprimeGrafo(int numVertice, int matriz_adj[numVertice][numVertice]){	// Funcao que imprime o grafo
	int i,j;								// Irá percorrer a matriz e onde encontrar uma ligacao, será impresso.
	printf("    Grafo\n");
	for(i=0; i<numVertice; i++){
		printf("v(%d): (",i);
		for(j=0; j<numVertice; j++){
			if (matriz_adj[i][j] == 1){
				printf("v%d ",j);
			}
		}
		printf(")");
		printf("\n");
	}
}

void verifica_aresta(int numVertice, int matriz_adj[numVertice][numVertice], int origem, int destino){ // Funcao para verificar se existe a aresta
	if (matriz_adj[origem][destino]==1) { 	
		printf("Existe!\n");
	}
	else{
		printf("Nao existe!\n");
	}
}

void verifica_adjacente(int numVertice, int matriz_adj[numVertice][numVertice], int vertice_adj){ // A funcao percorrera a matriz e se encontrar uma ligacao
	int i, cont;								// mostrará na tela
	for(i=0; i<numVertice; i++){
		if(matriz_adj[vertice_adj][i]==1){
			printf("v(%d) ",i);
			cont++;
		}
	}
	if (cont==0){				// Caso contrario, dirá que ela não possui adjacentes.
		printf("Nao possui adjacentes!");
	}
}

void grafo_completo(int numVertice, int matriz_adj[numVertice][numVertice]){ // Verifica se todos os vertices estao conectados entre si.
	int i, j, cont=0, chave=0;			
	for(i=0; i<numVertice; i++){		// Percorrendo a linha da matriz
		for(j=0; j<numVertice; j++){	// Percorrendo a coluna da matriz
			if(matriz_adj[i][j] == 0){	// Contará qunatas vezez aparece o zero.
				cont++;
			}
		}
		if  (cont>1){		// No momento que a contagem de zero da linha passar de 1, uma chave será ligada. Ela servirá para informar que 
			chave = 1;}	 // O grafo não é completo. Pois o grafo completo poderá apenas nao ter uma ligacao com si mesmo, mas com os outros seria obrigatorio acontecer.
		cont=0;		 // cont volta a ser 0 para que a nova contagem da proxima linha acontece desde o 0;
	}
	if (chave==1){	// Chave indicando se ela foi ligada, entao não é um grafo completo.
		printf("\n\nO grafo nao e completo!\n");
	}
	else{
		printf("\n\nO grafo e completo!\n"); // Chave nunca ligada, então o grafo é completo.
	}
}

void grafo_regular(int numVertice, int matriz_adj[numVertice][numVertice]){	// Assim como o garfo completo, o garfo regular terá uma chave para informar 
	int i,j,cont=0, compare,chave=0, chave_resposta=0;			// se é regular ou não. 
	for(i=0; i<numVertice; i++){		// Percorre a linha da matriz.
		for(j=0; j<numVertice; j++){	// Percorre a coluna da matriz.
			if(matriz_adj[i][j] == 1){		// Contagem para saber o grau dos vertices.
				cont++;
			}
		}
		if (chave==0){		// Chave auxiliar para pegar o valor total da primeira linha e comparar com as outas linhas.
			compare=cont;
			chave=1;
		}
		if (compare!=cont){	// Depois que pega o valor da primeira linha, começo a comparar com a segunda em diante. No momento que que a comparação der
			chave_resposta=1; 	// que elas são diferentes, então a chave_resposta será ligado, assim informando que o grau do vertice é diferente dos outros.
		}					
		cont=0;				// cont volta a ser 0 para que a nova contagem da proxima linha acontece desde o 0;
	}
	if (chave_resposta==1){	// Se cahve liga, então o grafo não é regular.
		printf("\nO grafo nao e regular!\n");
	}
	else{		// Do contrario, ela é regular.
		printf("\nO grafo e regular!\n");
	}
}

void liberaGrafo(int numVertice, int matriz_adj[numVertice][numVertice]){ // Funcao adicional apenas para liberar o valores do grafo.
	int i,j;
	for(i=0; i<numVertice; i++){
		for(j=0; j<numVertice; j++){
			if(matriz_adj[i][j] == 1){			// Quem tiver com 1 receberá 0; Arestas removidas.
				matriz_adj[i][j] = 0;
			}
		}
	}
}

int main(){
	int i,j;
	int numVertice, verifOrigem, verifDestino, vertice_adj;
	
	printf("O grafo tem quantos vertice? ");
	scanf("%d", &numVertice);
	
	int matriz_adj[numVertice][numVertice]; // Criacao do matriz.
	inicializaMatriz(numVertice, matriz_adj);
	mostra_matriz(numVertice, matriz_adj);
	

	insercao_matriz(numVertice, matriz_adj, 1,3);
	insercao_matriz(numVertice, matriz_adj, 0,2);
	insercao_matriz(numVertice, matriz_adj, 2,2);
	insercao_matriz(numVertice, matriz_adj, 3,4);
	mostra_matriz(numVertice, matriz_adj);
	
	/* // Grafo completo e regular.
	insercao_matriz(numVertice, matriz_adj, 0,1);
	insercao_matriz(numVertice, matriz_adj, 0,2);
	insercao_matriz(numVertice, matriz_adj, 0,3);
	insercao_matriz(numVertice, matriz_adj, 1,2);
	insercao_matriz(numVertice, matriz_adj, 3,1);
	insercao_matriz(numVertice, matriz_adj, 2,3);
	mostra_matriz(numVertice, matriz_adj);
	*/
	
	remove_aresta(numVertice, matriz_adj, 2,2);
	mostra_matriz(numVertice, matriz_adj);
	imprimeGrafo(numVertice, matriz_adj);
	
	printf("\n    Verifica aresta\n");
	printf("Digite o vertice de origem:");
	scanf("%d", &verifOrigem);
	printf("Digite o vertice de destino:");
	scanf("%d", &verifDestino);
	verifica_aresta(numVertice, matriz_adj, verifOrigem, verifDestino);
	
	printf("\n    Verifica adjacentes\n");
	printf("Digite o vertice: ");
	scanf("%d", &vertice_adj);
	verifica_adjacente(numVertice, matriz_adj, vertice_adj);
	grafo_completo(numVertice, matriz_adj);
	grafo_regular(numVertice, matriz_adj);
	
	
											// funcao adicional de libera grrafo
	//printf("\n\n    LIBERANDO GRAFO ");
	//liberaGrafo(numVertice, matriz_adj);
	//mostra_matriz(numVertice, matriz_adj);
	//imprimeGrafo(numVertice, matriz_adj);
}



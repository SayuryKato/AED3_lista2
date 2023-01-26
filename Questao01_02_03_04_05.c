#include <stdio.h>
#include <stdlib.h>

void inicializaMatriz(int numVertice, int matriz_adj[numVertice][numVertice]){
	int i,j;
	for (i=0; i<numVertice; i++){
		for(j=0; j<numVertice; j++){
			matriz_adj[i][j]=0;
		}
	}
}


void insercao_matriz(int numVertice, int matriz_adj[numVertice][numVertice], int origem, int destino){
	matriz_adj[origem][destino]=1;
	matriz_adj[destino][origem]=1;
}

void mostra_matriz(int numVertice, int matriz_adj[numVertice][numVertice]){
	int i,j;
	printf("\n    Matriz de Adjacencia\n");
	for(i=0; i<numVertice; i++)
	{
		for(j=0; j<numVertice; j++)
		{
			printf(" |%d|", matriz_adj[i][j]);
		}
		printf("\n");
	}
}

void remove_aresta(int numVertice, int matriz_adj[numVertice][numVertice], int origem, int destino){
	matriz_adj[origem][destino]=0;
	matriz_adj[destino][origem]=0;
	printf("\nRemocao (%d, %d) concluida!\n", origem, destino);
}

void imprimeGrafo(int numVertice, int matriz_adj[numVertice][numVertice]){
	int i,j;
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

void verifica_aresta(int numVertice, int matriz_adj[numVertice][numVertice], int origem, int destino){
	if (matriz_adj[origem][destino]==1) {
		printf("Existe!\n");
	}
	else{
		printf("Nao existe!\n");
	}
}

void verifica_adjacente(int numVertice, int matriz_adj[numVertice][numVertice], int vertice_adj){
	int i, cont;
	for(i=0; i<numVertice; i++){
		if(matriz_adj[vertice_adj][i]==1){
			printf("v(%d) ",i);
			cont++;
		}
	}
	if (cont==0){
		printf("Nao possui adjacentes!");
	}
}

void grafo_completo(int numVertice, int matriz_adj[numVertice][numVertice]){
	int i, j, cont=0, chave=0;
	for(i=0; i<numVertice; i++){
		for(j=0; j<numVertice; j++){
			if(matriz_adj[i][j] == 0){
				cont++;
			}
		}
		if  (cont>1){
			chave = 1;}
		cont=0;
	}
	if (chave==1){
		printf("\n\nO grafo nao e completo!\n");
	}
	else{
		printf("\n\nO grafo e completo!\n");
	}
}

int main(){
	int i,j;
	int numVertice, verifOrigem, verifDestino, vertice_adj;
	
	printf("O grafo tem quantos vertice? ");
	scanf("%d", &numVertice);
	
	int matriz_adj[numVertice][numVertice]; 
	inicializaMatriz(numVertice, matriz_adj);
	mostra_matriz(numVertice, matriz_adj);
	
	/*
	insercao_matriz(numVertice, matriz_adj, 1,3);
	insercao_matriz(numVertice, matriz_adj, 0,2);
	insercao_matriz(numVertice, matriz_adj, 2,2);
	insercao_matriz(numVertice, matriz_adj, 3,4);
	mostra_matriz(numVertice, matriz_adj);
	*/
	
	insercao_matriz(numVertice, matriz_adj, 0,1);
	insercao_matriz(numVertice, matriz_adj, 0,2);
	insercao_matriz(numVertice, matriz_adj, 0,3);
	insercao_matriz(numVertice, matriz_adj, 1,2);
	insercao_matriz(numVertice, matriz_adj, 3,1);
	insercao_matriz(numVertice, matriz_adj, 2,3);
	mostra_matriz(numVertice, matriz_adj);
	
	
	//remove_aresta(numVertice, matriz_adj, 2,2);
	//mostra_matriz(numVertice, matriz_adj);
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
	
	/*
	LiberaGrafo(numVertice, matriz_adj);
	ImprimeMatiz(numVertice, matriz_adj);
	*/
}



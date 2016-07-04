/*
 * File: main.cpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:39
 */

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
#include <vector>
#include <math.h>
#include <limits.h>
#include "vertex.cpp"
#include "edge.cpp"

using namespace std;

void makeSet(vector<Vertex>  vertice, Vertex *vertex); 
void quickSort(Vertex *vertex, int esq, int dir); 
float findWay(vector<Vertex> vertice,int position);

int main(int argc, char **argv){
	float x; // Store coordinate X
	float y; // Store coordinate Y
	int size;
	vector<Vertex>  vertices; // Vector of vertex

    if(argc !=2){ 
		cout << "\nForma de uso: c:\nome_programa nome_arquivo " << endl; 
        exit(1);          
    } 
	
	FILE *arq;
	// Opening of the file passed by parameter
	arq = fopen(argv[1], "r");
	if(arq == NULL)
			printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		fscanf(arq,"%d\n",&size);	// Capture the total number of vertices
		vertices.resize(size); // Resizes the vector for total number of vertices
 
		for(int i = 0; i < size;i++){	// Loop for reading vertices from the input file
			if((fscanf(arq,"%f %fn", &x, &y))!=EOF){
				vertices[i].setX(x);	// coordinate X
				vertices[i].setY(y);	// coordinate y
			}
		}

	}
	
	// =====================================================

	// =====================================================

	for(int i=0; i < size; i++){
		makeSet(vertices,&vertices[i]); // Creates a complete graph, each vertice has a vector of edges (with weights) for all other vertices
	}

	float custos[size];
	float menorCaminho=INT_MAX;
	for(int i=0; i< size; i++){ // Find the path of the nearest neighbor, starting all vertices.
		custos[i]=findWay(vertices,i);
	}

	for(int i = 0; i < size; i++){
		if(menorCaminho > custos[i])
			menorCaminho = custos[i];
	}
	// =========================================================

	cout << endl << menorCaminho << endl<<endl; // Total minimum length of edges
	
	return 0;
}

// ================================================================
// Encontra um caminho de acordo com o vizinho mais próximo
// ================================================================
float findWay(vector<Vertex> vertice, int position){
	float w=0;
	int aux;
	int ligacao=0;
	while(ligacao < vertice.size()-1){ // Fica no laço enquanto não visitar todos os vertices
		for(int j = 0; j < vertice[position].edges.size(); j++ ){
			aux = vertice[position].edges[j].getCoordinate();
			if(vertice[aux].getVisited() == 0){	// Verifica se o vertice de destino já foi Visitado
				vertice[position].setVisited();		
				w += vertice[position].edges[j].getWeight();
				vertice[position].edges.pop_back();	// Retira esta aresta da fila
				position = aux; // Vertice de destino passa a ser o vertice atual
				ligacao+=1;	// Incrementa contador de conexões
				j=0;	// J volta a ser zero para percorrer o vetor de arestas do inicio
			}
		}
		
	}
	return w;
}

// ================================================================
// Cria um grafo completo, cada vértice tem um vetor de arestas (com pesos) para todos os outros vértices
// ================================================================
void makeSet(vector<Vertex> vertice,Vertex *vertex){
	float w;
	Edge edge;
	for(int i = 0 ; i < vertice.size(); i++){
		if( (vertice[i].getX() != vertex->getX()) || vertice[i].getY() != vertex->getY())  {
			// Weight calculation between two coordinates. Pythagoras theorem.
			w = pow(vertex->getX() - vertice[i].getX(),2) + pow((vertex->getY() - vertice[i].getY()),2);
			if(w < 0)
				w *= -1;
			w = sqrt(w);
			// ==============================================================

			edge.setCoordinate(i);	// Coordinate of vertice edge connection
			edge.setWeight(w);		// Weight of edge
			if(edge.getWeight() > 0)
				vertex->edges.push_back(edge); // Add edge to the vector contained in vertice
		}
	}
	quickSort(vertex,0,vertex->edges.size());
}

// ================================================================
// Algoritmo de ordenação para o vetor de pesos das arestas
//=================================================================
void quickSort(Vertex *vertex, int esq, int dir){
    int pivo = esq,i,ch,j;
    Edge edge;
    for( i = esq+1; i<= dir; i++){
        j = i;
        if(vertex->edges[i].getWeight() < vertex->edges[pivo].getWeight() && vertex->edges[i].getWeight() > 0){
         	edge = vertex->edges[j];
         while(j > pivo){    
            vertex->edges[j] = vertex->edges[j-1];
            j--;
         }
         vertex->edges[j] = edge;
         pivo++;        
        }  
    }
    if(pivo-1 >= esq){
        quickSort(vertex,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quickSort(vertex,pivo+1,dir);
    }
}
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <math.h> 
#include <unistd.h>
#include <math.h>   // Libreria para sqrt() y pow()
#include <unistd.h> // Libreria usada para sleep(2) 

// Variables globales
int NumeroDeVectores = 100;  // cantidad de elementos por vector
int Quantum = 10;           // numero de elementos que procesa cada proceso en un turno
int j = 0;
int i = 0;
int k = 0;
int p = 0;
int p = 0;              // Nueva variable: usada en Resultados() para recorrer índices impresos
int NumeroDeVueltas = 0;
int Escalar = 4;

int V1[100], V2[100];
int R_Suma[100], R_Resta[100];
float R_Magnitud[100];
int R_Escalar1[100], R_Escalar2[100];
int R_ProductoPunto = 0;
int Prioridades[5];

int Prioridades[5];     // arreglo de prioridades

// Función que genera los vectores de entrada V1 y V2 con números aleatorios
void GenerarVectores(){
	int i;
	for(i = 0 ; i < NumeroDeVectores ; i++){
    	V1[i]=(rand() % 100) + 1;   
    	V2[i]=(rand() % 100) + 1;
    }
    printf("----- Vector 1 -----\n[");
    for(i = 0 ; i < NumeroDeVectores ; i++){
    	if(i == NumeroDeVectores - 1){
    		printf("%d]\n\n", V1[i]);
		}
		else{
			printf("%d, ", V1[i]);
		}
	}
	
	printf("----- Vector 2 -----\n[");
    for(i = 0 ; i < NumeroDeVectores ; i++){
    	if(i == NumeroDeVectores - 1){
    		printf("%d]\n\n", V2[i]);
		}
		else{
			printf("%d, ", V2[i]);
		}
	}

    printf("\n--- Vectores generados aleatoriamente ---\n");

    // Imprimir valores de V1
    printf("Valores de V1:\n");
    for(i = 0 ; i < NumeroDeVectores ; i++){
        printf("V1[%d] = %d\n", i, V1[i]);
    }

    // Imprimir valores de V2
    printf("\nValores de V2:\n");
    for(i = 0 ; i < NumeroDeVectores ; i++){
        printf("V2[%d] = %d\n", i, V2[i]);
    }
}

void Resultados(){
	
	printf("------PROCESO %d con prioridades [%d, %d, %d, %d, %d]------\n", i/10, Prioridades[0],Prioridades[1],Prioridades[2],Prioridades[3],Prioridades[4]);
	
	printf("Suma:\n[");
	for(p = 0 ; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Suma[p]);
		}
		else{
			printf("%d, ", R_Suma[p]);
		}
	}
	
	printf("Resta:\n[");
	for(p = 0 ; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Resta[p]);
		}
		else{
			printf("%d, ", R_Resta[p]);
		}
	}
	
	printf("Magnitud:\n[");
	for(p = 0 ; p < i ; p++){
    	if(p == i - 1){
    		printf("%.2f]\n\n", R_Magnitud[p]);
		}
		else{
			printf("%.2f, ", R_Magnitud[p]);
		}
	}
	
	printf("Producto Escalar:\n[ %d ",R_ProductoPunto);
	printf("]\n\n");
	
	printf("Vector 1 por Escalar:\n[");
	for(p = 0 ; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Escalar1[p]);
		}
		else{
			printf("%d, ", R_Escalar1[p]);
		}
	}
	printf("Vector 2 Por Escalar:\n[",R_Escalar2[p]);
	for(p = 0 ; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n\n\n", R_Escalar2[p]);
		}
		else{
			printf("%d, ", R_Escalar2[p]);
		}
	}
		 
	if(i == 100){
		printf("---------------------FIN DE PROCESO---------------------\n\n\n");
		
	}
}


void llenarPrioridades(){
	int pri;
	int k = 0;
	int l = 0;
	bool flag;
	while(k < 5){
		flag = true;
		pri = rand() % 5;           //generamos valor aleatorio entre 0 y 4
		// verificamos que la prioridad asignada no se repita
		for( l = 0 ; l < k ; l++){
			if(Prioridades[l] == pri){ // si la prioridad es la misma que otra, genera un valor entero nuevo
				flag = false;
				break;
			}
		}
		if(flag){       //cuando el de prioridad es diferente de uno ya asignado se guarda 
			Prioridades[k] = pri;
			k++;
		}
	}
}

// ---------------------------- Procesos --------------------------------------------------
void SumaVectores(int i){
	R_Suma[i] = V1[i] + V2[i];
    
}

void RestaVectores(int i){
	R_Resta[i] = V1[i] - V2[i];
}

void MagnitudVectores(int i){
	R_Magnitud[i] = sqrt(pow(V1[i],2)+pow(V2[i],2));

}

void ProductoVectores(int i){
	R_ProductoPunto += (V1[i]*V2[i]);
}

void EscalarVectores(int i){
	R_Escalar1[i] = Escalar * V1[i];
	R_Escalar2[i] = Escalar * V2[i];
}

void ProductoVectores(int i){
	R_ProductoPunto += (V1[i]*V2[i]);
}

void EscalarVectores(int i){
	R_Escalar1[i]=Escalar*V1[i];
	R_Escalar2[i]=Escalar*V2[i];
}
// -------------------------- MAIN -----------------------------------------
int main(void){
	srand((unsigned)time(NULL)); // inicializa la semilla
	GenerarVectores();
	
	void (*ops[])(int) = {SumaVectores, RestaVectores, MagnitudVectores, ProductoVectores, EscalarVectores};
	i = 0;
	while(1){
		llenarPrioridades();
		for(j = 0 ; j < 5 ; j++){
			for(k = 0 ; k < Quantum ; k++){
				ops[Prioridades[j]](k + i);
			}
		}
		i += k;
		Resultados();
		if(i == 100){
			i = 0;
			GenerarVectores();
		} 
		sleep(3);
	}
	return 0;
}


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <math.h>   // Libreria para sqrt() y pow()
#include <unistd.h> // Libreria usada para sleep(2) 

// Variables globales
int NumeroDeVectores = 100;  // cantidad de elementos por vector
int Quantum = 10;           // numero de elementos que procesa cada proceso en un turno
int j = 0;
int i = 0;
int k = 0;
int p = 0;              // Nueva variable: usada en Resultados() para recorrer índices impresos
int NumeroDeVueltas = 0;
int Escalar = 4;        //  Nueva variable: define el valor con el que se multiplican vectores

// Vectores de entrada
int V1[100],V2[100];

// Vectores de resultados
int R_Suma[100];        // resultado de la suma 
int R_Resta[100];       // resultado de la resta
//float R_Modulo[100];    // -------------------> este no se usa ya. no?
float R_Magnitud[100];  // resultado de magnitud entre vectores
int R_Escalar1[100],R_Escalar2[100]; //Resutados de multiplicacion de V1 y V2 por un escalar
int R_Producto=0;       // resultado de producto punto entre vectores

int Prioridades[5];     // arreglo de prioridades

// Función que genera los vectores de entrada V1 y V2 con números aleatorios
void GenerarVectores(){
    int i;
    // Llenamos V1 y V2 con valores aleatorios
    for(i = 0 ; i < NumeroDeVectores ; i++){
        V1[i] = (rand() % 100) + 1;   
        V2[i] = (rand() % 100) + 1;  
        //printf("%d. Vector 1  = %d\n",i,V1[i]);
    	//printf("%d. Vector 2  = %d\n",i,V2[i]);
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

//Funcion que imprime resultados parciales de cada proceso
void Resultados(){
	while(p!=k){
	// esto no jala del todo pero ya tengo mucho sueño y ya mañana lo checo con calmita, pero creo que en ese formato se entienden bien los resultados
	printf("Suma:\n");
    while(p != k){
        printf("%d ", R_Suma[p]);
        p++;
    }
    printf("\n");
    
	printf("Resta:\n");
    while(p != k){
        printf("%d ", R_Resta[p]);
        p++;
    }
    printf("\n");    
	
    printf("Magnitud:\n");
    while(p != k){
        printf("%f ", R_Magnitud[p]);
        p++;
    }
    printf("\n");   
    
    printf("Producto Escalar:\n");
        printf("%d ", R_Producto);
    printf("\n"); 
    
    printf("V1 por un escalar:\n");
    while(p != k){
        printf("%d ", R_Escalar1[p]);
        p++;
    }
    printf("\n"); 
    printf("V2 por un escalar:\n");
    while(p != k){
        printf("%d ", R_Escalar2[p]);
        p++;
    }
    printf("\n"); 
	/*printf("Suma = %d\n",R_Suma[p]);  // -------------> cambiamos i por p
	printf("Resta = %d\n",R_Resta[p]);
	printf("Magnitud = %f\n",R_Magnitud[p]);
	printf("Producto Escalar = %d\n",R_Producto);
	printf("Vector1 por Escalar = %d\n",R_Escalar1[p]);
	printf("Vector2 Por Escalar = %d\n",R_Escalar2[p]);*/
	p++;
}
p=k;
if(k==100){
	p=0;
}
	//sleep(2); //pausa de dos segundos entre impresion de resultados ---------> lo movimos a main
}

// funcion que asigna orden de prioridades aleatorios
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
	// imprimimos arreglo de prioridades generado
	printf("\n--- Arreglo de prioridades generado: ---\n");
	printf("[%d, %d, %d, %d, %d] \n", Prioridades[0],Prioridades[1],Prioridades[2],Prioridades[3],Prioridades[4]);
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
	R_Producto += (V1[i]*V2[i]);
}

void EscalarVectores(int i){
	R_Escalar1[i]=Escalar*V1[i];
	R_Escalar2[i]=Escalar*V2[i];
}
// -------------------------- MAIN -----------------------------------------
int main(void){
	srand((unsigned)time(NULL)); // inicializa la semilla de aleatorios
	GenerarVectores();          // genera vectores V1 y V2
	
    // Arreglo de puntreos a funcion, apuntamos a las operaciones existentes
	void (*ops[])(int) = {SumaVectores, RestaVectores, MagnitudVectores, ProductoVectores,EscalarVectores};

	i = 0;
	while(1){  // iniciamos bucle infinito
		llenarPrioridades(); // asignamos orden de prioridad aleatorio a cada proceso
		for(j = 0 ; j < 5 ; j++){ // recorremos los 5 procesos en el orden de prioridad asignado
			for(k = 0 ; k < Quantum ; k++){ // ejecutamos cada proceso durante 10 quantums
				ops[Prioridades[j]](k + i);
			}
		}
		i += k; // -----------------------------> ajuste: actualiza valor de i
		sleep(3); // ---------------------------> sleep aqui en vez de en resultados
		Resultados(); //Imprimimos resultados obtenidos
		if(i == 100){
			i = 0;
			GenerarVectores(); //Genera nuevos vectores V1 y v2 cuando se han completado todos lor procesos.
		} 
	}
	
	return 0;
}


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
int j = 0;                    // Variable para recorrer los 5 procesos
int i = 0;                    // Variable para recorrer el numero de dato del vector
int k = 0;                    // Variable para recorrer los 10 ticks
int p = 0;                   // Variable para recorrer índices impresos
int NumeroDeVueltas = 0;
int Escalar = 4;        //Variable para el escalador

// Vectores de entrada
int V1[100],V2[100];

// Vectores de resultados
int R_Suma[100];        // resultado de la suma 
int R_Resta[100];       // resultado de la resta
float R_Magnitud[100];  // resultado de magnitud entre vectores
int R_Escalar1[100],R_Escalar2[100]; //Resutados de multiplicacion de V1 y V2 por un escalar
int R_ProductoPunto=0;  // codigo nuevo: antes estaba como R_Producto, ahora es R_ProductoPunto

int Prioridades[5];     // arreglo de prioridades

char Operaciones[5][20]={"Suma:","Resta:","Magnitud","Producto:","Escalar1:  Escalar2:"};

// Función que genera los vectores de entrada V1 y V2 con números aleatorios
void GenerarVectores(){
    int i;
    // Llenamos V1 y V2 con valores aleatorios
    for(i = 0 ; i < NumeroDeVectores ; i++){
        V1[i] = (rand() % 100) + 1;   
        V2[i] = (rand() % 100) + 1;  
    }

    	
		}


void printResta(){
	if(Prioridades[4]==1){
			
    	printf("%d\n", R_Resta[p]);
    }
    else{
    	printf("%d\t", R_Resta[p]);
	}		
	
	
	
	
}

void printSuma(){
    
	if(Prioridades[4]==0){
			
    	printf("%d\n", R_Suma[p]);
    }
    else{
    		printf("%d\t", R_Suma[p]);
	}
    	
}


void printMagnitud(){
	if(Prioridades[4]==2){
			
    	printf("%.2f\n", R_Magnitud[p]);
    }
    else{
    	printf("%.2f\t", R_Magnitud[p]);
	}
}


void printProducto(){

    
	if(Prioridades[4]==3){
			
    	printf("%d\n", R_ProductoPunto);
    }
    else{
    	printf("%d\t", R_ProductoPunto);
	}		
		
}

	
//print
void printEscalar(){

    
	if(Prioridades[4]==4){
			
    	printf("%d\t\t%d\n", R_Escalar1[p],R_Escalar2[p]);
    }
    else{
    	printf("%d\t\t%d\t", R_Escalar1[p],R_Escalar2[p]);
	}		
		
}
	


//Funcion que imprime resultados parciales de cada proceso
void Resultados(){

	printf("------PROCESO %d con prioridades [%d, %d, %d, %d, %d]------\n", i/10, Prioridades[0],Prioridades[1],Prioridades[2],Prioridades[3],Prioridades[4]);
	printf("Vector1 Vector2 %s %s %s %s %s\n",Operaciones[Prioridades[0]],Operaciones[Prioridades[1]],Operaciones[Prioridades[2]],Operaciones[Prioridades[3]],Operaciones[Prioridades[4]]);
	for(p = i - Quantum; p < i ; p++){
		printf("%d\t", V1[p]);
			printf("%d\t", V2[p]);
		for(j=0;j < 5; j++ ){
			switch(Prioridades[j]){
				case 0:
					printSuma();
					break;
			
				case 1:
					printResta();
					break;
			
				case 2:
					printMagnitud();
					break;
			
				case 3:
					printProducto();
					break;
	
				case 4:
					printEscalar();
					break;
			}
		}
	}	
	
	if(i == 100){
		printf("---------------------FIN DE PROCESO---------------------\n\n\n");
	}
}

// funcion que asigna orden de prioridades aleatorios
void LlenarPrioridades(){
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
	R_ProductoPunto += (V1[i]*V2[i]); // codigo nuevo: acumulador usa R_ProductoPunto
	
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
		LlenarPrioridades(); // asignamos orden de prioridad aleatorio a cada proceso
		for(j = 0 ; j < 5 ; j++){ // recorremos los 5 procesos en el orden de prioridad asignado
			for(k = 0 ; k < Quantum ; k++){ // ejecutamos cada proceso durante 10 quantums
				ops[Prioridades[j]](k + i);
			}
			
		}
		i += k; //actualiza valor de i
		sleep(3); // pausa para ver resultados
		Resultados(); //Imprimimos resultados obtenidos
		if(i == 100){
			i = 0;
			GenerarVectores(); //Genera nuevos vectores V1 y v2 cuando se han completado todos lor procesos.
		} 
	}
	
	return 0;
}

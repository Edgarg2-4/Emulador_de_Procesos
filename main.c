#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>

int NumeroDeVectores = 100;
int Quantum = 10;
int j = 0;
int i = 0;
int k = 0;
int NumeroDeVueltas = 0;

typedef struct{
    int x;
    int y;
}Vector;

Vector V1[100];
Vector V2[100];

Vector R_Suma[100];
Vector R_Resta[100];

float R_Modulo[100];
float R_Escalar[100];

int Prioridades[5];


void GenerarVectores(){
	int i;
	for(i = 0 ; i < NumeroDeVectores ; i++){
    	V1[i].x=(rand() % 100) + 1;
    	V1[i].y=(rand() % 100) + 1;    
    	V2[i].x=(rand() % 100) + 1;   	
    	V2[i].y=(rand() % 100) + 1;
		printf("%d. Vector 1 x = %d, y = %d\n",i,V1[i].x, V1[i].y);
    	printf("%d. Vector 2 x = %d, y = %d\n",i,V2[i].x, V2[i].y);
    }

}

void llenarPrioridades(){
	int pri;
	int k = 0;
	int l = 0;
	bool flag;
	while(k < 5){
		flag = true;
		pri = rand() % 5;
		for( l = 0 ; l < k ; l++){
			if(Prioridades[l] == pri){
				flag = false;
				break;
			}
		}
		if(flag){
			Prioridades[k] = pri;
			k++;
		}
	}
	printf("[%d, %d, %d, %d, %d] \n", Prioridades[0],Prioridades[1],Prioridades[2],Prioridades[3],Prioridades[4]);
}

void SumaVectores(int i){
	R_Suma[i].x = V1[i].x + V2[i].x;
	R_Suma[i].y = V1[i].y + V2[i].y;
    printf("Suma: x = %d, y = %d\n",R_Suma[i].x, R_Suma[i].y);
}

void RestaVectores(int i){
	R_Resta[i].x = V1[i].x - V2[i].x;
	R_Resta[i].y = V1[i].y - V2[i].y;
    printf("Resta: x = %d, y = %d\n",R_Resta[i].x, R_Resta[i].y);
}

void ModuloVectores(int i){
	R_Modulo = 1;
}

int main(void){
	srand((unsigned)time(NULL)); // inicializa la semilla
	GenerarVectores();
	void (*ops[])(int) = {SumaVectores, RestaVectores, ModuloVectores};
	i = 0;
	while(i < 100){
		llenarPrioridades();
		for(j = 0 ; j < 5 ; j++){
			for(k = 0 ; k < 10 ; k++){
				ops[Prioridades[j]](k + i);
			}
		}
		i = k;
		//Función para imprimir los resultados
		if(i == 100){
			//delay
			i = 0;
			GenerarVectores();
			
		} 
		
	}
	
	
	/*while(i < 100){
		ops[0](i);
		ops[1](i);
		i++;
	}
	for(j = 0 ; j < 10 ; j++){
		llenarPrioridades();
	}*/
	return 0;
}








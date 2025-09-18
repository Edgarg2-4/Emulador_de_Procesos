#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>
#include <math.h> 
#include <unistd.h>

int NumeroDeVectores = 100;
int Quantum = 10;
int j = 0;
int i = 0;
int k = 0;
int p = 0;
int NumeroDeVueltas = 0;
int Escalar = 4;

int V1[100],V2[100],R_Suma[100], R_Resta[100];
float R_Modulo[100], R_Magnitud[100];
int R_Escalar1[100],R_Escalar2[100];
int R_Producto=0;
int Prioridades[5];


void GenerarVectores(){
	int i;
	for(i = 0 ; i < NumeroDeVectores ; i++){
    	V1[i]=(rand() % 100) + 1;   
    	V2[i]=(rand() % 100) + 1;   	
	//	printf("%d. Vector 1 x = %d, y = %d\n",i,V1[i].x, V1[i].y);
    //	printf("%d. Vector 2 x = %d, y = %d\n",i,V2[i].x, V2[i].y);
    }

}

void Resultados(){
	while(p!=k){
	printf("Suma = %d\n",R_Suma[i]);
	printf("Resta = %d\n",R_Resta[i]);
	printf("Magnitud = %f\n",R_Magnitud[i]);
	printf("Producto Escalar = %d\n",R_Producto);
	printf("Vector1 por Escalar = %d\n",R_Escalar1[i]);
	printf("Vector2 Por Escalar = %d\n",R_Escalar2[i]);
	p++;
}
p=k;
if(k==100){
	p=0;

}
	sleep(2);

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

int main(void){
	srand((unsigned)time(NULL)); // inicializa la semilla
	GenerarVectores();
	
	void (*ops[])(int) = {SumaVectores, RestaVectores, ProductoVectores, MagnitudVectores,};
	i = 0;
	while(1){
		llenarPrioridades();
		for(j = 0 ; j < 5 ; j++){
			for(k = 0 ; k < 10 ; k++){
				ops[Prioridades[j]](k + i);
			}
		}
		i = k;
		Resultados();
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








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
int pos = 0;
int val = 0;

// Vectores de entrada
int V1[100],V2[100];

// Vectores de resultados
int R_Suma[100];        // resultado de la suma 
int R_Resta[100];       // resultado de la resta
float R_Magnitud[100];  // resultado de magnitud entre vectores
int R_Escalar1[100],R_Escalar2[100]; //Resutados de multiplicacion de V1 y V2 por un escalar
int R_ProductoPunto=0;  // codigo nuevo: antes estaba como R_Producto, ahora es R_ProductoPunto

int Prioridades[5];     // arreglo de prioridades

// Función que genera los vectores de entrada V1 y V2 con números aleatorios
void GenerarVectores(){
    int i;
    // Llenamos V1 y V2 con valores aleatorios
    for(i = 0 ; i < NumeroDeVectores ; i++){
        V1[i] = (rand() % 100) + 1;   
        V2[i] = (rand() % 100) + 1;  
    }

    //Impresión de Vector 1
    printf("----- Vector 1 -----\n[");
    for(i = 0 ; i < NumeroDeVectores ; i++){
    	if(i == NumeroDeVectores - 1){
    		printf("%d]\n\n", V1[i]);
		}
		else{
			printf("%d, ", V1[i]);
		}
	}
    //Impresión de Vector 2
	printf("----- Vector 2 -----\n[");
    for(i = 0 ; i < NumeroDeVectores ; i++){
    	if(i == NumeroDeVectores - 1){
    		printf("%d]\n\n", V2[i]);
		}
		else{
			printf("%d, ", V2[i]);
		}
	}
}

//Funcion que imprime resultados parciales de cada proceso -------------------- ya no se usa ---------------------------------
void Resultados(){

	printf("------PROCESO %d con prioridades [%d, %d, %d, %d, %d]------\n", i/10, Prioridades[0],Prioridades[1],Prioridades[2],Prioridades[3],Prioridades[4]);
	
	printf("Suma:\n[");
	for(p = i - Quantum; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Suma[p]);
		}
		else{
			printf("%d, ", R_Suma[p]);
		}
	}
	
	printf("Resta:\n[");
	for(p = i - Quantum; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Resta[p]);
		}
		else{
			printf("%d, ", R_Resta[p]);
		}
	}
	
	printf("Magnitud:\n[");
	for(p = i - Quantum; p < i ; p++){
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
	for(p = i - Quantum; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Escalar1[p]);
		}
		else{
			printf("%d, ", R_Escalar1[p]);
		}
	}
	printf("Vector 2 Por Escalar:\n[",R_Escalar2[p]);
	for(p = i - Quantum; p < i ; p++){
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
	printf("------PROCESO %d con prioridades [%d, %d, %d, %d, %d]------\n", i/10, Prioridades[0],Prioridades[1],Prioridades[2],Prioridades[3],Prioridades[4]);
}

// ---------------------------- Procesos --------------------------------------------------
void SumaVectores(int i){
	R_Suma[i] = V1[i] + V2[i];
	
	if(k==Quantum-1){
	    printf("Suma:\n[");
	    for(p = i - Quantum; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Suma[p]);
		}
		else{
			printf("%d, ", R_Suma[p]);
		}
	}
	}
	
}

void RestaVectores(int i){
	R_Resta[i] = V1[i] - V2[i];
	
	if(k==Quantum-1){
	    printf("Resta:\n[");
	    for(p = i - Quantum; p < i ; p++){
    	if(p == i - 1){
    		printf("%d]\n\n", R_Resta[p]);
		}
		else{
			printf("%d, ", R_Resta[p]);
		}
	}
	}
}

void MagnitudVectores(int i){
	R_Magnitud[i] = sqrt(pow(V1[i],2)+pow(V2[i],2));
	if(k==Quantum-1){
	    printf("Magnitud:\n[");
	    for(p = i - Quantum; p < i ; p++){
    	    if(p == i - 1){
    		    printf("%.2f]\n\n", R_Magnitud[p]);
		    }
		    else{
		    	printf("%.2f]\n\n", R_Magnitud[p]);
		    }
	    }
	}
}

void ProductoVectores(int i){
	R_ProductoPunto += (V1[i]*V2[i]); // codigo nuevo: acumulador usa R_ProductoPunto
	
	if(k==Quantum-1){
	    printf("Producto Escalar:\n[ %d ",R_ProductoPunto); 
	    printf("]\n\n");
	}
}

void EscalarVectores(int i){
	R_Escalar1[i]=Escalar*V1[i];
	R_Escalar2[i]=Escalar*V2[i];
	
	if(k==Quantum-1){
	    printf("Vector 1 por Escalar:\n[");
	    for(p = i - Quantum; p < i ; p++){
    	    if(p == i - 1){
    		    printf("%d]\n\n", R_Escalar1[p]);
		    }
		    else{
		    	printf("%d, ", R_Escalar1[p]);
		    }
	    }
	    printf("Vector 2 por Escalar:\n[");
	    for(p = i - Quantum; p < i ; p++){
    	    if(p == i - 1){
    		    printf("%d]\n\n", R_Escalar2[p]);
		    }
		    else{
		    	printf("%d, ", R_Escalar2[p]);
		    }
	    }
	}
	
	
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
		// --------------------------------------- añadi esto
		val = 0;
		pos = 0;
		while(val <= 4){ // ejecuta los 5 procesos
		//printf("Valor val: %d \n",val);
		//printf("Valor pos: %d \n",pos);
		//printf("Prioridad[pos]: %d \n",Prioridades[pos]);
		    if(Prioridades[pos] == val){ // revisamos si el valor de la posicion es igual al valor de prioridad
		        for(k = 0 ; k < Quantum ; k++){ // ejecutamos cada proceso durante 10 quantums
    				ops[pos](k + i); // una vez que se encuentra en la posicion correcta, ejecuta ese proceso
    			}
    		    if(val > 4){ //Reseteamos val si se excede de numero de prioridades
		            val = 0;
		        }else{
		            val++;
		        }
    			if(pos > 4){//Reseteamos pos si se excede de numero de posiciones
		            pos = 0;
		        }else{
		            pos++;
		        }
		        i += k; //actualiza valor de i
    		    sleep(1); // pausa para ver resultados
    		    //Resultados(); //Imprimimos resultados obtenidos
    			
		    }else{
		        if(pos > 4){ // si la posicion excede el numero de elementos del vector, se reinicia
		            pos = 0;
		        }else{
		            pos++;
		        }
		    }
		} // cierre de while( val < 5)
        if(i == 100){
    		i = 0;
    		GenerarVectores(); //Genera nuevos vectores V1 y v2 cuando se han completado todos lor procesos.
    		R_ProductoPunto = 0;
    	} 
	} // cierre del while(1)
	return 0;
}

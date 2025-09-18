#include<stdio.h>
#include <stdlib.h> 
#include <time.h>

int NumeroDeVectores=100;
int Quantum=10;
int *Proceso;
int NumeroDeTick=0;
int i=0;
int NumeroDeVueltas=0;
struct Vector{
    float x;
    float y;
	//No se donde tengamos que utilizar malloc
	//No estoy seguro de como utilizar los apuntadores
	//Tal Vez con un Apuntador a un arreglo

}Vector1[100],Vector2[100],Suma[100],Resta[100]; //Forma Rectangular


int main(){
	
srand(time(NULL)); // inicializa la semilla
GenerarVectores();
SumaVectores();
RestaVectores();
printf("Se acabo Planificador");
//while ()
//{
    /* code */
//}



}

int GenerarVectores(){
	for(i=0;i<NumeroDeVectores;i++){
    	

    	

    	Vector1[i].Magnitud=(rand()%200)+1;
    	Vector1[i].Angulo=(rand()%100)+1;    
    	Vector2[i].Magnitud=(rand()%200)+1;   	
    	Vector2[i].Angulo=(rand()%100)+1;
		printf("Vector 1 %d Magnitud: %f\n",i,Vector1[i].Magnitud);
    	printf("Vector 1 %d Angulo: %f\n",i,Vector1[i].Angulo);
    	printf("Vector 2 %d Magnitud: %f\n",i,Vector2[i].Magnitud);
    	printf("Vector 2 %d Angulo: %f\n",i,Vector2[i].Angulo);
    }

}

//int MagnitudDeVectores(){
//Raiz de del cuadrado de la resta magnitud y resta del angulo

//}


int RestaVectores(){
	for(i=0;i<NumeroDeVectores;i++){
		Resta[i].Magnitud=Vector1[i].Magnitud-Vector2[i].Magnitud;
		Resta[i].Angulo=Vector1[i].Angulo-Vector2[i].Angulo;
		NumeroDeTick++;
		printf("Vector Resta %d Magnitud: %f\n",i,Resta[i].Magnitud);
		if(NumeroDeTick==10){
			//Antes de salir hay que guardar la i para llegar el siguiente valor en la i correspondiente
			printf("Antes de Break Vector Resta %d Magnitud: %f\n",i,Resta[i].Magnitud);
			NumeroDeTick=0;
			break;
		}
	}

}

int SumaVectores(){
	for(i=0;i<NumeroDeVectores;i++){
		Suma[i].Magnitud=Vector1[i].Magnitud+Vector2[i].Magnitud;
		Suma[i].Angulo=Vector1[i].Angulo+Vector2[i].Angulo;
    	NumeroDeTick++;
		printf("Vector Suma %d Magnitud: %f\n",i,Suma[i].Magnitud);
		if(NumeroDeTick==10){
			printf("Antes de Break Vector Suma %d Magnitud: %f\n",i,Suma[i].Magnitud);
			NumeroDeTick=0;
			break;
		}
	}
}

//int ProductoEscalarVectores(){


//}


//int EscalarVector(){


    
//}




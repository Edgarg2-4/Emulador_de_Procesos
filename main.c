#include<stdio.h>
#include <stdlib.h> 
#include <time.h>

int NumeroDeVectores = 100;
int Quantum=10;
int i=0;
int NumeroDeVueltas=0;
struct Vector{
    float Magnitud;
    float Angulo;

}Vector1[100],Vector2[100],Suma[100],Resta[100];


int main(){

srand(time(NULL)); // inicializa la semilla
GenerarVectores();
SumaVectores();
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

//int Magnitud(){


//}


int RestaVectores(){
	Resta[1].Magnitud=Vector1[1].Magnitud-Vector2[1].Magnitud;
	Resta[1].Angulo=Vector1[1].Angulo-Vector2[1].Angulo;
    printf("Vector Resta Magnitud: %f\n",Resta[1].Magnitud);
    printf("Vector Resta Angulo: %f \n",Resta[1].Angulo);

}

int SumaVectores(){
	
	Suma[1].Magnitud=Vector1[1].Magnitud+Vector2[1].Magnitud;
	Suma[1].Angulo=Vector1[1].Angulo+Vector2[1].Angulo;
    printf("Vector Suma Magnitud: %f\n",Suma[1].Magnitud);
    printf("Vector Suma Angulo: %f \n",Suma[1].Angulo);

}

//int ProductoEscalarVectores(){


//}


//int EscalarVector(){


    
//}




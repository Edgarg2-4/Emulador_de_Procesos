#include<stdio.h>
#include <stdlib.h> 

int NumeroDeVectores = 100;
int Quantum=10;
int i=0;
int NumeroDeVueltas=0;
struct Vector{
    float Magnitud;
    float Angulo;

}Vector1[100],Vector2[100],Suma[100],Resta[100];


int main(){

    
GenerarVectores();
SumaVectores();
//while ()
//{
    /* code */
//}



}

int GenerarVectores(){
	for(i=0;i<NumeroDeVectores;i++){
    	

    	

    	Vector1[NumeroDeVectores].Magnitud=(rand())+1;
    	Vector1[NumeroDeVectores].Angulo=(rand())+1;
    	Vector2[NumeroDeVectores].Magnitud=(rand())+1;
    	Vector2[NumeroDeVectores].Angulo=(rand())+1;
		printf("Vector 1 %d Magnitud: %f\n",i,Vector1[NumeroDeVectores].Magnitud);
    	printf("Vector 1 %d Angulo: %d\n",i,Vector1[NumeroDeVectores].Angulo);
    	printf("Vector 2 %d Magnitud: %f\n",i,Vector2[NumeroDeVectores].Magnitud);
    	printf("Vector 2 %d Angulo: %d\n",i,Vector2[NumeroDeVectores].Angulo);
    }

}

//int Magnitud(){


//}


//int RestaVectores(){


//}

int SumaVectores(){
	
	Suma[1].Magnitud=Vector1[1].Magnitud+Vector2[1].Magnitud;
	Suma[1].Angulo=Vector1[1].Angulo+Vector2[1].Angulo;
    printf("Vector Suma Magnitud: %f\n",Suma[1].Magnitud);
    printf("Vector Suma Angulo: %d\n",i,Suma[1].Angulo);

}

//int ProductoEscalarVectores(){


//}


//int EscalarVector(){


    
//}




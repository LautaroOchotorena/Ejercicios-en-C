#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*Para poder ejecutar time debo usar su biblioteca*/
#include <time.h>

int main(){
	int N = pow(10,5);
	double x;
	double y;
	/*time(0) indica el número de segundos 
	transcurridos desde 00:00:00 UTC, enero 1, 1970. 
	Esto se hace para obtener diferentes semillas cuando se genera el programa.*/
	int semilla;
	semilla = time(0);
	/*Srand es el generador de números aleatorios*/
	srand(semilla);
	int contador = 0;
	for (int k=0; k<N; k++){
		/*x e y serán variables aleatorias distribuidas de manera uniforme en [0,1].*/
		x=rand()/(RAND_MAX+1.0);
		y=rand()/(RAND_MAX+1.0);
		/*Cuento ahora cuántos pares están por debajo de mi función*/
		if(y <= exp(-x)){
			contador++;
		}
	}
	/* n sería una aproximación de la integral*/
	double n;
	n = (double)contador/N;
	/* -1/(n-1) sería la aproximación de e, esto se obtiene al resolver la integral y despejando*/
	printf("La aproximación de e es %.7f", -1/(n-1));
}

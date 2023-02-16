#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void Cuadratica(double A,double B,double C){
	/*Ahora escribo el discriminante*/
	double D;
	D = B*B-4*A*C;
	/*Separo en caso de que el discriminante sea positivo*/
	if(D >= 0){
		/*Si las dos soluciones son iguales dar una única solución, caso contrario dar las dos*/
		if (D == 0){
			printf("La única solución a la ecuación %fx²+%fx+%f es x=%f\n\n", A, B, C, -B/(2*A));
		}
		else{
			printf("Una solución a la ecuación %fx²+%fx+%f es x=%f\n", A, B, C, (-B+sqrt(D))/(2*A));
			printf("Otra solución a la ecuación %fx²+%fx+%f es x=%f\n\n", A, B, C, (-B-sqrt(D))/(2*A));
		}

	}
	else{
		printf("Una solución a la ecuación %fx²+%fx+%f es x=%f+%fi\n", A, B, C, -B/(2*A), sqrt(-D)/(2*A));
		printf("Otra solución a la ecuación %fx²+%fx+%f es x=%f-%fi\n\n", A, B, C, -B/(2*A), sqrt(-D)/(2*A));
	}
	return;
}

int main(){
	Cuadratica(1,2,1);
	Cuadratica(2,4,1);
	Cuadratica(1,1,1);
	Cuadratica(2.3,4.2,1.2);
	return 0;
}
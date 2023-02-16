#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*Defino Pi*/
#define M_PI 3.14159265358979323846
int function(double x){
	/*Defino la función en el intervalo donde vale 1, el resto lo mando al -1 (ahorro escribir). 
	|| actúa como un o*/
	if((-2*M_PI<=x & x<-M_PI) || (0<=x & x<=M_PI) || (2*M_PI<x & x<=3*M_PI)){
		return (1);
	}
	else{
		return(-1);
	}
}
/*Defino los b(k), así más fácil usarlos*/
double b(int x){
	/*Si es par devolver 0, si es impar 4/(x*pi)*/
	if(x%2 == 0){
		return (0);
	}
	else{
		return (4/(x*M_PI));
	}
}
/*Ahora defino la serie de fourier de N términos*/
double fourier_f(double x, int N){
	int k;
	double Sumatoria;
	Sumatoria=0;
	for(k=1; k<=N; k++){
		Sumatoria = Sumatoria + b(k)*sin(k*x);
	}
	return(Sumatoria);
}
int main(){
	FILE *fopen(), *fout, *fout1, *fout2, *fout3, *fout4;
	fout=fopen("f.dat","w");
	double x;
	double y;
	int k;
	/*Rango de x de [-3*PI,3*PI]*/
	for (k=0; k<=999; k++){
	x=-3*M_PI+((double) k/999)*6*M_PI;
	y=function(x);
	/*Escribo en el archivo primero el x y luego su evaluación f(x)*/
	fprintf(fout, "%.7f %1.0f\n", x, y);
	}
	fclose(fout);
	fout1=fopen("fourier_f_N=2.dat","w");
	for (k=0; k<=999; k++){
	x=-3*M_PI+((double) k/999)*6*M_PI;
	y=fourier_f(x,2);
	/*Escribo en el archivo (uno nuevo) primero el x y luego su evaluación fourier_f(x,2)*/
	fprintf(fout1, "%.7f %.7f\n", x, y);
	}
	fclose(fout1);
	fout2=fopen("fourier_f_N=5.dat","w");
	for (k=0; k<=999; k++){
	x=-3*M_PI+((double) k/999)*6*M_PI;
	y=fourier_f(x,5);
	/*Escribo en el archivo (uno nuevo) primero el x y luego su evaluación fourier_f(x,5)*/
	fprintf(fout2, "%.7f %.7f\n", x, y);
	}
	fclose(fout2);
	fout3=fopen("fourier_f_N=10.dat","w");
	for (k=0; k<=999; k++){
	x=-3*M_PI+((double) k/999)*6*M_PI;
	y=fourier_f(x,10);
	/*Escribo en el archivo (uno nuevo) primero el x y luego su evaluación fourier_f(x,10)*/
	fprintf(fout3, "%.7f %.7f\n", x, y);
	}
	fclose(fout3);
	fout4=fopen("fourier_f_N=100.dat","w");
	for (k=0; k<=999; k++){
	x=-3*M_PI+((double) k/999)*6*M_PI;
	y=fourier_f(x,100);
	/*Escribo en el archivo (uno nuevo) primero el x y luego su evaluación fourier_f(x,100)*/
	fprintf(fout4, "%.7f %.7f\n", x, y);
	}
	fclose(fout4);
	/*Usamos el siguiente comando que representa todos los 
	gráficos con diferente color (queda un poco feo pero se puede cambiar) 
	y en una misma ventana. Aparte subí la foto del gráfico para que se vea mejor*/
	system("xmgrace -block f.dat -bxy 1:2 -block fourier_f_N=2.dat -bxy 1:2 -block fourier_f_N=5.dat -bxy 1:2 -block fourier_f_N=10.dat -bxy 1:2 -block fourier_f_N=100.dat -bxy 1:2");
	/*En el entorno de los puntos de discontinuidad se observa 
	que la función de fourier oscila más y que necesita un N más grande 
	para poder aproximar bien a la función inicial.*/
}
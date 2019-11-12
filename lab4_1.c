/*
--------КП №4.1--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

double get_number(double min, double max);
double get_cos(double angle, double eps);

int main(){
	//printf("%lf\n", get_cos(M_PI/6,1e-5));

	do{
		double x1, x2, dx, eps;

		printf("Enter min. angle:\n");
		x1=get_number(0,360);
		printf("Enter max. angle:\n");
		x2=get_number(x1,360);
		printf("Enter step:\n");
		dx=get_number(0,x2-x1);
		printf("Enter accuracy:\n");
		eps=get_number(0,1);

		printf("ANGLE:\tGET_COS:\tMATH.H:\t\tDIFFERENCE:\n");

		for(int x=x1;x<=x2;x+=dx){
			printf("%4d\t%2.7lf\t%2.7lf\t%.7lf\n", x, get_cos(x*M_PI/180, eps), cos(x*M_PI/180 ), cos(x*M_PI/180)-get_cos(x*M_PI/180, eps));
		}

		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	return 0;
}

double get_cos(double angle, double eps){
	double delta=1,result=1,n=1;

	while(fabs(delta)>=eps){
		delta*=-pow(angle,2)/2/n/(2*n-1);
		result+=delta;
		n++;
	}

	return result;
}



double get_number(double min, double max){
	double n=0;
	double a;
	while(1){
		fflush(stdin);

		//printf("%G\n", n);

		if(!scanf("%lf", &n)){
			printf("You entered not a number!\n");
		}else if(n<min || n>max){
			printf("Must be in range [%lf;%lf]\n",min,max);
		}else if(fabs(modf(n,&a))<1e-15 && fabs(modf(n,&a))){
			printf("Your number is incorrect!\n");
		}else{
			return n;
		}
	}
}
/*
--------КП №3.1--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

double get_number(int zero);
double degree(double n, double d);

int main(){
	do{
		double x, k, eps, delta=1 ,y=1;

		printf("Enter number:\n");
		x=get_number(0);
		printf("Enter power:\n");
		k=get_number(0);
		printf("Enter accuracy:\n");
		eps=get_number(1);

		if(
			(!fmod(k,2) && k>0 && x<0)||
			//(!fmod(k,2) && k<0 && x<=0)||
			//(fmod(k,2) && k<0 && x==0)
			(k<0)
			){
			printf("Can't be calculated!");
		}else{
			while(fabs(delta)>=eps){
				delta=1/k*(x/degree(y, k-1)-y);
				y+=delta;
			}



			printf("Result: %lf\n", y);
		}

		

		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	return 0;
}

double get_number(int zero){
	double n=0;
	double a;
	while(1){
		scanf("%lf", &n);
		fflush(stdin);

		//printf("%G\n", n);

		if(!n){
			printf("You entered not a number!\n");
		}else if(fabs(modf(n,&a))<1e-15 && fabs(modf(n,&a))){
			printf("Your number is incorrect!\n");
		}else if(zero && !n){
			printf("The number mustn't be zero!\n");
		}else{
			return n;
		}
	}
}

double degree(double n, double d){
	if(d>0){
		double result=n;
		while(d>1){
			result*=n;
			d--;
			//printf("%d %d\n", d, result);
		}
		return result;
	}else{
		printf("Error!\n");
	}
}
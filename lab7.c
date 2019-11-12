/*
--------КП №7--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double get_number();
double fun1(double x, double t){return(cos(t/x)-2*sin(1/x)+1/x);}
double fun2(double x, double t){return(sin(log(x))-cos(log(x))+t*log(x));}


int main(){
	do{
		int count;
		double a1, a2, t, eps=0, x=1, delta=1, (*fun)(double,double);

		printf("%s\n%s\n%s\n%s","Choose the equation:",
			"1. cos(t/x) - 2sin(1/x) + 1/x = 0",
			"2. sin(ln x) - cos(ln x) + t ln x = 0",
			"Press 1 or 2: ");

		char sym;
		while(sym=getch()){
			if(sym=='1'){
				fun=fun1;
				break;
			}

			else if(sym=='2'){
				fun=fun2;
				break;
			}
		}

		printf("%c\n", sym);


		printf("Enter min X: ");
		a1=get_number();
		printf("\nEnter max X: ");
		a2=get_number();

		printf("\nEnter t: ");
		t=get_number();

		printf("\nEnter Accuracy:  ");

		while(eps==0){
			printf("\b \b");
			eps=get_number();
		}
		


		while(fabs(a2-a1)>eps){
			x=(a1+a2)/2;

			if(fun(a1,t)*fun(x,t)>0){
				a1=x;
			}else{
				a2=x;
			}
		}

		printf("\nResult: %lf\n", x);


		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	
	return 0;
}

double get_number(){
	int str_size=16;
	char str[str_size];
	char sym;

	int i=0;

	while(i<str_size){
		sym=getch();

		if(sym==8&&i!=0){
			i--;
			printf("\b \b");
		}else if(sym==13){
			if(i!=0 && str[i-1]<=57 && str[i-1]>=48){
				str[i]=3;
				break;
			}
		}else if(sym>=48 && sym<=57 || sym=='.' || sym=='-' || sym=='e' || sym=='E'){
			printf("%c", sym);
			str[i]=sym;
			i++;
		}
	}

	return(atof(str));
}
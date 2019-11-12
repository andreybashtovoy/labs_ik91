/*
--------КП №2--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

float get_number();

int main(){
	do{
		float a,b,c;

		printf("Enter the length of the first side\n");
		a=get_number();
		printf("Enter the length of the second side\n");
		b=get_number();
		printf("Enter the length of the third side\n");
		c=get_number();

		//printf("%f %f %f\n", a,b,c);

		if(a+b<=c || b+c<=a || a+c<=b){
			printf("The sum of any two sides must not exceed the length of the third!\n");
		}else{
			//Периметр
			printf("\nPerimetr: %G\n",a+b+c);

			//Полупериметр
			float p=(a+b+c)/2;

			//Площадь
			float S=sqrt(p*(p-a)*(p-b)*(p-c));
			printf("Area of the triangle: %G\n\n",S);

			//Высоты
			float Ha=2*S/a;
			float Hb=2*S/b;
			float Hc=2*S/c;
			printf("Height drawn to side:\n");
			printf("\ta: %G\n",Ha);
			printf("\tb: %G\n",Hb);
			printf("\tc: %G\n\n",Hc);

			//Медианы
			float Ma=sqrt(2*b*b+2*c*c-a*a)/2;
			float Mb=sqrt(2*a*a+2*c*c-b*b)/2;
			float Mc=sqrt(2*b*b+2*a*a-c*c)/2;
			printf("Median drawn to side:\n");
			printf("\ta: %G\n",Ma);
			printf("\tb: %G\n",Mb);
			printf("\tc: %G\n\n",Mc);

			//Бисектрисы
			float Ba=2*sqrt(b*c*p*(p-a))/(b+c);
			float Bb=2*sqrt(a*c*p*(p-b))/(a+c);
			float Bc=2*sqrt(b*a*p*(p-c))/(b+a);
			printf("Bisectrix drawn to side:\n");
			printf("\ta: %G\n",Ba);
			printf("\tb: %G\n",Bb);
			printf("\tc: %G\n",Bc);
		}
		
		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	return 0;
}

float get_number(){
	float n=0;
	do{
		scanf("%f",&n);
		fflush(stdin);

		if(!n){
			printf("You entered not a number!\n");
		}else if(n<0){
			printf("The number must be positive!\n");
		}else{
			return n;
		}
	}while(n<=0);
}
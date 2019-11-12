/*
--------КП №4.2--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

double get_number();
void sort(double *array,int num);

int main(){
	do{
		int count;
		printf("Enter the count of elements: ");
		count=get_number(1);
		double array[count];
		printf("\n");

		for(int i=0;i<count;i++){
			printf("Enter element [%d]: ",i);
			array[i]=get_number(0);
		}

		sort(array,count);


		printf("\nResult:\n");

		for(int i=0;i<count;i++){
			printf("\t[%d]: %lf\n",i,array[i]);
		}


		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	

	return 0;
}

void sort(double *array,int num){
	double t;
	for(int a=0;a<num-1;a++)
	for(int b=a+1;b<num;b++){
		if(array[a]>array[b]){
			t=array[a];
			array[a]=array[b];
			array[b]=t;
		}
	}
}

double get_number(int is_count){
	double a;
	double n=0;
	while(1){
		fflush(stdin);

		if(!scanf("%lf", &n)){
			printf("You entered not a number!\n");
		}else if(is_count && (n<1 || n>1024)){
			printf("The count must be positive and less then 1024.\n");
		}else if(fabs(modf(n,&a))<1e-15 && fabs(modf(n,&a))){
			printf("Your number is incorrect!\n");
		}else{
			return n;
		}
	}
}
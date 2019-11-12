/*
--------КП №1--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>

int roman(int,int,char);

int main(){
	do{
		int n=0;
		
		printf("ENTER NUMBER\n");
		scanf("%d",&n);
		fflush(stdin);

		if(!n){
			printf("You entered not a number!\n");
		}else if(n<0 || n>999999){
			printf("The number must be positive and less than 999999!\n");
		}else{
			n=roman(n,1000,'M');
			n=roman(n,500,'D');
			n=roman(n,100,'C');
			n=roman(n,50,'L');
			n=roman(n,10,'X');
			n=roman(n,5,'V');
			n=roman(n,1,'I');
		}

		printf("\nPress ANY KEY to enter new number or ESCAPE to close.\n");

	}while(getch()!=27);
	return 0;
}

int roman(int n,int a,char r){
	while(n>=a){
		putchar(r);
		n=n-a;
	}
	return(n);
}
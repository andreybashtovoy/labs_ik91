/*
--------КП №5--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <string.h>

int get_number();
void sort(char **a,char **b);

int main(){
	do{
		int count;
		printf("Enter the count of elements: ");
		count=get_number();
		char list[count][64];
		char *addr[count];

		printf("\n");

		for(int i=0;i<count;i++){
			printf("Enter element [%d]: ",i);
			scanf("%s", list[i]);
		}

		for(int i=0; i<count; i++) addr[i]=list[i];

		for(int a=0;a<count-1;a++)
		for(int b=a+1;b<count;b++){
			if(strcmp(addr[a],addr[b])>0){
				sort(&addr[a],&addr[b]);
			}
		}

		printf("\nResult:\n");

		for(int i=0;i<count;i++){
			printf("\t[%d]: %s\n",i,addr[i]);
		}


		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	

	return 0;
}

void sort(char **a,char **b){
	char *c;
	c=*a;
	*a=*b;
	*b=c;
}

int get_number(){
	int a;
	int n=0;
	while(1){
		fflush(stdin);

		if(!scanf("%d", &n)){
			printf("You entered not a number!\nTry again: ");
		}else if(n<1 || n>1024){
			printf("The count must be positive and less then 1024.\nTry again: ");
		}else{
			return n;
		}
	}
}

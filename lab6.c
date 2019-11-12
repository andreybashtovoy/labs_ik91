/*
--------КП №6--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

double get_number();
int get_order();

int main(){
	do{
		int order;
		double **matrix, *matrix_b, *x, *xp, eps, delta;
		
		printf("Enter the size of system: ");
		order = get_order();

		matrix = (double**)calloc(order, sizeof(double*));

		for(int i=0;i<order;i++)
			matrix[i]=(double*)calloc(order, sizeof(double));

		matrix_b = (double*)calloc(order, sizeof(double));
		x = (double*)calloc(order, sizeof(double));
		xp = (double*)calloc(order, sizeof(double));

		printf("Enter the coefficients: ");

		for(int i=0;i<order;i++){
			for(int j=0;j<order;j++){
				printf("A[%d][%d] = ",i+1,j+1);
				matrix[i][j]=get_number();
			}


			double sum=0;
			for(int k=0;k<order;k++){
				if(i!=k)
					sum+=matrix[i][k];
			}
			if(matrix[i][i]<=sum){
				printf("A[%d][%d] must be bigger than Sum"
					   " of other elements of the %d raw!\n", i+1, i+1, i+1);
				i--;
			}
		}

		printf("Enter the free elements: \n");
		for(int i=0;i<order;i++){
			printf("B[%d] = ",i+1);
			matrix_b[i] = get_number();
		}

		printf("Enter the accuracy: ");
		eps = get_number();
		
		do{
			for(int i=0;i<order;i++){
				xp[i]=0;

				delta = 0;

				for(int j=0;j<order;j++){
					if(i!=j)
						xp[i]+=matrix[i][j]*x[j];
				}

				xp[i] = (matrix_b[i]-xp[i])/matrix[i][i];

				if(fabs(x[i] - xp[i]) > delta)
					delta = fabs(x[i] - xp[i]);

				x[i] = xp[i];
			}
		}while(delta>=eps);

		for(int i=0;i<order;i++)
			free(matrix[i]);
		free(matrix);
		free(matrix_b);
		free(xp);


		printf("\nSolutions of the system:\n");
		for (int i = 0;i<order;i++)
			printf("\tx[%d] = %lf\n",i+1,x[i]);

		free(x);

		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);

	return 0;
}

double get_number(){
	double a;
	double n=0;
	while(1){
		fflush(stdin);

		//printf("%d\n", scanf("%lf", &n));

		if(scanf("%lf", &n) != 1){
			printf("You entered not a number!\nTry again: ");
		}else if(fabs(modf(n,&a))<1e-15 && fabs(modf(n,&a))){
			printf("Your number is incorrect!\n");
		}else{
			return n;
		}
	}
}

int get_order(){
	int n=0;
	while(1){
		fflush(stdin);

		if(scanf("%d", &n) != 1){
			printf("You entered not a number!\nTry again: ");
		}else if(n<1 || n>1024){
			printf("The count must be positive and less then 1024.\nTry again: ");
		}else{
			return n;
		}
	}
}
/*
--------КП №8--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

double get_number();

typedef struct{
	double fp, sp;
}complex;

int main(){
	do{
		char sym=0;
		double R1, R2, C, L, fmin, fmax, step, f0, a, b, c, d;
		complex res;
		printf("Choose a circuit. Press 1,2,3 or 4: ");
		while(sym<'1' || sym>'4')
			sym=getch();

		printf("%c\n", sym);

		printf(">>>R1 = ");
		R1=get_number();
		if(sym=='3' || sym=='4'){
			printf("\n>>>R2 = ");
			R2=get_number();
		}
		printf("\n>>>C = ");
		C=get_number();
		printf("\n>>>L = ");
		L=get_number();
		printf("\n>>>fmin = ");
		fmin=get_number();
		printf("\n>>>fmax = ");
		fmax=get_number();
		printf("\n>>>step = ");
		step=get_number();


		f0=1/(2*M_PI*sqrt(L*C));
		printf("\n\nResonanse frequancy: %lf Hz\n", f0);
		printf("Frequancy, Hz\tResistance, Ohm\n");
		for(;fmin<=fmax;fmin+=step){
			double w=2*M_PI*fmin;

			switch(sym){
				case '1':
					a = L/C;
					b = -R1/(w*C);
					c = R1;
					d = w*L - 1/(w*c);
					break;
				case '2':
					a = L/C;
					b = R1/(w*C);
					c = R1;
					d = w*L - 1/(w*C);
					break;
				case '3':
					a = R1*R2;
					b = R1*(w*L - 1/(w*C));
					c = R1 + R2;
					d = w*L - 1/(w*C);
					break;
				case '4':
					a = R1*R2 + L/C;
					b = w*C*R1 - R2/(w*C);
					c = R1 + R2;
					d = w*L - 1/(w*C);
					break;
			}

			res.fp = (a*c + b*d)/(c*c + d*d);
			res.sp = (b*c - a*d)/(c*c + d*d);
			printf("%lf\t%e + i*%e\n", fmin, res.fp, res.sp);
		}

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
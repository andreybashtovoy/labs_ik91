/*
--------КП №3.3--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

float root(float x, float k);

int main(){
	do{
		float a=0,b=0,c=0;

		printf("Enter a:\n");
		scanf("%f",&a);
		fflush(stdin);
		printf("Enter b:\n");
		scanf("%f",&b);
		fflush(stdin);
		printf("Enter c:\n");
		scanf("%f",&c);
		fflush(stdin);

		float p=b-pow(a,2)/3;
		float q=2*pow(a,3)/27-a*b/3+c;

		float d=pow(p,3)/27+pow(q,2)/4;

		float y1,y2,y3,y;

		if(d>0){
			float u=root(-q/2+sqrt(d),3);
			float v=-p/3/u;

			y1=u+v;
			y2=y3=-(u+v)/2;
			y=sqrt(3)*(u-v)/2;

			printf("\nX1=%.3f\n",y1-a/3);
			printf("X2=%.3f+i*%.3f\n",y2-a/3,y);
			printf("X3=%.3f-i*%.3f\n",y3-a/3,y);
		}else if(d==0){
			y1=3*q/p;
			y2=y3=-3*q/2/p;

			printf("\nX1=%.3f\n",y1-a/3);
			printf("X2=%.3f\n",y2-a/3);
			printf("X3=%.3f\n",y3-a/3);
		}else if(d<0){
			float r=sqrt(-pow(p,3)/27);
			float fi=acos(-q/2/r);
			y1=2*fabs(root(r,3))*cos(fi/3);
			y2=2*fabs(root(r,3))*cos((fi+2*M_PI)/3);
			y3=2*fabs(root(r,3))*cos((fi+4*M_PI)/3);

			printf("\nX1=%.3f\n",y1-a/3);
			printf("X2=%.3f\n",y2-a/3);
			printf("X3=%.3f\n",y3-a/3);
		}


		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	return 0;

}

float root(float x, float k){
	float delta=1,y=1;
	while(fabs(delta)>=1e-5){
		delta=1/k*(x/pow(y, k-1)-y);
		y+=delta;
	}
	return y;
}
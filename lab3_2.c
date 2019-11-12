/*
--------КП №3.2--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

int is_leap(int year);
int get_number();

int main(){
	do{
		//printf("%d %d %d %d\n", is_leap(1987), is_leap(2004), is_leap(1978), is_leap(1900));
		int date=0, month=0, year=0, n, day;

		printf("Enter date in format day.month.year:\n");
		date=get_number();
		month=get_number();
		year=get_number();

		//printf("%d %d %d\n", date, month, year);

		fflush(stdin);

		if(
			(is_leap(year) && month==2 && date>29 || !is_leap(year) && month==2 && date>28)||
			(date<1 || date>31)||
			(month<1 || month>12)||
			(year<1000 || year>9999)||
			(date==31 && (month==4 || month==6 || month==9 || month==11))
			){
			printf("Your date is incorrect!\n");
		}else{
			if(month>2){
				n=0;
			}else if(is_leap(year) && month<=2){
				n=1;
			}else if(!is_leap(year) && month<=2){
				n=2;
			}

			day=(int)(trunc(365.25*year) + trunc(30.56*month) + date + n)%7;

			switch(day){
				case 0:
					printf("Monday\n");
					break;
				case 1:
					printf("Tuesday\n");
					break;
				case 2:
					printf("Wednesday\n");
					break;
				case 3:
					printf("Thursday\n");
					break;
				case 4:
					printf("Friday\n");
					break;
				case 5:
					printf("Saturday\n");
					break;
				case 6:
					printf("Sunday\n");
					break;
			}
		}

		

		printf("\nPress ANY KEY to enter new numbers or ESCAPE to close.\n");
	}while(getch()!=27);
	return 0;
}

int get_number(){
	int n=0;
	scanf("%d",&n);


	int sym=getchar();

	if(sym==46 || sym==10){
		return n;
	}else{
		return 0;
	}
}

int is_leap(int year){
	return(year%100 && !(year%4) || !(year%100) && !(year%400));
}
/*
--------КП №1--------

Если помогло, подпишись на инстик автора)00)0))
@andrey_bashtovoy_sd

Принимал не Лес.

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h> 

void create_file(int ret);
void read_file(int ret);
void remove_file(int ret);
void create_record(int ret);
void open_menu(int menu);
void edit_record(int ret);
void remove_record(int ret);
void read_records(int ret);
void sort_records(int ret);
void insert_record(int ret);
void sort_file(FILE *fp, char *filename, int ret);
char* get_str(char *write_in, int vtype, int ret, FILE *fp);
double get_double(int ret, FILE *fp);
int get_int(int ret, FILE *fp);

struct menu{
	char name[16];
	int num_acts;
	char acts[6][16];
	int funs[6];
	int prev;
	void (*fun)(int ret);
};

void set_string(char *str, char *str2){
	strncpy(str, str2, 15);
	str[15] = 0;
}

int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	open_menu(0);
}

void open_menu(int menu){
	int menu_len = 12;
	struct menu menu_arr[menu_len];

	set_string(menu_arr[0].name, "МЕНЮ");
	menu_arr[0].num_acts = 2;
	set_string(menu_arr[0].acts[0], "Файл");
	set_string(menu_arr[0].acts[1], "Записи");
	menu_arr[0].funs[0] = 1;
	menu_arr[0].funs[1] = 5;
	menu_arr[0].prev = 0;
	menu_arr[0].fun = NULL;


	set_string(menu_arr[1].name, "ФАЙЛ");
	menu_arr[1].num_acts = 3;
	set_string(menu_arr[1].acts[0], "Создать");
	set_string(menu_arr[1].acts[1], "Прочитать");
	set_string(menu_arr[1].acts[2], "Удалить");
	menu_arr[1].funs[0] = 2;
	menu_arr[1].funs[1] = 3;
	menu_arr[1].funs[2] = 4;
	menu_arr[1].prev = 0;
	menu_arr[1].fun = NULL;

	set_string(menu_arr[2].name, "Создание Файла");
	menu_arr[2].num_acts = 0;
	menu_arr[2].prev = 1;
	menu_arr[2].fun = create_file;

	set_string(menu_arr[3].name, "Чтение файла");
	menu_arr[3].num_acts = 0;
	menu_arr[3].prev = 1;
	menu_arr[3].fun = read_file;

	set_string(menu_arr[4].name, "Удаление файла");
	menu_arr[4].num_acts = 0;
	menu_arr[4].prev = 1;
	menu_arr[4].fun = remove_file;

	set_string(menu_arr[5].name, "Записи");
	menu_arr[5].num_acts = 6;
	set_string(menu_arr[5].acts[0], "Создать");
	set_string(menu_arr[5].acts[1], "Прочитать");
	set_string(menu_arr[5].acts[2], "Удалить");
	set_string(menu_arr[5].acts[3], "Сортировать");
	set_string(menu_arr[5].acts[4], "Вставить");
	set_string(menu_arr[5].acts[5], "Редактировать");
	menu_arr[5].funs[0] = 6;
	menu_arr[5].funs[1] = 7;
	menu_arr[5].funs[2] = 9;
	menu_arr[5].funs[3] = 10;
	menu_arr[5].funs[4] = 11;
	menu_arr[5].funs[5] = 8;
	menu_arr[5].prev = 0;
	menu_arr[5].fun = NULL;

	set_string(menu_arr[6].name, "СОЗДАНИЕ ЗАПИСЕЙ");
	menu_arr[6].num_acts = 0;
	menu_arr[6].prev = 5;
	menu_arr[6].fun = create_record;

	set_string(menu_arr[7].name, "ЧТЕНИЕ ЗАПИСЕЙ");
	menu_arr[7].num_acts = 0;
	menu_arr[7].prev = 5;
	menu_arr[7].fun = read_records;

	set_string(menu_arr[8].name, "РЕДАКТИРОВАНИЕ");
	menu_arr[8].num_acts = 0;
	menu_arr[8].prev = 5;
	menu_arr[8].fun = edit_record;

	set_string(menu_arr[9].name, "УДАЛЕНИЕ ЗАПИСИ");
	menu_arr[9].num_acts = 0;
	menu_arr[9].prev = 5;
	menu_arr[9].fun = remove_record;

	set_string(menu_arr[10].name, "СОРТИРОВКА");
	menu_arr[10].num_acts = 0;
	menu_arr[10].prev = 5;
	menu_arr[10].fun = sort_records;

	set_string(menu_arr[11].name, "ВСТАВИТЬ ЗАПИСЬ");
	menu_arr[11].num_acts = 0;
	menu_arr[11].prev = 5;
	menu_arr[11].fun = insert_record;


	system("cls");
	printf("%s %s\n\n","Нажмите <ESC>, чтобы ", menu==0?"выйти":"вернуться");
	printf("%s\n", menu_arr[menu].name);
	for(int i=0;i<menu_arr[menu].num_acts;i++){
		printf("%d. %s\n", (i+1), menu_arr[menu].acts[i]);
	}
	
	char sym = 0;

	if(menu_arr[menu].fun == NULL){
		while((sym<49 || sym>48+menu_arr[menu].num_acts) && sym!=27)
				sym=getch();
	}else{
		menu_arr[menu].fun(menu_arr[menu].prev);
		while(sym!=27)
				sym=getch();
	}

	if(sym==27){
		if(menu==0){
			exit(0);
		}else{
			open_menu(menu_arr[menu].prev);
		}
	}else{
		open_menu(menu_arr[menu].funs[sym-49]);
	}
}

void create_file(int ret){
	FILE *fp;
	printf("Имя файла: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "w");
	fclose(fp);
	printf("\nОк! Нажмите <ESC>, чтобы вернуться.");
}

void read_file(int ret){
	FILE *fp;
	printf("File name: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "r");

	if(fp==NULL){
		printf("\nТакого файла не существует. Нажмите <ESC>, чтобы вернуться.\n");
	}else{
		printf("\n");
		while(!feof(fp)){
			printf("%c", fgetc(fp));
		}
		fclose(fp);
		printf("\nНажмите <ESC>, чтобы вернуться.");
	}
}

void remove_file(int ret){
	printf("File name: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);

	printf("\n%s %s\n", remove(filename)==-1?"Такого файла на существует.":"Ок!", "Нажмите <ESC>, чтобы вернуться.");
}

typedef struct{
	char name[40];
	double square;
	int nas;
}rec;

void create_record(int ret){
	FILE *fp;
	printf("Имя файла: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "a");

	int i = 0;

	while(1){
		i++;
		rec region;
		printf("\nЗапись №%d\n", i);
		printf(">>> Название области: ");
		get_str(region.name, 3, ret, fp);
		printf("\n>>> Площадь: ");
		region.square = get_double(ret, fp);
		printf("\n>>> Население: ");
		region.nas = get_int(ret, fp);
		fprintf(fp, "%s %lf %d\n", region.name, region.square, region.nas);
	}

	fclose(fp);
}

void insert_record(int ret){
	FILE *fp;
	printf("Имя файла: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "a");

	rec region;
	printf("\n>>> Название области: ");
	get_str(region.name, 3, ret, fp);
	printf("\n>>> Площадь: ");
	region.square = get_double(ret, fp);
	printf("\n>>> Население: ");
	region.nas = get_int(ret, fp);
	fprintf(fp, "%s %lf %d\n", region.name, region.square, region.nas);

	fclose(fp);
	fp=fopen(filename, "r");

	sort_file(fp, filename, ret);

	printf("\nОК! Нажмите <ESC>, чтобы вернуться.\n");
}

int print_table(FILE *fp){
	printf("\n№\tНАЗВАНИЕ\tПЛОЩАДЬ\t\tНАСЕЛЕНИЕ\n");
	int i=0;

	while(!feof(fp)){
		i++;
		rec region;
		fscanf(fp, "%s %lf %d\n", region.name, &region.square, &region.nas);
		printf("%d\t%11s\t%lf\t%d\n", i, region.name, region.square, region.nas);
	}

	return i;
}

void read_records(int ret){
	FILE *fp;
	printf("Имя файла: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "r");

	if(fp==NULL){
		printf("\nТакого файла не существует. Нажмите <ESC>, чтобы вернуться.\n");
	}else{
		print_table(fp);

		printf("\nНажмите <ESC>, чтобы вернуться.\n");

		fclose(fp);
	}
}

void edit_record(int ret){
	FILE *fp;
	printf("Имя файла: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "r");

	if(fp==NULL){
		printf("\nТакого файла не существует. Нажмите <ESC>, чтобы вернуться.\n");
	}else{
		int count = print_table(fp);

		int num = 0;
		while(num<1 || num>count){
			printf("\nВыберите номер записи, которую хотите редактировать: ");
			num = get_int(ret, fp);
		}

		rec records[count];

		fseek(fp, 0, SEEK_SET);

		int i=0;

		while(!feof(fp)){
			i++;
			fscanf(fp, "%s %lf %d\n", records[i-1].name, &records[i-1].square, &records[i-1].nas);
		}

		rec region;
		printf("\n>>> Название области: \n");
		get_str(records[num-1].name, 3, ret, fp);
		printf("\n>>> Площадь: \n");
		records[num-1].square = get_double(ret, fp);
		printf("\n>>> Население: \n");
		records[num-1].nas = get_int(ret, fp);

		fclose(fp);
		fp=fopen(filename, "w");

		for(int i=0;i<count;i++){
			fprintf(fp, "%s %lf %d\n", records[i].name, records[i].square, records[i].nas);
		}


		fclose(fp);

		printf("\nОк! Нажмите <ESC>, чтобы вернуться.\n");
	}
}

void remove_record(int ret){
	FILE *fp;
	printf("Имя файла: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "r");

	if(fp==NULL){
		printf("\nТакого файла не существует. Нажмите <ESC>, чтобы вернуться.\n");
	}else{
		int count = print_table(fp);

		int num = 0;
		while(num<1 || num>count){
			printf("\nВыберите номер записи, которую хотите удалить: ");
			num = get_int(ret, fp);
		}

		rec records[count];

		fseek(fp, 0, SEEK_SET);

		int i=0;

		while(!feof(fp)){
			i++;
			fscanf(fp, "%s %lf %d\n", records[i-1].name, &records[i-1].square, &records[i-1].nas);
		}

		fclose(fp);
		fp=fopen(filename, "w");

		for(int i=0;i<count;i++){
			if(i!=num-1)
				fprintf(fp, "%s %lf %d\n", records[i].name, records[i].square, records[i].nas);
		}


		fclose(fp);

		printf("\nОк! Нажмите <ESC>, чтобы вернуться.\n");
	}
}

void sort_file(FILE *fp, char *filename, int ret){
	int count = print_table(fp);

	printf("\nВыберите столбец, по которому будет сортировка:\n1. Название\n2. Площадь\n3. Население\n");

	char sym=0;
	while((sym<49 || sym>51) && sym!=27){
		sym=getch();
	}

	if(sym==27){
		fclose(fp);
		open_menu(ret);
	}

	printf("\nВыберите тип сортировки:\n1. По возрастанию\n2. По убыванию\n");

	char stype=0;
	while((stype<49 || stype>50) && stype!=27){
		stype=getch();
	}

	if(stype==27){
		fclose(fp);
		open_menu(ret);
	}

	rec records[count];

	fseek(fp, 0, SEEK_SET);

	int i=0;

	while(!feof(fp)){
		i++;
		fscanf(fp, "%s %lf %d\n", records[i-1].name, &records[i-1].square, &records[i-1].nas);
	}

	int arr[count];

	for(int i=0;i<count;i++)
		arr[i]=i;

	for(int i = 0 ; i < count - 1; i++){
		for(int j = 0 ; j < count - i - 1 ; j++){
			if(
				sym=='1'&&stype=='1'&&(strcmp(records[arr[j]].name,records[arr[j+1]].name)>0)||
				sym=='1'&&stype=='2'&&(strcmp(records[arr[j+1]].name,records[arr[j]].name)>0)||
				sym=='2'&&stype=='1'&&(records[arr[j]].square>records[arr[j+1]].square)||
				sym=='2'&&stype=='2'&&(records[arr[j]].square<records[arr[j+1]].square)||
				sym=='3'&&stype=='1'&&(records[arr[j]].nas>records[arr[j+1]].nas)||
				sym=='3'&&stype=='2'&&(records[arr[j]].nas<records[arr[j+1]].nas)
				){
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}

	fclose(fp);
	fp=fopen(filename, "w");

	for(int i=0;i<count;i++){
		fprintf(fp, "%s %lf %d\n", records[arr[i]].name, records[arr[i]].square, records[arr[i]].nas);
	}

	fclose(fp);
}

void sort_records(int ret){
	FILE *fp;
	printf("Имя файла: ");
	char filename[16];
	get_str(filename, 3, ret, NULL);
	fp=fopen(filename, "r");

	if(fp==NULL){
		printf("\nТакого файла не существует. Нажмите <ESC>, чтобы вернуться.\n");
	}else{
		sort_file(fp, filename, ret);
		printf("\nОк! Нажмите <ESC>, чтобы вернуться.\n");
	}
}

int get_int(int ret, FILE *fp){
	char str[16];
	get_str(str, 2, ret, fp);
	return(atof(str));
}

double get_double(int ret, FILE *fp){
	char str[16];
	get_str(str, 1, ret, fp);
	return(atof(str));
}


char* get_str(char *write_in, int vtype, int ret, FILE *fp){
	int str_size=16;
	char str[str_size];
	char sym;

	int i=0;

	fflush(stdin);

	while(i<str_size){
		sym=getch();

		if(sym==27){
			if(fp != NULL){
				fclose(fp);
			}
			open_menu(ret);
		}else if(sym==8){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else if(sym==13){
			if(
				(vtype==1 || vtype==2) && (i!=0 && str[i-1]<=57 && str[i-1]>=48) || // double, int
				vtype==3 && (i!=0) // int
				){
					str[i]=3;
					break;
			}
		}else if(
			vtype==1 && (sym>=48 && sym<=57 || sym=='.' || sym=='-' || sym=='e' || sym=='E') || // double
			vtype==2 && sym>=48 && sym<=57 || // int
			vtype==3 && sym!='/' && sym!=':' && sym!='?' && sym!='<' && sym!='>' && sym!='\\' && sym!='"' // string
			){
			printf("%c", sym);
			str[i]=sym=='.'?',':sym;
			i++;
		}
	}
	strncpy(write_in, str, i);
	write_in[i] = 0;
}

#include <stdio.h>
#include <conio.h> //gotoxy
#include <string.h>
#include <stdlib.h>
#include <windows.h> //coord pos


void gotoxy(short x, short y) {
COORD pos = {x, y};//sets co-ordinates in (x,y).
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void header_up();
void login();
void add();
void del();
void search_name();
void show();
void end();

FILE *fp;

struct hotel{
	
	char room[100];
	char name[100];
	char surname[100];
	char address[100];
	char phone[100];
	char nationality[100];
	char period[100];
	char arrivaldate[100];
}h;



int main(){
	
    system("cls");
	header_up();
	login();
	
	//header_down();


	return 0;	
};


void header_up()
{
	printf("\033[1;31m");
    printf("\n\n\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*          Welcome to Otel GELiSiM              *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*************************************************\n\n\n");
    printf("\t\t*************        MENU        *****************\n\n");
    printf("\033[0m");
	
}

void login()
{
	char adminEntry[20] = {'y'};
	int admin_or_exit,admin_panel;
	int i=0;
	
	for(i=0;i<27;i++)
		printf("*");
	if (i=13)
		{printf("     LOGIN FORM     ");
		i=i+1;
		};
	for(i=0;i<27;i++)
		printf("*");
	printf("\n\n\tFOR ADMIN PANEL\t[1]");
    printf("\n\tEXIT\t        [2]\n");
	
	printf("\t-->              ");
	scanf("%d",&admin_or_exit);
	
	switch (admin_or_exit)
	{
		case 1:
		{
			system("cls");
			char pass[20];
			char filepass[20];
			int i;
			FILE *passwordF;
			passwordF= fopen("password.txt","r");
			
			printf("\n\nYou are welcome!\nTo continue as an admin, please enter the password --> ");
				
			for (i=0;i<5;i++){
				scanf("%s",pass);
                fscanf(passwordF,"%s",filepass);
                if (strcmp(filepass,pass) == 0){
                	system("cls");
                    printf("\n\nWelcome! Login Successful!\n");
                   	fclose(passwordF);
				   		break;
				}
				else{
					if(i==4){
						printf("\nLogin Failed! You have entered the wrong password five times!");
						fclose(passwordF);
						end();
                   	}
                   	else{
					   printf("\nWrong password, please try again.");
					printf("\nYou have %d tries left ",4-i);
                    printf("\n\nEnter the password >> ");}
                }
            }
            while(adminEntry[0] =='y')
			{
				printf("\033[1;33m");
           		printf("\n\n\tADD RECORD\t[1]");
        		printf("\n\tVIEW RECORD\t[2]");
       			printf("\n\tSEARCH RECORD\t[3]");
        		printf("\n\tDELETE RECORD\t[4]");
				printf("\n\tEXIT\t        [5]");
   	        	printf("\033[0m");

                printf("\n--> ");
                scanf("%d",&admin_panel);
                
                switch (admin_panel)
				{
                	case 1:{
                		add();
						break;
					}
					case 2:{
						show();
						break;
					}
                	case 3:{
						search_name();
						break;
					}
                	case 4:{
						del();
						break;
					}
					case 5:{
						end();
						break;
					}
					default:
					{
						printf("Invalid Choice!");
						break;
					}
				}
			}
		}
		case 2:{
			end();
			
			break;
		}
		default:
		{
			printf("Invalid Choice!\n");
			printf("Redirectting to Main Menu...");
			Sleep(2000);
			main();
			break;
		}
	}
	
}

void add(){
	
	system("cls");
    char test;
    
    fp=fopen("gelisimhotel.txt","ab+");
    
    if ( fp == NULL ){
        fp=fopen("gelisimhote.txt","wb+");
        if(fp==NULL){
			printf("\nSystem Error");
            printf("\nPress Any Key To Exit");
            getch();
            return ;
        }
    }
    
    while(1)
	{
		int i;
		system("cls");
		printf("\n");
		printf("\n\n\t\t*******************************\n");
	printf("\t\t*           ADD MENU          *");
    printf("\n\t\t*******************************\n\n");
		Z:
		printf("\n\nEnter Room Number:\n\n");
		fflush(stdin);
		gets(h.room);
		if(strlen(h.room)>3||strlen(h.room)<1)
		{
			printf("\nInvalid!\nThe max range for room number is 3 and min range is 1\n");
			goto Z;
		}
		A:
		printf("\nEnter First Name: ");
		fflush(stdin);
		gets(h.name);
		if(strlen(h.name)>20||strlen(h.name)<3)
		{
			printf("\nInvalid!\nThe max range for first name is 20 and min range is 2\n");
			goto A;
		}
		B:
		printf("\nLast Name: ");
    	fflush(stdin);
		gets(h.surname);
    	if(strlen(h.surname)>20||strlen(h.surname)<3)
		{
			printf("\nInvalid!\nThe max range for last name is 20 and min range is 2\n");
			goto B;
		}
		C:
		printf("\nEnter Guest Address: ");
		fflush(stdin);
		gets(h.address);
		if(strlen(h.address)>20||strlen(h.address)<5)
		{
			printf("\nInvalid!\nThe max range for address is 20 and min range is 4\n");
			goto C;
		}
		D:
		printf("\nEnter Guest Phone Number (05xxxxxxxxx): ");
		fflush(stdin);
		gets(h.phone);
		if(strlen(h.phone)>12||strlen(h.phone)<10)
		{
			printf("\nInvalid!\nThe must be 11 digits (05xxxxxxxxx)\n");
			goto D;
		}
		E:
		printf("\nEnter Guest Nationality: ");
		fflush(stdin);
		gets(h.nationality);
		if(strlen(h.nationality)>20||strlen(h.nationality)<5)
		{
			printf("\nInvalid!\nThe max range for nation is 20 and min range is 4\n");
			goto E;
		}
		F:
		printf("\nEnter Period(Days): ");
		scanf("%s",&h.period);
		if(strlen(h.period)>3||strlen(h.period)<1)
		{
			printf("\nInvalid!\nThe max range for period is 3 and min range is 1\n");
			goto F;
		}
		printf("\nEnter Arrival Date(dd-mm--yyyy): ");
		scanf("%s",&h.arrivaldate);
		//fprintf(fp,"\n");
		fwrite(&h,sizeof(h),1,fp);
		printf("\n\nRoom has been booked successfully");
		printf("\nPress Esc key to Main Menu\nPress any key to add another record:\n");
		test=getche();
		if(test==27)
			break;
			
	}

	fclose(fp);
    
}

void del(){
	FILE *tmp;
	char del_room[20];
	int i=1;
	system("cls");
	printf("\n\n\t\t*******************************\n");
	printf("\t\t*         DELETE MENU         *");
    printf("\n\t\t*******************************\n\n");
    
	if(((tmp=fopen("temp.txt","w"))==NULL)|| ((fp=fopen("gelisimhotel.txt","r"))==NULL))
	exit(0);
		
	printf("Enter guest room number to checkout: ");
    fflush(stdin);
	gets(del_room);

    while(fread(&h,sizeof(h),1,fp)==1){
        if(strcmp(h.room,del_room) == 0){
            i=0;
            continue;
        }
        else
        	fwrite(&h,sizeof(h),1,tmp);
    }
	if (i==1){
		printf("\n\nRoom is empty");
		printf("\n\nPress Esc to Main Menu\n");
		fclose(fp);
		fclose(tmp);
		getch();
		
	}
	else{
		fclose(fp);
		fclose(tmp);
		remove("gelisimhotel.txt");
		rename("temp.txt","gelisimhotel.txt");
		printf("\n\nRoom %s checked out!",del_room);
		printf("\n\nPress Esc to Main Menu\n");
		getch();
	}
	
};
void search_name(){
   
   system("cls");
   char roomno[20];
   int guestFound =0,i,row;
   
   	printf("\n\n\t\t*******************************\n");
	printf("\t\t*         SEARCH MENU         *");
    printf("\n\t\t*******************************\n\n");
   
   fp=fopen("gelisimhotel.txt","r+");
   if(fp==0)
		exit(0);
	printf("Enter room number to find: \n");
	scanf("%s", roomno);
	
	gotoxy(1,11);
	printf("ROOM");
	gotoxy(7,11);
	printf("NAME");
	gotoxy(17,11);
	printf("SURNAME");
	gotoxy(29,11);
	printf("ADDRESS");
	gotoxy(49,11);
	printf("PHONE");
	gotoxy(64,11);
	printf("NATIONALITY");
	gotoxy(88,11);
	printf("PERIOD");
	gotoxy(98,11);
	printf("ARRIVAL DATE\n\n");
	for(i=0;i<120;i++)
		printf("=");
	row=15;
		
	while(fread(&h,sizeof(h),1,fp)==1){
		if(strcmp(h.room,roomno)==0){
			guestFound=1;
			gotoxy(1,row);
			printf("%s",h.room);
			gotoxy(7,row);
			printf("%s",h.name);
			gotoxy(17,row);
			printf("%s",h.surname);
			gotoxy(29,row);
			printf("%s",h.address);
			gotoxy(49,row);
			printf("%s",h.phone);
			gotoxy(64,row);
			printf("%s",h.nationality);
			gotoxy(88,row);
			printf("%s",h.period);
			gotoxy(98,row);
			printf("%s",h.arrivaldate);
			row++;
		}
			
	}
	if(guestFound==0){	
		printf("\nRoom %s not found!\n",roomno);
	}
	
	printf("\n\nPress Esc to Main Menu\n");
	getch();
	fclose(fp);
	
	
}
void show(){
	int i,row;
	
	if((fp=fopen("gelisimhotel.txt","r"))==NULL)
		exit(0);
		system("cls");
		printf("\n\n\t\t\t*************** GUEST LIST ***************\n");

		gotoxy(1,5);
		printf("ROOM");
		gotoxy(7,5);
		printf("NAME");
		gotoxy(17,5);
		printf("SURNAME");
		gotoxy(29,5);
		printf("ADDRESS");
		gotoxy(49,5);
		printf("PHONE");
		gotoxy(64,5);
		printf("NATIONALITY");
		gotoxy(88,5);
		printf("PERIOD");
		gotoxy(98,5);
		printf("ARRIVAL DATE\n\n");
		for(i=0;i<120;i++)
			printf("=");
		row=9;
		
		while(fread(&h,sizeof(h),1,fp)==1){
			gotoxy(1,row);
			printf("%s",h.room);
			gotoxy(7,row);
			printf("%s",h.name);
			gotoxy(17,row);
			printf("%s",h.surname);
			gotoxy(29,row);
			printf("%s",h.address);
			gotoxy(49,row);
			printf("%s",h.phone);
			gotoxy(64,row);
			printf("%s",h.nationality);
			gotoxy(88,row);
			printf("%s",h.period);
			gotoxy(98,row);
			printf("%s",h.arrivaldate);
			row++;
			
		}
		
		printf("\n\n");
		for(i=0;i<120;i++)
			printf("=");
		fclose(fp);
		printf("\n\nPress Esc to Main Menu\n");
		getch();
	
	
};

void end(){
	system("cls");
	printf("\n\n\t *****THANK YOU*****");
	Sleep(1000);
	printf("\n                 FOR");
	Sleep(1000);
	printf("\n\t *****CHOOSING US*****");
	Sleep(2000);
	exit(0);
}


    
    
    
    
    

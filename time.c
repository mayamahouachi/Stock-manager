#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
struct timing{
	int h;
	int m;
	int s;
};
struct timee{
	char day[20];
	char month[20];
	int dym;
	struct timing time;
	int year;
};

void topper(char ch[20]){
    int i;
    char aux;
    for(i=0;i<strlen(ch);i++){
        aux=toupper(ch[i]);
        ch[i]=aux;
    }
};
void gotoxy(short x, short y)
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
};
struct description{
	char color[20];
	short type;//1,2,3 could be int
};
struct product{
	int productID;
	char name[20];
	float price;//dont use double
	struct description discp;
	char inventory;//a,b,c
	int Qt;
	float inventoryVAL;
	char  Time[40];
}p;
struct files{
	FILE *fselect;
	FILE *fconserve; 
};
void menu(void);
void add(){ 
    struct product p;
	struct timee T;
    float t;
    int test,ID;
    FILE *fptr,*f;
       int k,j,i;
       char w;
    char b='a';
    //fptr = fopen("TEST!.txt","a+");
    printf("How many items would you like to add? ");
    scanf("%d",&k);
    while(k<=0){
           printf("invalid!! Please enter the number of items you want to add : ");
           scanf("%d",&k);
		}
    for(i=1;i<=k;i++){
a:      //fptr = fopen("TEST!.txt","a+");
        printf("Give the product to add:------------------\n\n");
I:
        printf("Product Id: ");
        scanf("%d",&ID);
        while(ID<=0){
           printf("INVALID !! Please enter a positive number for the ID : ");
           scanf("%d",&ID);
		}//&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL
		fptr = fopen("TEST!.txt","a+");
		while(fscanf(fptr,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
	    	if(ID==p.productID){
	    		printf("This product already exists\n");
				fclose(fptr);
	    		goto I;
			}
		}
		p.productID=ID;
        do
		{   printf("Product Name: ");
            scanf("%s",&p.name);
		   topper(p.name);
			for (j=0; j<strlen(p.name); j++)
			{	
				if(isalpha(p.name[j])){
					test = 1;
				}
				else
				{
					test = 0;
					break;
				}
			}
			if (test==0)
			{
				printf(" Please 'Enter' an alphabetic string \n");
				getch();		
			}
		}while(test==0);
        printf("Product Price: ");
        scanf(" %f",&p.price);//lf
        while(p.price<=0){
           printf("invalid!! Please enter a positive number for the price : ");
           scanf("%f",&t);
           p.price=t;
		}
        printf("Product Description:\n");
        printf("\nProduct color[BLACK,BLUE,RED]: ");
        scanf("%s",&p.discp.color);
        topper(p.discp.color);
        while((strcmp(p.discp.color,"RED")!=0)&&(strcmp(p.discp.color,"BLUE")!=0)&&(strcmp(p.discp.color,"BLACK")!=0)){
        	printf("Wrong!! Please enter [BLACK,BLUE,RED]: ");
        	scanf("%s",&p.discp.color);
        	topper(p.discp.color);
		}
        printf("Product type[1,2,3]: ");
        scanf("%hd",&p.discp.type);
        while((p.discp.type!=1)&&(p.discp.type!=2)&&(p.discp.type!=3)){
        	printf("Wrong!! Please enter [1,2,3]: ");
        	scanf("%hd",&p.discp.type);
		}
        printf("Inventory[A,B,C]: ");
        scanf("%s",&p.inventory);
        p.inventory=toupper(p.inventory);
        while((p.inventory!='A')&&(p.inventory!='B')&&(p.inventory!='C')){
        	printf("Wrong!! Please enter [A,B,C]: ");
        	scanf("%s",&p.inventory);
        	p.inventory=toupper( p.inventory);
		}
        printf("Quantity : ");
        scanf("%d",&p.Qt);
        while(p.Qt<0){
           printf("Quantity : ");
           scanf("%d",&p.Qt);
		}
        p.inventoryVAL=p.Qt*p.price;
        
        time_t  D;
	     time(&D);

        fprintf(fptr,"\n%d",p.productID);
        fprintf(fptr," %s",p.name);
        fprintf(fptr," %.3f",p.price);
        fprintf(fptr," %s",p.discp.color);
        fprintf(fptr," %hd",p.discp.type);
        fprintf(fptr," %c",p.inventory);
        fprintf(fptr," %d",p.Qt);
        fprintf(fptr," %.3f",p.inventoryVAL);
        fprintf(fptr," %s",ctime(&D));
       fclose(fptr);
              	f=fopen("historique.txt","a+");
       	fprintf(f,"\n%c",b);
       fprintf(f," %s",ctime(&D));
       fprintf(f," %d",p.productID);
       	
    fclose(f);
        
 
    }
    printf("If you want to add new products press(y) Or press any other keys to return to the Main Menu");
w=getch();
   system("cls");
   if(toupper(w)=='Y'){
   	goto a;
   }
   menu();
}
struct files Select(FILE *f){//retourne 2file qui sont remplis des donnees qu'on voulait selectionnes et un autre rempli des donnees a ne pas toucher
	int i,o,j,test;
    char w;
    char m='u';
    FILE *ft;
	struct files FL,F;
	char nm[20],col[20],inv,nmS[20],colS[20],invS,black[]="BLACK",blue[]="BLUE",red[]="RED";
	float pr,inval,prMX,prMN,invalMX,invalMN;
	int pid,qt,p,qtS;
	int ok;
	short typ,typS;
	char a[]="A",b[]="B",c[]="C";
	struct timee T;
	check:
	printf("\n\nWHICH serie of products do you wish to use ?");
	printf("\nGroup by :\n(1)ProductID[UNIQUE]\n(2)name\n(3)price\n(4)color\n(5)type\n(6)Quantity\n(7)inventoryVAL\n");
	
	printf("Press the number corresponding to your selection ?");
	scanf("%d",&i);
	
	//F.fselect=fopen("select.txt","w");
	/*F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);*/
	ok=0;
	fclose(f);
	switch(i){
		case 1:
			
			label:
			F.fconserve=fopen("conserve.txt","w");
    		fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			printf("Give the product id[UNIQUE]:");
			scanf("%d",&p);
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){//(fscanf(F.fselect,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
				
				if (pid==p ){
					ok++;}
					
					
								if ((pid==p )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								time_t  D;
								time(&D);
								fprintf(F.fselect," %s\n",ctime(&D));
								fclose(F.fselect);
						}
						else{
								F.fconserve=fopen("conserve.txt","a+");
								fprintf(F.fconserve,"%d",pid);
								fprintf(F.fconserve," %s",nm);
								fprintf(F.fconserve," %.3f",pr);
								fprintf(F.fconserve," %s",col);
								fprintf(F.fconserve," %hd",typ);
								fprintf(F.fconserve," %c",inv);
								fprintf(F.fconserve," %d",qt);
								fprintf(F.fconserve," %.3f",inval);
								fprintf(F.fconserve," %s",T.day);
								fprintf(F.fconserve," %s",T.month);
								fprintf(F.fconserve," %d",T.dym);
								fprintf(F.fconserve," %d",T.time.h);
								fprintf(F.fconserve,":%d",T.time.m);
								fprintf(F.fconserve,":%d",T.time.s);
								fprintf(F.fconserve," %d\n",T.year);
								fclose(F.fconserve);
													}
						
			ft=fopen("historique.txt","a+");
           	fprintf(ft,"\n%c",m);
           	time_t  D;
			time(&D);
            fprintf(ft," %s",ctime(&D));
            fprintf(ft," %d",pid);
       	
            fclose(ft);

			}
			if (ok==0){
				printf("WRONG! non existant product id!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label;
			}
			break;
 
		case 2:
			label1:
			F.fconserve=fopen("conserve.txt","w");
                        fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
		        do
		        {  	printf("Give the product name selection:  ");
			        scanf("%s",&nmS);
			        topper(nmS);
			        for (j=0; j<strlen(nmS); j++)
			        {	
				     if(isalpha(nmS[j])){
					 test = 1;
				     }
				     else
				     {
					test = 0;
					break;
				     }
			        }
			        if (test==0)
			        {
				        printf(" Please 'Enter' an alphabetic string \n");
				        getch();		
			        }
		        }while(test==0);
				while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){				
					if (strcmp(nm,nmS) == 0 ){
					ok++;}
					
					
								if ((strcmp(nm,nmS) == 0 )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
								fclose(F.fselect);
						}
						else{
						
				if (strcmp(nm,nmS) == 0 ){// Les deux cha?nes sont ?gales si vrai
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
					fclose(F.fselect);
				}
				else{
				F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}

			ft=fopen("historique.txt","a+");
           	fprintf(ft,"\n%c",m);
           	time_t  D;
			time(&D);
            fprintf(ft," %s",ctime(&D));
            fprintf(ft," %d",pid);
       	
            fclose(ft);
        }
			if (ok==0){
				printf("WRONG non existant product name!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label1;
			}
			break;
		case 3:
			label2:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			printf("Give Minimum price of the product selection : ");
			scanf("%f",&prMN);
			printf("Give Maximum price of the product selection : ");
			scanf("%f",&prMX);
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
			if ((pr>=prMN )&&(pr<=prMX)){
					ok++;}
					
					
								if ((pr>=prMN )&&(pr<=prMX)&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
								fclose(F.fselect);
						}
						else{	
			
				
				if ((pr>=prMN )&&(pr<=prMX)){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			 	ft=fopen("historique.txt","a+");
           	fprintf(ft,"\n%c",m);
           	time_t  D;
			time(&D);
            fprintf(ft," %s",ctime(&D));
            fprintf(ft," %d",pid);
       	
            fclose(ft);
			}
			if (ok==0){
				printf("Inavailable products,TRY another scale!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label2;
			}
			break;
		case 4:
			label3:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			do{
			printf("Give the product color[BLUE,BLACK,RED] selection: ");
			scanf("%s",&colS);
			topper(colS);
			//printf("%d\n",((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0)));
			}
			while ((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0));// strcmp peut donner -1!!!!!!!!!!!!1
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
				if (strcmp(colS,col)==0 ){
					ok++;}
					
					
								if ((strcmp(colS,col)==0 )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
								fclose(F.fselect);
						}
						else{	
	
				
				if (strcmp(colS,col)==0 ){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			if (ok!=0){
			ft=fopen("historique.txt","a+");
           	fprintf(ft,"\n%c",m);
           	time_t  D;
			time(&D);
            fprintf(ft," %s",ctime(&D));
            fprintf(ft," %d",pid);
       	
            fclose(ft);
			}
		}
			if (ok==0){
				printf("Wrong non existant product in such color !!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label3;
			}
			break;
		case 5:
			label4:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			do{
			
			printf("Give the product type[1,2,3] selection :");
			scanf("%hd",&typS);
			}
			while ((typS!=1)&&(typS!=2)&&(typS!=3));
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
					if (typ==typS ){
					ok++;}
					
					
								if ((typ==typS )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
								fclose(F.fselect);
						}
						else{	
				
				if (typ==typS ){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
					fclose(F.fselect);
				}
				else{
				F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			 	ft=fopen("historique.txt","a+");
           	fprintf(ft,"\n%c",m);
           	time_t  D;
			time(&D);
            fprintf(ft," %s",ctime(&D));
            fprintf(ft," %d",pid);
       	
            fclose(ft);
			}
			if (ok==0){
				printf("No existant product in type!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label4;
			}
			break;
		
		case 6:
			label6:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			do{

			printf("Give Minimum quantity of products selection : ");
			scanf("%d",&qtS);}
			while(qtS<0);
		
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
			if (qt >=qtS ){
					ok++;}
					
					
								if ((qtS <=qt ) &&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
								fclose(F.fselect);
						}
						else{	
				if (qtS <=qt ){
					
				F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			 	ft=fopen("historique.txt","a+");
           	fprintf(ft,"\n%c",m);
           	time_t  D;
			time(&D);
            fprintf(ft," %s",ctime(&D));
            fprintf(ft," %d",pid);
       	
            fclose(ft);
			}
			if (ok==0){
				printf("Not enough product for the required quantity ");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label6;
			}
			break;
		case 7:
			label7:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			printf("give minimum inventory value selection :");
			scanf("%f",&invalMN);
			printf("give maximum inventory value selection :");
			scanf("%f",&invalMX);
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
				
			if ((inval>=invalMN)&&(inval<=invalMX)){
					ok++;}
					
					
								if ((inval>=invalMN)&&(inval<=invalMX) &&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
								fclose(F.fselect);
						}
						else{	
				
				if ((inval>=invalMN)&&(inval<=invalMX) ){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fselect," %s\n",ctime(&D));
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			 	ft=fopen("historique.txt","a+");
           	fprintf(ft,"\n%c",m);
           	time_t  D;
			time(&D);
            fprintf(ft," %s",ctime(&D));
            fprintf(ft," %d",pid);
       	
            fclose(ft);
			}
			if (ok==0){
				printf("Wrong non existant product id!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label7;
			}
			break;
		default :	
						system("cls");
						printf("INVALID choice !\n");
						goto check;	
	}  
		F.fselect=fopen("select.txt","r+");
		F.fconserve=fopen("conserve.txt","a+");
		return(F);
//noublier pas de les fermer apres les operations
}
////////////////////////////
//on va cree un select special pour readproducts
/////////
struct files SelectREAD(FILE *f){//retourne 2file qui sont remplis des donnees qu'on voulait selectionnes et un autre rempli des donnees a ne pas toucher
	int i,o,j,test;
    char w;
	struct files FL,F;
	char nm[20],col[20],inv,nmS[20],colS[20],invS,black[]="BLACK",blue[]="BLUE",red[]="RED";
	float pr,inval,prMX,prMN,invalMX,invalMN;
	int pid,qt,p,qtS;
	int ok;
	short typ,typS;
	char a[]="A",b[]="B",c[]="C";
	struct timee T;
	check:
	printf("\n\nWHICH serie of products do you wish to use ?");
	printf("\nGroup by :\n(1)ProductID[UNIQUE]\n(2)name\n(3)price\n(4)color\n(5)type\n(6)Quantity\n(7)inventoryVAL\n");
	
	printf("Press the number corresponding to your selection ?");
	scanf("%d",&i);
	
	//F.fselect=fopen("select.txt","w");
	/*F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);*/
	ok=0;
	fclose(f);
	switch(i){
		case 1:
			
			label:
			F.fconserve=fopen("conserve.txt","w");
    		fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			printf("Give the product id[UNIQUE]:");
			scanf("%d",&p);
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){//(fscanf(F.fselect,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
				
				if (pid==p ){
					ok++;}
					
					
								if ((pid==p )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
								fclose(F.fselect);
						}
						else{
								F.fconserve=fopen("conserve.txt","a+");
								fprintf(F.fconserve,"%d",pid);
								fprintf(F.fconserve," %s",nm);
								fprintf(F.fconserve," %.3f",pr);
								fprintf(F.fconserve," %s",col);
								fprintf(F.fconserve," %hd",typ);
								fprintf(F.fconserve," %c",inv);
								fprintf(F.fconserve," %d",qt);
								fprintf(F.fconserve," %.3f",inval);
								fprintf(F.fconserve," %s",T.day);
								fprintf(F.fconserve," %s",T.month);
								fprintf(F.fconserve," %d",T.dym);
								fprintf(F.fconserve," %d",T.time.h);
								fprintf(F.fconserve,":%d",T.time.m);
								fprintf(F.fconserve,":%d",T.time.s);
								fprintf(F.fconserve," %d\n",T.year);
								fclose(F.fconserve);
													}
						
				

			}
			if (ok==0){
				printf("WRONG! non existant product id!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label;
			}
			break;
		case 2:
			label1:
			F.fconserve=fopen("conserve.txt","w");
                        fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
		        do
		        {  	printf("Give the product name selection:  ");
			        scanf("%s",&nmS);
			        topper(nmS);
			        for (j=0; j<strlen(nmS); j++)
			        {	
				     if(isalpha(nmS[j])){
					 test = 1;
				     }
				     else
				     {
					test = 0;
					break;
				     }
			        }
			        if (test==0)
			        {
				        printf(" Please 'Enter' an alphabetic string \n");
				        getch();		
			        }
		        }while(test==0);
				while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){				
					if (strcmp(nm,nmS) == 0 ){
					ok++;}
					
					
								if ((strcmp(nm,nmS) == 0 )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
								fclose(F.fselect);
						}
						else{
						
				if (strcmp(nm,nmS) == 0 ){// Les deux cha?nes sont ?gales si vrai
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
					fclose(F.fselect);
				}
				else{
				F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("WRONG non existant product name!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label1;
			}
			break;
		case 3:
			label2:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			printf("Give Minimum price of the product selection : ");
			scanf("%f",&prMN);
			printf("Give Maximum price of the product selection : ");
			scanf("%f",&prMX);
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
			if ((pr>=prMN )&&(pr<=prMX)){
					ok++;}
					
					
								if ((pr>=prMN )&&(pr<=prMX)&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
								fclose(F.fselect);
						}
						else{	
			
				
				if ((pr>=prMN )&&(pr<=prMX)){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
										fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Inavailable products,TRY another scale!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label2;
			}
			break;
		case 4:
			label3:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			do{
			printf("Give the product color[BLUE,BLACK,RED] selection: ");
			scanf("%s",&colS);
			topper(colS);
			//printf("%d\n",((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0)));
			}
			while ((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0));// strcmp peut donner -1!!!!!!!!!!!!1
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
				if (strcmp(colS,col)==0 ){
					ok++;}
					
					
								if ((strcmp(colS,col)==0 )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
								fclose(F.fselect);
						}
						else{	
	
				
				if (strcmp(colS,col)==0 ){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Wrong non existant product in such color !!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label3;
			}
			break;
		case 5:
			label4:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			do{
			
			printf("Give the product type[1,2,3] selection :");
			scanf("%hd",&typS);
			}
			while ((typS!=1)&&(typS!=2)&&(typS!=3));
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
					if (typ==typS ){
					ok++;}
					
					
								if ((typ==typS )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
								fclose(F.fselect);
						}
						else{	
				
				if (typ==typS ){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
					fclose(F.fselect);
				}
				else{
				F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("No existant product in type!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label4;
			}
			break;
		
		case 6:
			label6:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			do{

			printf("Give Minimum quantity of products selection : ");
			scanf("%d",&qtS);}
			while(qtS<0);
		
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
			if (qt >=qtS ){
					ok++;}
					
					
								if ((qtS <=qt ) &&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
								fclose(F.fselect);
						}
						else{	
				if (qtS <=qt ){
					
				F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Not enough product for the required quantity ");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label6;
			}
			break;
		case 7:
			label7:
			F.fconserve=fopen("conserve.txt","w");
    fclose(F.fconserve);
			f=fopen("TEST!.txt","r+");
			printf("give minimum inventory value selection :");
			scanf("%f",&invalMN);
			printf("give maximum inventory value selection :");
			scanf("%f",&invalMX);
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF){
				
			if ((inval>=invalMN)&&(inval<=invalMX)){
					ok++;}
					
					
								if ((inval>=invalMN)&&(inval<=invalMX) &&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("select.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
								fclose(F.fselect);
						}
						else{	
				
				if ((inval>=invalMN)&&(inval<=invalMX) ){
					
					F.fselect=fopen("select.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f",inval);
								fprintf(F.fselect," %s",T.day);
								fprintf(F.fselect," %s",T.month);
								fprintf(F.fselect," %d",T.dym);
								fprintf(F.fselect," %d",T.time.h);
								fprintf(F.fselect,":%d",T.time.m);
								fprintf(F.fselect,":%d",T.time.s);
								fprintf(F.fselect," %d\n",T.year);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("conserve.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					fprintf(F.fconserve," %s",T.day);
					fprintf(F.fconserve," %s",T.month);
					fprintf(F.fconserve," %d",T.dym);
					fprintf(F.fconserve," %d",T.time.h);
					fprintf(F.fconserve,":%d",T.time.m);
					fprintf(F.fconserve,":%d",T.time.s);
					fprintf(F.fconserve," %d\n",T.year);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Wrong non existant product id!!");
				fclose(f);
                                    ////////
                                    printf("\nIf you want to go back to the main menu PRESS(y)!\nIf you want to try again => PRESS any other key\n");
                        w=getch();
                        if (toupper(w)=='Y'){
                            //getch();
                            menu();
                        }
                                    ////////
                system("cls");
				goto label7;
			}
			break;
		default :	
						system("cls");
						printf("INVALID choice !\n");
						goto check;	
	}
	
		F.fselect=fopen("select.txt","r+");
		F.fconserve=fopen("conserve.txt","a+");
		return(F);
//noublier pas de les fermer apres les operations
}
////////////////////////////////
void show(FILE *f){
    int i, q;
    struct timee T;

gotoxy(0,5);
			for(i=0;i<110;i++)
		{
			printf("-");
		}
		gotoxy(2,6);
		printf("ID");
		gotoxy(10,6);
		printf("Name");
		gotoxy(19,6);
		printf("Price");
		gotoxy(29,6);
		printf("Color");
		gotoxy(37,6);
		printf("Type");
		gotoxy(44,6);
		printf("Inventorty");
		gotoxy(57,6);
		printf("Quantity");
		gotoxy(69,6);
		printf("Inv-Value\n");
		gotoxy(95,6);
		printf("Time");
		q=8;
		while(fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF)
		{   gotoxy(2,q);
		    printf("%d",p.productID);
		    gotoxy(10,q);
            printf("%s",p.name);
            gotoxy(19,q);
            printf("%.3f",p.price);
            gotoxy(29,q);
            printf("%s",p.discp.color);
            gotoxy(37,q);
            printf("%hd",p.discp.type);
            gotoxy(44,q);
            printf("%c",p.inventory);
            gotoxy(57,q);
            printf("%d",p.Qt);
            gotoxy(69,q);
            printf("%.3f",p.inventoryVAL);
            gotoxy(84,q);
            printf("%s",T.day);  
			gotoxy(88,q);
			printf("%s",T.month);  
			gotoxy(92,q);
			printf("%d",T.dym);  
			gotoxy(95,q);
			printf("%d:%d:%d",T.time.h,T.time.m,T.time.s);  
			gotoxy(104,q);
			printf("%d",T.year);  
			gotoxy(111,q);
			q++;
		}
		printf("\n");
		for(i=0;i<110;i++)
			printf("-");
	}



//////////////////////
void delete_items(){
	int i,k;
	struct files F;
	FILE *f;
	char w;
	long size;
	if((f=fopen("TEST!.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
d:
	f=fopen("TEST!.txt","r+");
	fseek (f, 0, SEEK_END);
	size = ftell(f);
	if(size==0)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
//d:
	fclose(f);
	f = fopen("TEST!.txt","r+");
		
			printf("Press any key to select products to delete ");
			getch();
			F=Select(f);
			fclose(F.fselect);
		fclose(F.fconserve);
		fclose(f);
	
	system("cls");
		do {
				printf("\nDO you want to see the products that are going to DELETE?\n (1)yes , (0)no\n");
				scanf("%d",&k);
		}
		while (k!=0 && k!=1);
		if (k==1){
		F.fselect=fopen("select.txt","r");
		show(F.fselect);
		fclose(F.fselect);
		//F.fselect=fopen("select.txt","r+");
		}
	
	
		int rem;
		rem=remove("TEST!.txt");
		remove("select.txt");
		int ret;
		ret=rename("conserve.txt","TEST!.txt");
	 printf("\nIf you want to delete another product press(y) Or press any other keys to return to the Main Menu");
        w=getch();
        system("cls");
        if(toupper(w)=='Y'){
   	    goto d;
        }
         menu();	
}
///////////////////////////////////////////////////
////////////////////////////////////////////


void read_products(){
	///////////////
		FILE *f;
		struct files F;
		struct timee T;
		////////////////////////
			long size;
	time_t t;
	time(&t);
	f=fopen("TEST!.txt","r+");
	fseek (f, 0, SEEK_END);
	size = ftell(f);
	if(size==0){
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
	if((f=fopen("TEST!.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
		////////////////////


		f = fopen("TEST!.txt","r");
		
			printf("PRESS any key to select products that you want to READ : ");
			getch();
			F=SelectREAD(f);
			fclose(F.fselect);
		fclose(F.fconserve);
		fclose(f);
		system("cls");
		
		int i, q;
	
		f=fopen("select.txt","r");
		gotoxy(0,5);
			for(i=0;i<110;i++)
		{
			printf("-");
		}
		gotoxy(2,6);
		printf("ID");
		gotoxy(10,6);
		printf("Name");
		gotoxy(19,6);
		printf("Price");
		gotoxy(29,6);
		printf("Color");
		gotoxy(37,6);
		printf("Type");
		gotoxy(44,6);
		printf("Inventorty");
		gotoxy(57,6);
		printf("Quantity");
		gotoxy(69,6);
		printf("Inv-Value\n");
		gotoxy(95,6);
		printf("Time");
		q=8;
		while(fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF)
		{   gotoxy(2,q);
		    printf("%d",p.productID);
		    gotoxy(10,q);
            printf("%s",p.name);
            gotoxy(19,q);
            printf("%.3f",p.price);
            gotoxy(29,q);
            printf("%s",p.discp.color);
            gotoxy(37,q);
            printf("%hd",p.discp.type);
            gotoxy(44,q);
            printf("%c",p.inventory);
            gotoxy(57,q);
            printf("%d",p.Qt);
            gotoxy(69,q);
            printf("%.3f",p.inventoryVAL);
            gotoxy(84,q);
            printf("%s",T.day);  
			gotoxy(88,q);
			printf("%s",T.month);  
			gotoxy(92,q);
			printf("%d",T.dym);  
			gotoxy(95,q);
			printf("%d:%d:%d",T.time.h,T.time.m,T.time.s);  
			gotoxy(104,q);
			printf("%d",T.year);  
			gotoxy(111,q);
			q++;
		}
		printf("\n");
		for(i=0;i<110;i++)
			printf("-");
	
	fclose(f);
	remove("select.txt");////////////////
	printf("\nPRESS any key to go to Main Menu!");
		getch();
		menu();

		
		
		}

/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
void update(){
	char path[]="TEST!.txt";
	char nm[20],col[20],nmN[20],colS[20],inv,black[]="BLACK",blue[]="BLUE",red[]="RED";
	float pr,prN,inval,invalN;
	int pid,pidn,qt,k,qtS,c=0;
	short typ,typS;
	int i,j,test,r;
	char p;
	char u='U';
	struct files F;
	struct timee T;
    FILE *f,*ft;
    		long size;
	
	f=fopen("TEST!.txt","r+");
	fseek (f, 0, SEEK_END);
	size = ftell(f);
	if(size==0){
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
	if((f=fopen("TEST!.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
u:
		f = fopen(path,"r+");
		do{
			printf("PRESS (0) to use products selection, PRESS (1) to use all the products!");
			scanf("%d",&i);
		}
		while ((i!=0)&&(i!=1));
		if (i==0){//we choose selection///////////////////////////
			F=Select(f);
			fclose(f);
			r=0;
			
			do{
				printf("DO you want to see your selected list of projects ? (1)yes ,(0)no \n");
				scanf("%d",&i);
}
				while (i!=1 && i!=0);
				if (i==1){
				system("cls");
				show(F.fselect);
				fclose(F.fselect);
				
		}
		F.fselect=fopen("select.txt","r+");
		}
		else {//we work on the whole set/////////////////////////////
			fclose(f);
			F.fselect=fopen(path,"r+");
			F.fconserve=fopen("conserve.txt","w");
		}
rep:		printf("\nWHAT column do you wish to update ? ");
		
		printf("\n(1)name\n(2)price\n(3)color\n(4)type\n(5)Quantity\n");
		scanf("%d",&k);
	


	switch(k){	
			case 1:
		         do
		         {  	printf("Give the product name selection:  ");
			        scanf("%s",&nmN);
			        topper(nmN);
			        for (j=0; j<strlen(nmN); j++)
			        {	
				      if(isalpha(nmN[j])){
					 test = 1;
				      }
				      else
				      {
					 test = 0;
					 break;
				      }
			        }
			        if (test==0)
			        {
				        printf(" Please 'Enter' an alphabetic string \n");
				        getch();		
			        }
		             }while(test==0);
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
					
					strcpy(nm,nmN);
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fconserve," %s\n",ctime(&D));
			}
				break;
				
				
			case 2:
				do{
				printf("Give the NEW price of these products : ");
				scanf("%f",&prN);
			}
			while (prN<0);	
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
					pr=prN;
					
					invalN=qt*pr;
					inval=invalN;
					
					
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fconserve," %s\n",ctime(&D));
				}
				
				
				
				break;
				
			case 3:
				do{
				printf("Give the NEW product color[BLUE,BLACK,RED]: ");
				scanf("%s",&colS);
				topper(colS);
				}
				while ((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0));
				
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
					strcpy(col,colS);
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fconserve," %s\n",ctime(&D));
			}
				break;
				
			case 4:
				
				
				do{
				
				printf("Give the NEW product type[1,2,3]:");
				scanf("%hd",&typS);
				}
				while ((typS!=1)&&(typS!=2)&&(typS!=3));
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
					typ=typS;
				fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fconserve," %s\n",ctime(&D));
			}
				break;
			case 5:
				
				
				
				do{

				printf("Give the UPDATED quantity : ");
				scanf("%d",&qtS);}
				while(qtS<0);
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)==15){
					qt=qtS;
					
					invalN=qt*pr;
					inval=invalN;
					
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f",inval);
					time_t  D;
					time(&D);
					fprintf(F.fconserve," %s\n",ctime(&D));
			}
				break;
			default:
				system("cls");
				printf("INVALID choice!");
				goto rep;
				
				
		}			
		fclose(F.fselect);
		fclose(F.fconserve);
		fclose(f);
		int rem;
		rem=remove(path);
		remove("select.txt");
			int ret;
		ret=rename("conserve.txt",path);
		if (r!=0){
		f=fopen("historique.txt","a+");
       	fprintf(f,"\n%c",u);
       	time_t  D;
		time(&D);
        fprintf(f," %s",ctime(&D));
        fclose(f);
    }

	

	
	printf("If you want to Update another set of products press(y) Or press any other keys to return to the Main Menu");
        p=getch();
        system("cls");
        if(toupper(p)=='Y'){
   	    goto u;
        }
         menu();
}
void read_Product_ALL(){
		FILE *f;
	int i, q;
	long size;
	time_t t;
	char times[50];
	struct timee T;
	time(&t);
	f=fopen("TEST!.txt","r+");
	fseek (f, 0, SEEK_END);
	size = ftell(f);
	if(size==0){
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
	if((f=fopen("TEST!.txt","r"))==NULL)
	{
	
		gotoxy(10,3);
		printf("NO RECORDS");
		printf("\n\t\tPress any key to go back to Menu.");
		getch();
		menu();


	}
	else
	{
	
		gotoxy(0,5);
			for(i=0;i<110;i++)
		{
			printf("-");
		}
		gotoxy(2,6);
		printf("ID");
		gotoxy(10,6);
		printf("Name");
		gotoxy(19,6);
		printf("Price");
		gotoxy(29,6);
		printf("Color");
		gotoxy(37,6);
		printf("Type");
		gotoxy(44,6);
		printf("Inventorty");
		gotoxy(57,6);
		printf("Quantity");
		gotoxy(69,6);
		printf("Inv-Value\n");
		gotoxy(95,6);
		printf("Time");
		q=8;
		while(fscanf(f,"%d %s %f %s %hd %c %d %f %s %s %d %d:%d:%d %d\n",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year)!=EOF)
		{   gotoxy(2,q);
		    printf("%d",p.productID);
		    gotoxy(10,q);
            printf("%s",p.name);
            gotoxy(19,q);
            printf("%.3f",p.price);
            gotoxy(29,q);
            printf("%s",p.discp.color);
            gotoxy(37,q);
            printf("%hd",p.discp.type);
            gotoxy(44,q);
            printf("%c",p.inventory);
            gotoxy(57,q);
            printf("%d",p.Qt);
            gotoxy(69,q);
            printf("%.3f",p.inventoryVAL);
            gotoxy(84,q);
            printf("%s",T.day);  
			gotoxy(88,q);
			printf("%s",T.month);  
			gotoxy(92,q);
			printf("%d",T.dym);  
			gotoxy(95,q);
			printf("%d:%d:%d",T.time.h,T.time.m,T.time.s);  
			gotoxy(104,q);
			printf("%d",T.year);  
			gotoxy(111,q);
			q++;
		}
		printf("\n");
		for(i=0;i<110;i++)
			printf("-");
	}
	fclose(f);
	
	printf("\nPress any key to go to Main Menu!");
		getch();
		menu();

}
void delete_All(){
	char w;
	char d='D';
	FILE *f;
	long size;
	f=fopen("TEST!.txt","r+");
	fseek (f, 0, SEEK_END);
	size = ftell(f);
	if(size==0){
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
	if((f=fopen("TEST!.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);	
	printf("Do you really want to delete all the products?\nif yes PRESS(y) \nif no PRESS any other key and return to the main menu");
	w=getch();
	if (toupper(w)=='Y'){
		remove("TEST!.txt");
		f=fopen("historique.txt","a+");
     	fprintf(f,"\n%c",d);
        time_t  D;
	    time(&D);
        fprintf(f," %s",ctime(&D));
        fclose(f);
		printf("\nPress any key to go to Main Menu!");
		getch();
		menu();

	}
	system("cls");
	menu();
}
void Op_history(){
	FILE *f;
	char op;
	int i,q;
	long size;
	time_t t;
	char times[50];
	struct timee T;
	time(&t);
	f=fopen("historque.txt","r+");
    	fseek (f, 0, SEEK_END);
	size = ftell(f);
	if(size==0){
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	fclose(f);
	if((f=fopen("historique.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
			gotoxy(0,2);
			for(i=0;i<110;i++)
		{
			printf("-");
		}
	q=4;
	while(fscanf(f," %c %s %s %d %d:%d:%d %d %d",&op,&T.day,&T.month,&T.dym,&T.time.h,&T.time.m,&T.time.s,&T.year,&p.productID)!=EOF){
			gotoxy(0,q);
		if (op=='a'){
			printf("you added");
		}
		else if(toupper(op)=='U'){
			printf("you updated");
		}
		else if(toupper(op)=='D'){
			printf("you deleted");
		}
		    gotoxy(12,q);
		    printf("at"); 
			gotoxy(18,q);
            printf("%s",T.day);  
			gotoxy(23,q);
			printf("%s",T.month);  
			gotoxy(27,q);
			printf("%d",T.dym);  
			gotoxy(32,q);
			printf("%d:%d:%d",T.time.h,T.time.m,T.time.s);  
			gotoxy(43,q);
			printf("%d",T.year);
			gotoxy(50,q); 
			if ((op=='U')||(op=='D')){
				printf("all the products");
			}
			else{
			
			printf("the product %d",p.productID);
		}
		q++;
	}
	fclose(f);
	
	printf("\n\nPress any key to go to Main Menu!");
		getch();
		menu();

	
}
void menu(void)
{
	int choice;
	system("cls");
	main:
	printf("\n======================== Product Management System ========================");
	printf("                                                                                          ");
	printf("                                                                                          ");
	printf("\n\t\tPress <1> Add Products");
	printf("\n\t\tPress <2> Delete Products");
	printf("\n\t\tPress <3> Update Products");
	printf("\n\t\tPress <4> Read Products");
	printf("\n\t\tPress <5> Read ALL Products");
	printf("\n\t\tPress <6> Delete ALL");
	printf("\n\t\tPress <7> Operation History");
	printf("\n\t\tPress <8> Exit!");	
	printf("\n\n\t\tEnter your choice: ");
	scanf("%i", &choice);
	
	system("cls");
	
	switch(choice)	
	{
		case 1:
			add();
			break;
		case 2:
			delete_items();
			break;
		case 3:
			update();
			break;
		case 4:
			read_products();
			break;
		case 5:
			read_Product_ALL();
			break;
		case 6:
			delete_All();
			break;
		case 7:
	     	Op_history();
			break;
		case 8:
		printf("System Exit");
		exit(0);
		break;
			
		
		default:
		system("cls");
		printf("Invalid Choice! System Exit\n");
			getch();

	}
	
}
int main()
{   time_t t;
	time(&t);
    printf("                                                                                                         \n");
    printf(" -------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t%s",ctime(&t));
	printf("---------------------------------------------------------------------------------------------------------\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t  \t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t|\t   WELCOME TO   \t |\t\t\t\t\t|\n");
    printf("|\t\t\t\t|\t STOCK  MANAGEMENT  \t |\t\t\t\t\t|\n");
    printf("|\t\t\t\t  \t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("|PRESS any key to continue  \t\t\t\t\t\t\t\t\t\t|\n");

    printf(" -------------------------------------------------------------------------------------------------------\n");
getch();
system("cls");
menu();
}

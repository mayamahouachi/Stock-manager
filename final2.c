#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<ctype.h>
#include<conio.h>
#include<windows.h>
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
	
}p;
struct files{
	FILE *fselect;
	FILE *fconserve; 
};
void menu(void);
void add(){ 
    struct product p;
    float t;
    int test,ID;
    FILE *fptr;
       int k,j,i;
       char c;
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
		 while(fscanf(fptr,"%d %s %f %s %hd %c %d %f",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL)==8){
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
        printf("Inventary[A,B,C]: ");
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


        fprintf(fptr,"\n%d",p.productID);
        fprintf(fptr," %s",p.name);
        fprintf(fptr," %.3f",p.price);
        fprintf(fptr," %s",p.discp.color);
        fprintf(fptr," %hd",p.discp.type);
        fprintf(fptr," %c",p.inventory);
        fprintf(fptr," %d",p.Qt);
        fprintf(fptr," %.3f",p.inventoryVAL);
       fclose(fptr);
    }
    printf("If you want to add new products press(y) Or press any other keys to return to the Main Menu");
c=getch();
   system("cls");
   if(toupper(c)=='Y'){
   	goto a;
   }
   menu();
}
struct files Select(FILE *f){//retourne 2file qui sont remplis des donnees qu'on voulait selectionnes et un autre rempli des donnees a ne pas toucher
	int i,o;
	struct files FL,F;
	char nm[20],col[20],inv,nmS[20],colS[20],invS,black[]="BLACK",blue[]="BLUE",red[]="RED";
	float pr,inval,prMX,prMN,invalMX,invalMN;
	int pid,qt,p,qtS;
	int ok;
	short typ,typS;
	char a[]="A",b[]="B",c[]="C";
	check:
	printf("which serie of products do you wish to use ?");
	printf("Group by :\n(1)name\n(2)price\n(3)color\n(4)type\n(5)Quantity\n(6)inventoryVAL\n");
	
	printf("Press the number corresponding to your selection ?");
	scanf("%d",&i);
	
	//F.fselect=fopen("inter1.txt","w");
	F.fconserve=fopen("inter2.txt","w");
    fclose(F.fconserve);
	ok=0;
	switch(i){
	
		case 1:
			label1:
			
			printf("Give the product name:  ");
			scanf("%s",&nmS);
			topper(nmS);
			while (fscanf(f,"%d %s %f %s %hd %c %d %f\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
				if (strcmp(nm,nmS) == 0 ){
					ok++;}
					
					
								if ((strcmp(nm,nmS) == 0 )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("inter1.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f\n",inval);
								fclose(F.fselect);
						}
						else{
						
				if (strcmp(nm,nmS) == 0 ){// Les deux cha�nes sont �gales si vrai
					
					F.fselect=fopen("inter1.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f\n",inval);
					fclose(F.fselect);
				}
				else{
				F.fconserve=fopen("inter2.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("WRONG non existant product name!!");
				goto label1;
			}
			break;
		case 2:
			label2:
			
			printf("Give Maximum price of the product : ");
			scanf("%f",&prMX);
			printf("Give Minimum price of the product : ");
			scanf("%f",&prMN);
			while (fscanf(f,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
			if ((pr>=prMN )&&(pr<=prMX)){
					ok++;}
					
					
								if ((pr>=prMN )&&(pr<=prMX)&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("inter1.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f\n",inval);
								fclose(F.fselect);
						}
						else{	
			
				
				if ((pr>=prMN )&&(pr<=prMX)){
					
					F.fselect=fopen("inter1.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f\n",inval);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("inter2.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Inavailable products,TRY another scale!!");
				goto label2;
			}
			break;
		case 3:
			label3:
			do{
			printf("Give the product color[BLUE,BLACK,RED]: ");
			scanf("%s",&colS);
			topper(colS);
			//printf("%d\n",((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0)));
			}
			while ((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0));// strcmp peut donner -1!!!!!!!!!!!!1
			
			while (fscanf(f,"%d %s %f %s %hd %c %d %f\n",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
				if (strcmp(colS,col)==0 ){
					ok++;}
					
					
								if ((strcmp(colS,col)==0 )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("inter1.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f\n",inval);
								fclose(F.fselect);
						}
						else{	
	
				
				if (strcmp(colS,col)==0 ){
					
					F.fselect=fopen("inter1.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f\n",inval);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("inter2.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Wrong non existant product in such color !!");
				goto label3;
			}
			break;
		case 4:
			label4:
			do{
			
			printf("Give the product type[1,2,3]:");
			scanf("%hd",&typS);
			}
			while ((typS!=1)&&(typS!=2)&&(typS!=3));
			while (fscanf(f,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8) {
					if (typ==typS ){
					ok++;}
					
					
								if ((typ==typS )&&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("inter1.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f\n",inval);
								fclose(F.fselect);
						}
						else{	
				
				if (typ==typS ){
					
					F.fselect=fopen("inter1.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f\n",inval);
					fclose(F.fselect);
				}
				else{
				F.fconserve=fopen("inter2.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("No existant product in type!!");
				goto label4;
			}
			break;
		
		case 5:
			label6:
			do{

			printf("Give minimum quantity : ");
			scanf("%d",&qtS);}
			while(qtS<0);
		
			while (fscanf(f,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
			if (qt >=qtS ){
					ok++;}
					
					
								if ((qtS <=qt ) &&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("inter1.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f\n",inval);
								fclose(F.fselect);
						}
						else{	
				if (qtS <=qt ){
					
				F.fselect=fopen("inter1.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f\n",inval);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("inter2.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Not enough product for the required quantity ");
				goto label6;
			}
			break;
		case 6:
			label7:
			printf("give maximum inventory value :");
			scanf("%f",&invalMX);
			printf("give minimum inventory value :");
			scanf("%f",&invalMN);
			while (fscanf(f,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
				
			if ((inval>=invalMN)&&(inval<=invalMX)){
					ok++;}
					
					
								if ((inval>=invalMN)&&(inval<=invalMX) &&(ok==1)){
								//on doit etre sur que ce nouveau ficher va etre rempli par des nouveaux elements qui satisfaient les sorts
								F.fselect=fopen("inter1.txt","w");//w
								fprintf(F.fselect,"%d",pid);
								fprintf(F.fselect," %s",nm);
								fprintf(F.fselect," %.3f",pr);
								fprintf(F.fselect," %s",col);
								fprintf(F.fselect," %hd",typ);
								fprintf(F.fselect," %c",inv);
								fprintf(F.fselect," %d",qt);
								fprintf(F.fselect," %.3f\n",inval);
								fclose(F.fselect);
						}
						else{	
				
				if ((inval>=invalMN)&&(inval<=invalMX) ){
					
					F.fselect=fopen("inter1.txt","a+");
					fprintf(F.fselect,"%d",pid);
					fprintf(F.fselect," %s",nm);
					fprintf(F.fselect," %.3f",pr);
					fprintf(F.fselect," %s",col);
					fprintf(F.fselect," %hd",typ);
					fprintf(F.fselect," %c",inv);
					fprintf(F.fselect," %d",qt);
					fprintf(F.fselect," %.3f\n",inval);
					fclose(F.fselect);
				}
				else{
					F.fconserve=fopen("inter2.txt","a+");
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
					fclose(F.fconserve);
				}
			}
			}
			if (ok==0){
				printf("Wrong non existant product id!!");
				goto label7;
			}
			break;
		default :	goto check;	
	}
	
		F.fselect=fopen("inter1.txt","r+");
		F.fconserve=fopen("inter2.txt","a+");
		return(F);
//noublier pas de les fermer apres les operations
}
////////////////////////////


void show(FILE *f){
    int i, q;
    

        gotoxy(0,5);
            for(i=0;i<110;i++)
        {
            printf("-");
        }
        gotoxy(5,6);
        printf("ID");
        gotoxy(15,6);
        printf("Name");
        gotoxy(25,6);
        printf("Price");
        gotoxy(35,6);
        printf("Color");
        gotoxy(48,6);
        printf("Type");
        gotoxy(60,6);
        printf("Inventorty");
        gotoxy(74,6);
        printf("Quantity");
        gotoxy(87,6);
        printf("Inv-Value\n");
        q=8;
        while(fscanf(f,"%d %s %f %s %hd %c %d %f\n",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL)!=EOF)
        {   gotoxy(5,q);
            printf("%d",p.productID);
            gotoxy(15,q);
            printf("%s",p.name);
            gotoxy(25,q);
            printf("%.3f",p.price);
            gotoxy(35,q);
            printf("%s",p.discp.color);
            gotoxy(48,q);
            printf("%hd",p.discp.type);
            gotoxy(60,q);
            printf("%c",p.inventory);
            gotoxy(74,q);
            printf("%d",p.Qt);
            gotoxy(87,q);
            printf("%.3f",p.inventoryVAL);
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
	char c;
	if((f=fopen("TEST!.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
d:
	f = fopen("TEST!.txt","r+");
		
			printf("Press any key to selet products to delete ");
			getch();
			F=Select(f);
			fclose(F.fselect);
		fclose(F.fconserve);
		fclose(f);
	
	system("cls");
		do {
				printf("DO you want to see the products that are going to DELETE?\n (1)yes , (0)no");
				scanf("%d",&k);
		}
		while (k!=0 && k!=1);
		if (k==1){
		F.fselect=fopen("inter1.txt","r");
		show(F.fselect);
		fclose(F.fselect);
		F.fselect=fopen("inter1.txt","r+");
		}
	
	
		int rem;
		rem=remove("TEST!.txt");
		remove("inter1.txt");
		int ret;
		ret=rename("inter2.txt","TEST!.txt");
	 printf("\nIf you want to delete another product press(y) Or press any other keys to return to the Main Menu");
        c=getch();
        system("cls");
        if(toupper(c)=='Y'){
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
		////////////////////////
		////////////////////


		f = fopen("TEST!.txt","r");
		
			printf("PRESS any key to select products to delete ");
			getch();
			F=Select(f);
			fclose(F.fselect);
		fclose(F.fconserve);
		fclose(f);
		system("cls");
		
		int i, q;
	
		f=fopen("inter1.txt","r");
		gotoxy(0,5);
			for(i=0;i<110;i++)
		{
			printf("-");
		}
		gotoxy(5,6);
		printf("ID");
		gotoxy(15,6);
		printf("Name");
		gotoxy(25,6);
		printf("Price");
		gotoxy(35,6);
		printf("Color");
		gotoxy(48,6);
		printf("Type");
		gotoxy(60,6);
		printf("Inventorty");
		gotoxy(74,6);
		printf("Quantity");
		gotoxy(87,6);
		printf("Inv-Value\n");
		q=8;
		while(fscanf(f,"%d %s %f %s %hd %c %d %f\n",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL)!=EOF)
		{   gotoxy(5,q);
		    printf("%d",p.productID);
		    gotoxy(15,q);
            printf("%s",p.name);
            gotoxy(25,q);
            printf("%.3f",p.price);
            gotoxy(35,q);
            printf("%s",p.discp.color);
            gotoxy(48,q);
            printf("%hd",p.discp.type);
            gotoxy(60,q);
            printf("%c",p.inventory);
            gotoxy(74,q);
            printf("%d",p.Qt);
            gotoxy(87,q);
            printf("%.3f",p.inventoryVAL);
			q++;
		}
		printf("\n");
		for(i=0;i<110;i++)
			printf("-");
	
	fclose(f);
	remove("inter1.txt");////////////////
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
	int i;
	char p;
	struct files F;
    FILE *f;
    
u:
		f = fopen(path,"r+");
		do{
			printf("PRESS (0) to use products selection, PRESS (1) to use all the products!");
			scanf("%d",&i);
		}
		while ((i!=0)&&(i!=1));
		if (i==0){
			F=Select(f);

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
		}
		else {
			F.fselect=f;
			F.fconserve=fopen("inter2.txt","w");
		}
		//show(F.fselect);
		F.fselect=fopen("inter1.txt","r+");
		printf("\nWHAT do you want to update ? ");
		do{
		printf("\n(1)name\n(2)price\n(3)color\n(4)type\n(5)Quantity\n");
		scanf("%d",&k);
	}
	while (k<1 || k>8);

		//fTemp = fopen("replace.tmp", "w"); 
		switch(k){	
			case 1:
				printf("Give the new product name : ");
				scanf("%s",&nmN);
				topper(nmN);
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
					
					strcpy(nm,nmN);
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
			}
				break;
				
				
			case 2:
				do{
				printf("Give the new price of these products : ");
				scanf("%f",&prN);
			}
			while (prN<0);	
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
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
					fprintf(F.fconserve," %.3f\n",inval);
				}
				
				
				
				break;
				
			case 3:
				do{
				printf("Give the new product color[BLUE,BLACK,RED]: ");
				scanf("%s",&colS);
				topper(colS);
				}
				while ((strcmp(colS,black)!=0)&&(strcmp(colS,red)!=0)&&(strcmp(colS,blue)!=0));
				
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
					strcpy(col,colS);
					fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
			}
				break;
				
			case 4:
				
				
				do{
				
				printf("Give the product type[1,2,3]:");
				scanf("%hd",&typS);
				}
				while ((typS!=1)&&(typS!=2)&&(typS!=3));
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
					typ=typS;
				fprintf(F.fconserve,"%d",pid);
					fprintf(F.fconserve," %s",nm);
					fprintf(F.fconserve," %.3f",pr);
					fprintf(F.fconserve," %s",col);
					fprintf(F.fconserve," %hd",typ);
					fprintf(F.fconserve," %c",inv);
					fprintf(F.fconserve," %d",qt);
					fprintf(F.fconserve," %.3f\n",inval);
			}
				break;
			case 5:
				
				
				
				do{

				printf("Give Minimum quantity : ");
				scanf("%d",&qtS);}
				while(qtS<0);
				while (fscanf(F.fselect,"%d %s %f %s %hd %c %d %f",&pid,&nm,&pr,&col,&typ,&inv,&qt,&inval)==8){
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
					fprintf(F.fconserve," %.3f\n",inval);
			}
				
				
		}			
		fclose(F.fselect);
		fclose(F.fconserve);
		fclose(f);
		int rem;
		rem=remove(path);
		remove("inter1.txt");
		/*if (rem!= 0) {
			/* handle error 
			printf("mahabech file yetfasakh");
		}*/
		
		
		
			int ret;
		ret=rename("inter2.txt",path);

	
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
		gotoxy(5,6);
		printf("ID");
		gotoxy(15,6);
		printf("Name");
		gotoxy(25,6);
		printf("Price");
		gotoxy(35,6);
		printf("Color");
		gotoxy(48,6);
		printf("Type");
		gotoxy(60,6);
		printf("Inventorty");
		gotoxy(74,6);
		printf("Quantity");
		gotoxy(87,6);
		printf("Inv-Value\n");
		q=8;
		while(fscanf(f,"%d %s %f %s %hd %c %d %f\n",&p.productID,&p.name,&p.price,&p.discp.color,&p.discp.type,&p.inventory,&p.Qt,&p.inventoryVAL)!=EOF)
		{   gotoxy(5,q);
		    printf("%d",p.productID);
		    gotoxy(15,q);
            printf("%s",p.name);
            gotoxy(25,q);
            printf("%.3f",p.price);
            gotoxy(35,q);
            printf("%s",p.discp.color);
            gotoxy(48,q);
            printf("%hd",p.discp.type);
            gotoxy(60,q);
            printf("%c",p.inventory);
            gotoxy(74,q);
            printf("%d",p.Qt);
            gotoxy(87,q);
            printf("%.3f",p.inventoryVAL);
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
	char c;
	FILE *f;
	if((f=fopen("TEST!.txt","r+"))==NULL)
	{
		printf("NO RECORD ADDED.");
		getch();
		menu();
	}
	printf("Do you really want to delete all the products?\nif yes press(y) \nif no press any other key and return to the main menu");
	c=getch();
	if (toupper(c)=='Y'){
		remove("TEST!.txt");
		printf("\nPress any key to go to Main Menu!");
		getch();
		menu();

	}
	system("cls");
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
	printf("\n\t\tPress <7> Exit!");	
	
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
		printf("System Exit");
		exit(0);
		break;
			
		
		default:
		printf("Invalid Choice! System Exit\n");
			getch();

	}
	
}
int main()
{
    printf("                                                                                                         \n");
    printf(" -------------------------------------------------------------------------------------------------------\n");
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


 #include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"time.h"

#define systemc system("cls");

struct date
{
	int dd,mm,yy;
}today;	

struct bill
{
	int billnumber;
	char companyname[32];
	char companyaddress[148];
	char companymono[12];
	char companymailid[48];
	char companygstno[16];
	char partyname[32];
	char partyaddress[148];
	char partymono[12];
	char partymailid[48];
	char partygstno[16];
	float amount;
	float tempamount;
	float gst;
	struct date d_date;
}b;

struct amount
{
	char gstno[16];
	int billnumber;
	float tempamont;
	struct date d;
};
	
struct product 
{
	int billnumber;
	char productname[32];
	float productprice;
	int productqty;
}pr;

struct defaultsetting
{
	char companyname[32];
	char companyaddress[148];
	char companymono[12];
	char companymailid[48];
	char companygst[16];
	int flag;
}ds;

struct billnumber
{
	int b2bsellnumber;
	int b2bbuynumber;
	int b2coffline;
}bn;

struct date gdate(void);
void generatebill(int,int);
void makebill(int);
void billnumber(void);
void defaultsetting(void);
int strcmpf(char *,char *);
void searchbill(int);
void gstgenerate(int,struct date);
void billhistory(int);
void billpayment(int);
void putsf(char *);
void modifybill(int);
void deleteproduct(int,int);
void deletebill(int);
void partydetails(int);
int checkgst(char *);
int checkmono(char *);
void sleep(int);
void runbill(void);
int main()
{
	
	
	int choise,im=0,choise1;

	while(im==0)
	{
			prechoise:
			systemc
		printf("*****************MAIN MENU******************************");	
		printf("\n 1. Making bill");
		printf("\n 2. Search Bill");
		printf("\n 3. Modify Bill");
		printf("\n 4. Delete Bill");
		printf("\n 5. Bill History");
		printf("\n 6. payment");
		printf("\n 7. Default");
		printf("\n 8. Reset BillNumber");
		printf("\n 9. Exit");
		printf("\n*********************************************************");
		today=gdate();
		printf("\n Date : %d/%d/%d",today.dd,today.mm,today.yy);
				printf("\n*********************************************************");

		printf("\n Which Option You Want To Select Now ?");printf("\t %c  ",26);
		scanf("%d",&choise);
		switch(choise)
		{
			
			case 1:
				{
					systemc
					
					printf("\n*********************************************************");
					printf("\n 1. B2B-sell Bill");
					printf("\n 2. B2B-buy Bill");
					printf("\n 3. B2C Offlinebill");
					printf("\n*********************************************************");
					printf("\n Which Bill You Want To Make?");printf("\t %c  ",26);
					scanf("%d",&choise1);
					makebill(choise1);			
					break;
				}
				
			case 2:
				{
					systemc
					printf("\n*********************************************************");
					printf("\n 1. Date Wise B2B-sell Bill");
					printf("\n 2. Date Wise B2B-buy Bill");
					printf("\n 3. Date Wise B2C Offlinebill");
					printf("\n 4. GSTNO Wise B2B-sell Bill");
					printf("\n 5. GSTNO Wise B2B-Buy Bill");
					printf("\n 6. Search Bill Through Bill number");
					printf("\n*********************************************************");
					printf("\n Which Bill You Want To Search?");printf("\t %c  ",26);

					scanf("\n %d",&choise1);
					searchbill(choise1);
					break;	
				}
			case 3:
				{
					systemc
				
					printf("\n*********************************************************");
					printf("\n 1. B2B-sell Bill");
					printf("\n 2. B2B-buy Bill");
					printf("\n 3. B2C Offlinebill");
					printf("\n*********************************************************");
						printf("\n Which Bill You Want To Modify?");printf("\t %c  ",26);
					scanf("%d",&choise1);
					modifybill(choise1);
					break;	
				}	
			case 4:
				{
					systemc
										printf("\n*********************************************************");

					printf("\n 1. B2B-sell Bill");
					printf("\n 2. B2B-buy Bill");
					printf("\n 3. B2C Offlinebill");
										printf("\n*********************************************************");
					printf("\n Which Bill You Want To Delete?");printf("\t %c  ",26);

					scanf("\n %d",&choise1);
					deletebill(choise1);				
					break;
				}
			case 5:
				{
					systemc
															printf("\n*********************************************************");

					printf("\n 1. B2B-sell Bill");
					printf("\n 2. B2B-buy Bill");
					printf("\n 3. B2C Offlinebill");
															printf("\n*********************************************************");
					printf("\n Which Bill's History You Want To see?");printf("\t %c  ",26);

					scanf("\n %d",&choise1);
					billhistory(choise1);
					break;
				}	
			case 6:
				{
					systemc
				
					printf("\n*********************************************************");

					printf("\n 1. B2B-sell Bill");
					printf("\n 2. B2B-buy Bill");
					printf("\n 3. B2C Offlinebill");
					printf("\n 4. B2b-sell Each Party's Details");
					printf("\n 5. B2b- Buy Each Party's Details");
					printf("\n*********************************************************");
	printf("\n Which Bill's payment You Want To Pay?");printf("\t %c  ",26);
					scanf("\n %d",&choise1);
					billpayment(choise1);
					break;
				}	
			case 7:
				{
					defaultsetting();
					break;
				}
			case 8:
				{
					runbill();
					break;
				}			
			case 9:
				{
					systemc
					printf("\n Thanks...");
					printf("\nExiting in 3 second...........>");sleep(1000);
					printf("\nExiting in 2 second...........>");sleep(1000);
					printf("\nExiting in 1 second...........>");sleep(1000);

					exit(0);
				}
			default:
				{
					printf("\n Invalid Choise");
					systemc
					goto prechoise;
					break;
				}			
		}	
	}
	
	return 0;
}


void makebill(int n)
{
	FILE *fp1,*fp2,*dfs,*bill;
	int i,dill=0;
	float sum=0;
	bill=fopen("billnumber.txt","r");
	if(bill==NULL)
	{
		printf("\n For the first time you must have to running reset billnumber function");
		getch();
		exit(0);
	}
	fread(&bn,sizeof(bn),1,bill);
	fclose(bill);
	dfs=fopen("default.txt","a+");
		if(dfs==NULL)
		{
			getch();
			printf("\n default file doesn't Exist");
			exit(0);
		}
		fread(&ds,sizeof(ds),1,dfs);
		b.d_date=gdate();
	if(ds.flag==1)
	{
		
		strcpy(b.companyname,ds.companyname);
		strcpy(b.companyaddress,ds.companyaddress);
		strcpy(b.companymono,ds.companymono);
		strcpy(b.companymailid,ds.companymailid);
		strcpy(b.companygstno,ds.companygst);
		fclose(dfs);
		
		if(n==1)
		{
			fp1=fopen("b2bsell.txt","a");
			fp2=fopen("b2bsellproduct.txt","a");
		}
		else if(n==2)
		{
			fp1=fopen("b2bbuy.txt","a");
			fp2=fopen("b2bbuyproduct.txt","a");
		}
		else if(n==3)
		{
			fp1=fopen("b2coffline.txt","a");
			fp2=fopen("b2cofflineproduct.txt","a");
		}
	}
	else 
	{
		fclose(dfs);	
		if(n==1)
		{
			fp1=fopen("b2bsell.txt","a");
			fp2=fopen("b2bsellproduct.txt","a");

		}
		else if(n==2)
		{
			fp1=fopen("b2bbuy.txt","a");
			fp2=fopen("b2bbuyproduct.txt","a");

		}
		else if(n==3)
		{
			fp1=fopen("b2coffline.txt","a");
			fp2=fopen("b2cofflineproduct.txt","a");

		}
		if(n==1||n==2||n==3)
		{
			printf("\n Enter Your Company's Name :          ");fflush(stdin);      	gets(b.companyname);
			
		
			printf("\n Enter Your Company's Address :       ");
			fflush(stdin);
			gets(b.companyaddress);
			printf("\n Enter Your Company's GST NO :        ");
			fflush(stdin);
			gets(b.companygstno);
			while(checkgst(b.companygstno)==0)
			{
				printf("\n Entered Right Gst Number :           ");
				gets(b.companygstno);
			}
			printf("\n Enter Your company's Mobile Number : +91");
			fflush(stdin);
			gets(b.companymono);
			while(checkmono(b.companymono)==0)
			{
				printf("\n Entered Right Mobile Number :        +91");
				gets(b.companymono);
			}
			printf("\n Enter Your Company's Mail Id :        ");
			fflush(stdin);
			gets(b.companymailid);
		}
		
	}
	
	if(n==1||n==2)
	{
		if(n==1)
		b.billnumber=bn.b2bsellnumber;
		else if(n==2)
		b.billnumber=bn.b2bbuynumber;
		
			printf("\n Enter Your party's Company Name :           ");fflush(stdin);gets(b.partyname);
			
			printf("\n Enter Your Party's Company Address :        ");fflush(stdin);gets(b.partyaddress);
		
			printf("\n Enter Your Party's GST NO :                 ");fflush(stdin);gets(b.partygstno);
			
			while(checkgst(b.partygstno)==0)
			{
				printf("\n Entered Right Gst Number :                  ");
				gets(b.partygstno);
			}
			
			printf("\n Enter Your party's company Mobile Number : +91");fflush(stdin);gets(b.partymono);
			
			while(checkmono(b.partymono)==0)
			{
				printf("\n Entered Right Mobile Number :              +91");
				gets(b.partymono);
			}
			printf("\n Enter Your Party's Comapny Mail Id :       ");fflush(stdin);gets(b.partymailid);
			
	}
	else if(n==3)
	{
		b.billnumber=bn.b2coffline;
			printf("\n Enter customer's Name :           ");
			fflush(stdin);
			gets(b.partyname);
			printf("\n Enter Customer's Address :        ");
			fflush(stdin);
			gets(b.partyaddress);
			printf("\n Enter Customer's Mobile Number :  +91");
			fflush(stdin);
			gets(b.partymono);
				while(checkmono(b.partymono)==0)
			{
				printf("\n Entered Right Mobile Number :     +91");
				gets(b.partymono);
			}
			printf("\n Enter Customer's Mail Id :        ");
			fflush(stdin);
			gets(b.partymailid);	
	}
	printf("\n*********************************************************");
	printf("\n How Many prduct's Dill you are doing ?");printf("\t %c  ",26);
	scanf("%d",&dill);
	
	for(i=1;i<=dill;i++)
	{
		pr.billnumber=b.billnumber;
		printf("\n Enter a product name :       ");
		fflush(stdin);
		gets(pr.productname);
		printf("\n Enter a product price :      ");
		scanf("%f",&pr.productprice);
		printf("\n Enter QTY. :                 ");
		scanf("%d",&pr.productqty);

		fwrite(&pr,sizeof(pr),1,fp2);
		
		sum=sum+(pr.productprice*pr.productqty);

	}
			printf("\n Total Amount =               %f",sum);
	        fclose(fp2);
			printf("\n\n Entered GST Rate :           ");
			scanf("%f",&b.gst);
	b.amount=sum;
	b.tempamount=sum;
	fwrite(&b,sizeof(b),1,fp1);
	fclose(fp1);

	if(n==1)
	{
		bn.b2bsellnumber=bn.b2bsellnumber+1;
	}
	else if(n==2)
	{
		bn.b2bbuynumber=bn.b2bbuynumber+1;
	}
	else if(n==3)
	{
		bn.b2coffline=bn.b2coffline+1;
	}
	bill=fopen("billnumber.txt","w");
	fwrite(&bn,sizeof(bn),1,bill);
	fclose(bill);
	today.dd=0;today.mm=0;today.yy=0;
	generatebill(n,b.billnumber);
	
}





void defaultsetting()
{
	FILE *fp;
	int i=0,j;
	fp=fopen("default.txt","w");
	if(fp==NULL)
	{
	printf("\n For the first time you must have to running reset billnumber function");
		getch();
		exit(0);
	}
	while(i!=3)
	{
		systemc
		printf("\n*********************************************************");
		printf("\n 1.Add Content Or Modify Content");
		printf("\n 2.Delete Default Content");
		printf("\n 3.Go To Home Page ");
		printf("\n*********************************************************");
		printf("\n Select Option : ");printf("\t %c  ",26);
		scanf("%d",&j);
		switch(j)
		{
			case 1:
				{
					printf("\n Enter Your Company's Name :             ");
					fflush(stdin);
					gets(ds.companyname);
					printf("\n Enter Your Company's Address :          ");
					fflush(stdin);
					gets(ds.companyaddress);
					printf("\n Enter Your Company's GSTNO :            ");
					fflush(stdin);
					gets(ds.companygst);
					while(checkgst(ds.companygst)==0)
					{
						printf("\n Entered Right Gst Number :              ");
						gets(ds.companygst);
					}
					printf("\n Enter Your Company's Mobile Number :   +91");
					fflush(stdin);
					scanf("%s",ds.companymono);
					while(checkmono(ds.companymono)==0)
					{			
						printf("\n Entered Right Mobile Number :          +91");
						fflush(stdin);
						gets(ds.companymono);
					}
					printf("\n Enter Your Company's Email Id :        ");
					fflush(stdin);
					gets(ds.companymailid);
					ds.flag=1;
					fwrite(&ds,sizeof(ds),1,fp);
					break;
				}
			case 2:
				{
					ds.flag=0;
					fwrite(&ds,sizeof(ds),1,fp);
					break;
				}
			case 3:
				{
					i=3;
					break;
				}	
			default:
				{
					printf("\n Enter Valid Input");
					break;
				}		
		}
	}
	fclose(fp);
	printf("\n Your Default setting Updated...");
}

void billnumber()
{
	FILE *fp;
	fp=fopen("billnumber.txt","w");
	if(fp==NULL)
	{
		printf("\n Billnumber file does not exist");
		exit(0);
	}
	bn.b2bsellnumber=1;
	bn.b2bbuynumber=100000;
	bn.b2coffline=150000;
	
	fwrite(&bn,sizeof(bn),1,fp);
	fclose(fp);
}

void generatebill(int n,int o)
{
	FILE *fp1,*fp2;
	int c=0,e=1;
	if(n==1)
	{
		fp1=fopen("b2bsell.txt","r");
		fp2=fopen("b2bsellproduct.txt","r");
		if(fp2==NULL)
		{
			printf("\n File does not exist");
			exit(0);
		}
		while(fread(&b,sizeof(b),1,fp1))
		{
			if((o==b.billnumber))
			{
				c=1;
				break;
			}
		}
		if(c!=1)
		{
			printf("\n This Bill Is not available");
			exit(0);
		}
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","r");
		fp2=fopen("b2bbuyproduct.txt","r");
		while(fread(&b,sizeof(b),1,fp1))
		{
			if((o==b.billnumber))
			{
				c=1;
				break;
			}
		}
		if(c!=1)
		{
			printf("\n This Bill is not available");
			exit(0);
		}
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","r");
		fp2=fopen("b2cofflineproduct.txt","r");
		while(fread(&b,sizeof(b),1,fp1))
		{
			if((o==b.billnumber))
			{
				c=1;
				break;
			}
		}
		if(c!=1)
		{
			printf("\n This Bill is not avalable");
			exit(0);
		}
	}
	
	printf("\n_______________________________________________________________________________");
	printf("\n Date : %d/%d/%d",b.d_date.dd,b.d_date.mm,b.d_date.yy);
	printf("\n Bill number : %d",b.billnumber);
	printf("\n_______________________________________________________________________________");

	printf("\n\n **********Company's Details********** ");
	printf("\n_______________________________________________________________________________\n");
	puts(b.companyname);
	puts(b.companyaddress);
	puts(b.companygstno);
	puts(b.companymono);
	puts(b.companymailid);
	
		printf("\n_______________________________________________________________________________");
	printf("\n\n *********Party's Details**********");
	printf("\n_______________________________________________________________________________\n");
	puts(b.partyname);
	puts(b.partyaddress);
	puts(b.partygstno);
	puts(b.partymono);
	puts(b.partymailid);
		printf("\n_______________________________________________________________________________");
		printf("\n\n********** Product Details**********");
		printf("\n_______________________________________________________________________________");
		printf("\n No.");printf("\t Price");printf("\t\t QTY.");printf("\t GST");printf("\t\tProduct Name");
	while(fread(&pr,sizeof(pr),1,fp2))
	{
	
		if((o==pr.billnumber))
		{
		
			printf("\n %d",e);	printf("\t %f",pr.productprice);printf("\t %d",pr.productqty);printf("\t %f",b.gst);
			printf("\t");puts(pr.productname);
			e++;
		}
		
	}
	printf("\n_______________________________________________________________________________");
	printf("\n Total = %f",b.amount);
	printf("\n Temp -Amount = %f",b.tempamount);
	
	fclose(fp1);
	fclose(fp2);
	
	getch();
}

void searchbill(int n)
{
	char d[16];
	int i;
	if(n==1)
	{	
		printf("\n Enter A Date In this Formet : dd/mm/yyyy :");
		scanf("%d %d %d",&today.dd,&today.mm,&today.yy);
		gstgenerate(1,today);
	}
	else if(n==2)
	{	
			printf("\n Enter A Date In this Formet : dd/mm/yyyy :");
		scanf("%d %d %d",&today.dd,&today.mm,&today.yy);
		gstgenerate(2,today);
	}
	else if(n==3)
	{
			printf("\n Enter A Date In this Formet : dd/mm/yyyy :");
		scanf("%d %d %d",&today.dd,&today.mm,&today.yy);
		gstgenerate(3,today);
	}
	else if(n==4)
	{
		today.dd=0;today.mm=0;today.yy=0;
		gstgenerate(1,today);
		getch();
	}
	else if(n==5)
	{
		today.dd=0;today.mm=0;today.yy=0;
		gstgenerate(2,today);
	}
	else if(n==6)
	{
		printf("\n Enter a bill number, Which Details You want to see now :");
		scanf("%d",&i);
		if(i<99999)
		{
			generatebill(1,i);
		}
		else if(i<150000)
		{
			generatebill(2,i);
		}
		else
		{
			generatebill(3,i);
		}
	}
}

void gstgenerate(int n,struct date d)
{
	systemc
	int e=1;
	FILE *fp1,*fp2;
	char g[16];
	if(d.dd==0)
	{
			printf("\n Enter a gstno , Which details you want to see : ");
			scanf("%s",g);
			while(checkgst(g)==0)
			{
				printf("\n Entered Right Gst Number :");
				gets(g);
			}
	}

	
	if(n==1)
	{
		fp1=fopen("b2bsell.txt","r");
		fp2=fopen("b2bsellproduct.txt","r");
		if(fp2==NULL)
		{
			printf("\n File does not exist");
			exit(0);
		}
		while(fread(&b,sizeof(b),1,fp1))
		{
			if((strcmp(b.partygstno,g)==0)||((d.dd==b.d_date.dd)&&(d.mm==b.d_date.mm)&&(d.yy==b.d_date.yy)))
			{
						printf("\n_______________________________________________________________________________");
	printf("\n Date : %d/%d/%d",b.d_date.dd,b.d_date.mm,b.d_date.yy);
	printf("\n Bill number : %d",b.billnumber);
	printf("\n_______________________________________________________________________________");

	printf("\n\n **********Company's Details********** ");
	printf("\n_______________________________________________________________________________\n");
						puts(b.companyname);
						puts(b.companyaddress);
						puts(b.companygstno);
						puts(b.companymono);	
						puts(b.companymailid);
	
						printf("\n_______________________________________________________________________________");
	printf("\n\n *********Party's Details**********");
	printf("\n_______________________________________________________________________________\n");
						puts(b.partyname);
						puts(b.partyaddress);			
						puts(b.partygstno);
						puts(b.partymono);
						puts(b.partymailid);
							printf("\n_______________________________________________________________________________");
		printf("\n\n********** Product Details**********");
		printf("\n_______________________________________________________________________________");
		printf("\n No.");printf("\t Price");printf("\t\t QTY.");printf("\t GST");printf("\t\tProduct Name");
						while(fread(&pr,sizeof(pr),1,fp2))
						{
	
							if(b.billnumber==pr.billnumber)
							{
								printf("\n %d",e);	printf("\t %f",pr.productprice);printf("\t %d",pr.productqty);printf("\t %f",b.gst);
			printf("\t");puts(pr.productname);
			e++;
							}
						}
	
					printf("\n Total = %f",b.amount);
			}
					printf("\n_______________________________________________________________________________");

			rewind(fp2);
		}
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","r");
		fp2=fopen("b2bbuyproduct.txt","r");
		if(fp2==NULL)
		{
			printf("\n File does not exist");
			exit(0);
		}
		while(fread(&b,sizeof(b),1,fp1))
		{
			if(strcmp(b.partygstno,g)==0)
			{
			printf("\n_______________________________________________________________________________");
	printf("\n Date : %d/%d/%d",b.d_date.dd,b.d_date.mm,b.d_date.yy);
	printf("\n Bill number : %d",b.billnumber);
	printf("\n_______________________________________________________________________________");

	printf("\n\n **********Company's Details********** ");
	printf("\n_______________________________________________________________________________\n");
						puts(b.companyname);
						puts(b.companyaddress);
						puts(b.companygstno);
						puts(b.companymono);	
						puts(b.companymailid);
	
						printf("\n_______________________________________________________________________________");
	printf("\n\n *********Party's Details**********");
	printf("\n_______________________________________________________________________________\n");
						puts(b.partyname);
						puts(b.partyaddress);			
						puts(b.partygstno);
						puts(b.partymono);
						puts(b.partymailid);
							printf("\n_______________________________________________________________________________");
		printf("\n\n********** Product Details**********");
		printf("\n_______________________________________________________________________________");
		printf("\n No.");printf("\t Price");printf("\t\t QTY.");printf("\t GST");printf("\t\tProduct Name");
	while(fread(&pr,sizeof(pr),1,fp2))
	{
	
		if(b.billnumber==pr.billnumber)
		{
				printf("\n %d",e);	printf("\t %f",pr.productprice);printf("\t %d",pr.productqty);printf("\t %f",b.gst);
			printf("\t");puts(pr.productname);
			e++;
		}
	}
	
	printf("\n Total = %f",b.amount);
			printf("\n_______________________________________________________________________________");

			}
		}
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","r");
		fp2=fopen("b2cofflineproduct.txt","r");
		if(fp2==NULL)
		{
			printf("\n File does not exist");
			exit(0);
		}
		while(fread(&b,sizeof(b),1,fp1))
		{
			if((strcmp(b.partygstno,g)==0)||((d.dd==b.d_date.dd)&&(d.mm==b.d_date.mm)&&(d.yy==b.d_date.yy)))
			{
							printf("\n_______________________________________________________________________________");
	printf("\n Date : %d/%d/%d",b.d_date.dd,b.d_date.mm,b.d_date.yy);
	printf("\n Bill number : %d",b.billnumber);
	printf("\n_______________________________________________________________________________");

	printf("\n\n **********Company's Details********** ");
	printf("\n_______________________________________________________________________________\n");
						puts(b.companyname);
						puts(b.companyaddress);
						puts(b.companygstno);
						puts(b.companymono);	
						puts(b.companymailid);
	
						printf("\n_______________________________________________________________________________");
	printf("\n\n *********Party's Details**********");
	printf("\n_______________________________________________________________________________\n");
						puts(b.partyname);
						puts(b.partyaddress);			
						puts(b.partygstno);
						puts(b.partymono);
						puts(b.partymailid);
							printf("\n_______________________________________________________________________________");
		printf("\n\n********** Product Details**********");
		printf("\n_______________________________________________________________________________");
		printf("\n No.");printf("\t Price");printf("\t\t QTY.");printf("\t GST");printf("\t\tProduct Name");
						while(fread(&pr,sizeof(pr),1,fp2))
						{
	
							if(b.billnumber==pr.billnumber)
							{
										printf("\n %d",e);	printf("\t %f",pr.productprice);printf("\t %d",pr.productqty);printf("\t %f",b.gst);
			printf("\t");puts(pr.productname);
			e++;
							}
						}
	
					printf("\n Total = %f",b.amount);
			}
					printf("\n_______________________________________________________________________________");

			rewind(fp2);
		}
	}
	

	
	fclose(fp1);
	fclose(fp2);
	
	getch();
}

void billhistory(int n)
{
	int i=1;
	float sum=0,gst=0;
	FILE *fp1;
	if(n==1)
	{
		fp1=fopen("b2bsell.txt","r");
		printf("\n_______________________________________________________________________________");
		printf("\n DATE.");printf("\t\t");printf("Bill No");printf("\t");printf("GST");printf("\t");printf("\tCreadit");printf("\t");printf("\tTotal Amount");printf("\tParty");
		printf("\n_______________________________________________________________________________");
		while(fread(&b,sizeof(b),1,fp1))
		{
			printf("\n");
			printf("%d/%d/%d",b.d_date.dd,b.d_date.mm,b.d_date.yy);printf("\t");printf("%d",b.billnumber);printf("\t");
			printf("%f",b.gst);printf("\t%f",b.tempamount);printf("\t");printf("%f",b.amount);printf("\t");putsf(b.partyname);
			sum=sum+b.amount;
			gst=gst+((b.amount*b.gst)/100);
			i++;
		}
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","r");
		printf("\n NO.");printf("\t");printf("Bill No");printf("\t");printf("GST");printf("\t");printf("Total Amount");printf("\t");printf("Party's Name");
		while(fread(&b,sizeof(b),1,fp1))
		{
			printf("\n");
			printf("%d",i);printf("\t");printf("%d",b.billnumber);printf("\t");
			printf("%f",b.gst);printf("\t%f",b.tempamount);printf("\t");printf("%f",b.amount);printf("\t");putsf(b.partyname);
			sum=sum+b.amount;
			gst=gst+((b.amount*b.gst)/100);
			i++;
		}
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","r");
		printf("\n NO.");printf("\t");printf("Bill No");printf("\t");printf("GST");printf("\t");printf("Total Amount");printf("\t");printf("Customer's Name");
		while(fread(&b,sizeof(b),1,fp1))
		{
			printf("\n");
			printf("%d",i);printf("\t");printf("%d",b.billnumber);printf("\t");
		printf("%f",b.gst);printf("\t%f",b.tempamount);printf("\t");printf("%f",b.amount);printf("\t");	putsf(b.partyname);
			sum=sum+b.amount;
			gst=gst+((b.amount*b.gst)/100);
			i++;
		}
	}
	printf("\n_______________________________________________________________________________");
	printf("\n\nTotal Gst = %f",gst);
	printf("\nTotal Amount = %f",sum);
	fclose(fp1);
	getch();
}



void putsf(char *p)
{
	int i;
	for(i=0;*(p+i)!='\0';i++)
	{
		printf("%c",*(p+i));
	}
}

void modifybill(int n)
{
	int i,dill,k;
	float sum=0;
	FILE *fp1,*fp2,*fp3;
	fp2=fopen("temp.txt","w");
	if(n==1)
	{
		fp1=fopen("b2bsell.txt","r");
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","r");
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","r");
	}
	
	printf("\n Enter a Bill number ,Which Bill You Want To Modify :  ");
	scanf("%d",&i);
while(fread(&b,sizeof(b),1,fp1))
{
	if(b.billnumber==i)
	{
			b.billnumber=i;
	 		printf("\n Enter Your Company's Name :            ");
			fflush(stdin);
			gets(b.companyname);
			printf("\n Enter Your Company's Address :         ");
			fflush(stdin);
			gets(b.companyaddress);
			printf("\n Enter Your Company's GST NO :          ");
			fflush(stdin);
				gets(b.companygstno);
			while(checkgst(b.companygstno)==0)
			{
				printf("\n Entered Right Gst Number :             ");
				gets(b.companygstno);
			}
		
			printf("\n Enter Your company's Mobile Number :  +91");
			fflush(stdin);
			gets(b.companymono);
				while(checkmono(b.companymono)==0)
			{
				printf("\n Entered Right Mobile Number :         +91");
				gets(b.companymono);
			}
			printf("\n Enter Your Company's Mail Id :         ");
			fflush(stdin);
			gets(b.companymailid);
			printf("\n\n Enter party's(Customer's) Company Name :          ");
			fflush(stdin);
			gets(b.partyname);
			printf("\n Enter Party's(Customer's) Company Address :       ");
			fflush(stdin);
			gets(b.partyaddress);
			if(n==1||n==2)
			{
				printf("\n Enter Party's GST NO :                            ");
				fflush(stdin);
				gets(b.partygstno);
					while(checkgst(b.partygstno)==0)
			{
				printf("\n Entered Right Gst Number :                        ");
				gets(b.partygstno);
			}
		
			}
			printf("\n Enter party's(Customer's) company Mobile Number : +91");
			fflush(stdin);
			gets(b.partymono);
				while(checkmono(b.partymono)==0)
			{
				printf("\n Enterd Right Mobile Number :                      +91");
				gets(b.partymono);
			}
			printf("\n Enter Party's(Customer's) Comapny Mail Id :       ");
			fflush(stdin);
			gets(b.partymailid);
			deleteproduct(n,i);
	
    	if(n==1)
		{
			fp3=fopen("b2bsellproduct.txt","a");
		}
		else if(n==2)
		{
			fp3=fopen("b2bbuyproduct.txt","a");
		}
		else if(n==3)
		{
			fp3=fopen("b2cofflineproduct.txt","a");
		}
		printf("\n\n_______________________________________________________________________________");
		printf("\n How many product's ,You have to complete ?");printf("\t %c  ",26);
		scanf("%d",&dill);
		for(k=1;k<=dill;k++)
		{
			pr.billnumber=i;
			printf("\n Enter a product name  : ");
			fflush(stdin);
			gets(pr.productname);
			printf("\n Enter a product price : ");
			scanf("%f",&pr.productprice);
			printf("\n Enter QTY. :            ");
			scanf("%d",&pr.productqty);

			fwrite(&pr,sizeof(pr),1,fp3);
		
			sum=sum+(pr.productprice*pr.productqty);
		}
		printf("\n_______________________________________________________________________________");
		fclose(fp3);
		b.amount=sum;
		b.tempamount=sum;
		fwrite(&b,sizeof(b),1,fp2);
	}	
	else 
	{
		fwrite(&b,sizeof(b),1,fp2);
	}
}
fclose(fp1);
fclose(fp2);

fp2=fopen("temp.txt","r");
if(n==1)
	{
		fp1=fopen("b2bsell.txt","w");
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","w");
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","w");
	}
while(fread(&b,sizeof(b),1,fp2))
{
	fwrite(&b,sizeof(b),1,fp1);
}
fclose(fp1);
fclose(fp2);

generatebill(n,i);
}

void deleteproduct(int n,int i)
{
	FILE *fp1,*fp2;
	fp2=fopen("tempproduct.txt","w");
	if(n==1)
	{
		fp1=fopen("b2bsellproduct.txt","r");
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuyproduct.txt","r");
	}
	else if(n==3)
	{
		fp1=fopen("b2cofflineproduct.txt","r");
	}
	while(fread(&pr,sizeof(pr),1,fp1))
	{
		if(pr.billnumber!=i)
		{
				fwrite(&pr,sizeof(pr),1,fp2);
		}
	
	}
	fclose(fp1);
	fclose(fp2);
	fp2=fopen("tempproduct.txt","r");
	if(n==1)
	{
		fp1=fopen("b2bsellproduct.txt","w");
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuyproduct.txt","w");
	}
	else if(n==3)
	{
		fp1=fopen("b2cofflineproduct.txt","w");
	}
	while(fread(&pr,sizeof(pr),1,fp2))
	{
		fwrite(&pr,sizeof(pr),1,fp1);
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n Product Deleted Succcessfully...");
}

void deletebill(int n)
{
	FILE *fp1,*fp2;
	int i;
	printf("\n Enter A bill number");
	scanf("%d",&i);
	fp2=fopen("temp.txt","w");
	if(n==1)
	{
		fp1=fopen("b2bsell.txt","r");
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","r");
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","r");
	}
	while(fread(&b,sizeof(b),1,fp1))
	{
		if(b.billnumber!=i)
		{
			fwrite(&b,sizeof(b),1,fp2);
		}	
	}
	fclose(fp1);
	fclose(fp2);
	fp2=fopen("temp.txt","r");
		if(n==1)
	{
		fp1=fopen("b2bsell.txt","w");
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","w");
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","w");
	}
	while(fread(&b,sizeof(b),1,fp2))
	{
		fwrite(&b,sizeof(b),1,fp1);
	}
	fclose(fp1);
	fclose(fp2);
	deleteproduct(n,i);
}

void billpayment(int n)
{
	struct amount a;
	FILE *fp1,*fp2,*fp3;
	float sum;
	int i;
	char g[16];
	if(n==1||n==2||n==3)
{
	fp2=fopen("temp.txt","w");
	if(n==1)
	{
		fp1=fopen("b2bsell.txt","r");
		printf("\n Enter A gst Number ,Which Payment You Got : ");
		scanf("%s",g);
		while(checkgst(g)==0)
		{	
			printf("\n Entered Right Gst Number :             ");
			fflush(stdin);
			gets(g);
		}
		
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","r");
		printf("\n Enter A Gst number, Which Payment You Paid :  ");
		scanf("%s",g);
			while(checkgst(g)==0)
		{	
			printf("\n Entered Right Gst Number : ");
			gets(g);
		}
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","r");
		printf("\n Enter A Bill Number, Which payment You Got :  ");
		scanf("%d",&i);
	}
	
	fp3=fopen("tempamount.txt","a");
	
	printf("\n Provide Amount = ");
	scanf("%f",&sum);
	while(fread(&b,sizeof(b),1,fp1))
	{ 
		if((strcmp(b.partygstno,g)==0)&&(sum>=0))
		{
		    if(b.tempamount>sum)
			{
				a.d=gdate();
				a.billnumber=b.billnumber;
				a.tempamont=sum;
				strcpy(a.gstno,b.partygstno);
				b.tempamount=b.tempamount-sum;
				sum=0;
				fwrite(&b,sizeof(b),1,fp2);
				fwrite(&a,sizeof(a),1,fp3);
			}
			else if(b.tempamount<=sum)
			{
				sum=sum-b.tempamount;
				a.d=gdate();
				a.billnumber=b.billnumber;
				a.tempamont=b.tempamount;
				strcpy(a.gstno,b.partygstno);
				b.tempamount=0;
				fwrite(&b,sizeof(b),1,fp2);
				fwrite(&a,sizeof(a),1,fp3);
			}
		}
		else
		{
			fwrite(&b,sizeof(b),1,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fp2=fopen("temp.txt","r");
	if(n==1)
	{
		fp1=fopen("b2bsell.txt","w");
	}
	else if(n==2)
	{
		fp1=fopen("b2bbuy.txt","w");
	}
	else if(n==3)
	{
		fp1=fopen("b2coffline.txt","w");
	}
	
	while(fread(&b,sizeof(b),1,fp2))
	{
		fwrite(&b,sizeof(b),1,fp1);
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n Bill Updated SuccessFull...");
	printf("\t Enter Any Key For Continuee...");
	getch();
}
if(n==4||n==5)
	partydetails(n);
}

void partydetails(int n)
{
	int c=0;
	struct amount a;
	FILE *fp1,*fp2;
	char gst[16];
	printf("\n Enter a party's Gst number :  ");
	scanf("%s",gst);
		while(checkgst(gst)==0)
		{	
		    fflush(stdin);
			printf("\n Entered Right Gst Number :  ");
			gets(gst);
		}
	if(n==4)
	{
		fp1=fopen("b2bsell.txt","r");
	}
	else if(n==5)
	{
		fp1=fopen("b2bbuy.txt","r");
	}
	fp2=fopen("tempamount.txt","r");
	
	while(fread(&b,sizeof(b),1,fp1))
	{
		if(strcmp(b.partygstno,gst)==0)
		{
			if(c==0)
			{
				printf("\n_______________________________________________________________________________");
	printf("\n\n *********Party's Details**********");
	printf("\n_______________________________________________________________________________\n");
	puts(b.partyname);
	puts(b.partyaddress);
	puts(b.partygstno);
	puts(b.partymono);
	puts(b.partymailid);
		printf("\n_______________________________________________________________________________");
		break;
			}
		
		}
	
	}
	printf("\n\n");
	printf("\n_______________________________________________________________________________");
	printf("\nDate");printf("\t\tBill No");printf("\tPaid Amount");
	printf("\n_______________________________________________________________________________");
	while(fread(&a,sizeof(a),1,fp2))
	{
		if((strcmp(a.gstno,gst)==0)&&(a.tempamont!=0))
		{
			
			printf("\n%d/%d/%d",a.d.dd,a.d.mm,a.d.yy);printf("\t");
			printf("%d",a.billnumber);printf("\t");
			printf("%f",a.tempamont);
		}
	}
	printf("\n_______________________________________________________________________________");
	printf("\n_______________________________________________________________________________");
	fclose(fp1);
	fclose(fp2);
	getch();
}

int checkgst(char *g)
{
	
	int i,d=0,j=0;
	for(i=0;*(g+i)!='\0';i++)
	{
		if((*(g+i)>=48&&*(g+i)<=57)||(*(g+i)>=65&&*(g+i)<=91))
		{
			d++;
		}
	}

	j=strlen(g);
	
	if((d==j)&&(j==15))
	return 1;
	else 
	return 0;
}
struct date gdate()
{
    struct date tempdate;
    time_t t=time(NULL);
    struct tm *local=localtime(&t);
    tempdate.dd=local->tm_mday;
    tempdate.mm=local->tm_mon+1;
    tempdate.yy=local->tm_year+1900;
    return tempdate;
}
int checkmono(char *m)
{
	int i,d=0,j=0;
	for(i=0;*(m+i)!='\0';i++)
	{
		if(*(m+i)>=48&&*(m+i)<=57)
		{
			d++;
		}
	}
	j=strlen(m);
	if((d==j)&&(j==10))
	return 1;
	else 
	return 0;
}

void sleep(int n)
{
     int j;     double z;
	for(j=0;j<=n;j++)
	{
	    for(z=0;z<99999.99;z++)
	    {
    	    z++;
       	 z--;
    	}
	}
}

void runbill()
{
	FILE *fp;
	int j;
	char d[30];
			printf("\n_______________________________________________________________________________");
		printf("\n_______________________________________________________________________________");
	printf("\n NOTE  :   ");
			printf("\n_______________________________________________________________________________");

printf("\n Before Running the billnumber function i want to give some instruction, Following that :\n");
printf("\n 1.If your program is running for the first time then don't worry, You are okay, You must be riding billnumber function");
			printf("\n_______________________________________________________________________________");
printf("\n 2.If you had already made some bill ya whatever process, then be carefull that, After running your billnumber function your whole data will be eraced & bill will be started from begining");
			printf("\n_______________________________________________________________________________");

printf("\n\n If You want to run billnumber function, enter your name otherwise close the program\n\nEnter Name :");
fflush(stdin);
getch();


printf("\n\n 1. Again think, Really You Want To Run Billnumber Function(instruction is upon)");
printf("\n 2. exit the program without running billnumber function\n\n");
printf("\n Your Choosen Option = ");scanf("%d",&j);
switch(j)
{
	case 1:
		{
			billnumber();
			fp=fopen("b2bsell.txt","w");
			fclose(fp);
			fp=fopen("b2bbuy.txt","w");
			fclose(fp);
			fp=fopen("b2coffline.txt","w");
			fclose(fp);
			fp=fopen("b2bsellproduct.txt","w");
			fclose(fp);
			fp=fopen("b2bbuyproduct.txt","w");
			fclose(fp);
			fp=fopen("b2cofflineproduct.txt","w");
			fclose(fp);
			fp=fopen("temp.txt","w");
			fclose(fp);
			fp=fopen("tempamount.txt","w");
			fclose(fp);
			fp=fopen("tempproduct.txt","w");
			fclose(fp);
			
			
			break;
		}
	case 2:
		{
			exit(0);
			break;
		}	
		default:
		{
			exit(0);
			break;
		}	
}

	
}




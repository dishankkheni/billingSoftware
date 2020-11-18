 #include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<time.h>
#include<iomanip>

#define systemc system("cls");

using namespace std;

class bill;
class bill *first=NULL,*last=NULL,*nn=NULL;


int infix =0;
int infix1=0;
int infix2=0;


int checkgst(char*);
int checkmono(char*);
void putsf(char*);
struct date
{
	int dd,mm,yy;
};


class sequrity
{
	private:
		char mono[12];
		char password[12];
		int flag;
	public:
		void add_sequritydata()
		{
			cout<<"\n Enter A Mobile No :                      +91";fflush(stdin);
			cin.getline(mono,11);
			cout<<endl<<"\n Make  A Password :                           ";fflush(stdin);
			cin.getline(password,11);
			flag=1;
		}
		void show_sequrity()
		{
			cout<<endl<<" Mobile No : "<<mono;
			cout<<endl<<" Password : "<<password;
		}
	void store_seqdata();	
	int read_seqdata();
	int compare_mono(char*);
	int compare_password(char*);
};

	

class billnumber
{
	private:
		int billno;
		int b2bgstno;
		int b2cgstno;
	public:
		billnumber()
		{
			billno=0;
			b2bgstno=0;
			b2cgstno=0;
		}
		void add_data()
		{
			fstream fout;
			fout.open("billnumber.txt",ios::out);
			billno=1;
			b2bgstno=10000;
			b2cgstno=50000;
			fout.write((char*)this,sizeof(*this));
			fout.close();
		}	
		int return_billnumber(int mode)
		{
			ifstream fin;
			fin.open("billnumber.txt",ios::in);
			fin.read((char*)this,sizeof(*this));
			if(mode==1)
			return this->billno;
			else if(mode==2)
			return this->b2bgstno;
			else if(mode==3)
			return this->b2cgstno;
		}
		void increment_billnumber(int mode)
		{
			fstream fio;
			fio.open("billnumber.txt",ios::in|ios::out);
			fio.read((char*)this,sizeof(*this));
			if(mode==1)
			this->billno=this->billno+1;
			else if(mode==2)
			this->b2bgstno=this->b2bgstno+1;
			else if(mode==3)
			this->b2cgstno=this->b2cgstno+1;
			fio.seekg(0);
			fio.write((char*)this,sizeof(*this));
			fio.close();
		}
};


class product
{
	private:
		int billnumber;
		char productname[25];
		float price;
		int qty;
		float gstrate;
	public:
		void add_productdata(int bn)
			{
				billnumber=bn;
				fflush(stdin);
				cout<<endl<<" Enter a product name :       ";
				fflush(stdin);
				cin.getline(productname,24);
				cout<<endl<<" Enter a product price :      ";
				fflush(stdin);
				cin>>price;
				cout<<endl<<" Enter QTY. :                 ";
				fflush(stdin);
				cin>>qty;
			}	
			void add_gstproductdata()
			{
				cout<<endl<<" Entere  GST Rate :           ";fflush(stdin);
				cin>>gstrate;
			}	
			void d_productdata()
			{
			
				cout<<"\n\t "<<price<<"\t "<<qty<<"\t "<<price*qty<<"\t ";
				puts(productname);			
			}
			void d_gstproductdata()
			{
				float a;
				a=(price*qty)*(gstrate)/100;
			
				cout<<"\n\t "<<price<<"\t "<<qty<<"\t "<<gstrate<<"\t "<<a<<"\t   "<<price*qty<<"\t  ";
				puts(productname);
			}
			
			void structure_productdata()
			{
				printf("\n_______________________________________________________________________________");
				printf("\n             Product's Details           ");
				printf("\n_____________^^^^^^^^^ ^^^^^^^_________________________________________________\n");
				cout<<"\n\t PRICE \t Qty \tAMOUNT \t PRODUCT";
				cout<<"\n\t --------------------------------";
			}
			
			void structure_gstproductdata()
			{
				printf("\n_______________________________________________________________________________");
				printf("\n\n **********Product's Details********** ");
				printf("\n___________^^^^^^^^^ ^^^^^^^___________________________________________________\n");
				cout<<"\n\t PRICE \t Qty \tGSTRATE GSTAMOUNT AMOUNT  PRODUCTNAME";
				cout<<"\n\t ----------------------------------------------------";
			}
			
		void store_productdata(int);	
		void delete_productdata(int,int);
		void update_productdata(int,int);
		float read_productdata(int,int,int);

};

struct date gdate(void);

class payment
{
	private:
		int billnumber;
		char paymentmethod[15];
		float amount;
		struct date d;
		char mono[12];
	protected:

	public:
		void add_paymentsetdata(char *m)	
		{
			int k;
			d=gdate();
			strcpy(mono,m);
			cout<<"\n Payment Method :";
			cout<<"\n 1. Cash";
			cout<<"\n 2. Bank Transfer(UPI,Check,NEFT,RTGS,Net Banking)";
			cout<<"\n Select Option : ";cin>>k;
			if(k==1)
			strcpy(paymentmethod,"Cash");
			else if(k==2)
			strcpy(paymentmethod,"Bank Transfer");
		}
		void add_paymentdata(int bn,float tamount)
		{
			billnumber=bn;
			amount=tamount;
		}
		void display_paymentdata()
		{
			cout<<endl<<d.dd<<"/"<<d.mm<<"/"<<d.yy<<"  "<<billnumber<<setw(9)<<"  "<<amount<<"\t"<<paymentmethod;
		}
		void structure_paymentdata()
		{
			cout<<"\n______________''Payment Detail''________________________________________________";
			cout<<"\nDate\t  BillNo     Amount\tPayment Method";
		}
		
//		void push()
//		{
//			pnn=(class payment *) new payment;
//			if(pfirst==NULL)
//			{
//				pfirst=plast=pnn;
//			}
//			else
//			{
//				plast->right=pnn;
//				pnn->left=plast;
//				plast=pnn;
//			}
//		}
		void store_paymentdata(int);
		float read_paymentdata(int,char *);
		void delete_payment(int,char *,struct date,int);
};

class gstbill;

class bill
{
	protected:
		char companyname[32];
		char companyaddress[50];
		char companymono[12];
		char companymailid[30];		
		char partyname[32];
		char partyaddress[50];
		char partymailid[30];
		struct date d;
	
		float amount;
		float tempamount;
		int billnumber;
		char partymono[12];
		class bill *left=NULL,*right=NULL;
	public:
		void add_companybilldata(int bn)
		{
				billnumber=bn;
				fflush(stdin);
				cout<<endl<<" Enter Your Company's Name :                 ";fflush(stdin);
				cin.getline(companyname,31);
				cout<<endl<<" Enter Your Company's Address :              ";
				fflush(stdin);
				cin.getline(companyaddress,49);
				cout<<endl<<" Enter Your company's Mobile Number :     +91";
				fflush(stdin);
				cin.getline(companymono,11);
				while(checkmono(companymono)==0)
				{
					cout<<"\n Entere Valid Mobile Number :             +91";
					fflush(stdin);
					cin.getline(companymono,11);
				}
				cout<<endl<<" Enter Your Company's Mail Id :              ";
				fflush(stdin);
				cin.getline(companymailid,29);
				
		}
		void add_partybilldata()
		{
	
				cout<<endl<<" Enter Your party's Mobile Number :       +91";
				fflush(stdin);	
				cin.getline(partymono,11);
				while(checkmono(partymono)==0)
				{
					printf("\n Entere  Valid Mobile Number :            +91");
					fflush(stdin);
					cin.getline(partymono,11);
				}
				add_prepartydata(partymono);
		}
		void add_prepartydata(char *m)
		{
				cout<<endl<<" Enter Your party's Company Name :           ";
				fflush(stdin);
				cin.getline(partyname,31);
				cout<<endl<<" Enter Your Party's Company Address :        ";
				fflush(stdin);
				cin.getline(partyaddress,49);
				strcpy(this->partymono,m);
				cout<<endl<<" Enter Your Party's Comapny Mail Id :        ";
				fflush(stdin);
				cin.getline(partymailid,29);
		}
		void display_basicbilldata()
		{
			printf("\n_______________________________________________________________________________");
			printf("\n_________________________Bill Details__________________________________________");
			printf("\n Date : %d/%d/%d",d.dd,d.mm,d.yy);
			printf("\t\t\t Bill number : %d",billnumber);
		//	printf("\n_______________________________________________________________________________\n");
		}
		void display_companydata()
		{
			printf("\n_______________________________________________________________________________");
			printf("\n\n **********Company's Details********** ");
			printf("\n___________--------- -------_________________________________________________\n");
			puts(companyname);
			puts(companyaddress);
			puts(companymono);
			puts(companymailid);
		}
		void display_partydata()
		{
			printf("\n_______________________________________________________________________________");
			printf("\n\n *********Party's Details**********");
			printf("\n__________---------------____________________________________________________\n");
			puts(partyname);
			puts(partyaddress);
			puts(partymono);
			puts(partymailid);
		}
	
		void display_billhistory()
		{
			int i=8,j;
		//	(billnumber<9)?i=12:i=11;
			(d.dd>9)?j=4:j=5;
		//	cout.precision(1);
			cout.width(6);cout<<"\n "<<d.dd<<"/"<<d.mm<<"/"<<d.yy;cout.width(j);cout<<billnumber;cout.width(i);	 cout<<tempamount;cout.width(12);cout<<amount<<"\t    "<<partyname<<"\t ";
		}
		
		void display_gstbill()
		{
			cout<<"\n"<<d.dd<<"/"<<d.mm<<"/"<<d.yy<<"  "<<billnumber;
		}
		void display_partyname()
		{
			cout<<partyname;
		}
		void gdate()
		{
			struct date tempdate;
   			time_t t=time(NULL);
    		struct tm *local=localtime(&t);
    		tempdate.dd=local->tm_mday;
    		tempdate.mm=local->tm_mon+1;
   			tempdate.yy=local->tm_year+1900;
    		d.dd=tempdate.dd;
    		d.mm=tempdate.mm;
    		d.yy=tempdate.yy;
		}
		
		
		
		
//		void copyb2bData(int bNo,char cName[32],cha
//r cAddress[50],char cMailId[30],char cMoNo[12],char pName[32],char pAddress[50],char pMailId[30],char pMoNo[12],double Amount,double TempAmount)
//		
//		{
//			billnumber=bNo;
//			strcpy(companyname,cName);
//			strcpy(companyaddress,cAddress);
//			strcpy(companymailid,cMailId);
//			strcpy(companymono,cMoNo);
//			strcpy(partyaddress,pAddress);
//			strcpy(partymailid,pMailId);
//			strcpy(partymono,pMoNo);
//			strcpy(partyname,pName);
//			amount=Amount;
//			tempamount=TempAmount;
//			display_companydata();
//			
//		}
		
		void push()
		{
			nn=(class bill*) new bill;
			nn->billnumber=billnumber;
			strcpy(nn->companyname,companyname);
			strcpy(nn->companyaddress,companyaddress);
			strcpy(nn->companymailid,companymailid);
			strcpy(nn->companymono,companymono);
			strcpy(nn->partyaddress,partyaddress);
			strcpy(nn->partymailid,partymailid);
			strcpy(nn->partymono,partymono);
			strcpy(nn->partyname,partyname);
			nn->amount=amount;
			nn->tempamount=tempamount;
			nn->d=d;
			nn->left=NULL;
			nn->right=NULL;
			
			if(first==NULL)
			{
				first=last=nn;
			}
			else
			{
				last->right=nn;
				nn->left=last;
				last=nn;
			}
			infix++;
		}
		int pop()
		{
			int bn;
			if(infix==0)
			{
				cout<<"\n Stack overflow ";
				return 0;
			}
			else
			{
				bn=last->billnumber;
				last=last->left;
				delete (last->right);
				last->right=NULL;
				infix--;
				cout<<"\n Bill Deleted SuccessFully...";
				return bn;
			}
		}
//		void dsDisplay()
//		{
//		class bill *temp;
//		temp=first;
//		cout<<"\n DS Date : ";	
//		
//		
//		while(temp!=NULL)
//		{
//			cout<<"\n billnumber : \n"<<temp->billnumber;
//			cout<<"\n amount : \n"<<temp->amount;
//			temp=temp->right;
//		}
//		}
		void store_billdata(int);
		void delete_billdata(int);
		int search_bill(int,int,char*);
		void update_billdata(int,float,float);
		void add_maindata(int,float);
		float read_billdata(int,char*);
		void bill_paymentdata();
	//	void assignValue();
};
class gstbill *b1first=NULL,*b1last=NULL,*b1nn=NULL,*b2first=NULL,*b2last=NULL,*b2nn=NULL;

//void bill::assignValue()
//{
//	display_companydata();
//	b1nn->copyb2bData(billnumber,companyname,companyaddress,companymailid,companymono,partyname,partyaddress,partymailid,partymono,amount,tempamount);	
//}

class gstbill:public bill
{
	private:
		char companygstno[17];
		char partygstno[17];
		char billfrom[15];
		char billto[15];
		float gstamount;
	class gstbill *right=NULL,*left=NULL;	
	public:
	 void add_b2bgstbilldata()
	 {
	 	cout<<endl<<" Enter Your Company's GST NO :        ";fflush(stdin);
		cin.getline(companygstno,16);
			while(checkgst(companygstno)==0)
			{
				printf("\n Entered Valid Gst Number :           ");
				gets(companygstno);
			}
		cout<<endl<<" Enter Your Party's GST NO :                 ";fflush(stdin);
		cin.getline(partygstno,16);
			while(checkgst(partygstno)==0)
			{
				printf("\n Entered Valid Gst Number :           ");
				gets(partygstno);
			}
		cout<<endl<<" Enter Your state :                          ";fflush(stdin);
		cin.getline(billfrom,14);
		cout<<endl<<" Enter Party's state :                       ";fflush(stdin); 
		cin.getline(billto,14);	
	 }	
	 
	  void add_b2cgstbilldata()
	 {
	 	cout<<endl<<" Enter Your Company's GST NO :        ";fflush(stdin);
		cin>>companygstno;
			while(checkgst(companygstno)==0)
			{
				printf("\n Entered Valid Gst Number :           ");
				gets(companygstno);
			}
	 }
	 
	 void add_gstno()
	 {
	 		cout<<endl<<" Enter Your Party's GST NO :                 ";fflush(stdin);
			cin.getline(partygstno,16);
			while(checkgst(partygstno)==0)
			{
				printf("\n Entered Valid Gst Number :           ");
				gets(partygstno);
			}
	 }
	 void add_destination()
	 {
	 	cout<<endl<<" Enter Your state :                          ";fflush(stdin);
		cin.getline(billfrom,14);
		cout<<endl<<" Enter Party's state :                       ";fflush(stdin); 
		cin.getline(billto,14);	
	 }
	 
	 void display_b2bdata()
	 {
			display_b2cdata();
	 		cout<<endl<<"	Party Gst No   : "<<partygstno;
	 }
	 	 void display_b2cdata()
	 {
	 		printf("\n------------------------------------------------------------------------------");
	 		cout<<endl<<"	Company Gst No : "<<companygstno;
			cout<<endl<<"	Bill From      : "<<billfrom;
			cout<<endl<<"	Bill To        : "<<billto;
			printf("\n------------------------------------------------------------------------------");
	 }
	void display_b2bgstbilldata()
	{
		cout<<" "<<partygstno<<" "<<showpoint<<gstamount<<" "<<billfrom<<"-"<<billto<<"\t";
		this->display_partyname();
	/*fflush(stdin);	cout<<endl<<"Company Gst No :"<<companygstno;
	fflush(stdin);	cout<<endl<<"Party Gst NO :"<<partygstno;
	fflush(stdin);	cout<<endl<<"Bill From :"<<billfrom;
	fflush(stdin);	cout<<endl<<"Bill To :"<<billto;*/
	}
	void display_b2cgstbilldata()
	{
		cout<<" "<<companygstno<<" "<<showpoint<<gstamount<<" "<<billfrom<<"-"<<billto<<"\t";
		this->display_partyname();
	}
	void display_gstbillhistory()
	{
			cout<<gstamount;
	}
	void add_gstmaindata(float amount)
	{
		gstamount=amount;
	}
	
		void push()
		{
			b1nn=(class gstbill*) new gstbill;
			b1nn->billnumber=billnumber;
			strcpy(b1nn->companyname,companyname);
			strcpy(b1nn->companyaddress,companyaddress);
			strcpy(b1nn->companymailid,companymailid);
			strcpy(b1nn->companymono,companymono);
			strcpy(b1nn->partyaddress,partyaddress);
			strcpy(b1nn->partymailid,partymailid);
			strcpy(b1nn->partymono,partymono);
			strcpy(b1nn->partyname,partyname);
			b1nn->amount=amount;
			b1nn->tempamount=tempamount;
			b1nn->d=d;
			b1nn->left=NULL;
			b1nn->right=NULL;
			
			if(b1first==NULL)
			{
				b1first=b1last=b1nn;
			}
			else
			{
				b1last->right=b1nn;
				b1nn->left=b1last;
				b1last=b1nn;
			}
			infix1++;
		}
	
		int pop()
		{
			int bn;
			if(infix1==0)
			{
				cout<<"\n Stack Underflow ";
				return 0;
			}
			else
			{
				bn=b1last->billnumber;
				b1last=b1last->left;
				delete (b1last->right);
				b1last->right=NULL;
				infix1--;
				cout<<"\n Bill Deleted SuccessFully...";
				return bn;
			}
		}
		void update_gstbilldata(int,int,float,float);
		float read_gstbilldata(int,int,char*);
		void store_billdata(int);
		int search_bill(int,int,char*);
		void delete_billdata(int,int);
		void bill_paymentdata(int);
};

void bill::store_billdata(int mode)
{
	ofstream fout;
	if(mode==1)
	fout.open("bill.txt",ios::app);
	else if(mode==4)
	fout.open("billdefaultdata.txt",ios::out);
	
	fout.write((char*)this,sizeof(*this));
	fout.close();
}

int bill::search_bill(int mode,int bn,char *mono)
{
	int c=0;
	ifstream fin;
	if(mode==1)
	fin.open("bill.txt",ios::in);
	else if(mode==4)
	fin.open("billdefaultdata.txt",ios::in);
	if(mode==4)
	{
		fin.read((char*)this,sizeof(*this));
		fin.close();
		return billnumber;
	}
	while(fin.read((char*)this,sizeof(*this)))
	{
		if((this->billnumber==bn)||(strcmp(this->partymono,mono)==0))
		{
			c++;
			break;
		}
	}
	fin.close();
	return c; 
}

void bill::add_maindata(int bn,float tamount)
{
	this->billnumber=bn;
	this->amount=tamount;
	this->tempamount=tamount;
	this->gdate();
}

float bill::read_billdata(int n,char *m)
{	
	if(n==1)
	{
		cout<<"\nDoubly-Link List Data :- \n";
		
		class bill *temp;
		temp=first;
		while(temp!=NULL)
		{
			temp->display_billhistory();
			temp=temp->right;
		}
		cout<<"\n\nFile Data :- \n\n";
	}
	product p;
	float sum=0;
	ifstream fin;
	fin.open("bill.txt",ios::in);
	while(fin.read((char*)this,sizeof(*this)))
	{
		if(n==1)
		{
			this->display_billhistory();
		}
		else if(n==2)
		{
			if(strcmp(m,this->partymono)==0)
			{
				this->display_gstbill();
				cout<<" \t  "<<this->amount;
				sum=sum+amount;
			}
		}
		else if(n==3)
		{
			
			if(strcmp(m,this->partymono)==0)
			{
				cout<<endl<<endl;
				display_basicbilldata();
				display_companydata();
				display_partydata();
				p.structure_productdata();
				p.read_productdata(1,this->billnumber,1);
			}
		}
	}
	fin.close();
	return sum;
}

void gstbill::store_billdata(int mode)
{
	ofstream fout;
	if(mode==2)
	fout.open("b2bgstbill.txt",ios::app);
	else if(mode==3)
	fout.open("b2cgstbill.txt",ios::app);
	else if(mode==5)
	fout.open("gstdefaultbill.txt",ios::out);
	
	fout.write((char*)this,sizeof(*this));
	fout.close();
}

int gstbill::search_bill(int mode,int bn,char *mono)
{
	int c=0;
	ifstream fin;

	if(mode==2)
	fin.open("b2bgstbill.txt",ios::in);
	else if(mode==3)
	fin.open("b2cgstbill.txt",ios::in);
	else if(mode==5)
	fin.open("gstdefaultbill.txt",ios::in);
	if(mode==5)
	{
		fin.read((char*)this,sizeof(*this));
		fin.close();
		return billnumber;
	}
	while(fin.read((char*)this,sizeof(*this)))
	{
		if((this->billnumber==bn)||(strcmp(this->partymono,mono)==0))
		{				
			c++;
			break;
		}
	}
	fin.close();
	return c; 
}

float gstbill::read_gstbilldata(int mode,int n,char *m)
{
	if(mode==2&&n==1)
	{
		cout<<"\nDoubly-Link List Data :- \n";
		
		class gstbill *temp;
		temp=b1first;
		while(temp!=NULL)
		{
			temp->display_billhistory();
			temp->display_gstbillhistory();
			temp=temp->right;
		}
		cout<<"\n\nFile Data :- \n\n";
	}
	product p;
	float sum=0;
	ifstream fin;
	if(mode==2)
	fin.open("b2bgstbill.txt",ios::in);
	else if(mode==3)
	fin.open("b2cgstbill.txt",ios::in);

	while(fin.read((char*)this,sizeof(*this)))
	{
		if(n==1)
		{
			this->display_billhistory();
			this->display_gstbillhistory();
		}
		else if(n==2)
		{
			if(strcmp(m,this->partymono)==0)
			{
				this->display_gstbill();
				cout<<"\t    "<<this->amount;
				sum=sum+amount;
			}
		}
		else if(n==3)
		{
			if(strcmp(m,this->partymono)==0)
			{
				this->display_basicbilldata();
				this->display_companydata();
				this->display_partydata();
				if(mode==2)
				this->display_b2bdata();
				else if(mode==3)
				this->display_b2cdata();
				p.structure_gstproductdata();
				p.read_productdata(mode,this->billnumber,1);
			}
		}
		else if(n==4)
		{
			this->display_gstbill();
			if(mode==2)
			this->display_b2bgstbilldata();
			else if(mode==3)
			this->display_b2cgstbilldata();
		}
	}
	
	fin.close();
	return sum;
}

void bill::delete_billdata(int bn)
{
	ifstream fin;
	ofstream fout;
	fin.open("bill.txt",ios::in);
	fout.open("temp.txt",ios::out);
	while(fin.read((char*)this,sizeof(*this)))
	{
		if(this->billnumber!=bn)
		fout.write((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
		remove("bill.txt");
		rename("temp.txt","bill.txt");	

}

void bill::update_billdata(int bn,float damount,float tamount)
{
	ifstream fin;
	ofstream fout;
	int k=0;
	fin.open("bill.txt",ios::in);
	fout.open("temp.txt",ios::out);
	while(fin.read((char*)this,sizeof(*this)))
	{
		if(this->billnumber==bn)
		{
			if(damount!=0)
			{
				this->amount=damount;
				this->tempamount=damount;
			}
			else if(tamount>0)
			{
				
				this->tempamount=tempamount+tamount;
				cout<<"\n Temp Amount ="<<tempamount;
			}
			else 
			{
				cout<<"\n Which Details You Want To modify";
				cout<<"\n1. Company Details";
				cout<<"\n2. Party Details";
				cout<<"\n3. Both";
				cin>>k;
				switch(k)
				{
					case 1:
						{
							this->add_companybilldata(bn);
							break;
						}
					case 2:
						{
							this->add_partybilldata();
							break;
						}	
					case 3:
						{
							this->add_companybilldata(bn);
							this->add_partybilldata();
							break;
						}	
				}
			}
			fout.write((char*)this,sizeof(*this));
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		}
	}
	fin.close();
	fout.close();

		remove("bill.txt");
		rename("temp.txt","bill.txt");	

}

void bill::bill_paymentdata()
{
	char mono[12];
	float sum=0;
	ifstream fin;
	ofstream fout;

		fin.open("bill.txt",ios::in);

	fout.open("temp.txt",ios::out);
	payment p;
	cout<<"\n Enter A mobile Number, Which Payment You Got : +91";
	fflush(stdin);
	cin>>mono;
		while(checkmono(mono)==0)
		{
			printf("\n Entered Valid Mobile Number :        +91");
			fflush(stdin);
			cin.getline(mono,11);
		}
	p.add_paymentsetdata(mono);
	cout<<"\n Enter An Amount :";
	cin>>sum;
	while(fin.read((char*)this,sizeof(*this)))
	{
		if((strcmp(this->partymono,mono)==0)&&(this->tempamount>0)&&(sum>0))
		{
			if(this->tempamount>sum)
			{
				cout<<"\n Temp Amount Is Greater";
				p.add_paymentdata(this->billnumber,sum);
				tempamount=tempamount-sum;
				sum=0;
				p.store_paymentdata(1);
				fout.write((char*)this,sizeof(*this));
			}
			else if(this->tempamount<=sum)
			{
				p.add_paymentdata(this->billnumber,this->tempamount);
				sum=sum-this->tempamount;
				p.store_paymentdata(1);
				tempamount=0;
				fout.write((char*)this,sizeof(*this));
			}
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		}
	}
	fin.close();
	fout.close();

		remove("bill.txt");
		rename("temp.txt","bill.txt");	

}

void gstbill::bill_paymentdata(int mode)
{
	char mono[12];
	float sum=0;
	ifstream fin;
	ofstream fout;
	if(mode==2)
	{
		fin.open("b2bgstbill.txt",ios::in);
	}
	else if(mode==3)
	{
		fin.open("b2cgstbill.txt",ios::in);
	}
	fout.open("temp.txt",ios::out);
	payment p;
	cout<<"\n Enter A mobile Number, Which Payment You Got : +91";
	fflush(stdin);
	cin>>mono;
		while(checkmono(mono)==0)
		{
			printf("\n Entered Valid Mobile Number :        +91");
			fflush(stdin);
			cin.getline(mono,11);
		}
	p.add_paymentsetdata(mono);
	cout<<"\n Enter An Amount :";
	cin>>sum;
	while(fin.read((char*)this,sizeof(*this)))
	{
		if((strcmp(this->partymono,mono)==0)&&(this->tempamount>0)&&(sum>0))
		{
			if(this->tempamount>sum)
			{
				p.add_paymentdata(this->billnumber,sum);
				tempamount=tempamount-sum;
				sum=0;
				p.store_paymentdata(mode);
				fout.write((char*)this,sizeof(*this));
			}
			else if(this->tempamount<=sum)
			{
				p.add_paymentdata(this->billnumber,this->tempamount);
				sum=sum-this->tempamount;
				p.store_paymentdata(mode);
				tempamount=0;
				fout.write((char*)this,sizeof(*this));
			}
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		}
	}
	fin.close();
	fout.close();
	 if(mode==2)
	{
		remove("b2bgstbill.txt");
		rename("temp.txt","b2bgstbill.txt");	
	}
	else if(mode==3)
	{
		remove("b2cgstbill.txt");
		rename("temp.txt","b2cgstbill.txt");	
	}
}

void gstbill::update_gstbilldata(int mode,int bn,float tamount,float gamount)
{
	int k;
	ifstream fin;
	ofstream fout;
	if(mode==2)
	fin.open("b2bgstbill.txt",ios::in);
	else if(mode==3)
	fin.open("b2cgstbill.txt",ios::in);
	
	fout.open("temp.txt",ios::out);
	while(fin.read((char*)this,sizeof(*this)))
	{
		
		if(this->billnumber==bn)
		{
			if(tamount>0)
			{
	
				this->tempamount=tempamount+tamount;
			}
			if(gamount>0)
			{
				gstamount=gamount;
			}
			else
			{
				cout<<"\n Which Details You Want To modify";
				cout<<"\n1. Company Details";
				cout<<"\n2. Party Details";
				cout<<"\n3. Both";
				cin>>k;
				switch(k)
				{
					case 1:
						{
							this->add_companybilldata(bn);
							break;
						}
					case 2:
						{
							this->add_partybilldata();
							break;
						}	
					case 3:
					{
						this->add_companybilldata(bn);
						this->add_partybilldata();
						break;
					}	
				}
				if(mode==2)
				this->add_b2bgstbilldata();
				else if(mode==3)
				this->add_b2cgstbilldata();
			}
			fout.write((char*)this,sizeof(*this));
		}
		else
		{
			fout.write((char*)this,sizeof(*this));
		}
	}
	fin.close();
	fout.close();
	 if(mode==2)
	{
		remove("b2bgstbill.txt");
		rename("temp.txt","b2bgstbill.txt");	
	}
	else if(mode==3)
	{
		remove("b2cgstbill.txt");
		rename("temp.txt","b2cgstbill.txt");	
	}
}

void gstbill::delete_billdata(int mode,int bn)
{
	ifstream fin;
	ofstream fout;
	if(mode==2)
	fin.open("b2bgstbill.txt",ios::in);
	else if(mode==3)
	fin.open("b2cgstbill.txt",ios::in);
	fout.open("temp.txt",ios::out);
	while(fin.read((char*)this,sizeof(*this)))
	{
		if(this->billnumber!=bn)
		fout.write((char*)this,sizeof(*this));
	}
	fin.close();
	fout.close();
	 if(mode==2)
	{
		remove("b2bgstbill.txt");
		rename("temp.txt","b2bgstbill.txt");	
	}
	else if(mode==3)
	{
		remove("b2cgstbill.txt");
		rename("temp.txt","b2cgstbill.txt");	
	}
}


void product::store_productdata(int mode)
{
	ofstream fout;
	if(mode==1)
	fout.open("product.txt",ios::app);
	else if(mode==2)
	fout.open("gstproduct.txt",ios::app);
	
	fout.write((char*)this,sizeof(*this));
	fout.close();
}

float product::read_productdata(int mode,int bn,int flag)
{
	ifstream fin;
	float sum=0;
	
	if(mode==1)
	fin.open("product.txt",ios::in);
	else if(mode==2)
	fin.open("gstproduct.txt",ios::in);
	while(fin.read((char*)this,sizeof(*this)))
	{
		if(this->billnumber==bn)
		{
			if(flag==1)
			{
					if(mode==1)
					this->d_productdata();
					else if(mode==2||mode==3)
					{
					//	this->d_productdata();
						this->d_gstproductdata();
					}	
			}
			else if(flag==2)
			{
				sum=sum+(price*qty);
			}
			else if(flag==3)
			{
				float a;
				a=price*qty;
				sum=sum+(a*gstrate/100);
			}
		}
	}
	fin.close();
	return sum;
}

void product::delete_productdata(int mode,int bn)
{
	ifstream fin;
	ofstream fout;
	
	if(mode==1)
	fin.open("product.txt",ios::in);
	else if(mode==2)
	fin.open("gstproduct.txt",ios::in);
	
	fout.open("temp.txt",ios::out);
	while(fin.read((char*)this,sizeof(*this)))
	{
		if(this->billnumber!=bn)
		{
			fout.write((char*)this,sizeof(*this));
		}
	}
	fin.close();
	fout.close();
	if(mode==1)
	{
		remove("product.txt");
		rename("temp.txt","product.txt");
	}
	else if(mode==2)
	{
		remove("gstproduct.txt");
		rename("temp.txt","gstproduct.txt");
	}
}

void product::update_productdata(int mode,int bn)
{
	int i,k=0;
	product *p;
	cout<<"\n How Many Product You Want To Add?";
	cin>>k;
	p=new product[k];
	for(i=0;i<k;i++)
	{
		if(mode==1)
		p[i].add_productdata(bn);
		else if(mode==2)
		{
			p[i].add_productdata(bn);
			p[i].add_gstproductdata();
		}
	}
	delete_productdata(mode,bn);
	for(i=0;i<k;i++)
	{
		p[i].store_productdata(mode);
	}	
}

void payment::store_paymentdata(int mode)
{
	ofstream fout;
	if(mode==1)
	fout.open("billpayment.txt",ios::app);
	else if(mode==2)
	fout.open("gstb2bbillpayment.txt",ios::app);
	else if(mode==3)
	fout.open("gstb2cbillpayment.txt",ios::app);
	fout.write((char*)this,sizeof(*this));
	fout.close();
}
float payment::read_paymentdata(int mode,char  *m)
{
	float sum;
	ifstream fin;
	if(mode==1)
	fin.open("billpayment.txt",ios::in);
	else if(mode==2)
	fin.open("gstb2bbillpayment.txt",ios::in);
	else if(mode==3)
	fin.open("gstb2cbillpayment.txt",ios::in);
	while(fin.read((char*)this,sizeof(*this)))
	{
		if(strcmp(m,this->mono)==0)
		{
			sum=sum+this->amount;
			this->display_paymentdata();
		}
	}
	fin.close();
	return sum;
}

	void sequrity::store_seqdata()
	{
		ofstream fout;
		fout.open("sequrity.txt",ios::out);
		fout.write((char*)this,sizeof(*this));
		fout.close();
	}
	
	int sequrity::read_seqdata()
	{
		ifstream fin;
		fin.open("sequrity.txt",ios::in);
		fin.read((char*)this,sizeof(*this));
		fin.close();
		return this->flag;
	}
	
	int sequrity::compare_mono(char *m)
	{
		int c=0;
		read_seqdata();
		if(strcmp(mono,m)==0)
		{
			c++;
		}
		return c;
	}
	
	int sequrity::compare_password(char *m)
	{
		int c=0;
		read_seqdata();
		if(strcmp(password,m)==0)
		{
			c++;
		}
		return c;
	}


int menu1(void);
int menu(void);
void makebill(int);
void updatebill(int);
void deletebill(int);
void billhistory(int);
void billpayment(int);
void gstfile(int);
void billsequrity(void);
void display_partydata(int);
void searchbill(int);
void checkbillnumber();
void resetbill();
void add_defaultdata(int);

bill b1;
gstbill b2;

void payment::delete_payment(int mode,char *m,struct date da,int bn)
{
	ifstream fin;
	ofstream fout;
	if(mode==1)
	fin.open("billpayment.txt",ios::in);
	else if(mode==2)
	fin.open("gstb2bbillpayment.txt",ios::in);
	else if(mode==3)
	fin.open("gstb2cbillpayment.txt",ios::in);
	
	fout.open("temppayment.txt",ios::out);
	
	while(fin.read((char*)this,sizeof(*this)))
	{
		if((strcmp(m,this->mono)==0)&&(da.dd==d.dd&&da.mm==d.mm&&da.yy==d.yy))
		{
			if(mode==1)
			{
			//	bill b1;
				b1.update_billdata(this->billnumber,0,this->amount);
			}
			else if(mode==2||mode==3)
			{
				gstbill b2;
				b2.update_gstbilldata(mode,this->billnumber,this->amount,0);
			}

		}
		else if(this->billnumber==bn)
		{
			if(mode==1)
			{
			//	bill b1;
				b1.update_billdata(this->billnumber,0,this->amount);
			}
			else if(mode==2||mode==3)
			{
				gstbill b2;
				b2.update_gstbilldata(mode,this->billnumber,this->amount,0);
			}
		}
		else
		{
			fout.write((char*)this,sizeof(*this));	
		}
	}
	fin.close();
	fout.close();
	if(mode==1)
	{
		remove("billpayment.txt");
		rename("temppayment.txt","billpayment.txt");	
	}
	else if(mode==2)
	{
		remove("gstb2bbillpayment.txt");
		rename("temppayment.txt","gstb2bbillpayment.txt");	
	}
	else if(mode==3)
	{
		remove("gstb2cbillpayment.txt");
		rename("temppayment.txt","gstb2cbillpayment.txt");	
	}
									
}

int main()
{
//	billsequrity();
//	checkbillnumber();
	int k=0;
	
	while(1)
	{
		systemc;
		switch(menu())
		{
			case 1:
				{
					k=menu1();
					makebill(k);
					cout<<"\n Bill Has Been Added SuccessFully...";
					getch();
					break;
				}
			case 2:
				{
					int a;
					k=menu1();
					searchbill(k);
					getch();
					break;
				}	
			case 3:
				{
					k=menu1();
					updatebill(k);
					cout<<"\n Your Bill Has Been Modify Sucessfully...";
					getch();
					break;
				}	
			case 4:
				{
					k=menu1();
					deletebill(k);
					cout<<"\n Your Bill Has Been Deleted Successfully...";
					getch();
					break;
				}	
			case 5:
				{
					k=menu1();
					billhistory(k);
					getch();
					break;
				}	
			case 6:
				{
					k=menu1();
					display_partydata(k);
					getch();
					break;	
				}
			case 7:
				{
					int a=0;
					k=menu1();
					systemc;
					cout<<"\n 1. ADD Payment Data";
					cout<<"\n 2. Delete Payment";
					cout<<"\n 3. Show Payment Data";
					cout<<"\n\n Select Option = ";cin>>a;
					switch(a)
					{
						case 1:
							{
								billpayment(k);
								cout<<"\n Payment Has Been Added Successfully...";
								break;
							}
						case 2:
							{
								struct date d;
								char m[12];
								cout<<"\n Enter A Mobile No : ";cin>>m;
								cout<<"\n Enter A Date : ";cin>>d.dd>>d.mm>>d.yy;
								payment p;
								p.delete_payment(k,m,d,0);
								cout<<"\n Payment Has Been Deleted successfully...";
								break;
							}
						case 3:
							{
								payment p;
								char m[12];
								cout<<"\n Enter A Mobile No : ";cin>>m;
								cout<<"\nDate\t\tBillNo Amount\tPayment Method";
								p.read_paymentdata(k,m);
								break;
							}
							
						default:
							{
								cout<<"\n Plese Enter Valid Input : ";
								break;
							}	
					}
					getch();
					break;
				}	
			case 8:
				{
					systemc;
					cout<<"\n 1. B2B Gst Data";
					cout<<"\n 2. B2C Gst Data";
					cout<<"\n\n Select Option = ";cin>>k;
					gstfile(k);
					getch();
					break;
				}	
			case 9:
				{
					k=menu1();
					add_defaultdata(k);	
					cout<<"\n Default Data Has Been Seted ";		
					getch();
					break;
				}	
			case 10:
				{
					sequrity s;
					billsequrity();
					s.add_sequritydata();
					s.store_seqdata();
					cout<<"\n Your Updatiion Completely Succesfully...";
					getch();
					break;
				}	
			case 11:
				{
					resetbill();
					cout<<"\n All Bill Reset SuccessFully...";
					getch();
					break;
				}	
			case 12:
				{
					exit(0);
				}	
			default:
				{
					cout<<"\n Plese Enter Valid Input : ";
					getch();
					break;
				}	
		}
	}
	return 0;
}

int menu1()
{
	in:
	systemc;
	int a;
	cout<<"\n*****************INSIDE MENU******************************";
	cout<<"\n 1. Bill";
	cout<<"\n 2. B2B Gst Bill";
	cout<<"\n 3. B2c Gst Bill";
	
	cout<<"\n\n Select Option = ";cin>>a;
	if(a==1||a==2||a==3)
	{
			return a;
	}
	else
	{
		cout<<"\n Plese Enter Valid Input : ";
		goto in;
	}

}

int menu()
{
	struct date today;
	int a=0;
	cout<<"\n*****************MAIN MENU******************************";
	cout<<"\n 1. Make Bill";
	cout<<"\n 2. Search Bill";
	cout<<"\n 3. Modify Bill";
	cout<<"\n 4. Delete Bill";
	cout<<"\n 5. Bill History";
	cout<<"\n 6. Display Party's Whole Data";
	cout<<"\n 7. Payment";
	cout<<"\n 8. Display Gst Data";
	cout<<"\n 9. Set Default Data";
	cout<<"\n10. Lock Setting";
	cout<<"\n11. Reset Bill";
	cout<<"\n12. Exit";	
			printf("\n*********************************************************");
				today=gdate();
				printf("\n Date : %d/%d/%d",today.dd,today.mm,today.yy);
				printf("\n*********************************************************");
	cout<<"\n\n Select Option = ";cin>>a;
	return a;
}

void add_defaultdata(int mode)
{
	if(mode==1)
	{
		//	bill b1;
			b1.add_companybilldata(1);
			b1.store_billdata(4);
	}
	else if(mode==2|mode==3)
	{
	//	gstbill b1;
		b2.add_companybilldata(1);
		b2.add_b2cgstbilldata();
		b2.store_billdata(5);
	}
}

void checkbillnumber()
{
	int a;
	billnumber b;
//	b.increment_billnumber()
	a=b.return_billnumber(1);
	if(a>0)
	{
		
	}
	else
	{
		b.add_data();
	}
}

void resetbill()
{
/*	int a=3;
	char password[12];
		printf("\n_______________________________________________________________________________");
		printf("\n_______________________________________________________________________________");
		printf("\n NOTE  :   ");
		printf("\n_______________________________________________________________________________");

printf("\n Before Running the Reset function i want to give some instruction, Following that :\n");
//	printf("\n_______________________________________________________________________________");
printf("\n 1.If you had already made some bill ya whatever process, then be carefull that, After   running your Resetbill function your whole data will be Eraced From your Computer & bill will be started from begining");
	printf("\n_______________________________________________________________________________");

printf("\n\n After Upper Instruction, If You want to run resetbill function, Then enter your Password Of Application For Sequrity Purpose otherwise close the program\n\n");
p1:
cout<<"\n Enter A Password : ";
fflush(stdin);
cin>>password;
sequrity s;*/
//if(s.compare_password(password)==1)

	remove("billnumber.txt");
	remove("bill.txt");
	remove("b2bbill.txt");
	remove("b2cbill.txt");
	remove("billdefaultdata.txt");
	remove("gstbilldefaultdata.txt");
	remove("billpayment.txt");
	remove("gstb2bbillpayment.txt");
	remove("gstb2cbillpayment.txt");
	remove("product.txt");
	remove("gstproduct.txt");
	remove("sequrity.txt");

/*else
{
	cout<<"\n Plese Enter A Valid Password.";
	cout<<"\n Your Can Entered Wrong Password For "<<a<<" Times";
	a--;
	if(a==0)
	exit(0);
	goto p1;
}*/

}

void searchbill(int mode)
{

	product p;
		systemc;
		int a,k;
		char mono[12];	
		cout<<"\n 1.Search Bill Mobile Number Wise";
		cout<<"\n 2.Search Bill Bill Number Wise";
		cout<<"\n\n Select Option = ";
		cin>>a;
		if(mode==1)
		{
		//	bill b;
			if(a==1)
			{
				cout<<"\n Enter A Mobile Number :                  +91";
				cin>>mono;
				while(checkmono(mono)==0)
				{
					cout<<"\n Entere Valid Mobile Number :             +91";
					fflush(stdin);
					cin.getline(mono,11);
				}
				b1.read_billdata(3,mono);
			}
			else if(a==2)
			{
				cout<<"\n Enter A Bill Number : ";
				cin>>k;
				b1.search_bill(mode,k,mono);
				b1.display_basicbilldata();
				b1.display_companydata();
				b1.display_partydata();
				p.structure_productdata();
				p.read_productdata(mode,k,1);
			}
		}
		else if(mode==2||mode==3)
		{
		//	gstbill b1;
			if(a==1)
			{
				cout<<"\n Enter A Mobile Number :                  +91";
				cin>>mono;
				while(checkmono(mono)==0)
				{
					cout<<"\n Entere Valid Mobile Number :             +91";
					fflush(stdin);
					cin.getline(mono,11);
				}
				b2.read_gstbilldata(mode,3,mono);
			}
			else if(a==2)
			{
				cout<<"\n Enter A Bill Number : ";
				cin>>k;
				b2.search_bill(mode,k,0);
				b2.display_basicbilldata();
				b2.display_companydata();
				b2.display_partydata();
				if(mode==2)
				b2.display_b2bdata();
				else if(mode==3)
				b2.display_b2cdata();
				p.structure_gstproductdata();
				p.read_productdata(2,k,1);
			}
		}
}
	void billsequrity()
	{
		
		cout<<"\n\n\n\n";
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n                           Log In Page                                         ";
		cout<<"\n___________________________^^^ ^^ ^^^^_________________________________________";
		cout<<"\n_______________________________________________________________________________";


		sequrity s;
		char mono[12];
		char password[12];
		mono1:
		cout<<"\n Enter A Mobile No :                      ";
		cin>>mono;
		while(checkmono(mono)==0)
		{
			printf("\n Entered Valid Mobile Number :        +91");
			fflush(stdin);
			cin.getline(mono,11);
		}
		if(s.compare_mono(mono)==1)
		{
			password1:
			cout<<"\n Enter A Password :                           ";
			cin>>password;
			if(s.compare_password(password)==1)
			{
				cout<<"\n Login Successfully...";
			}
			else
			{
				cout<<"\n Plese Enter Valid password :                ";
				goto password1;
			}
		}
		else
		{
			if(s.read_seqdata()==1)
			{
				cout<<"\n Enterd registered Mobile Number :            ";
				goto mono1;
			}
			
			cout<<"\n Wel Come To our Billing Application, Hope that your mostly problems about billing has been resolved through using this application & also greeting to good experiences. ";
			s.add_sequritydata();
			s.store_seqdata();
			cout<<"\n Loging Successfully...";
		}
	}

void gstfile(int mode)
{
//	gstbill b1;
	if(mode==1)
	{
		cout<<"\n                           GST File                                            ";
		cout<<"\n---------------------------^^^ ^^^^--------------------------------------------";
		cout<<endl<<"Date\t  BillNo PartyGSTNO     Amount BillFrom-BillTO \tPartyname ";
		cout<<"\n----------------------------------------------------------------------";
		b2.read_gstbilldata(2,4,0);

	}
	else if(mode==2)
	{
		cout<<"\n                           GST File                                            ";
		cout<<"\n---------------------------^^^ ^^^^--------------------------------------------";
		cout<<endl<<"Data\t   BillNo CompanyGSTNO     Amount BillFrom-BillTO \tPartyname ";
		cout<<"\n------------------------------------------------------------------------";
		b2.read_gstbilldata(3,4,0);
	}
	
}
void billpayment(int mode)
{
	if(mode==1) 
	{
	//	bill b1;
		b1.bill_paymentdata();
	}
	else if(mode==2||mode==3)
	{
	//	gstbill b1;
		b2.bill_paymentdata(mode);
	}
}

void display_partydata(int mode)
{
	payment p;
	float a=0,b=0;
	char mono[12];
	cout<<"\n Enter A mobile Number , Which party details you want to show : +91";
	fflush(stdin);
	cin>>mono;
		while(checkmono(mono)==0)
		{
			printf("\n Entered Valid Mobile Number :        +91");
			fflush(stdin);
			cin.getline(mono,11);
		}
	if(mode==1)
	{
	//	bill b1;
		b1.search_bill(mode,0,mono);
		b1.display_partydata();
		cout<<"\n______________''Business Dill''_________________________________________________";
		cout<<"\n Date\t  BillNo  Amount ";
		a=b1.read_billdata(2,mono);
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n Total Amount = "<<a;
		cout<<"\n_______________________________________________________________________________";
		cout<<endl;
		p.structure_paymentdata();
		b=p.read_paymentdata(mode,mono);
		cout<<endl;
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n Remaining Amount = "<<a-b;
		cout<<"\n_______________________________________________________________________________";
	}
	else if(mode==2||mode==3)
	{
	//	gstbill b1;
		b2.search_bill(mode,0,mono);
		b2.display_partydata();
		if(mode==2)
		b2.display_b2bdata();
		else
		b2.display_b2cdata();
		
		cout<<"\n\n______________''Business Dill''_________________________________________________";
		cout<<"\n Date\t  BillNo   Amount ";
		a=b2.read_gstbilldata(mode,2,mono);
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n Total Amount = "<<a;
		cout<<"\n_______________________________________________________________________________";
		cout<<endl;
		p.structure_paymentdata();
		b=p.read_paymentdata(mode,mono);
		cout<<endl;
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n Remaining Amount = "<<a-b;
		cout<<"\n_______________________________________________________________________________";
	}
}

void deletebill(int mode)
{
	int choise;
	cout<<"\n 1. Delete By BillNumber ";
	cout<<"\n 2. POP Bill";
	cout<<"\n Selected Option = ";
	cin>>choise;
	
	switch(choise)
	{
		case 1:
		{
				int bn;
	cout<<"\n ENter a bill number ,Whch Bill you want to delete : ";cin>>bn;
	if(mode==1)
	{
	//	bill b;
		b1.delete_billdata(bn);
	}
	else if(mode==2)
	{
	//	gstbill b;
		b2.delete_billdata(mode,bn);
	}	
		}
		case 2:
		{
			if(mode==1)
			{
				int bn=b1.pop();
			if(bn==0)
			{
				cout<<"\n Process Finished";	
			}
			else
			{
				b1.delete_billdata(bn);
			}
			}
			else if(mode==2)
			{
				int bn = b2.pop();
				if(bn==0)
				{
					cout<<"\n Process Has been finished";
				}
				else
				{
					b2.delete_billdata(mode,bn);
				}
			}
		}	
	}
	

}
void updatebill(int mode)
{
	struct date d;
	int bn;
	cout<<"\n Enter a bill Number Which Bill, You want to modify : ";
	cin>>bn;
	product p;
	int k;
	float gstsum=0,sum=0;
	cout<<"\n Which Option You Want To Choose";
	cout<<"\n 1. Update Product Bill";
	cout<<"\n 2. Update Main Bill";
	cout<<"\n 3. Both";
	cin>>k;
	switch(k)
	{
		case 1:
			{
				again2:
				p.update_productdata(mode,bn);
				if(mode==1)
				{
					payment p1;
					sum=p.read_productdata(mode,bn,2);
					p1.delete_payment(mode,0,d,bn);
				//	bill b1;
					b1.update_billdata(bn,sum,0);
				}
				else if(mode==2||mode==3)
				{
					sum=0;
					sum=p.read_productdata(mode,bn,3);
					gstsum=p.read_productdata(mode,bn,2);
				//	gstbill b1;
					b2.update_gstbilldata(mode,bn,gstsum,sum);
				}
				break;	
			}
		case 2:
			{
				again3:
				if(mode==1)
				{
			//		bill b1;
					b1.update_billdata(bn,0,0);		
				}	
				else if(mode==2||mode==3)
				{
			//		gstbill b1;
					b2.update_gstbilldata(mode,bn,0,0);
				}
				break;
			}	
		case 3:
		{
			goto again2;
			goto again3;
			break;
		}	
	}	
}

void billhistory(int mode)
{
	if(mode==1)
	{
	
	//	bill b1;
		
	//	b1.dsDisplay();
		
		cout<<"\n--------------------Bill Histoty-----------------------------------------------";
		cout<<"\n_______________________________________________________________________________";
		cout<<"\n  Date     BillNo    Creadit   Amount    Party Name";
		cout<<"\n----------------------------------------------------";

		b1.read_billdata(1,0);
	}
	else if(mode==2||mode==3)
	{
		gstbill b2;
		cout<<"\n--------------------Bill Histoty-----------------------------------------------";
		cout<<"\n Date         BillNo  \t    Creadit    Amount    Party Name    \tGst Amount";
		cout<<"\n---------------------------------------------------------------------------";
		b2.read_gstbilldata(mode,1,0);
	}
}
void makebill(int mode)
{
	char mono[11];
	billnumber b;
	product p;
	

	int i,k;
//		bill b1;
	float sum=0,gstsum=0;
	cout<<"\n Enter Party's Mobil Number : +91";
	fflush(stdin);
	cin.getline(mono,11);
		while(checkmono(mono)==0)
		{
			printf("\n Entered Valid Mobile Number :        +91");
			fflush(stdin);
			cin.getline(mono,11);
		}
	if(mode==1)
	{
	
		if(b1.search_bill(mode,0,mono)==1)
		{
			again:
			printf("\n*********************************************************");
			cout<<"\nHow Many Product, You Want To Deal now ?";printf("\t %c  ",26);
			cin>>k;
			for(i=0;i<k;i++)
			{
				p.add_productdata(b.return_billnumber(mode));
				p.store_productdata(mode);
			}
			sum=p.read_productdata(mode,b.return_billnumber(mode),2);
			b1.add_maindata(b.return_billnumber(mode),sum);
			b1.store_billdata(mode);
			b1.push();
			b1.search_bill(mode,b.return_billnumber(mode),mono);
			b1.display_basicbilldata();
			b1.display_companydata();
			b1.display_partydata();
			p.structure_productdata();
			p.read_productdata(mode,b.return_billnumber(mode),1);		
			b.increment_billnumber(mode);
			
		}
		
		else if(b1.search_bill(4,0,mono)==1)
		{
			b1.add_prepartydata(mono);
			goto again;
		}
		else 
		{
			b1.add_companybilldata(b.return_billnumber(mode));
			b1.add_prepartydata(mono);
			goto again;
		}
	}
	else if(mode==2||mode==3)
	{
		sum=0;
		gstsum=0;
		k=0;
	//	gstbill b2;
		cout<<b2.search_bill(mode,0,mono);
		if(b2.search_bill(mode,0,mono)==1)
		{
			b2.add_destination();
			again1:
			printf("\n*********************************************************");
			cout<<"\nHow Many Product, You Want To Deal now ?";printf("\t %c  ",26);
			cin>>k;
			for(i=0;i<k;i++)
			{
				p.add_productdata(b.return_billnumber(mode));
				p.add_gstproductdata();
				p.store_productdata(mode);
			}
			sum=p.read_productdata(mode,b.return_billnumber(mode),2);
			gstsum=p.read_productdata(mode,b.return_billnumber(mode),3);
			b2.add_maindata(b.return_billnumber(mode),sum);
			b2.add_gstmaindata(gstsum);
			b2.store_billdata(mode);
			b2.push();
			b2.search_bill(mode,b.return_billnumber(mode),mono);
			b2.display_basicbilldata();
			b2.display_companydata();
			b2.display_partydata();
			p.structure_gstproductdata();
			p.read_productdata(mode,b.return_billnumber(mode),1);
			b.increment_billnumber(mode);
		}
		else if(b2.search_bill(5,0,mono)==1)
		{
			b2.add_prepartydata(mono);
			if(mode==2)
			{
				b2.add_gstno();
				b2.add_destination();
			}
			else if(mode==3)
			{
				b2.add_b2bgstbilldata();
			}
			goto again1;
		}
		else
		{
			b2.add_companybilldata(b.return_billnumber(mode));
			b2.add_prepartydata(mono);
			if(mode==2)
			b2.add_b2bgstbilldata();
			else if(mode==3)
			{
				b2.add_b2bgstbilldata();
			}
			goto again1;
		}
	
	}
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
void putsf(char *p)
{
	int i;
	for(i=0;*(p+i)!='\0';i++)
	{
		printf("%c",*(p+i));
	}
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

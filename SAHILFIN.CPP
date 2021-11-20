//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************


#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<time.h>


//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class account
{
	int acno;
	char name[20];
	int deposit;
	char type;
	char un[10];
	char pd[10];
	int no;
	char active;
	int day,month,year;
	char admin[10];
	int total;
	char transaction[10];
	int withdrawmoney;
	int depositmoney;

public:

	void activeon();         //function to turn on active flag
	char activecheck();	 //function to check active flag
	void adminpass();	 //function to create/change admin password
	void details();		 //function to get user details
	int create_account(int); //function to get data from user
	void show_account();	 //function to show data on screen
	int modify(); 		 //function to get new data from user
	void dep(int);		 //function to accept amount and add to balance amount
	void draw(int);		 //function to accept amount and subtract from balance amount
	void report();		 //function to show Account data in tabular format
	void detail();           //function to show login data in tabular format
	void passbook();         //function to show specific account data in tabular format
	char * apass();          //function to return user password
	char * acnum();	         //function to return user name
	char * password();	 //function to return password
	int retacno();		 //function to return account number
	int retdeposit();	 //function to return balance amount
	char rettype();		 //function to return type of account
	char * holdername();     //function to return account holder name
	void systemdate();	 //function to get current time
	void passbook(int,int,char,int);//function to put entry in passbook
};         //class ends here

void account::systemdate()
{
      struct date d;
      getdate(&d);
      day = d.da_day;
      month = d.da_mon;
      year = d.da_year;

}

void account::activeon()
{
	active='y';
	systemdate();
}

void account::adminpass()
{
	char c;
	int i=0	;

	cout<<"\n\t\t\t\t  New Admin password  "<<endl;
	cout<<"\t\t\t\t    ";
	while( (c=getch())!=13)
	{
		admin[i]=c;
		if(admin[i]==8)
		{
			admin[i]=NULL;
			i--;
			admin[i]=NULL;
		}
		else
		{
			printf("*");
			i++;
		}
	}
	admin[i]=0;
	activeon();
}

void account::details()
{
	account ac;
	int i=0;
	char c;
	cout<<"\t\t\t\tEnter The User Name  "<<endl;
	cout<<"\t\t\t\t    ";
	cin>>un;
	cout<<endl;
	cout<<endl<<"\t\t\t\tEnter Password  "<<endl;
	cout<<"\t\t\t\t    ";
	while( (c=getch())!=13)
	{
		pd[i] = c;
		if(pd[i]==8)
		{
			pd[i]=NULL;
			i--;
			pd[i]=NULL;
		}
		else
		{
		printf("*");
		i++;
		}
	}
	pd[i]=0;
	activeon();
}

int account::create_account(int accountnumber)
{
	int save=0,passbookflag =1;
	char answer;
	acno=accountnumber;
	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
	strupr(name);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	printf("\n\n\n");
	cout<<"Do You Want To SAVE Record(Y""/""N) : ";
	cin>>answer;
	answer=toupper(answer);
	switch(answer)
	{	case 'Y':	save=1;		break;		}
	if(save==1)
	{
	textcolor(RED);
	gotoxy(35,12);
	cprintf("Account Created..");
	gotoxy(30,24);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	activeon();
	passbook(passbookflag,acno,type,deposit);
	}
	return save;
}

void account::show_account()
{
	cout<<"\nAccount No.     :     "<<acno;
	cout<<"\nA\c Holder Name  :     ";
	cout<<name;
	cout<<"\nAccount Type    :     "<<type;
	cout<<"\nTotal Balance   :     "<<deposit;
	cout<<"\nOpening Date    :     "<<day<<'/'<<month<<'/'<<year;
	cout<<endl;
	printf("\n\n\n");

}

int account::modify()
{
	int save=0;
	char answer;
	cout<<"\nThe account No."<<acno;
	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
	strupr(name);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"Do You Want To SAVE Record(Y""/""N) : ";
	cin>>answer;
	answer=toupper(answer);
	switch(answer)
	{	case 'Y':	save=1;		break;		}
	return save;
}

char account::activecheck()
{
	return active;
}

char * account::apass()
{
	return admin;
}

char * account::acnum()
{
	return un;
}

char * account::password()
{
	return pd;
}

char * account::holdername()
{
	return name;
}

void account::dep(int x)
{
	deposit+=x;
}

void account::draw(int x)
{
	deposit-=x;
}

void account::report()
{
	cout<<acno<<" ";
	cout<<setprecision(10)<<setw(15)<<name<<" ";
	cout<<setprecision(10)<<setw(10)<<" ";
	cout<<setprecision(10)<<setw(10)<<type<<" ";
	cout<<setprecision(10)<<setw(10)<<deposit<<" ";
	cout<<setprecision(10)<<setw(10)<<day<<'/'<<month<<'/'<<year<<" ";
	cout<<endl;
}

void account::detail()
{
	cout<<un<<" "<<setprecision(10);
	cout<<setprecision(10)<<setw(15)<<pd<<" ";
	cout<<setprecision(10)<<setw(15)<<" ";
	cout<<setprecision(10)<<setw(15)<<active<<" ";
	cout<<setprecision(10)<<setw(0)<<day<<'/'<<month<<'/'<<year<<" ";
	cout<<endl;
}

void account::passbook()
{
	cout<<day<<'/'<<month<<'/'<<year<<" ";
	cout<<setprecision(10)<<setw(15)<<transaction<<" ";
	cout<<setprecision(10)<<setw(15)<<depositmoney<<" ";
	cout<<setprecision(10)<<setw(15)<<withdrawmoney<<" ";
	cout<<endl;
}
int account::retacno()
{
	return acno;
}

int account::retdeposit()
{
	return deposit;
}

char account::rettype()
{
	return type;
}

void account::passbook(int f,int acc,char t,int bal)
{
	account ac;
	ofstream outFile;
	outFile.open("passbook.dat",ios::binary|ios::app);
	if(f==1)
	{
		ac.acno=acc;
		strcpy(ac.transaction,"Initial");
		ac.depositmoney=bal;
		ac.withdrawmoney=NULL;
		ac.systemdate();
		outFile.write((char *)&ac, sizeof(account));
		outFile.close();
	}
	if(f==2 && t=='c')
	{
		ac.acno=acc;
		strcpy(ac.transaction,"Cash");
		ac.depositmoney=bal;
		ac.withdrawmoney=NULL;
		ac.systemdate();
		outFile.write((char *)&ac, sizeof(account));
		outFile.close();
	}
	if(f==2 && t=='q')
	{
		ac.acno=acc;
		strcpy(ac.transaction,"Cheque");
		ac.depositmoney=bal;
		ac.withdrawmoney=NULL;
		ac.systemdate();
		outFile.write((char *)&ac, sizeof(account));
		outFile.close();
	}
	if(f==3 && t=='c')
	{
		ac.acno=acc;
		strcpy(ac.transaction,"Cash");
		ac.withdrawmoney=bal;
		ac.depositmoney=NULL;
		ac.systemdate();
		outFile.write((char *)&ac, sizeof(account));
		outFile.close();
	}
	if(f==2 && t=='q')
	{
		ac.acno=acc;
		strcpy(ac.transaction,"Cheque");
		ac.withdrawmoney=bal;
		ac.depositmoney=NULL;
		ac.systemdate();
		outFile.write((char *)&ac, sizeof(account));
		outFile.close();
	}
}

//***************************************************************
//    	function declaration
//****************************************************************
void newadmin();		//make new admin password
void adminmenu();		//open admin menu
void adminpassword();  		//To make new/modify admin password
void login(int);		//function to log in
void reg();			//function to create new user
void write_account();		//function to write record in binary file
void display_sp(int);		//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void passbookdisplay(int);      //function to display Digital Passbook
void deposit_withdraw(int, int);// function to desposit/withdraw amount for given account
void intro();			//introductory screen function
void mainmenu();		//function to open main menu
void login_account();		//function to see all login accounts
void help();			//function to see help text
void loginhelp();		//function to see login screen help
int validation(char name[]);    //function to validate login
void deleteuser(int);		//function to delete user

//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************

int main()
{
	char ch;
	char no[10];
	fstream file;
	clrscr();
	intro();
	textattr(113);
	do
	{
		clrscr();
		cout<<"\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		textcolor(BLINK);
		cout<<"\t|";
		gotoxy(33,2);
		cprintf("LOGIN SCREEN");
		cout<<"\t\t\t    |\n";
		textattr(113);
		cout<<"\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		cout<<"\n\n\t01. Login";
		cout<<"\n\n\t02. New User";
		cout<<"\n\n\t03. Administrative option";
		cout<<"\n\n\t04. Help";
		cout<<"\n\n\t05. Quit\n";
		cout<<"\n\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		cout<<"\tEnter Your Choice[1-5] : ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
			case '1':
				cout<<"\t\t\t\t  User Name  "<<endl;
				cout<<"\t\t\t\t    ";
				cin>>no;
				int flag = validation(no);
				login(flag);
				break;
			case '2':
				reg();
				gotoxy(35,12);
				cout<<"Account Created";
				getch();
				break;
			case '3':
				newadmin();
				break;

			case '4':
				loginhelp();
				break;
			case '5':
				gotoxy(22,12);
				cout<<"Thanks for using bank managemnt system";
				gotoxy(30,24);
				cout<<"Created By SAHIL TRIVEDI";
				gotoxy(40,25);
				delay(2000);
				break;
			default :
				gotoxy(30,12);
				cout<<"Incorrect Selection";
				gotoxy(30,24);
				textcolor(BLINK);
				cprintf("Press Any Key To Continue...");
				textattr(113);
				getch();
				break;

		 }
    }while(ch!='5');
	return 0;
}

//***************************************************************
//    	function to open admin menu
//****************************************************************

void adminmenu()
{
	char ch;
	char user[10];
	account ac;
	clrscr();
	do
	{
		clrscr();
		cout<<"\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		textcolor(BLINK);
		cout<<"\t|";
		gotoxy(33,2);
		cprintf("ADMIN SCREEN");
		cout<<"\t\t\t    |\n";
		textattr(113);
		cout<<"\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		cout<<"\n\n\t01. See All User Accounts";
		cout<<"\n\n\t02. Delete User Account";
		cout<<"\n\n\t03. Change Admin Password";
		cout<<"\n\n\t04. Quit\n";
		cout<<"\n\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		cout<<"\tEnter Your Choice[1-4] : ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
			case '1':
				login_account();
				break;
			case '2':
				cout<<"\t\t\t  Enter User Name To DELETE  "<<endl;
				cout<<"\t\t\t\t    ";
				cout<<"";
				cin>>user;
				int flag = validation(user);
				deleteuser(flag);
				break;
			case '3':
				adminpassword();
				break;
			case '4':
				gotoxy(33,12);
				cout<<"Signing Out...";
				gotoxy(35,13);
				textcolor(BLINK);
				cprintf("Please Wait ");
				textattr(113);
				delay(2000);
				break;
			default :
				gotoxy(30,12);
				cout<<"Incorrect Selection";
				gotoxy(30,24);
				textcolor(BLINK);
				cprintf("Press Any Key To Continue...");
				textattr(113);
				getch();
				break;
		 }

	}while(ch!='4');
 }

//***************************************************************
//    	function to display main menu of system
//****************************************************************

void mainmenu()
{
	int num;
	char ch;
	do
	{
		clrscr();
		textattr(113);
		cout<<"\t**************************************************************\n";
		cout<<"\t|\t\t\tMAIN MENU\t\t\t     |\n";
		cout<<"\t**************************************************************\n";
		cout<<"\n\t1. NEW ACCOUNT";
		cout<<"\n\t2. DEPOSIT AMOUNT";
		cout<<"\n\t3. WITHDRAW AMOUNT";
		cout<<"\n\t4. SPECIFIC ACCOUNT DETAIL";
		cout<<"\n\t5. MODIFY AN ACCOUNT";
		cout<<"\n\t6. CLOSE AN ACCOUNT";
		cout<<"\n\t7. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t8. DIGITAL PASSBOOK";
		cout<<"\n\t9. HELP";
		cout<<"\n\t0. EXIT";
		cout<<"\n\n\t**************************************************************\n";
		cout<<"\tSelect Your Option (0-9) : ";
		getch();
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			write_account();
			break;
		case '2':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		case '6':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		case '7':
			display_all();
			break;
		case '8':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			passbookdisplay(num);
			break;
		case '9':
			help();
			break;
		case '0':
			gotoxy(33,12);
			cout<<"Signing Out...";
			gotoxy(35,13);
			textcolor(BLINK);
			cprintf("Please Wait ");
			textattr(113);
			delay(2000);
			break;
		 default :
			gotoxy(30,12);
			cout<<"Incorrect Selection";
			gotoxy(30,24);
			textcolor(BLINK);
			cprintf("Press Any Key To Continue...");
			textattr(113);
			getch();
			break;
		}
      }while(ch!='0');
}

//***************************************************************
//    	function to login in system
//****************************************************************

void newadmin()
{
	fstream afile;
	int flag=0;
	account ac;
	afile.open("admin.dat",ios::binary|ios::in);
	if(!afile)
	{
		afile.close();
		afile.open("admin.dat",ios::binary|ios::app);
		ac.adminpass();
		afile.write((char *)&ac,sizeof(account));
		afile.close();
		flag=1;
		adminmenu();
	}
	else
	{
		char no[10];
		char c;
		int i=0;
		afile.close();
		afile.open("admin.dat",ios::binary|ios::in);
		cout<<"\t\t\t\t  Admin Password  "<<endl;
		cout<<"\t\t\t\t    ";
		while( (c=getch())!=13)
		{
			no[i] = c;
			if(no[i]==8)
			{
				no[i]=NULL;
				i--;
				no[i]=NULL;
			}
			else
			{
				printf("*");
				i++;
			}
		}
		no[i]=NULL;
		while(afile.read((char *)&ac,sizeof(account)))
		{
			if(strcmp(ac.apass(),no)==0)
			{
				flag=1;
				adminmenu();
			}
		}
		afile.close();
	}
	if(flag==0)
	{
		gotoxy(32,10);
		textcolor(RED);
		cprintf("Incorrect Password");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;

	}
}

//***************************************************************
//    	function to Change admin password
//****************************************************************

void adminpassword()
{
	fstream afile,tfile;
	int flag=0;
	account ac;
	char no[10];
	char c;
	int i=0;
	afile.open("admin.dat",ios::binary|ios::in);
	cout<<"\n\n\n";
	cout<<"\t\t\t\t  Current Password  "<<endl;
	cout<<"\t\t\t\t    ";
	while( (c=getch())!=13)
	{
		no[i] = c;
		if(no[i]==8)
		{
			no[i]=NULL;
			i--;
			no[i]=NULL;
		}
		else
		{
		printf("*");
		i++;
		}
	}
	no[i]=0;
	while(afile.read((char *)&ac,sizeof(account)))
	{
		if(strcmp(ac.apass(),no)==0)
			{
				afile.close();
				flag=1;
			}
	}
	afile.close();
	if(flag==1)
	{
		tfile.open("Temp.dat",ios::binary|ios::out);
		ac.adminpass();
		tfile.write((char *)&ac,sizeof(account));
		tfile.close();
		remove("admin.dat");
		rename("Temp.dat","admin.dat");
		gotoxy(32,10);
		textcolor(RED);
		cprintf("Password Updated");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
	if(flag==0)
	{
		gotoxy(32,10);
		textcolor(RED);
		cprintf("Fail To Updated");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
}

//***************************************************************
//    	function to create new user
//****************************************************************

void reg()
{
	account ac;
	fstream regFile;
	regFile.open("logins.dat",ios::binary|ios::app);
	ac.details();
	gotoxy(30,24);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	regFile.write((char *)&ac,sizeof(account));
	regFile.close();
}

//***************************************************************
//    	function to Delete User Account
//****************************************************************

void deleteuser(int f)
{
	clrscr();
	account ac;
	char log[10];
	char pwd[10];
	char c;
	int i=0;
	fstream logFile,tFile;
	logFile.open("logins.dat",ios::binary|ios::in);
	if(f==1)
	{
		cout<<" \n\t\tRe Confirm The Username And password";
		cout<<"\n\t\t\t\t User Name";
		cout<<"\n\t\t\t\t  ";
		cin>>log;
		while(logFile.read((char *)&ac,sizeof(account)))
		{
			if(strcmp(ac.acnum(),log)==0)
			{
				cout<<endl;
				cout<<"\t\t\t\tEnter Password  "<<endl;
				cout<<"\t\t\t\t    ";
				while( (c=getch())!=13)
				{
					pwd[i] = c;
					if(pwd[i]==8)
					{
						pwd[i]=NULL;
						i--;
						pwd[i]=NULL;
					}
					else
					{
						printf("*");
						i++;
					}
				}
				pwd[i]=NULL;
				if(strcmp(ac.password(),pwd)==0)
				{
					logFile.seekg(0,ios::beg);
					tFile.open("Temp.dat",ios::binary|ios::out|ios::app);
					while(logFile.read((char *) &ac, sizeof(account)))
					{
						if(strcmp(ac.acnum(),log)!=0)
						{
							tFile.write((char *) &ac, sizeof(account));
						}
					}
					logFile.close();
					tFile.close();
					remove("logins.dat");
					rename("Temp.dat","logins.dat");
					gotoxy(32,10);
					textcolor(RED);
					cprintf("Record Updated");
					textattr(113);
					getch();
					break;
				}
				else
				{
					gotoxy(32,10);
					textcolor(RED);
					cprintf("Incorrect Password");
					gotoxy(30,24);
					textcolor(BLINK);
					cprintf("Press Any Key To Continue...");
					textattr(113);
					getch();
				 }
			}
		}
	}
}

//***************************************************************
//    	function to Validate User Account
//****************************************************************

int validation(char name[])
{
	account ac;
	char pass[10],c;
	int flag=0,i=0;
	fstream logFile;
	logFile.open("logins.dat",ios::binary|ios::in);
	if(!logFile)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		flag=2;
		getch();

	}
	while(logFile.read((char *)&ac,sizeof(account)))
	{
		if(strcmp(ac.acnum(),name)==0)
		{
			cout<<endl;
			cout<<"\t\t\t\tEnter Password  "<<endl;
			cout<<"\t\t\t\t    ";
			while( (c=getch())!=13)
			{
				pass[i] = c;
				if(pass[i]==8)
				{
					pass[i]=NULL;
					i--;
					pass[i]=NULL;
				}
				else
				{
					printf("*");
					i++;
				}
			}
			pass[i]=0;
			if(strcmp(ac.password(),pass)==0)
			{
				flag=1;
				break;
			}
			else
			{
				gotoxy(32,10);
				textcolor(RED);
				cprintf("Incorrect Password");
				gotoxy(30,24);
				textcolor(BLINK);
				cprintf("Press Any Key To Continue...");
				textattr(113);
				flag=2;
				getch();
			}
		}
	}
logFile.close();
return flag;
}

//***************************************************************
//    	function to login in system
//****************************************************************

void login(int flag)
{
	if(flag==1)
	{
		gotoxy(35,12);
		cout<<"Logging...";
		gotoxy(33,13);
		textcolor(BLINK);
		cprintf("Please Wait ");
		delay(2000);
		textattr(113);
		mainmenu();
		return;
	}
	if(flag==0)
	{
		gotoxy(25,12);
		textcolor(RED);
		cprintf("Account Number Does Not Exist");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
}

//***************************************************************
//    	function to see all login accounts
//****************************************************************

void login_account()
{
	account ac;
	ifstream inFile;
	inFile.open("logins.dat",ios::binary);
	if(!inFile)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
	cout<<"\n\n";
	gotoxy(33,2);
	textcolor(BLINK);
	cprintf("ACCOUNT HOLDER LIST");
	textattr(113);
	cout<<"\n\n";
	cout<<"====================================================\n";
	cout<<"USERNAME";
	cout<<setprecision(10)<<setw(20)<<"PASSWORD";
	cout<<setprecision(10)<<setw(15)<<"ACTIVE";
	cout<<setprecision(10)<<setw(15)<<"CREATED ON";
	cout<<endl;
	cout<<"====================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.detail();
	}
	inFile.close();
	gotoxy(30,24);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	getch();
}

//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	int save=0,flag=0,accountnumber;
	fstream outFile,File;
	File.open("account.dat",ios::binary|ios::in);
	cout<<"\nEnter The account No. :";
	cin>>accountnumber;
	while(File.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==accountnumber)
		{
			flag=1;
			break;
		}
	}
	File.close();
	if(flag==1)
	{
		gotoxy(28,10);
		textcolor(RED);
		cprintf("Account Number Already Exist !");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
	if(flag!=1)
	{
	outFile.open("account.dat",ios::binary|ios::app);
	save=ac.create_account(accountnumber);
	}
	if(flag!=1 && save==1)
	{
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		outFile.write((char *) &ac, sizeof(account));
		outFile.close();
		getch();
		return;
	}
	if(flag!=1 && save!=1)
	{
		gotoxy(28,14);
		textcolor(RED);
		cprintf("Account Record Not SAVE !");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	int flag=0;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		return;
	}
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			cout<<"\nACCOUNT DETAILS\n";
			ac.show_account();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		{
		gotoxy(30,12);
		textcolor(RED);
		cprintf("Account Number Does Not Exist");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		}
		getch();
}

//***************************************************************
//    	function to modify record of file
//****************************************************************

void modify_account(int n)
{
	int save=0,found=0;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			found=1;
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			save=ac.modify();
			if(save==1)
			{
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			gotoxy(28,14);
			textcolor(RED);
			cprintf("Account Record UPDATED !");
			gotoxy(30,24);
			textcolor(BLINK);
			cprintf("Press Any Key To Continue...");
			textattr(113);
			getch();
			}
		  }
	}
	File.close();
	if(found==1 && save!=1)
	{
		gotoxy(28,14);
		textcolor(RED);
		cprintf("Account Record Not SAVE !");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
	if(found==0 && save!=1)
	{
		gotoxy(30,14);
		textcolor(RED);
		cprintf("\n\n Record Not Found ");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_account(int n)
{
	account ac;
	char answer;
	fstream inFile,inFile1,outFile,outFile1;
	int found = 0,del = 0;
	inFile.open("account.dat",ios::binary|ios::in);
	if(!inFile)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			found=1;
			ac.show_account();
			cout<<"\n\n";
			cout<<"Do You Want To DELETE Record(Y""/""N) : ";
			cin>>answer;
			answer=toupper(answer);
			break;
		}
	}
	switch(answer)
	{	case 'Y':	del=1;		break;		}
	if(found==1 && del==1)
	{
	outFile.open("Temp.dat",ios::binary|ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");

	inFile1.open("Passbook.dat",ios::binary|ios::in);
	outFile1.open("Temp.dat",ios::binary|ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
	inFile1.close();
	outFile1.close();
	remove("passbook.dat");
	rename("Temp.dat","passbook.dat");
	gotoxy(25,12);
	textcolor(RED);
	cprintf("RECORD OF ACCOUNT DELETED ...");
	gotoxy(30,24);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	getch();
	}
	if(found==1 && del!=1)
	{
		gotoxy(25,12);
		textcolor(RED);
		cprintf("Account Record NOT DELETED");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
	if(found==0)
	{
		gotoxy(25,12);
		textcolor(RED);
		cprintf("Account Number Does Not Exist");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
}

//***************************************************************
//    	function to display Digital passbook
//****************************************************************

void passbookdisplay(int n)
{

	clrscr();
	account ac;
	ifstream inFile,inFile2;
	int found=0;
	inFile.open("passbook.dat",ios::binary);
	inFile2.open("account.dat",ios::binary|ios::in);
	if(!inFile)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
	while(inFile2.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			char t_type = ac.rettype();
			char *t_name = ac.holdername();
			int t_deposit = ac.retdeposit();
			char t_t_type[10];
			switch(t_type)
			{
			case 'S':
				strcpy(t_t_type,"SAVING");
				break;
			case 'C':
				strcpy(t_t_type,"CURRENT");
				break;
			default:
				strcpy(t_t_type,"UNAVAILABLE");
				break;
			}
			found=1;
			cout<<"\n\n\t\t";
			gotoxy(33,1);
			textcolor(BLINK);
			cprintf("DIGITAL PASS BOOK");
			cout<<"\n\n";
			textattr(113);
			gotoxy(2,3);
			cprintf("ACCOUNT NO. :  ");
			cout<<n<<"\t\t\t";
			gotoxy(50,3);
			cprintf("TYPE        :  ");
			cout<<t_t_type;
			gotoxy(2,4);
			cprintf("HOLDER NAME :  ");
			cout<<t_name<<"\t\t\t";
			gotoxy(50,4);
			cprintf("BALANCE     :  ");
			cout<<t_deposit<<endl;
			cout<<"==========================================================================\n";
			cout<<"DATE";
			cout<<setprecision(10)<<setw(22)<<"PARTICULAR";
			cout<<setprecision(10)<<setw(16)<<"DEPOSIT";
			cout<<setprecision(10)<<setw(16)<<"WITHDRAW";
			cout<<endl;
			cout<<"==========================================================================\n";
			break;
		}
	}

	if(found==1)
	{
		inFile.seekg(0,ios::beg);
		while(inFile.read((char *) &ac, sizeof(account)))
		{
			if(ac.retacno()==n)
			{
				ac.passbook();
			}
		}
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
	else
	{
		gotoxy(25,12);
		textcolor(RED);
		cprintf("Account Number Does Not Exist");
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
	}
	inFile.close();
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
	cout<<"\n\n\t\t";
	gotoxy(33,2);
	textcolor(BLINK);
	cprintf("ACCOUNT HOLDER LIST");
	cout<<"\n\n";
	textattr(113);
	cout<<"==========================================================================\n";
	cout<<"A/c No.";
	cout<<setprecision(10)<<setw(10)<<"NAME";
	cout<<setprecision(10)<<setw(15)<<"TYPE";
	cout<<setprecision(10)<<setw(20)<<"BALANCE";
	cout<<setprecision(10)<<setw(18)<<"OPENING DATE";
	cout<<endl;
	cout<<"==========================================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
	gotoxy(30,24);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	getch();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	int found=0,flag=0;
	char medium[10],type;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		gotoxy(35,12);
		cout<<"File could not be open";
		gotoxy(30,24);
		textcolor(BLINK);
		cprintf("Press Any Key To Continue...");
		textattr(113);
		getch();
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			found=1;
			if(option==1)
			{
				cout<<"\n\n";
				gotoxy(33,11);
				cout<<"TO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited : ";
				cin>>amt;
				cout<<"CASH / CHEQUE : ";
				gets(medium);
				strupr(medium);
				if((strcmp(medium,"CASH")==0))
				{
					type='c';
				}
				if((strcmp(medium,"CHEQUE")==0))
				{
					type='q';
				}
				if(type=='c'|| type=='q')
				{
					ac.dep(amt);
					flag=1;
					int daliyflag=2;
					ac.passbook(daliyflag,n,type,amt);
				}
				else
				{
					cout<<"\n\n";
					gotoxy(30,16);
					textcolor(RED);
					cprintf("CASH OR CHEQUE Wrongly Entered");
					break;
				}
			}
			if(option==2)
			{
				cout<<"\n\n";
				gotoxy(33,11);
				cout<<"TO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw : ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
				{
					cout<<"\n\n";
					gotoxy(33,15);
					textcolor(RED);
					cprintf("Insufficience balance");
					textattr(113);
				}
				else
				{
					cout<<"CASH / CHEQUE : ";
					gets(medium);
					strupr(medium);
					if((strcmp(medium,"CASH")==0))
					{
						type='c';
					}
					if((strcmp(medium,"CHEQUE")==0))
					{
						type='q';
					}
					if(type=='c'|| type=='q')
					{
						ac.draw(amt);
						flag=1;
						int daliyflag=3;
						ac.passbook(daliyflag,n,type,amt);
					}
					else
					{
					cout<<"\n\n";
					gotoxy(30,16);
					textcolor(RED);
					cprintf("CASH OR CHEQUE Wrongly Entered");
					break;
					}

				}
		}
	}
	int pos=(-1)* sizeof(ac);
	File.seekp(pos,ios::cur);
	File.write((char *) &ac, sizeof(account));
	}
	File.close();
	if(found==0)
	{
		gotoxy(33,11);
		textcolor(RED);
		cprintf("Record Not Found ");
		textattr(113);
	}
	if(flag==1)
	{
		cout<<"\n\n";
		gotoxy(33,15);
		cout<<"Record Updated";
		found=1;
	}
	gotoxy(30,24);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	getch();
}

//***************************************************************
//    	FUNCTION to see Login screen help text
//****************************************************************

void loginhelp()
{
	clrscr();
	textcolor(GREEN);
	gotoxy(27,3);
	cprintf("Welcome To HELP ! ");
	textcolor(GREEN);
	delay(10);
	gotoxy(10,6);
	cout<<"This Screen Provide Basic Help Text On Login Screen";
	delay(10);
	gotoxy(10,7);
	cout<<" This Login Screen Give Access To Banking Program. ";
	delay(10);
	gotoxy(10,11);
	cout<<" - With Option -1 you can LOGIN into the program ";
	delay(10);
	gotoxy(10,13);
	cout<<" - With Option -2 you can CREATE new USERNAME to get access";
	delay(10);
	gotoxy(10,15);
	cout<<" - With Option -3 you can Use ADMINISTRATIVE option";
	delay(10);
	gotoxy(12,16);
	cout<<" - For First Time You Have To CREATE ADMIN PASSWORD";
	delay(10);
	gotoxy(12,17);
	cout<<" - Other than First time Use ADMIN PASSWORD To Access";
	delay(10);
	gotoxy(10,19);
	cout<<" - With Option -4 you GET HELP Screen ";
	delay(10);
	gotoxy(10,22);
	cout<<" - With Option -5 you can EXIT the Login Screen";
	delay(10);
	gotoxy(30,24);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	getch();
}

//***************************************************************
//    	FUNCTION to see help text
//****************************************************************
void help()
{
	clrscr();
	textcolor(GREEN);
	gotoxy(29,2);
	cprintf("Welcome To HELP ! ");
	textcolor(GREEN);
	delay(10);
	gotoxy(10,4);
	cout<<"This Program can keep record of daily booking";
	delay(10);
	gotoxy(10,5);
	cout<<"transactions.";
	delay(10);
	cout<<"This Program is capable of hoding any No. of Account. ";
	delay(10);
	gotoxy(10,6);
	cout<<" - With Option -1 you can create new account of a customer";
	delay(10);
	gotoxy(10,8);
	cout<<" - With Option -2 you can DEPOSIT amount in Specific Account";
	delay(10);
	gotoxy(10,10);
	cout<<" - With Option -3 you can WITHDRAW amount from Specific Account";
	delay(10);
	gotoxy(10,12);
	cout<<" - With Option -4 you can ENQUIRE BALANCE in Specific Account";
	delay(10);
	gotoxy(10,14);
	cout<<" - With Option -5 you can MODIFY Specific Account details";
	delay(10);
	gotoxy(10,16);
	cout<<" - With Option -6 you can CLOSE Specific Account ";
	delay(10);
	gotoxy(10,18);
	cout<<" - With Option -7 you can SEE ALL Account details";
	delay(10);
	gotoxy(10,20);
	cout<<" - With Option -8 you Can Get DIGITAL PASSBOOK OF Specific Account";
	delay(10);
	gotoxy(10,22);
	cout<<" - With Option -9 you Can Get HELP On Program";
	delay(10);
	gotoxy(10,24);
	cout<<" - With Option -0 you can LOGOUT of Account";
	delay(10);
	gotoxy(30,25);
	textcolor(BLINK);
	cprintf("Press Any Key To Continue...");
	textattr(113);
	getch();
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
	textattr(115);
	gotoxy(26,11);
	cout<<"****************************";
	gotoxy(26,12);
	cout<<"|";
	gotoxy(26,12);
	cout<<"|  Bank Management System  |";
	gotoxy(53,12);
	cout<<"|";
	gotoxy(26,13);
	cout<<"|";
	gotoxy(39,13);
	cout<<"By";
	gotoxy(53,13);
	cout<<"|";
	gotoxy(26,14);
	cout<<"|";
	gotoxy(34,14);
	textcolor(BLINK);
	cprintf("SAHIL TRIVEDI");
	gotoxy(53,14);
	cout<<"|";
	gotoxy(26,15);
	cout<<"****************************";
	gotoxy(40,25);
	delay(3000);
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
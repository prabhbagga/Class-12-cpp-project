#include<iostream>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<process.h>
#include<iomanip>
#include<stdio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
char name[20];
COORD coord={0,0}; // this is global variable
                                    //center of axis is set to the top left cornor of the screen
 void gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 void clrscr()
{
   system("cls");
}

class id
{
      public:
	     char uname[20];
	     char password[20];
}idp;
class sendbox
{
public :
char sto[20];
char smessage[100];
}sb;
class inbox
{
      public :

	    char from[20];
	    char message[100];
}ib;


int login(char[],char[]);
void create(char[]);
void afterlogin(char[]);
void passstar(char[]);
void box();
void delmail(char[],int);
int main()
{
    clrscr();
    int ch;
    box();
    char pass[20],repass[20];
    /*ofstream o("idpass.dat",ios::binary|ios::app);
    o.close();
   ifstream t("idpass.dat",ios::binary|ios::in);
    t.seekg(0);
    while(t.read((char*)&idp,sizeof(idp)))
    {
     cout<<"u:" ;
     cout<<idp.uname<<"\n";
     cout<<"p:";
     cout<<idp.password<<"\n";
     }
    t.close();
    cout<<"\n";*/
    gotoxy(26,12);
    cout<<"!!!....Welcome to Gmail....!!!";
    gotoxy(35,21);
     cout<<"1 : Create";
     gotoxy(35,23);
     cout<<"2 : Login";
     int i=0;
     gotoxy(28,25);
     cout<<"Enter your choice ( 1 / 2 ): ";
     cin>>i;
     if(i=='-')
     {
     exit(0);
     }
     if(i>2)
     {
      gotoxy(28,27);
      cout<<"Incorrect No.";
      getch();
      main();
     }
     if(i==1)
     {
         clrscr();
	box();
	gotoxy(26,10);
	cout<<"!!!....Welcome to Gmail....!!!";
	gotoxy(25,21);
	cout<<"Enter your user name   : ";
	cin>>name;
	create(name);
     }
    else if(i==2)
      {
          clrscr();
	     box();
	     gotoxy(26,12);
	     cout<<"!!!....Welcome to Gmail....!!!";
	     gotoxy(27,21);
	     cout<<"Enter your user name : ";
	     cin>>name;
	     gotoxy(27,23);
	     cout<<"Enter your password : ";
	     passstar(pass);
	     if(login(name,pass)==1)
	     {
	     gotoxy(31,27);
	     cout<<"Login succesful";
	     gotoxy(27,29);
	     cout<<"Press Enter to continue...";
	     getch();
	     afterlogin(name);
	     }
	     else if(login(name,pass)==0)
	     {
	     gotoxy(27,30);
	     cout<<"Username or Password is wrong.\n ";
	     getch();
	     main();
	     }
      }
 getch();
 exit(0);
 return 0;
}
void passstar(char pass1[])
{
	int i1=0,ch=' ';
	while(ch!=13)
	{
	ch=getch();
	if(ch!=13&&ch!=8)
	 {
	   pass1[i1]=ch;
	   i1++;
	 cout<<"*";
	 }

	 if(ch==8&&i1>0)
	 {
	 i1--;
	 cout<<"\b \b";
	 }
    }
       pass1[i1]='\0';
 }
void create(char n[])
{
     char pass[30],repass[30];;
     ifstream coi("idpass.dat",ios::binary|ios::in);     //create object ifstream to search if there is any existing user of not
     coi.seekg(0);
     while(coi.read((char*)&idp,sizeof(idp)))
     {
     if(strcmp(idp.uname,n)==0)
      {
	 gotoxy(25,30);
	 cout<<"User with the same name already exists";
	 gotoxy(25,32);
	 cout<<"Press ENTER to go to main menu";
	 getch();
	 main();
      }
      }
      gotoxy(25,23);
      cout<<"Enter the password : ";
      passstar(pass);
	gotoxy(25,25);
	cout<<"Re-enter your password : ";
	passstar(repass);
      if(strcmp(pass,repass)==0)
       {
	coi.close();
	strcpy(idp.uname,n);
	strcpy(idp.password,pass);
	strcat(n,"data.dat");
	ofstream coo("idpass.dat",ios::binary|ios::app);      //create object ofstream to create user id
	ofstream userdata(n,ios::binary|ios::app);
	userdata.close();
	coo.write((char*)&idp,sizeof(idp));
	coo.close();
	gotoxy(22,30);
	cout<<"Your account has been successfully created";
	gotoxy(25,32);
	cout<<"Press Enter to go to main menu.";
	getch();
	main();
       }
     if(strcmp(pass,repass)!=0)
      {
	gotoxy(25,30);
	cout<<"Password mismatch....!!!!";
	getch();
	main();
      }

}
int login (char n[],char p[])
{
    ifstream lo("idpass.dat",ios::binary|ios::in);
    lo.seekg(0);
    while(!lo.eof())
    {
	  lo.read((char*)&idp,sizeof(idp));
	  if(strcmp(idp.uname,n)==0 && strcmp(idp.password,p)==0)
	  return 1;
    }
    return 0;
}
void afterlogin(char name1[])
{
    clrscr();
     box();
     gotoxy(26,12);
     cout<<"!!!....Welcome "<<name1<<" to Gmail....!!!";
     gotoxy(35,18);
     cout<<"1 : SEND";
     gotoxy(35,20);
     cout<<"2 : INBOX";
     gotoxy(35,22);
     cout<<"3 : SEND BOX";
     gotoxy(35,24);
     cout<<"4 : CHANGE PASSWORD";
     gotoxy(35,26);
     cout<<"5 : DELETION OF ANY MAIL";
     gotoxy(35,28);
     cout<<"6 : LOGOUT";
     gotoxy(28,30);
     cout<<"Enter your choice : ";
     char to[39];
     long int p;
     int no;
     cin>>no;
     clrscr();
     box();
     gotoxy(26,9);
     cout<<"!!!....Welcome to Gmail....!!!";
     if(no==1)
     {
	  char name2[20];
	  strcpy(name2,name1);
	  strcat(name2,"data2.dat");
	  gotoxy(25,15);
	  cout<<"To : ";
	  cin>>to;
	  ifstream t("idpass.dat",ios::binary|ios::in);
	  t.seekg(0);
	  int f=0;
	  while(t.read((char*)&idp,sizeof(idp)))
	 {
		 f=0;
		 if(strcmp(to,idp.uname)==0)
		 {
			  f=1;
			  break;
		 }
	  }
	  if(f==0)
	  {
	  gotoxy(30,20);
	  cout<<"Username not found.";
	  getch();
	  afterlogin(name1);
	  }
	 else if(f==1)
	 {

		  strcpy(sb.sto,to);
		  strcat(to,"data1.dat");
		  strcpy(ib.from,name1);
		  gotoxy(25,17);
		  cout<<"Enter the message : ";
		  cin.ignore();
          gets(ib.message);
		  strcpy(sb.smessage,ib.message);
		  ofstream w(to,ios::binary|ios::app);
		  ofstream w2(name2,ios::binary|ios::app);
		  w2.write((char*)&sb,sizeof(sb));
		  w2.close();
		  w.write((char*)&ib,sizeof(ib));
		  gotoxy(35,30);
		  cout<<"Sending Mail.";
		   for(int j=0;j<3;j++)
		   {
			    for(int k=0;k<5;k++)
			    {
				 Sleep(300);
				 cout<<".";
			     }
			    int t=0;
			    while(t<5)
			    {
				 cout<<"\b \b";
				 t++;
			    }
		   }
		    gotoxy(30,32);
		    cout<<"Your Mail has been sent.";
		    getch();
		    w.close();
		    afterlogin(name1);

	     }
      }
     else if(no==2)
     {
	char name2[20];
	int i=15,j=17,k=1;
	long p;
	gotoxy(40,11);
	cout<<"INBOX";
	strcpy(name2,name1);
	strcat(name2,"data1.dat");
	ifstream  r(name2,ios::binary|ios::in);
	while(r.read((char*)&ib,sizeof(ib)))
	{
	gotoxy(17,i);
	i+=4;
	cout<<k++;
	cout<<". From    : "<<ib.from;
	gotoxy(17,j);
	j+=4;
	cout<<"   Message : "<<ib.message;
	}
	r.close();
	gotoxy(17,j+2);
	cout<<"Press Enter to go to Main Menu.";
	getch();
	afterlogin(name1);
     }
     else if(no==3)
     {
       char name2[20];
       int i=15,j=17,k=1;
       gotoxy(40,11);
       cout<<"SEND BOX";
       strcpy(name2,name1);
       strcat(name2,"data2.dat");
       ifstream sb1(name2,ios::binary|ios::in);
       while(sb1.read((char*)&sb,sizeof(sb)))
       {
	     gotoxy(17,i);
         i+=4;
	     cout<<k++;
	     cout<<". To : "<<sb.sto;
	     gotoxy(17,j);
	     j+=4;
	     cout<<"   Message : "<<sb.smessage;
       }
       sb1.close();
       gotoxy(17,j+2);
       cout<<"Press Enter to go to Main Menu.";
       getch();
       afterlogin(name1);

     }
     else if(no==4)
     {
     char npass[20],repass[20];
     gotoxy(40,11);
     cout<<"CHANGE PASSWORD";
     fstream cp("idpass.dat",ios::binary|ios::out|ios::in);
     gotoxy(30,15);
     cout<<"Enter the new password : ";
     passstar(npass);
     gotoxy(30,17);
     cout<<"Re-enter your password : ";
     passstar(repass);
     if(strcmp(npass,repass)==0)
     {
     cp.seekg(0);
     while(cp.read((char *)&idp,sizeof(idp)))
     {
     if(strcmp(name1,idp.uname)==0)
     {
     p=cp.tellg();
     cp.seekp(p-1*sizeof(idp));
     strcpy(idp.password,npass);
     cp.write((char *)&idp,sizeof(idp));
     cp.close();
     gotoxy(30,19);
     cout<<"Your password has been changed.";
     break;
     }
     }
     }
     else
     {
     gotoxy(30,21);
     cout<<"Password Mismatch";
     }
     getch();
     afterlogin(name1);
     }
     else if(no==5)
     {
       int c;
       gotoxy(30,15);
       cout<<"1 : Delete Inbox Mail.";
       gotoxy(30,17);
       cout<<"2 : Delete Sendbox Mail.";
       gotoxy(30,19);
       cout<<"Choice (1 / 2) : ";
       cin>>c;
       delmail(name1,c);
       afterlogin(name1);
     }
     else if(no==6)
     {
     gotoxy(30,22);
     cout<<"Logout successful .......";
     getch();
     main();
     }

}
void box()
{

int i=0,j=0;
cout<<"\n\n\n\n\n";
cout<<"         ";
while(j<61)
{
cout<<"*";
j++;
}
cout<<"\n";
while(i<40)
{
   j=0;
   cout<<"         *";
   while(j<50)
   {
   cout<<" ";
   j++;
   }
   cout<<"         *";
   cout<<"\n";
   i++;
}
j=0;
cout<<"         ";
while(j<61)
{
cout<<"*";
j++;
}
}
void delmail(char name1[],int choice)
{
	 char name2[20];
	 int k,i=1,j=0;
	 gotoxy(27,25);
	 cout<<"Enter the Mail No. : ";
	 cin>>k;
	 strcpy(name2,name1);
	 if (choice==1)
	 strcat(name2,"data1.dat");
	 if (choice==2)
	 strcat(name2,"data2.dat");
	 ifstream check(name2,ios::in|ios::binary);
	 while(check.read((char *)&ib,sizeof(ib)))
	 {
	 j++;
	 }
	 if(k>j)
	 {
	 gotoxy(27,27);
	 cout<<"Mail does not exist.";
	 }
	 else
	 {
	 ofstream odel("temp.dat",ios::binary|ios::app);
	 ifstream idel(name2,ios::binary|ios::in);
	 idel.seekg(0);
	 while(idel.read((char*)&ib,sizeof(ib)))
	 {
	    if(i!=k)
	    odel.write((char*)&ib,sizeof(ib));
	    i++;
	 }
	 odel.close();
	 idel.close();
	 remove(name2);
	 rename("temp.dat",name2);
	 gotoxy(27,29);
	 cout<<"Your mail has been deleted.";
	 }
	 getch();
}








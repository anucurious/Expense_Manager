#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

class user
{
    public:
	char uname[30];
	char name[30];
	char pass[40];
	long income;
	void newuser();
	void dispuser();

};
class userexpense
{
	public:
		char cat[20],date[11];
		float expense;
		float budget;

};
void user::newuser()
{
	char ch;
	int i=0;
	cout<<"\nEnter the Name: ";
	cin>>name;
	cout<<"\nEnter the User Name: ";
	cin>>uname;
	cout<<"\nEnter the Income in Rs: ";
	cin>>income;
	cout<<"\nEnter the Password: ";
	ch=getch();
	while(ch!=13)
	{
		cout<<'*';
		pass[i++]=ch;
		ch=getch();
	}
	pass[i]='\0';
}
void insert()
{
	clrscr();
	user u;
	ofstream fo("stu.dat",ios::app|ios::out|ios::binary);
	u.newuser();
	fo.write((char*)&u,sizeof(u));
	cout<<"\nAccount Created Successfully";
	fo.close();
}
void manage(char fname[])
{
	userexpense u;
	int ch;
	clrscr();
	cout<<"choose the category\n1.Automobile\n2.Entertainment\n3.Family\n4.Food\n5.Insurance\n6.Tax\n7.Travel\n8.Utilities\n9.Others\n Your Choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			strcpy(u.cat,"Automobile");
			break;
		case 2:
			strcpy(u.cat,"Entertainment");
			break;
		case 3:
			strcpy(u.cat,"Family");
			break;
		case 4:
			strcpy(u.cat,"Food");
			break;
		case 5:
			strcpy(u.cat,"Insurance");
			break;
		case 6:
			strcpy(u.cat,"Tax");
			break;
		case 7:
			strcpy(u.cat,"Travel");
			break;
		case 8:
			strcpy(u.cat,"Utilities");
			break;
		case 9:
			strcpy(u.cat,"Others");
			break;
	}
	cout<<"Enter the Expense: ";
	cin>>u.expense;
	cout<<"Enter the Date(dd/mm/yyyy): ";
	cin>>u.date;
	ofstream ofile(fname,ios::out|ios::app|ios::binary);
	ofile.write((char*)&u,sizeof(u));
	ofile.close();
}
void track(char fname[],char uname[],long income)
{
	userexpense u1;
	int ch;
	int i=1;
	float bal=0;
	ifstream ifile(fname,ios::in|ios::binary);
	if(!ifile)
	{
		cout<<"Error cannot open file";
	}
	clrscr();
	do
	{
		cout<<"\n\n1.All Expense\n2.Balance Available\n3.Back\nEnter Your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				ifile.seekg(0);
				clrscr();
				cout<<"\n\n\t\t\tOverall Expense of user "<<uname<<endl;
				cout<<"\nS.No\t\t   Date\t\t Amount\t\tCategory\n\n";
				while(ifile.read((char*)&u1,sizeof(u1)))
				{
					cout<<i++<<"\t\t"<<u1.date<<"\t"<<u1.expense<<" Rs \t"<<u1.cat<<endl;
					bal+=u1.expense;
				}
			       //	cout<<"\nTotal Income: "<<income<<" Rs";
			      //	cout<<"\nBalance: "<<income-bal;
				break;
			case 2:
				clrscr();
				ifile.seekg(0);
				while(ifile.read((char*)&u1,sizeof(u1)))
				{
					bal+=u1.expense;
				}
				cout<<"\n\n\t\tBudget: "<<income<<" Rs";
				cout<<"\n\n\t\tAmount Spent: "<<bal<< " Rs";
				cout<<"\n\n\t\tBalance: "<<income-bal<<" Rs";
				break;
			case 3:
				break;
		}
	}while(ch>0&&ch<3);
	ifile.close();

}
void report(char fname[],char uname[],long income)
{
	clrscr();
	userexpense u1;
	int ch,i,j,k,n;
	char cat[20],date[11],charx,yr[8],filename[50];
	float tot=0.0;
	ifstream ifile(fname,ios::in|ios::binary);
	ofstream ofile("report.txt",ios::out);
	if(!ifile)
		cout<<"Error Cannot open";

	cout<<"\n\n\t\t Reports";
	cout<<"\n\n\t\t1.By Category\n\t\t2.By Date\n\t\t3.By Month\n\t\t4.By Year\n\t\t Enter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			clrscr();
			cout<<"choose the category\n1.Automobile\n2.Entertainment\n3.Family\n4.Food\n5.Insurance\n6.Tax\n7.Travel\n8.Utilities\n9.Others\n Your Choice: ";
			cin>>cat;
			clrscr();
			i=1;
			n=1;
			tot=0.0;
			cout<<"User "<<uname<<endl;
			ofile<<"User "<<uname<<endl<<"Income \t"<<income<<endl;
			ifile.seekg(0);
			cout<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			ofile<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			while(ifile.read((char*)&u1,sizeof(u1)))
			{
				if((stricmp(u1.cat,cat)==0))
				{
					cout<<i++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					ofile<<n++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					tot+=u1.expense;
				}
			}
			cout<<"\nTotal amount spent on "<<cat<<" is "<<tot;
			ofile<<"\nTotal amount spent on "<<cat<<" is "<<tot;
			cout<<"\nType B to go back: ";
			cin>>charx;
			break;
		case 2:
			cout<<"Enter the Date: ";
			cin>>date;
			clrscr();
			i=1;
			n=1;
			tot=0.0;
			cout<<"User "<<uname<<endl;
			ofile<<"User "<<uname<<endl<<"Income \t"<<income<<endl;
			ifile.seekg(0);
			cout<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			ofile<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			while(ifile.read((char*)&u1,sizeof(u1)))
			{
				if((stricmp(u1.date,date)==0))
				{
					cout<<i++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					ofile<<n++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					tot+=u1.expense;
				}
			}
			cout<<"\nTotal amount spent on "<<date<<" is "<<tot;
			ofile<<"\nTotal amount spent on "<<date<<" is "<<tot;
			cout<<"\nType B to go back: ";
			cin>>charx;
			break;
		case 3:
			cout<<"Enter the Month and Year(mm/yyyy): ";
			cin>>date;
			clrscr();
			i=1;
			n=1;
			tot=0.0;
			cout<<"User "<<uname<<endl;
			ofile<<"User "<<uname<<endl<<"Income \t"<<income<<endl;
			ifile.seekg(0);
			cout<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			ofile<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			while(ifile.read((char*)&u1,sizeof(u1)))
			{
				for(j=0,k=3;k<10;j++,k++)
				{
					yr[j]=u1.date[k];
				}
				yr[7]='\0';
				if((stricmp(yr,date)==0))
				{
					cout<<i++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					ofile<<n++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					tot+=u1.expense;
				}
			}
			cout<<"\nTotal amount spent on "<<date<<" is "<<tot;
			ofile<<"\nTotal amount spent on "<<date<<" is "<<tot;
			cout<<"\nType B to go back: ";
			cin>>charx;
			break;
		case 4:
			cout<<"Enter the Year: ";
			cin>>date;
			clrscr();
			i=1;
			n=1;
			tot=0.0;
			cout<<"User "<<uname<<endl;
			ofile<<"User "<<uname<<endl<<"Income \t"<<income<<endl;
			ifile.seekg(0);
			cout<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			ofile<<"\n\nS.No\t Date\t Amount\t Category\n\n";
			while(ifile.read((char*)&u1,sizeof(u1)))
			{
				for(j=0,k=6;k<10;j++,k++)
				{
					yr[j]=u1.date[k];
				}
				yr[4]='\0';
				if((stricmp(yr,date)==0))
				{
					cout<<i++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					ofile<<n++<<"\t"<<u1.date<<"\t"<<u1.expense<<"\t"<<u1.cat<<endl;
					tot+=u1.expense;
				}
			}
			cout<<"\nTotal amount spent on "<<date<<" is "<<tot;
			ofile<<"\nTotal amount spent on "<<date<<" is "<<tot;
			cout<<"\nType B to go back: ";
			cin>>charx;
			break;
		case 5:
			break;
	}
	ifile.close();
	ofile.close();
}
void newpage(user u1)
{
	char fname[30];
	int ch;
	strcpy(fname,u1.uname);
	strcat(fname,".dat");
	do
	{
		clrscr();
		cout<<" \n Welcome "<<u1.name<<endl;
		cout<<"\n1.Manage Expense\n2.Track Expense\n3.Generate Reports\n4.Logout";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				manage(fname);
				break;
			case 2:
				track(fname,u1.name,u1.income);
				break;
			case 3:
				report(fname,u1.name,u1.income);
				break;

		}

	}while(ch!=4);
}
void login()
{
	user u1,temp;
	char ch='\0',cname[30],cpass[30];
	int i=0,flag=0;
	clrscr();
	cout<<"\n\n\n\t\tEnter Username: ";
	cin>>cname;
	cout<<"\n\t\tEnter Password: ";
	ch=getch();
	while(ch!=13)
	{
		cout<<'*';
		cpass[i++]=ch;
		ch=getch();
	}
	cpass[i]='\0';
	ifstream ifile("stu.dat",ios::in|ios::binary);
	if(!ifile)
	{
		cout<<"Error cannot open file";
	}
	ifile.seekg(0);
	while(ifile.read((char*)&u1,sizeof(u1)))
	{
		if((strcmp(u1.uname,cname)==0)&&(strcmp(u1.pass,cpass)==0))
		{
			flag=1;
			temp=u1;
		}
	}
	ifile.close();
	if(flag==1)
		newpage(temp);
	else
		cout<<"\nInvalid username or password ";
}
int main()
{
	clrscr();
	int ch;
	do
	{
		clrscr();
		cout<<"\n\n\n\t\t\t EXPENSE MANAGER\n\n";
		cout<<"\n\t1.New User\n\t2.Login\n\t3.Exit\n\n\t";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				insert();
				break;
			case 2:
				login();
				break;
		}
	}while(ch>0&&ch<3);
	return 0;
}
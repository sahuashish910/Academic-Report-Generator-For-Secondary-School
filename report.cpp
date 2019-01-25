#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<cstring>
using namespace std;

class student
{
	int roll;
	char name[50];
	char* remark;
	char grade;
	float english, physics, chemistry, maths, cs;
	double percent;
	void calculate()
	{
	percent=(english+physics+chemistry+maths+cs)/5;
	if(percent>=95)
		grade='O',remark="Outstanding";
	else if(percent>=90)
		grade='A+',remark="Excellent";
	else if(percent>=80)
		grade='A',remark="Best";
	else if(percent>=70)
		grade='B+',remark="Better";
	else if(percent>=60)
		grade='B',remark="Good";
	else if(percent>=50)
		grade='C',remark="Satisfactory";
	else if(percent>=40)
		grade='D',remark="Poor";
	else if(percent>=35)
		grade='E',remark="Very Poor";
	else
		grade='F',remark="Fail";
	}	
public:
	void getdata()
	{
	cout<<"\n\t\t\t\t\t\t\t\t\tNAME : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\t\t\t\t\t\t\tROLL NO. : ";
	cin>>roll;
    cout<<"\n\t\t\t\t\t\t\t\t\tEnter Marks ----";
	cout<<"\n\t\t\t\t\t\t\t\t\tENGLISH : ";
	cin>>english;
	cout<<"\n\t\t\t\t\t\t\t\t\tPHYSICS : ";
	cin>>physics;
	cout<<"\n\t\t\t\t\t\t\t\t\tCHEMISTRY : ";
	cin>>chemistry;
	cout<<"\n\t\t\t\t\t\t\t\t\tMATHEMATICS : ";
	cin>>maths;
	cout<<"\n\t\t\t\t\t\t\t\t\tCOMPUTER SCIENCE : ";
	cin>>cs;
	calculate();
	}
		
	void showdata() 
	{
    cout<<"\n\t\t\t\t\t                                        Name        : "<<name;
    cout<<"\n\t\t\t\t\t                                        Roll No.    : "<<roll;
    cout<<"\n\t\t\t\t\t                                        Marks Obtained....  ";
    cout<<"\n\t\t\t\t\t                                        English     : "<<english;
    cout<<"\n\t\t\t\t\t                                        Physics     : "<<physics;
    cout<<"\n\t\t\t\t\t                                        Chemistry   : "<<chemistry;
    cout<<"\n\t\t\t\t\t                                        Mathematics : "<<maths;
    cout<<"\n\t\t\t\t\t                                        CS          : "<<cs;
    cout<<"\n\t\t\t\t\t                                        Percentage  : "<<percent<<"%";
    cout<<"\n\t\t\t\t\t                                        Grade       : "<<grade;
    cout<<"\n\t\t\t\t\t                                        Remark      : "<<remark;
	}	
	
	void layout() 
	{
		cout<<"\t\t\t"<<setw(5)<<roll<<setw(17)<<name<<setw(9)<<english<<setw(10)<<physics<<setw(11)<<chemistry<<setw(13)
		<<maths<<setw(16)<<cs<<setw(17)<<percent<<setw(10)<<grade<<setw(15)<<remark<<endl;
	}
    
	int backrollno() 
	{
		return roll;
	}
}; 

void main_menu(int c);
void front();
int aut=0;

void intro()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);	
	SetConsoleTextAttribute(h,2|FOREGROUND_INTENSITY);
    cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t  -----------------------------------------------------------------------------\n\n";
    SetConsoleTextAttribute(h,6|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t\t\t\t                                    C++ PROJECT \n\n";
    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t                                STUDENT ACADEMIC REPORT-CARD GENERATOR \n";
    cout<<"\t\t\t\t\t                                        FOR SECONDARY SCHOOL ";
    SetConsoleTextAttribute(h,3|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t\t\t                                         Made By ASHISH SAHU \n\n";
    SetConsoleTextAttribute(h,2|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t\t\t\t  -----------------------------------------------------------------------------";

	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);	
    cout<<"\n\n\t\t\t\t\t\t  Press any key to continue...";
    getch();
}

void heading()
{
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_INTENSITY);
    cout<<"\n\n\n\n\t\t\t\t\t                                STUDENT ACADEMIC REPORT-CARD GENERATOR \n";
    cout<<"\t\t\t\t\t                                        FOR SECONDARY SCHOOL ";
    SetConsoleTextAttribute(h,3|FOREGROUND_INTENSITY);
    cout<<"\n\n\t\t\t\t\t                                        Made By ASHISH SAHU \n\n";
    SetConsoleTextAttribute(h,2|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t\t  -----------------------------------------------------------------------------";

    SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
}

void add_student_result(int y)
{
	system("cls");
	heading();
	cout<<"\n\n\n\n\n";
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t                 ENTER DETAILS\n";
	cout<<"\t\t\t\t\t\t\t\t              ------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	student stu;
	ofstream outfile;
	if(y==1)
	{
		outfile.open("student_result.dat",ios::binary|ios::app);
	}
	else
	{
		outfile.open("student_resultss.dat",ios::binary|ios::app);
	}
	stu.getdata();
	outfile.write(reinterpret_cast<char *> (&stu), sizeof(student));
	outfile.close();
    	cout<<"\n\n\t\t\t\t\t\t\t\tStudent result is successfully added...";	
	cin.ignore();
	cin.get();
	main_menu(y);
}

void search_student_result(int y)
{
	system("cls");
	heading();
	int n;
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t                 Enter Roll no. : ";
	cin>>n;
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\n\n\t\t\t\t\t\t\t\t                 STUDENT REPORT-CARD\n";
	cout<<"\t\t\t\t\t\t\t\t               -----------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	student stu;
	ifstream inFile;
	if(y==1)
	{
		inFile.open("student_result.dat",ios::binary);
	}
	else
	{
		inFile.open("student_resultss.dat",ios::binary);
	}
	if(!inFile)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO RECORD FOUND...";
	    cout<<"\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
		cin.get();
		main_menu(y);
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&stu), sizeof(student)))
	{
		if(stu.backrollno()==n)
		{
	  		 stu.showdata();
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
	cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO RECORD FOUND...";
	cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
	cin.ignore();
	cin.get();
	main_menu(y);
}

void show_class_result(int y)
{
	system("cls");
	heading();
	cout<<"\n\n\n\n\n";
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t                 CLASS STUDENTS RESULT\n";
	cout<<"\t\t\t\t\t\t\t\t              -------------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	student stu;
	ifstream inFile;
	if(y==1)
	{
		inFile.open("student_result.dat",ios::binary);
	}
	else
	{
		inFile.open("student_resultss.dat",ios::binary);
	}
	if(!inFile)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO RECORD FOUND...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
		cin.get();
		main_menu(y);
	}
	
	SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout<<"\t\t\t===========================================================================================================================\n";
	SetConsoleTextAttribute(h,6|FOREGROUND_INTENSITY);
	cout<<"\t\t\tROLL_NO.       NAME        ENGLISH   PHYSICS   CHEMISTRY   MATHEMATICS   COMPUTER_SCIENCE   PERCENT(%)   GRADE       REMARK"<<endl;
	SetConsoleTextAttribute(h,FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	cout<<"\t\t\t===========================================================================================================================\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	while(inFile.read(reinterpret_cast<char *> (&stu), sizeof(student)))
	{
		stu.layout();
	}
	cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
	inFile.close();
	cin.ignore();
	cin.get();
	main_menu(y);
}

void edit_student_result(int y)
{
	system("cls");
	heading();
	int n;
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\t                 Enter Roll no. : ";
	cin>>n;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\n\n\t\t\t\t\t\t\t\t                 DETAILS\n";
	cout<<"\t\t\t\t\t\t\t\t              ------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	
    bool found=false;
	student stu;
	fstream File;
	if(y==1)
	{
		File.open("student_result.dat",ios::binary|ios::in|ios::out);
	}
	else
	{
		File.open("student_resultss.dat",ios::binary|ios::in|ios::out);
	}
	if(!File)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...File could not be open...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
		cin.get();
		main_menu(y);
	}
    	while(!File.eof() && found==false)
	{

		File.read(reinterpret_cast<char *> (&stu), sizeof(student));
		if(stu.backrollno()==n)
		{
			stu.showdata();
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\n\n\t\t\t\t\t\t\t\t                 ENTER DETAILS\n";
	cout<<"\t\t\t\t\t\t\t\t              ------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	stu.getdata();
		    	int pos=(-1)*static_cast<int>(sizeof(stu));
		    	File.seekp(pos,ios::cur);
		    	File.write(reinterpret_cast<char *> (&stu), sizeof(student));
		    	cout<<"\n\n\t\t\t\t\t\t\t\tStudent result is successfully updated...";
		    	found=true;
		}
	}
	File.close();
	if(found==false)
	cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO RECORD FOUND...";
	cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
	cin.ignore();
	cin.get();
	main_menu(y);
}

void delete_student_result(int y)
{
	aut=0;
	system("cls");
	heading();
	int n;
	cout<<"\n\n\n\n\n";
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t                 DELETE RESULT\n";
	cout<<"\t\t\t\t\t\t\t\t              ------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
	
	cout<<"\n\n\t\t\t\t\t\t\t\t                 Enter Roll no. : ";
	cin>>n;

    student stu;
    bool found=false;
    fstream File;
    if(y==1)
    {
    	File.open("student_result.dat",ios::binary|ios::in|ios::out);
    }
	else
	{
		File.open("student_resultss.dat",ios::binary|ios::in|ios::out);
	}
	if(!File)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...File could not be open...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
		cin.get();
		main_menu(y);
	}
    while(!File.eof() && found==false)
	{

		File.read(reinterpret_cast<char *> (&stu), sizeof(student));
		if(stu.backrollno()==n)
		{
			cout<<"\n\n\t\t\t\t\t\t\t\tStudent result is successfully deleted...";
			File.close();
			aut=1;
			break;
		}
	}
	if(aut!=1)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...NO RECORD FOUND...";
		File.close();
	}
	
	ifstream inFile;
	if(y==1)
	{
		inFile.open("student_result.dat",ios::binary);
	}
	else
	{
		inFile.open("student_resultss.dat",ios::binary);
	}
	if(!inFile)
	{
		cout<<"\n\n\t\t\t\t\t\t\t\tSORRY...File could not be open...";
	    cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		cin.ignore();
		cin.get();
		main_menu(y);
	}
	
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&stu), sizeof(student)))
	{
		if(stu.backrollno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&stu), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	if(y==1)
	{
		remove("student_result.dat");
	    rename("Temp.dat","student_result.dat");
	}
	else
	{
		remove("student_resultss.dat");
	    rename("Temp.dat","student_resultss.dat");
	}
	cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
	cin.ignore();
	cin.get();
    main_menu(y);
}

void main_menu(int z)
{
	int k=z;
	system("cls");
	heading();
	int ch;
    cout<<"\n\n\n\n\n";
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t                    MAIN MENU\n";
	cout<<"\t\t\t\t\t\t\t\t                 ---------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t\t\t\t              1. ADD STUDENT RESULT\n\n";
    cout<<"\t\t\t\t\t\t\t\t              2. SEARCH STUDENT RESULT\n\n";
    cout<<"\t\t\t\t\t\t\t\t              3. SHOW CLASS RESULT\n\n";
    cout<<"\t\t\t\t\t\t\t\t              4. EDIT STUDENT RESULT\n\n";
    cout<<"\t\t\t\t\t\t\t\t              5. DELETE STUDENT RESULT\n\n";
    cout<<"\t\t\t\t\t\t\t\t              6. GO BACK\n\n";
    cout<<"\t\t\t\t\t\t\t\tYour choice : ";
    cin>>ch;
    if(ch==1)
        add_student_result(k);
    else if(ch==2)
	    search_student_result(k);
    else if(ch==3)             
        show_class_result(k);
    else if(ch==4)             
        edit_student_result(k);
    else if(ch==5)            
        delete_student_result(k);
    else if(ch==6)             
        front();
	else
	    main_menu(k);         
}

void front()
{
	system("cls");
	heading();
	int ch;
    cout<<"\n\n\n\n\n";
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,5|FOREGROUND_INTENSITY);
	cout<<"\t\t\t\t\t\t\t\t                    SELECT CLASS\n";
	cout<<"\t\t\t\t\t\t\t\t                 ------------------\n\n";
	SetConsoleTextAttribute(h,FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    cout<<"\t\t\t\t\t\t\t\t                   1. CLASS XI\n\n";
    cout<<"\t\t\t\t\t\t\t\t                   2. CLASS XII\n\n";
    cout<<"\t\t\t\t\t\t\t\t                   3. EXIT\n\n";
    cout<<"\t\t\t\t\t\t\t\t    Your choice : ";
    cin>>ch;
    switch(ch)
    {
    	case 1: main_menu(ch);
    	         break;
        case 2: main_menu(ch);
                 break;
        case 3: exit(0);
		default: front();         
	}
}

void login()
{
	system("cls");
	heading();
	int i=0;
	char ch,a,uname[30]="babu";
	char pass[30]="coder";
	char ename[30],epass[30];
	cout<<"\n\n\n\n\n\t\t\t\t\t\t\t\t\tUSERNAME : ";
	cin>>ename;
	cout<<"\t\t\t\t\t\t\t\t\tPASSWORD : ";
	while(1)
	{
		ch=getch();
		if(ch==13)
		break;
		else if(ch==8 && i!=0)
		{
            i--;
            cout<<"\b"<<" "<<"\b";
            continue;
    }
        else if(ch==8)
        continue;
		else
		{
			cout<<"*";
			epass[i]=ch;
			i++;
		}
	}
	if((strcmp(uname,ename)==0)&&(strcmp(pass,epass)==0))
	{
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\tYou have successfully logged into your account.";
		cout<<"\n\n\t\t\t\t\t\t\t\tPress any key to continue...";
		getch();
		front();
	}
	else
	{
		cout<<"\n\n\n\n\t\t\t\t\t\t\t\tYou have entered wrong credentials.";
		char ch;
        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t\t  -----------------------------------------------------------------------------\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t                1. TRY AGAIN\n\n";
        cout<<"\t\t\t\t\t\t\t\t                2. EXIT\n\n\n";
        cout<<"\t\t\t\t\t\t\t\tYour choice : ";
        cin>>ch;
        switch(ch)
		{
		case'1':  login();
    	          break;
    	case'2':  exit(0);
		default:  login(); 
    	}
	}
}

int main()
{
	intro();
	login();
}

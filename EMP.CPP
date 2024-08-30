#include<iostream.h>
#include<conio.h>
#include<string.h>

class employee
{
	private :
		int eid;
		char ename[20],department[20];
		float salary;

	public :
		employee(int id,char name[20],char dept[20],float sal)
		{
			eid=id;
			strcpy(ename,name);
			strcpy(department,dept);
			salary=sal;
		}

		void display()
		{
			cout<<"Employee id : "<<eid<<endl;
			cout<<"Employee name : "<<ename<<endl;
			cout<<"Employee department : "<<department<<endl;
			cout<<"Employee salary  : "<<salary<<endl;
		}

		const char* getname()
		{
			return ename;
		}
};

int main()
{
	clrscr();

	int i,t=0,id,n;
	char searchname[20],empname[20],dept[20];
	float esalary;

	// number of employees.
	cout<<"Enter number of employees : ";
	cin>>n;

	//creating array of objects.
	employee** emp=new employee*[n];

	//for taking user details.
	for(i=0;i<n;i++)
	{
		cout<<"Enter id : ";
		cin>>id;
		cout<<"Enter name : ";
		cin>>empname;
		cout<<"Enter department : ";
		cin>>dept;
		cout<<"Enter salary : ";
		cin>>esalary;

		//intializing object through constructor.
		emp[i]=new employee(id,empname,dept,esalary);
	}

	//for displaying all employees details.
	for(i=0;i<n;i++)
	{
		cout<<"\n Employee "<<i+1<< ": "<<endl;
		emp[i]->display();
	}

	cout<<"Enter name to be searched : ";
	cin>>searchname;

	//for searching employee by name.
	for(i=0;i<n;i++)
	{
		if(strcmp(emp[i]->getname(),searchname)==0)
		{
			emp[i]->display();
			t++;
		}
	}
	if(t==0)
	{
		cout<<"Employee not found.";
	}

	//for cleaning up memory.
	for(i=0;i<n;i++)
	{
		delete emp[i];
	}
	delete[] emp;

	getch();
	return 0;
}
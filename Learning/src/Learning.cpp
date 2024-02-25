#include<iostream>
using namespace std;
struct student { int stno; string name; string address;int stage; };
int main()
{
		int SIZE;
		cout<<"Enter the Number of Students"<<endl;
		cin>> SIZE;
		student *A= new student[SIZE];
		cout<<"Please Enter Number,Name,Address,Stage for each student "<<endl;
		for (int i=0;i<SIZE;i++)
		{
		cout<<" \nThe "<<i+1<<"st student information is: "<<endl;
		cin>> A[i].stno>>i[A].name>>(*(A+i)).address>>(A+i)->stage;
		}
		cout<<"Students Information is:"<<endl;
		for (int i=0;i<SIZE;i++)
		{
		cout<<" \nThe "<<i+1<<"st student : "<<endl;
		cout<< A[i].stno<<"\t"<<i[A].name<<"\t"<<(*(A+i)).address<<"\t"<<(A+i)->stage<<endl;
		}
		return 0;
}

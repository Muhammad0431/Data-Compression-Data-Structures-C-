#include<iostream>
#include<string>
#include<fstream>
#include "Task1.cpp"
#include "Task2.cpp"
using namespace std;
int main()
{
    TreeLinklist T1;
	string value1;
	string input1;
    Tree T;
    
	string value;
	string input;
	int length=0;
    cout<<"\nPress 1: for Task1 \n";
    cout<<"\nPress 2: for Task2 \n";
    cout<<"\nEnter Choice \n";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
    {
	cout<<"\nFile Name : \n";
	cin>>input1;
	value1=LinklistFileRead(input1);
	cout<<endl;
	T1.insertList(value1);
	cout<<"\n Character          Frequency\n";
	T1.printList(T1.Root);
	string* A1L;
    A1L=new string[128];
	char* A2L;
	A2L = new char[120];
	string* AAL;
	int IL = 0;
	AAL = T1.HUFList(A1L,IL,A2L,T1.Root);
	cout<<"\nCharatcer       Huffman Code\n";
	for (int i = 0; i < IL; i++)
	{
		cout << A2L[i] << "                " << A1L[i] << endl;
	}
    }  
        break;
        case 2:
        {
    cout<<"\nFile Name : \n";
	cin>>input;
	value=FileRead(input);
	cout<<endl;
	T.insert(value);
    cout<<"\n Character       Frequency\n";
	T.print(T.Root);
	string* A1;
    A1=new string[128];
	char* A2;
	A2 = new char[120];
	string* AA;
	int I = 0;
	AA = T.HUF(A1,I,A2,T.Root);
	cout<<"\nCharatcer       Huffman Code\n";
	for (int i = 0; i < I; i++)
	{
		cout << A2[i] << "                " << A1[i] << endl;
	}

    		 int A3[128];
		 for (int i = 0; i < 128; i++)
			 A3[i] = 0;
	     for (int i = 0; i < value.length(); i++)
    	 {
			 A3[int(value[i])]++;
  		 }

int total=0;
        for(int i=0;i<I;i++)
        {
          int q1,q2,q3;
          q1=int(A2[i]);
          q2=A3[q1];
          q3=q2*A1[i].length();
           total=total+q3;
        }
float ARB=float(total)/float(value.length());
ARB=float(8)/ARB;


cout<<"Compression Ratio is Given as :"<<ARB<<endl;


        }
    default:
        break;
    }
    
}
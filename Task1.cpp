#include<iostream>
#include<string>
#include<fstream>
using namespace std;
template<class T>
class Node1
{
public:
	T data;
	int p;
	Node1* next = NULL;
	Node1(T d,int n)
	{
		data = d;
		p = n;
		next = NULL;
	}
};
template<class T1>
class Linklist
{
public:
	Node1<T1>* head = NULL;
	Node1<T1>* tail = NULL;
	int N = 0;
	Node1<T1>* newn = NULL;
	Node1<T1>* temp = NULL;
	Node1<T1>* getTail()
	{
		return tail;
	}
	void Insert(T1 x,int i)
	{
		newn = new Node1<T1>(x, i);
		if (head == NULL||head->p>i)
		{
			newn->next = head;
			head = newn;
			N++;
		}
		else if (head != NULL)
		{
			temp = head;
			while (temp->next)
			{
				if (temp->next->p < i)
				{
					temp = temp->next;
				}
				else if (temp->next->p == i)
				{
					//temp = temp->next;
					break;
				}
				else
					break;
			}
			newn->next = temp->next  ;
			temp->next = newn;
			N++;
		}
	}
	T1 Head()
	{
		return head->data;
	}
	void Delete()
	{
		if (head != NULL)
		{
			newn = head;
			head = head->next;
			delete newn;
			N--;
		}
	}
	bool isEmpty1()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void PrintList()
	{
		temp = head;
		for (int i = 0; i < N && temp != NULL; i++)
		{
			cout << temp->p<<". " << temp->data->data<<endl;
			temp = temp->next;
		}
		cout << endl;
	}
};
class TreeNODE
{
 public:
	char data;
	int F;
	TreeNODE* left=NULL;
	TreeNODE* right = NULL;
	TreeNODE(int f)
	{
		data = NULL;
		F = f;
	}
	TreeNODE(char d,int f)
	{
		data = d;
		F = f;
	}
};
class TreeLinklist
{
public:
	TreeNODE* t1 = NULL;
	TreeNODE* newn = NULL;
	TreeNODE* t2 = NULL;
	TreeNODE* Root=NULL;
	void insertList(string S)
	{
		Linklist<TreeNODE*> Q;
		 int A1[128];
		 for (int i = 0; i < 128; i++)
			 A1[i] = 0;
	     for (int i = 0; i < S.length(); i++)
    	 {
			 A1[int(S[i])]++;
  		 }

		 for (int i = 0; i < 128; i++)
		 {
			 if (A1[i])
			 {
				 newn = new TreeNODE(char(i), A1[i]);
				 Q.Insert(newn, A1[i]);
			 }
		 }
		 while (Q.N != 1)
		 {
			 t2 = Q.Head();
			 Q.Delete();
			 t1 = Q.Head();
			 Q.Delete();
			 int no = t1->F + t2->F;
			 newn = new TreeNODE(no);
			 newn->left = t1;
			 newn->right = t2;
			 Q.Insert(newn,newn->F);
		 }
		 Root = Q.Head();
		 Q.Delete();
	}
	void printList(TreeNODE* root)
	{
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->data << "                        "<<root->F<<endl;
		}
		else
		{
			printList(root->left);
			printList(root->right);
		}
		return;
	}
	string* HUFList(string* A, int& i,char*& A2, TreeNODE* root)
	{
		if (root->left == NULL && root->right == NULL)
		{
			A2[i] = root->data;
			A[i + 1] = A[i];
			i++;
		}
		else
		{
			A[i] += '0';
      		A=HUFList(A,i, A2, root->left);
			A[i] += '1';
			A=HUFList(A,i, A2, root->right);
		}

		string a;
		for(int j=0;j<A[i].length();j++)
		{
     		if(j< A[i].length()-1)
			a+=A[i][j];
		}A[i] = a;
		return A;
	}
};
string LinklistFileRead(string input1)
{
	fstream myfile;
	string userstring1;
	myfile.open(input1, ios::in);
	if(myfile.is_open())
	{
		while(getline(myfile, userstring1))
		{
			cout<<userstring1;
		}
		myfile.close();
	}
	return userstring1;
}
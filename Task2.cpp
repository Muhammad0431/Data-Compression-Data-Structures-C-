#include<iostream>
#include<string>
#include<fstream>
using namespace std;
template<class T>
class Node
{
public:
	T data;
	int p;
	Node* next = NULL;
	Node(T d,int n)
	{
		data = d;
		p = n;
		next = NULL;
	}
};
template<class T1>
class Queue
{
public:
	Node<T1>* head = NULL;
	Node<T1>* tail = NULL;
	int N = 0;
	Node<T1>* newn = NULL;
	Node<T1>* temp = NULL;
	Node<T1>* getRear()
	{
		return tail;
	}
	void enqueue(T1 x,int i)
	{
		newn = new Node<T1>(x, i);
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
				if (temp->next->p > i)
				{
                  break;
				}
				else if (temp->next->p == i)
				{
					break;
				}
				else
					temp = temp->next;
			}
			newn->next = temp->next  ;
			temp->next = newn;
			N++;
		}
	}
	T1 Front()
	{
		return head->data;
	}
	void dequeue()
	{
		if (head != NULL)
		{
			newn = head;
			head = head->next;
			delete newn;
			N--;
		}
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void Print()
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
class NODE
{
 public:
	char data;
	int F;
	NODE* left=NULL;
	NODE* right = NULL;
	NODE(char d,int f)
	{
		data = d;
		F = f;
	}
};
class Tree
{
public:
	NODE* t1 = NULL;
	NODE* newn = NULL;
	NODE* t2 = NULL;
	NODE* Root=NULL;
	void insert(string S)
	{
		Queue<NODE*> Q;
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
				 newn = new NODE(char(i), A1[i]);
				 Q.enqueue(newn, A1[i]);
			 }
		 }
		 while (Q.N != 1)
		 {
			 t2 = Q.Front();
			 Q.dequeue();
			 t1 = Q.Front();
			 Q.dequeue();
			 int no = t1->F + t2->F;
			 newn = new NODE('\0',no);
			 newn->left = t1;
			 newn->right = t2;
			 Q.enqueue(newn,newn->F);
		 }
		 Root = Q.Front();
		 Q.dequeue();
	}
	void print(NODE* root)
	{

		if (root->left == NULL && root->right == NULL)
		{
			cout << root->data << "                 "<<root->F<<endl;
		}
		else
		{
			print(root->left);
			print(root->right);
		}
		return;
	}
	string* HUF(string* A, int& i,char*& A2, NODE* root)
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
      		A=HUF(A,i, A2, root->left);
			A[i] += '1';
			A=HUF(A,i, A2, root->right);
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
string FileRead(string input)
{
	fstream myfile;
	string userstring1;
	myfile.open(input, ios::in);
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

	

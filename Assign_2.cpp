/*Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key)*/


#include<iostream>
#include<cstring>
#define max 10
using namespace std;

struct dic
{
	char theWord[20];
	char theMeaning[20];

};	

class hashtable
{
	public:
		dic ht[max];
		hashtable()	
		{
			for(int i=0;i<max;i++)
			{
				strcpy(ht[i].theWord,"");
				strcpy(ht[i].theMeaning,"");
			}
		}
		
		int hash(char thekey[10])
		{
			int i,s=0;
			for(i=0;thekey[i]!='\0';i++)
			{
				s=s+thekey[i];
			}
			return(s%max);
		
		}
		
		void insert_word(dic d);
		void display();
		int search_word(char theW[]);
		void del_word(char theW[]);
		
};

void hashtable::insert_word(dic d)
{
	int iIndex=10;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(d.theWord)+i*i)%max;
		cout<<"\n\n Position :"<<i<<" "<<iIndex;
		if(i>0)
		cout<<"\n Collision at "<<iIndex; 
		if(strcmp(ht[iIndex].theWord,"")==0)
		{
			ht[iIndex]=d;
			break;
		}
	}	
		
}

void hashtable::display()
{
	cout<<"index\t\tWord\t\tmeaning";
	for(int i=0;i<max;i++)
	{
		cout<<"\n"<<i<<"\t\t"<<ht[i].theWord<<"\t\t"<<ht[i].theMeaning<<"\n";
	}

}

int hashtable::search_word(char theW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(theW)+i*i)%max;
		if(strcmp(ht[iIndex].theWord,theW)==0)
		{
			cout<<"\nWord Found and the Meaning is :"<<ht[iIndex].theMeaning;
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\nWord Not Found";
	
}

void hashtable::del_word(char theW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(theW)+i*i)%max;
		if(strcmp(ht[iIndex].theWord,theW)==0)
		{
			cout<<"\nWord Found and deleted :"<<ht[iIndex].theMeaning;
			strcpy(ht[iIndex].theWord,"");
			strcpy(ht[iIndex].theMeaning,"");
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\n Word Not Found";
	
}
	
int main()
{
	char theW[10];
	int iCh,iFlag=0;
	hashtable h;
	dic d;
	do
	{
		cout<<"\nLIST\n";
		cout<<"1.INSERT THE WORD\n2.DISPLAY THE WORD\n3.SEARCH MEANING OF THE WORD\n4.DELETE THE WORD\n5.EXIT\n";
		cout<<"Enter your choice:";
		cin>>iCh;
		cout<<"\n";
		
		switch(iCh)
		{
			case 1:
				cout<<"\n Enter the word to be inserted:";
				cin>>d.theWord;
				cout<<"\n Enter the meaning of the word:";
				cin>>d.theMeaning;
				h.insert_word(d);
				break;
				
			case 2:
				h.display();
				break;
				
			case 3:
				cout<<"\n Enter the word to be searched:";
				cin>>theW;
				h.search_word(theW);
				break;
				
			case 4:
				cout<<"\n Enter the word to be deleted:";
				cin>>theW;
				h.del_word(theW);
				break;
				
			case 5:
				break;
				
		}
	}while(iCh!=5);			
return 0;
}					
						



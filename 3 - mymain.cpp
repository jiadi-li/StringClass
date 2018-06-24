#include"mystring.h"
#include<iostream>
 
void swap(String&, String&);
void Sort(String S[],int);
void ToLower(String&);
bool IsPalindrome(String); 

int main()
{
	cout<<"--------Sorting & Palindrome--------"<<endl;
	String answer;
	String strarray[100]; 
	int word_count=0;
	do{
		cout<<"Do you have a word to input? ";
		cin>>answer;
		ToLower(answer);
		if(answer!="yes"&&answer!="no")
			cout<<"Invalid input. Please enter again. ";
		else if(answer=="yes")
		{
			cout<<"Please enter the word: ";
			cin>>strarray[word_count];
			word_count++;
		}
	}while(answer!="no");
	Sort(strarray,word_count);
	cout<<"\n-----------Sorted Words-----------"<<endl; 
	for(int i=0;i<word_count;i++)
	{
		cout<<strarray[i];
		String s_c=strarray[i];
		ToLower(s_c);
		if(IsPalindrome(s_c))
			cout<<"\t\tPalindrome";
		cout<<"\n";
	}
	return 0;
}

void swap(String&s1, String&s2)
{
	String temp=s1;
	s1=s2;
	s2=temp;
}

void Sort(String S[],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-1;j++)
		{
			String s_a=S[j],s_b=S[j+1];
			ToLower(s_a);
			ToLower(s_b);
			if(s_a>s_b)
				swap(S[j],S[j+1]);
		}
	}
}

void ToLower(String& s)
{
	for(int i=0;i<s.Length();i++)
	{
		if (s[i]>='A'&&s[i]<='Z')
			s[i]+=32;
	}
}

bool IsPalindrome(String s)
{
	for(int i=0;i<(s.Length()/2);i++)
	{
		if(s[i]!=s[s.Length()-1-i])
			return false;
	}
	return true;
}

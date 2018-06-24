#include"mystring.h"

String::String()
{
	strval=NULL;
	strln=0;
}

String::String(char s[])
{
	for(strln=0;s[strln];strln++)
		;
	strval=new(char[strln]);
	for(int i=0;i<strln;i++)
		strval[i]=s[i];
}

String::String(int ln,char val)
{
	strln=ln;
	strval=new(char[ln]);
	for(int i=0;i<ln;i++)
	{
		strval[i]=val;
	}
}

String::String(const String& s)
{
	strval=new(char[s.strln]);
	for(strln=0;strln<s.strln;strln++)
		strval[strln]=s.strval[strln];
}

String::~String()
{
	delete[]strval;
}

void String::ToCstring(char s[])
{
	for(int i=0;i<strln;i++)
		s[i]=strval[i];
	s[strln]='\0';
}

int String::Length()
{
	return strln;
}
		
String String::operator +(String s)
{
	String newstring;
	newstring.strln=strln+s.strln;
	newstring.strval=new(char[newstring.strln]);
	for(int i=0;i<strln;i++)
		newstring.strval[i]=strval[i];
	for(int i=0;i<s.strln;i++)
		newstring.strval[strln+i]=s.strval[i];
	return newstring;
}

bool String::operator >(String s)
{
	int length=0;
	if(strln>=s.strln)
		length=s.strln;
	else
		length=strln;
	for(int i=0;i<length;i++)
	{
		if(strval[i]<s.strval[i])
			return false;
		if(strval[i]>s.strval[i])
			return true;			
	}
	if(strln<=s.strln)
		return false;
	return true;	
}

bool String::operator <(String s)
{
	int length=0;
	if(strln>=s.strln)
		length=s.strln;
	else
		length=strln;
	for(int i=0;i<length;i++)
	{
		if(strval[i]>s.strval[i])
			return false;
		if(strval[i]<s.strval[i])
			return true;			
	}
	if(strln>=s.strln)
		return false;
	return true;	
}

bool String::operator ==(String s)
{
	if(strln!=s.strln)
		return false;
	for(int i=0;i<strln;i++)
		if(strval[i]!=s.strval[i])
			return false;
	return true;
}

bool String::operator !=(String s)
{
	if(strln!=s.strln)
		return true;
	for(int i=0;i<strln;i++)
		if(strval[i]!=s.strval[i])
			return true;
	return false;
}

String String::operator =(String s)
{
	strln=s.strln;
	delete[]strval;
	strval=new(char[strln]);
	for(int i=0;i<strln;i++)
		strval[i]=s.strval[i];
	return *this;
} 

char& String::operator [](int index)
{
	return strval[index];
}
		 
ostream& operator <<(ostream&strm, String s)
{
	for(int i=0;i<s.strln;i++)
		cout<<s.strval[i];
	return strm;
}

istream& operator >>(istream&strm, String& s)
{
	char temp[101];
	cin>>temp;
	for(s.strln=0;temp[s.strln];s.strln++)
		;
	s.strval=new(char[s.strln]);
	for(int i=0;i<s.strln;i++)
		s.strval[i]=temp[i];
	return strm;
}

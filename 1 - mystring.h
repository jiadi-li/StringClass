//String Class (Dynamic Allocation), Sorting & Detecting Palindrome

#include <iostream>
using namespace std;

class String
{
	private:
		char *strval;
		int strln;
	public:
		String();
		String(char s[]);
		String(int,char);
		String(const String& s);		//Copy Constructor
		~String();				//Destructor
		void ToCstring(char s[]);
		int Length();
		String operator +(String s);
		bool operator >(String s);
		bool operator <(String s);
		bool operator ==(String s);
		bool operator !=(String s);
		String operator =(String s);		//operator = overloading
		char& operator [](int index);
		 
		friend ostream& operator <<(ostream&strm, String s);
		friend istream& operator >>(istream&strm, String& s);
		
 };

/*
	Luis Cervantes Oropeza 
	Program 3
	The purpose of this program was to use the operatros and overload so like that we can compare classes and add a node with doing node++
	so the main pupose of the program was to use operator overloading to make it easier for ourself. As well this was alll done using OOP as well the program was to 
	essentially create a text editor that will fix your stntax erros and the text is read from a text file and a word from the user
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <sys/time.h>
//editor base class
using namespace std;
class editor
{
	public:
		//constructor
		editor();
		//virtual destructor
		~editor();	
		int display() const;
		int insert(char * data);
	protected: 
		char * word;
};
//class to capitalize the first letter in the paragraph this class is derived from editor
class first_capital : public editor
{
	public:
		//constructor
		first_capital();
		//destructor
		~first_capital();
		//funtion to fix the text 
		int fix(char & data);
		//operator to display
		friend ostream& operator <<(ostream & out ,const first_capital & obj);
	private:
};
//derived calss from editor this class will make all of the "i" capital 
class capital_i : public editor 
{
	public:
		//constructor
		capital_i();
		//destructor
		~capital_i();
		//calls funtion to fix the error
		int fix(char *& data);
		//operator to display the data 
		friend ostream& operator <<(ostream & out ,const capital_i & obj);
	private:
		char * letter;
};
//This class will delete repeated words  & its derived from editor
class delete_repeated : public editor 
{
	public:
		//constructor
		delete_repeated();
		//destruictor
		~delete_repeated();
		// operator to display data 
		friend ostream& operator <<(ostream & out ,const delete_repeated & obj);
		//funtion to display 
		int fix(char * current, char * previous);
	
	private:
};

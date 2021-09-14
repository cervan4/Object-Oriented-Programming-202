
/*
	Luis Cervantes Oropeza 
	Program 3
	The purpose of this program was to use the operatros and overload so like that we can compare classes and add a node with doing node++
	so the main pupose of the program was to use operator overloading to make it easier for ourself. As well this was alll done using OOP as well the program was to 
	essentially create a text editor that will fix your stntax erros and the text is read from a text file and a word from the user
*/
#include"editor.h"
using namespace std;
//constructor
editor::editor() : word(NULL)
{
	char tmp[500];
	ifstream file_ins("sentence.txt");
	if(file_ins)// checks if file exist 
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		//Allocates memory
		word = new char[strlen(tmp) +1];
		//Copys the data 
		strcpy(word,tmp);	
	}
}
//virtual destructor
editor::~editor()
{
	//checks if there is data and if so it will delete it
	if(word) 
		delete [] word;
}
//function to enter in data from user
int editor::insert(char * data)
{
	//checks if there is still data and if so it will delete the data 
	if(word) 
		delete [] word;//deletes data
		word = NULL;
	//allocates the data
	word = new char [strlen(data) +1];
	strcpy(word,data);
}
//display funtion 
int editor::display() const
{
	//display the things that the editors will be able to fix
	cout<<"The three thing that this text editor will provide are things such as"<<endl;
	cout<<"1: Capatalize the first letter in the Paragraph"<<endl;
	cout<<"2: Capatalize all of the 'I'"<<endl;
	cout<<"3: Delete repreated words"<<endl;
} 

//constructor
first_capital::first_capital() { } 
//destructor
first_capital::~first_capital() { } 
//funtion to fix the text 
int first_capital::fix(char & data)// Still need to fix this funtion 
{ 
	int value =  0;//isupper(data);
	if(value == 0)
	{
		data = toupper(data);
	}
} 
//operator to display
ostream& operator <<(ostream & out ,const first_capital & obj)
{
	cout<<"The editor will capitalize the first letter in the paragraph if its not already"<<endl;
}

//constructor
capital_i::capital_i() 
{ 
	char word[2];
	word[0] = 'i';
	letter = new char [2];
	strcpy(letter,word);
} 
//destructor
capital_i::~capital_i()
{ 
	if(letter)
		delete []  letter;
		letter = NULL;
} 
//calls funtion to fix the error
int capital_i::fix(char *& data)
{
	//if data is not an i then it will exit the funtion 
	if(strcmp(letter, data) != 0) return 0;
	char word[2];
	word[0] = 'I';
	//copys the data so it makes it capital
	strcpy(data,word);
}
//operator to display the data 
ostream& operator <<(ostream & out ,const capital_i & object)
{
	cout<<"Where ever there is an 'I' that is lower case the text editor will make it so that its uppercase"<<endl;
	return out;
}

//constructor
delete_repeated::delete_repeated() { } 
//destruictor
delete_repeated::~delete_repeated() { } 
// operator to display data 
ostream& operator <<(ostream & out ,const delete_repeated & obj)
{
	cout<<"If ther are words that are the same for example: and and the first and will be deleted"<<endl;
}
//funtion to display 
int delete_repeated::fix(char * current, char * previous)
{
	//checks if data is still the same and if so it will delete return a 1 tekking is that is a match 
	if(strcmp(current,previous) == 0) 
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


/*
	Luis Cervantes Oropeza 
	Program 3
	The purpose of this program was to use the operatros and overload so like that we can compare classes and add a node with doing node++
	so the main pupose of the program was to use operator overloading to make it easier for ourself. As well this was alll done using OOP as well the program was to 
	essentially create a text editor that will fix your stntax erros and the text is read from a text file and a word from the user
*/
#include"editor.h"
//document class
class document
{
	public:
		//constructor
		document();
		//destructor
		~document();
		//ostream operator overlaod
		friend ostream& operator << (ostream&, const document & obj);
		//istream operator overload
		friend istream& operator >> (istream&, const document & obj);
		// = operator overloading
		document & operator = (const document &);
		// + operator overloading
		document& operator + (const document&);
		// == operator overloading
		bool operator == (const document & obj);
		//compare funtion wrapper
		int compare(class l_node *& source);
		//compare class funtion 
		int compare(class l_node *& head,class l_node *& source);
		//copy funtion 
		int copy(class l_node *& source);
		//add to the end of the LLL wrapper
		int add_end(l_node *& source);
		//copy wrapper funtion 
		int copy(l_node *& my_copy,l_node *& source);
		//delete all wrapper funtion 
		int delete_all();
		int delete_all_wrapper();
		//insert funtion wrapper 
		int insert();
		//fixed the text funtion 
		int fix();
	private:
		//array of pointers 
		class l_node ** head;
};
//the node class
class l_node
{
	public:
		//constructor
		l_node();
		//destructor
		~l_node();
		//ostream operator overloading
		friend ostream& operator << (ostream&, l_node *& obj);
		//istream operator overloading
		friend istream& operator >> (istream&, l_node *& obj);
		//overloads the += operator so it adds to the array of LLL
		l_node*& operator += (const l_node*&);

		bool operator > (const l_node *&);
		bool operator < (const l_node *&);
		bool operator >= (const l_node *&);
		bool operator <= (const l_node *&);
		//traverse to the next pointer funtion 
		l_node *& traverse();
		//compare nodes funtion 
		int compare(l_node *& head,l_node *& source);
		//will make the first letter upper case 
		int fix_first_letter();
		//copys the data from one node to the other
		int copy(l_node *& head, l_node *& source);
		//deletes repeated words
		int fix_repeated(l_node *& head);
		//deletes repeated words
		int fix_repeated(l_node *& head, char *& previous, char * current);
		//calls the fix funtion 
		int fix_i(l_node *& head);
		//displays all of the data
		int display_all(l_node *& head) const;
		//adds to the end of the LLL
		int add_end(l_node *& head, l_node *& adding);
		//insert new node 
		int insert(l_node *& head,l_node *& adding, char * word);
		//insert new node 
		int insert(l_node *& head, char * word);	
		//connect funtion 
		int connect(l_node *& head, l_node *& adding);
		//delete all funtion 
		int delete_all(l_node *& head);
		//funtion to write to the file
		int write_to_file(l_node * head);
	private:
		//declares variables that will be needed 
		char * data;
		l_node * next;	

		first_capital capital;
		capital_i capital_all_i;
		delete_repeated repeated;
};
class highlight
{
	public:
		//constructor
		highlight();
		//destructor
		~highlight();
		//insert funtion 
		int insert(char * data);
		//display all funtion wrapper
		int display_all();
		//funtion to display all in the tree	
		int display_all(class node *& root);
	
	private:
		// variables 
		class node * root;
};
class node
{
	public:
		//constructor
		node();
		//destructot
		~node();	
		//display funtion 
		int display();
		// insert funtion 
		int insert(char *& data,char*&,char *&, node *& head);
		//display funtion 
		int display(node * head);
		//funtion to delete everything in the 2-3 tree
		int delete_all(node *& root);
	private:
		//variables for the node
		char * data;
		char * data2;	

		node * left;
		node * right;
		node * middle;
			
};

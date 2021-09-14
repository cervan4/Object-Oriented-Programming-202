/*
	Luis Cervantes Oropeza
	Program 1
	In this program the purpose was to make a OOP the task was to create a game that I'm calling WAR in this game the user's have the choice 
	to chose a character or they have the option to create their own as well they can see their match history and have battles with the other player as
	well you can check all of the characters stats.
	This programs is build hierarchys as well the use of dynamic binding to create the program.
*/
#include "event.h"
using namespace std;
event::event() : info(NULL)
{ 
	char tmp[500];
	ifstream file_ins("event.txt");
	if(file_ins)
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			info = new char[strlen(tmp) + 1];
			strcpy(info,tmp);

			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');
		}
	}

}
event::~event()// destructor
{
	if(info)// checks if there is data and if so it dealocates data
		delete [] info;
}
int event::display() { }// display function (virtual)

int event:: display_event()// displays the event data 
{
	//Displays the data memebers 
	cout<<endl;
	cout<<info<<endl;	
	cout<<endl;
	//Displays the data memebers 
}
one_more_attack::one_more_attack(): random_event(NULL)// constructor 
{
	char tmp[500];
	ifstream file_ins("one_more_attack.txt");// calls the file one_more_attack.txt
	if(file_ins)//checks if file exits
	{
		file_ins.get(tmp,500,':');//reads in data
		file_ins.ignore(500,':');
		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			random_event = new char[strlen(tmp) + 1];//allocates memeory
			strcpy(random_event,tmp);//copys data

			file_ins.get(tmp,500,':');//checks if there is still more stull on the file
			file_ins.ignore(500,':');
		}
	}
}
one_more_attack::~one_more_attack()//constructor
{
	if(random_event)//checks if there is data in it 
		delete [] random_event;//deletes the memory 
}
int one_more_attack::display()//Display function
{
	cout<<random_event<<endl;
	cout<<endl;
}
extra_health::extra_health(): random_event(NULL)//sets data to NULL & its the constructor 
{
	char tmp[500];
	ifstream file_ins("extra_health.txt");//calls file 
	if(file_ins)
	{
		file_ins.get(tmp,500,':');//grabs data 
		file_ins.ignore(500,':');
		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			random_event = new char[strlen(tmp) + 1];//allocates memory
			strcpy(random_event,tmp);//copy data

			file_ins.get(tmp,500,':');//checks if there is more data
			file_ins.ignore(500,':');
		}
	}
}
extra_health::~extra_health()//destructor
{
	if(random_event)//deallocates memory if there is data 
		delete [] random_event;//deletes the memeory 
}
int extra_health::display()//display function 
{
	cout<<random_event<<endl;//displays data 
	cout<<endl;
}
node::node(): next(NULL) { }// constructor sets data to NULL

node::~node()//destructor
{
	
}
node *& node:: traverse()//traverse to the next pointer 
{
	return this->next;// returns the next pointer 
}
void node::connect(node *& rear)// connect funtion 
{
	next = rear;// sets next pointer to its self 
}
void node::connect(node *& adding, node *& rear)// function to connect up nodes 
{
	adding->next = rear->next;// adds to the CLL 
	rear->next = adding;// rear->next points to the new node
}
int node::new_attack()//creates a new attack character
{
	characters[0] = new attack_character;// creates attack 
}
int node::new_defensive()//creates new defensive
{
	characters[0] = new defensive_character;//create defensive
}
int node::new_neutral()//creates new neutral
{
	characters[0] = new neutral_character;// creates neutral character class 
}
int node::display()// display funtion 
{
	characters[0]->display();//calls funtion to display the character info
}
character_by_category::character_by_category() : rear(NULL) { }// constructor data is set to zero or equavalent 

character_by_category::~character_by_category()// destructor dealocates all the memory in the CLL
{
	node * tmp = rear;// makes a tmp
	tmp->traverse();// traverses to the next node
	delete_all(tmp);// calls funtion to delete all
}
int character_by_category::new_category_attack()// funtion to add to the CLL the attacking character type 
{
	if(rear == NULL)// checks if NULL
	{
		//creates a new node to the CLL
		rear = new node;
		rear->new_attack();// creats a attack character type
		rear->connect(rear);// connects up the node
	}
	else// this means that there is data at the CLL already 
	{
		node * tmp = new node;//creates new node
		tmp->new_attack();
		tmp->connect(tmp,rear);// adds the new node to the CLL that already exist 
		rear = tmp;// rear gets the value tmp
	}
}
int character_by_category::new_category_defensive()// In this funtion a defensive character type gets added to the CLL of character types 
{
	/*
		checks if rear is NULL and if so it creates a new node and creates the CLL 
		memeory is allocated and then the funtion to connect up the node to itself since its a CLL is called
	*/
	if(rear == NULL)
	{
		rear = new node;
		rear->new_defensive();
		rear->connect(rear);
	}
	/*
		Else this means that there is data there already in there so it just adds to the CLL then it creates a new node and creates the CLL 
		memeory is allocated and then the funtion to connect up the node is called and 2 values are passed in since there is a CLL
		that exists already 
	*/
	else
	{
		node * tmp = new node;
		tmp->new_defensive();
		tmp->connect(tmp,rear);
		rear = tmp;
	}
}
int character_by_category::new_category_neutral()
{
	/*
		checks if rear is NULL and if so it creates a new node and creates the CLL 
		memeory is allocated and then the funtion to connect up the node to itself since its a CLL is called
	*/
	if(rear == NULL)
	{
		rear = new node;
		rear->new_neutral();
		rear->connect(rear);
	}
	/*
		Else this means that there is data there already in there so it just adds to the CLL then it creates a new node and creates the CLL 
		memeory is allocated and then the funtion to connect up the node is called and 2 values are passed in since there is a CLL
		that exists already 
	*/
	else
	{
		node * tmp = new node;
		tmp->new_neutral();
		tmp->connect(tmp,rear);
		rear = tmp;
	}
}
int character_by_category::display_all()// funtion to display everything inside the CLL
{
	if(rear == NULL) return 0;// checks if its NULL and if so exits 
	node * tmp = rear->traverse();// makes a tmp node that traverses forward 
	display_all(tmp);//calls funtion to display everything 
}
int character_by_category::display_all(node * tmp)// funtion to display all inside the funtion 
{
	if(tmp == this->rear)// checks if its at the end 
	{
		tmp->display();// calls funtion to display 
		return 0;//exits program
	}
	tmp->display();// calls funtion to display data
	display_all(tmp->traverse());// traverses to the next node
	
}
int character_by_category::delete_all(node *& tmp)//funtion to delete everything inside of the CLL
{
	if(tmp == NULL) return 0;//if tmp is NULL it exits the program 
	if(tmp == this->rear)// if its at the tail again it deletes the last node and sets it to NULL
	{
		delete rear;//deletes rear
		rear = NULL;//sets to NULL
		return 1;
	}
	node * temp = tmp;// makes tmp variable
	tmp->traverse();// traverses to next 
	delete temp;//deletes tmp 
	delete_all(tmp);// calls funtion 
}

l_node::l_node() : next(NULL),name(NULL),wins(0),lose(0) { }//sets value to zero or equavalent & constroctro

l_node::~l_node()// destructor
{
	if(name)// checks if there is data and if so it deletes the memeory
		delete [] name;//deletes memory
}
l_node *& l_node:: traverse()// funtion to traverse to the next pointer
{
	return this->next;// returns the next pointer
}
int l_node::connect(l_node *& head)// funtion to connect up the LLL
{
	head->next = NULL;// sets the next pointer to NULL
}
int l_node::connect(l_node *& head, l_node *& adding)//funtion to connect up the lll and adds to the front  
{
	adding->next = head;// adding->next gets the value head 
}
int l_node::add_win(char * data)// funtion to add to the win talie 
{
	name = new char[strlen(data) +1];// allocates memory 
	strcpy(name,data);// copy data 
	wins++;// adds a one to the win 
}
int l_node::add_lose(char * data)//funtion to add to the lose talie 
{
	name = new char[strlen(data) +1];//allocates memory 
	strcpy(name,data);//copys data 
	lose++;// adds a one to the talie of their lose 
}
int l_node::display_win()//funtion to display the win 
{
	if(name == NULL) return 0;//if NULL exits 
	cout<<"This is the player(s) you won against: "<<name<<endl;// displays the info 
}
int l_node::display_lose()// funtion to display their lose
{
	if(name == NULL) return 0;// if NULL exits 
	cout<<"This is the player you lost against: "<<name<<endl;// displays info 
}
int l_node::delete_all(l_node *& head)// funtion to delete everything from the LLL
{
	if(head == NULL) return 0;// if NULL exits the funtion 
	l_node * tmp = head;// tmp gets the value head 
	head = head->next;// traverses to the next node
	delete tmp;// deletes tmp 
	return delete_all(head);// calls funtion 
}
match_history::match_history()// constructor sets data to NULL and allocates memory for the array of LLL
{
	history = new l_node*[2];// allocates the memory 
	history[0] = NULL;// set to NULL
	history[1] = NULL;//set to NULL
}
match_history::~match_history()// destructor to delete all the memory 
{

	if(history[0] != NULL)// checks if there is memory and if so it deletes it 
		history[0]->delete_all(history[0]);//calls funtion to delete all 

	if(history[1] != NULL)// checks if there is memory 
		history[1]->delete_all(history[1]);// deletes memory calls funtion to delete LLL
}
int match_history::win(char * name)
{
	/*
		checks if the first index has memory(LLL) and if no it creates a new node and then it creats the first node the the 
		LLL making it the head then it calls the funtion to connect up the node as well it calls the funtion to add to the win tally 
	*/
	if(history[0] == NULL)
	{
		history[0] = new l_node;
		history[0]->add_win(name);
		history[0]->connect(history[0]);	
	}
	/*
		this means that there is data inside the index(LLL) so it creates a new node and adds it to the existing LLL 
		it calls the funtion to connect up the nodes as well calls the funtion to add to the win 
	*/
	else
	{

		l_node * tmp = new l_node;
		tmp->add_win(name);
		tmp->connect(history[0],tmp);	
		history[0] = tmp;
	}
}
int match_history::lose(char * name)
{
	/*
		checks if the second index has memory(LLL) and if no it creates a new node and then it creats the first node the the 
		LLL making it the head then it calls the funtion to connect up the node as well it calls the funtion to add to the lose tally 
	*/
	if(history[1] == NULL)
	{
		history[1] = new l_node;
		history[1]->add_lose(name);
		history[1]->connect(history[1]);	
	}
	/*
		this means that there is data inside the index(LLL) so it creates a new node and adds it to the existing LLL 
		it calls the funtion to connect up the nodes as well calls the funtion to add to the lose
	*/
	else
	{

		l_node * tmp = new l_node;
		tmp->add_lose(name);
		tmp->connect(history[1],tmp);	
		history[1] = tmp;
	}
}
int match_history::display_all()// funtion to display all of the data 
{
	int loss = 0;
	int win = 0;
	display_w(history[0],win);//display all of the wins of the character 
	cout<<"This is the total number of win: "<<win<<endl;
	display_l(history[1],loss);// calls funtion to display all of the lost matches 
	cout<<"This is the total number of loss: "<<loss<<endl;
}
int match_history::display_w(l_node * head, int & data)// funtion to display all of the wins in the LLL
{

	if(head == NULL) return 0;// if NULL exits 
	head->display_win();// calls funtion to display data 
	data++;// adds a one 
	display_w(head->traverse(),data);// traverses to the next node
}
int match_history::display_l(l_node * head, int & data)//funtion to display all of the lost matches 
{

	if(head == NULL) return 0;// If NULL exists
	head->display_lose();// calls funtion to display 
	data++;// adds a one 
	display_l(head->traverse(),data);// traverses to the next node 
}

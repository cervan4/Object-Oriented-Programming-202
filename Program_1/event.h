/*
	Luis Cervantes Oropeza
	Program 1
	In this program the purpose was to make a OOP the task was to create a game that I'm calling WAR in this game the user's have the choice 
	to chose a character or they have the option to create their own as well they can see their match history and have battles with the other player as
	well you can check all of the characters stats.
	This programs is build hierarchys as well the use of dynamic binding to create the program.
*/
#include"player.h"
class event//base class for hierarchy of random events 
{
	public:
		event();//constructor
		virtual ~event();//virtual event funtion 
		virtual int display();//virtual display funtion 
		int display_event();//display event funtion 
	private:
		char *  info;
};
class one_more_attack: public event//derived class from event
{
	public:
		one_more_attack();//constructor
		~one_more_attack();//destructor
		int display();//display funtion 
	private:
		char * random_event;
};
class extra_health: public event// derived class from event 
{
	public:
		extra_health();//constructor
		~extra_health();//destructor
		int display();//display funtion 
	private:
		char * random_event;
};
class node
{
	public:
		node();//constructor
		~node();//destructor
		node *& traverse();//funtion to traverse to the next pointer
		void connect(node *& adding, node *& rear);//connect funtion to connect up the nodes
		void connect(node *& rear);// connect funtion to connect up the class when empty
		int display();// funtion to display 
		int new_attack();//creates new attack type
		int new_defensive();// creates new def type 
		int new_neutral();// creates new neutral type 
	protected:
		player * characters[2];
		node * next;
	
};

class character_by_category
{
	public:
		character_by_category();//constructor
		~character_by_category();//destructor
		int new_category_attack(); //adds new attack type to the CLL
		int new_category_defensive();//adds new def type to CLL
		int new_category_neutral();//adds new neutral type to CLL
		int display_all();//wrapper funtion to display all
	private:
		node * rear;
		int display_all(node * rear);//funtion to display all
		int delete_all(node *& rear);//funtion to delete all the data in CLL
};

class l_node
{
	public:
		l_node();//constructor
		~l_node();//destructor
		l_node *& traverse();//funtion to traverse to the next node
		int connect(l_node *& head, l_node *& adding);//funtion to connect up the node when adding to LLL
		int connect(l_node *& head);//funtion to add the first item to the LLL
		int add_win(char * data);//adds a win 
		int add_lose(char * data);//funtion to add a lose
		int display_lose();//displays all the lose
		int display_win();//displays a win 
		int delete_all(l_node *& head);// funtion to display all

	protected:
		char * name;
		int wins;
		int lose;
		l_node * next;
};
class match_history
{
	public:
		match_history();//constructor
		~match_history();//destructor
		int win(char * name);//funtion to add win
		int lose(char * name);//funtion to add lose
		int display_all();//funtion to display all wrapper
		int display_w(l_node * head,int & data);//funtion to display all the wins 
		int display_l(l_node * head,int & data);//funtions to displays all lost matches 
	private:
		l_node ** history ;
};

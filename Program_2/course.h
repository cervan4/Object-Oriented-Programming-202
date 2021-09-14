/*
	Luis Cervantes Oropeza
	Program 2
	In this program we are focused on the dynamic binding aspect of the code and the use of RTTI
	in this program we create a laser tag game where we use an array of DLL where every node holds a base class pointer 
	that allows us to create any type of a derived class(point) we are allowed to do this due to dynamic binding
*/
#include"path.h"
//node class
class node
{
	public:
		//constructor
		node();
		//destructor
		~node();
		//funtion to connect up nodes
		int connect(node *& head);
		//funtion to connect up nodes
		int connect(node *& head,node *& adding);
		//to traverse to next node
		node *& traverse();
		//to delete all 
		int delete_all(node *& head);	
		//to display all
		int display(node * head);
		//creates the space and allocate for the right things
		int create_path(int value);
		//adds the node to the end of the list
		int add_end(node *& head, node *& adding);
		// funtion to actually add to the end
		int start_game(node *& head);
		////wrapper funtion to call 
		int option(node *& head);
		//wrapper funtion to call attack funtion 
		int attack(node *& head);
		//wrapper funtion to retrieve
		int retriev(node *& copy);
		//wrapper funtion
		int RTTI(node *& head);
	private:
		node * next;
		node * previous;
		path * space;
};
//laser tag class
class laser_tag
{
	public:
		//constructor
		laser_tag();
		//destructor
		~laser_tag();	
		//creates the field
		int create_field();
		//lets the user actually play the game 
		int start_game();
		int start_game(node *& head);
		int delete_all();
		int insert();
		int retriev(laser_tag & copy);
		int retriev(node * head, node *& copy);
		int RTTI();
		int display_all();
		int display_all(node * head);
		
	private:
		node ** head;
};

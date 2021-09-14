/*
	Luis Cervantes Oropeza
	Program 2
	In this program we are focused on the dynamic binding aspect of the code and the use of RTTI
	in this program we create a laser tag game where we use an array of DLL where every node holds a base class pointer 
	that allows us to create any type of a derived class(point) we are allowed to do this due to dynamic binding
*/
#include"course.h"
using namespace std;
//constructor to set data to zero or equivalent 
node::node() : next(NULL),previous(NULL), space(NULL) { }

//destructor to deallocate memory
node::~node()
{
	delete space;
}

//funtion to connect up nodes
int node::connect(node *& head)
{
	head->previous = NULL;
	head->next = NULL;
}

//funtion to connect up nodes
int node::connect(node *& head, node *& adding)
{
	adding->next = NULL;
	adding->previous = head->next;
	head->next = adding;
}

//funtion to traverse to the next node 
node *& node :: traverse()
{
	//return next pointer
	return this->next;
}

//funtion to add to the end of the DLL
int node::add_end(node *& head, node *& adding)
{
	if(head == NULL) return 0;
	if(head->next == NULL)
	{
		connect(head,adding);//calls function to connect up nodes 
		return 0;
	}
	//traverses to next node	
	add_end(head->next,adding);
}
//funtion to delete enntire list
int node::delete_all(node *& head)
{
	//if empty deletes memory 
	if(head == NULL) return 0;
	node * tmp = head;//tmp node
	head = head->next;// traverses to next node
	delete tmp;
	delete_all(head);// calls recursive funtion 
}
int node::display(node * head)
{
	if(head == NULL || head->space == NULL) return 0;
	head->space->display();
}
//funtion to point to the proper type in the hierarchy & passes in value
int node::create_path(int value)
{
	if(space != NULL) return 0;
	if(value == 1)
	{
		//allocates the memory
		space = new player; 
	}
	else if(value == 2)
	{
		//allocates the memory
		space = new obstacle;
	}
	else if(value == 3)
	{
		//allocates the memory
		space = new home_base;
	}
}
int node::option(node *& head)
{
	int value = 0;
	//calls options funtion
	value = head->space->option();
	return value;
}
int node::attack(node *& head)
{
	//calls funtion to attack 
	head->space->attack();
}

int node::retriev(node *& copy)
{
	space->retriev(copy->space);
}

int node::RTTI(node *& head)
{
	player * ptr = dynamic_cast<player*>(head->space);
	if(ptr != NULL)
	{
		ptr->my_bullets();
	}
}
//constructor
laser_tag::laser_tag()
{
	//allocates the memory 
	head = new node*[2];
	head[0] = NULL;
	head[1] = NULL;
}
//destructor
laser_tag::~laser_tag()
{
	delete_all();
	/*
	if(head[0] == NULL || head[1] == NULL) return;

	//checks if null and if so deletes the memory
	if(head[0] != NULL)
		head[0]->delete_all(head[0]);

	//checks if null and if so deletes the memory
	if(head[1] != NULL)
		head[1]->delete_all(head[1]);*/
}
//creates the field
int laser_tag::create_field()
{
	int value = 0;
	int loop = 0;
	ifstream file_ins("field.txt");// reads in from file movement
	if(file_ins)// if file exists
	{
		file_ins>>value;
		file_ins.ignore(100,'\n');
		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			if(loop < 3)//checks if it has read in 3 items already
			{
				if(head[0] == NULL)//checks if NULL
				{
					//allocates memory 
					node * tmp = new node;
					//creates proper data
					tmp->create_path(value);
					//calls connect funtion 
					tmp->connect(tmp);		
					head[0] = tmp;
				}
				else
				{
					//allocates memory
					node * tmp = new node;
					//allocates proper memory
					tmp->create_path(value);
					//adds to the end of the DLL
					tmp->add_end(head[0],tmp);		
					//head[0] = tmp;
				}
			}
			else
			{
				if(head[1] == NULL)//checks if NULL
				{
					//allcoates memory
					node * tmp = new node;
					//creates proper 
					tmp->create_path(value);
					//calls connect funtion 
					tmp->connect(tmp);		
					head[1] = tmp;

				}
				else
				{
					//allocates memory
					node * tmp = new node;
					tmp->create_path(value);
					//calls funtion to add to the end of the list
					tmp->add_end(head[1],tmp);		
					//head[1] = tmp;
					
				}
			}
			loop++;
			file_ins>>value;
			file_ins.ignore(100,'\n');
		}
         }
}
int laser_tag::delete_all()
{
	if(head == NULL) return 0;
	//checks if null and if so deletes the memory
	if(head[0] != NULL)
		head[0]->delete_all(head[0]);

	//checks if null and if so deletes the memory
	if(head[1] != NULL)
		head[1]->delete_all(head[1]);
	head[0] = NULL;
	head[1] = NULL;
	if(head != NULL)
	{
		delete [] head; 
		head = NULL;
	}
}
//lets the user actually play the game 
int laser_tag::start_game()
{
	// if either are NULL it will exit
	if(head[0] == NULL || head[1] == NULL) return 0;
	//calls funtion 
	start_game(head[0]);
	//calls funtion 
	start_game(head[1]);
	cout<<"Game is over thanks for playing"<<endl;
}
int laser_tag::start_game(node *& head)
{
	//Checks if NULL
	if(head == NULL) return 0;
	cout<<endl;
	int value = 0;
	//catches value retured from function 
	value = head->option(head);
	if(value == 0)
	{
		head->attack(head);//calls funtion 
	}		
	cout<<endl;
	start_game(head->traverse());//traverses to the next node
}
int laser_tag::insert()
{
	if(head[0] == NULL || head[1] == NULL) return 0;
		
	//allocates memory
	node * tmp = new node;
	tmp->create_path(2);
	//calls funtion to add to the end of the list
	tmp->add_end(head[2],tmp);		
}
int laser_tag::retriev(laser_tag & copy)
{
	//checks if NULL and if so exits program
	if(head[0] == NULL || head[1] == NULL) return 0;
	//calls funtion to retriev data 

	//allocates memory 
	node * tmp = new node;
	//creates proper data
	tmp->create_path(1);
	//calls connect funtion 
	tmp->connect(tmp);		
	copy.head[0] = tmp;

	retriev(head[0],copy.head[0]);		
}
int laser_tag::retriev(node * head, node *& copy)
{
	head->retriev(copy);
}
int laser_tag::RTTI()
{
	//checks if NULL and if so exits program
	if(head[0] == NULL || head[1] == NULL) return 0;
	head[0]->RTTI(head[0]);
}
int laser_tag::display_all()
{
	if(head[0] == NULL || head[1] == NULL) return 0;
	display_all(head[0]);
	display_all(head[1]);
}
int laser_tag::display_all(node * head)
{
	if(head == NULL) return 0;
	head->display(head);
	display_all(head->traverse());
}

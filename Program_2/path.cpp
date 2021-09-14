/*
	Luis Cervantes Oropeza
	Program 2
	In this program we are focused on the dynamic binding aspect of the code and the use of RTTI
	in this program we create a laser tag game where we use an array of DLL where every node holds a base class pointer 
	that allows us to create any type of a derived class(point) we are allowed to do this due to dynamic binding
*/
#include"path.h"
using namespace std;
path::path():name(NULL) { }//constructor

path::path(char * data)
{
	name = new char[strlen(data) +1];//allocates memory
	strcpy(name, data);//copys data 
}
path::~path()
{
	if(name)//checks if there is data and if so deletes it 
		delete [] name;
}
//Virtual decleration of funtion in base class
int path::display() { }

//Virtual decleration of funtion in base class
int path::option() { }

//Virtual decleration of funtion in base class
int path::attack(class player & bot) { } 

//Virtual decleration of funtion in base class
int path::attack() { } 

//Virtual decleration of funtion in base class
int path::stun() { }


int path::retriev(path *& head) { }

obstacle::obstacle(): barrier(NULL)
{
	char tmp[500];
	char * data;
	ifstream file_ins("obstacle.txt");
	if(file_ins)// checks if file exist 
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		//Allocates memory
		barrier = new char[strlen(tmp) +1];
		//Copys the data 
		strcpy(barrier,tmp);	
	}
}

obstacle::obstacle(char * data)
{
	barrier = new char[strlen(data) +1];//allcates memory
	strcpy(barrier,data);//copy data
}

obstacle::~obstacle()
{
	//Checks if there is data and if so deletes it 
	if(barrier)
		delete [] barrier;
}

int obstacle::display()
{
	//Displays the object thats infront 
	cout<<"This is the obstacle infront of you is a "<<barrier<<" meaning you have to go around"<<endl;
}
int obstacle::option()
{
	//They get a choice on what they can do 
	int choice;
	cout<<"You can either shoot whats infront of you or continue to the left"<<endl;
	cout<<"1:Shoot"<<endl;
	cout<<"2:continue to the left"<<endl;
	cout<<"Enter in choice: ";
	//reads in data from the user 
	cin>>choice;
	cin.ignore();
	cout<<endl;
	if(choice == 1)//return value depending on they choice
	{
		cout<<"You shot the obstacle meaning you lost a bullet"<<endl;
		cout<<endl;
		return 0;
	}
	else
	{
		display();
		cout<<endl;
		return 1;
	}
}
int obstacle::stun()
{
	//Stun funtcion 
	cout<<"You have been stuned"<<endl;
	return 1;
}

//constructor
home_base::home_base() : base(NULL)
{
	char tmp[500];
	char * data;
	ifstream file_ins("home_base.txt");
	if(file_ins)// checks if file exist 
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		//Allocates memory
		base = new char[strlen(tmp) +1];
		//Copys the data 
		strcpy(base,tmp);	
	}
}

//constructor with arguments 
home_base::home_base(char * data)
{	
	//accloate memory
	base = new char[strlen(data) +1];
	//copy data
	strcpy(base,data); 
}

//destructor
home_base::~home_base()
{
	//Checks if there is data allocated and if so deletes the memory 
	if(base) 
		delete [] base;
}

//display funtion 
int home_base::display()
{
	cout<<"You are at "<<base<<endl;
	cout<<"This means you have relaod your gun"<<endl;
	//return 1;
}
//option funtion 
int home_base::option()
{
	//They get a choice on what they can do 
	int choice;
	cout<<"1: Stay here and find out where you are at"<<endl;
	cout<<"2: continue walking"<<endl;
	cout<<"Enter in choice: ";
	//reads in data from the user 
	cin>>choice;
	cin.ignore();
	if(choice == 1)//return value depending on they choice
	{
		display();// calls display funtion 
		return 0;
	}
	else
	{
		cout<<"You will continue to walk"<<endl;
		return 1;
	}
}
//stun funtion
int home_base::stun()
{
	cout<<"You have been stuned"<<endl;
}
//constructor
weapon::weapon() : my_weapon(NULL)
{
	char tmp[500];
	char * data;
	ifstream file_ins("weapon.txt");
	if(file_ins)// checks if file exist 
	{
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		//Allocates memory
		my_weapon = new char[strlen(tmp) +1];
		//Copys the data 
		strcpy(my_weapon,tmp);	
	}
}

//constructor with arguments 
weapon::weapon(char * input)
{
	//Allocates memory
	my_weapon = new char[strlen(input) +1];
	//Copys the data 
	strcpy(my_weapon,input);
}
//destructor
weapon::~weapon()
{
	//Dealocates a meomory if there is 
	if(my_weapon)
		delete [] my_weapon;
}
//display funtion 
int weapon::display()
{
	cout<<"Your weapon is a "<<my_weapon<<endl;
}
//constructor
player::player() : health(5),bullets(5){ }
//destructor
player::~player()
{
	health = 0;
	bullets = 0;
}

//display funtion 
int player::display()
{
	cout<<"You have encountered another player and you both shot each other"<<endl;
	cout<<"This means you have one less bullet and you lost one health point"<<endl;
}
//option funtion
int player::option()
{
	//They get a choice on what they can do 
	int choice;
	cout<<"1: Shoot whats infront of you"<<endl;
	cout<<"2: continue walking"<<endl;
	cout<<"Enter in choice";
	//reads in data from the user 
	cin>>choice;
	cin.ignore();
	if(choice == 1)//return value depending on they choice
	{
		display();// calls display funtion 
		return 0;
	}
	else
	{
		cout<<"You will continue to walk"<<endl;
		return 1;
	}	
}
//attack funtion  with no arguments 
int player::attack()
{
	//reduces the amount of bullets by one 
	bullets--;
	if(bullets <= 0)
		cout<<"There are no bullets left you cant shoot"<<endl;
	else
		cout<<"You took a shot"<<endl;
		cout<<"You have one less bullet"<<endl;
}
//attack funtion 
int player::attack(player & bot)
{
	bot.health--;
	bot.bullets--;	
	health--;
	//bullets--;
	//if no bullets are left then it tells them there is no bullets
	if(bullets <= 0)
	{
		cout<<"Your have no bullets left"<<endl;
		return 0;
	}
	else if(health <= 0)
	{
		cout<<"You have died you have zero health sorry you lost"<<endl;
		return 1;
	}
	else
	{
		stun();
	}
}
//stun funtion
int player::stun()
{
	cout<<"Your have been stunned by the other player and have lost 1 point health"<<endl;
}
int player::my_bullets()
{
	cout<<"This is how many bullets you have: "<<bullets<<endl;
}
int player::retriev(path *& head)
{
	if(head == NULL) return 0;
	/*
	head->bullets = bullets;
	head->health = health;*/
}

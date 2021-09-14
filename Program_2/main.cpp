/*
	Luis Cervantes Oropeza
	Program 2
	In this program we are focused on the dynamic binding aspect of the code and the use of RTTI
	in this program we create a laser tag game where we use an array of DLL where every node holds a base class pointer 
	that allows us to create any type of a derived class(point) we are allowed to do this due to dynamic binding
*/
#include "course.h"
using namespace std;

int main()
{
	// creates all variables that will be needed 
	laser_tag my_game;
	laser_tag test;
	my_game.create_field();
	int done = 0;
	int choice = 0;
	char tmp[100];
	char * name = NULL;
	cout<<"Enter in name: ";
	cin.get(tmp,100,'\n');
	cin.ignore(100,'\n');
	name = new char[strlen(tmp) +1];//allocates memory
	strcpy(name,tmp);//copys data
	// creates all variables that will be needed 

	//clears out the screen
	for(int loop = 0;loop < 40;loop++) { cout<<endl; }

	while(done != 1)
	{
		//clears out the screen
		for(int loop = 0;loop < 20;loop++) { cout<<endl; }
		//welcomes in the user and tells them their options that they have to choose from 
		cout<<"Welcome to free for all laser tag"<<endl;
		cout<<"In this game you will will encounter obstacles players & a home base where you will recharge"<<endl;
		cout<<endl;
		cout<<"MENU:"<<endl;
		cout<<"1: Play game"<<endl;
		cout<<"2: Delete everything"<<endl;
		cout<<"3: Insert new path"<<endl;
		cout<<"4: Retriev"<<endl;
		cout<<"5: Check how many bullets you will have (entire game)"<<endl;
		cout<<"6: Display all (This will display the location of the path along the way)"<<endl;
		cout<<"10: Exit game"<<endl;
		cout<<endl;
		//reads in data from user
		cout<<"Enter in choice: ";
		//reads in data
		cin>>choice;
		cin.ignore();
		cout<<endl;
		//switch statement so it can go where they want it to go 
		switch(choice)
		{
			//starts the game
			case 1:
				//calls funtion to start playing the game
				my_game.start_game();		
				break;
			case 2:
				//calls funtion to delete all 
				my_game.delete_all();
				break;
			case 3:
				//calls funtion to add to the 
				my_game.insert();
				break;
			case 4:
				//calls funtion to retriev
				my_game.retriev(test);
				break;
			case 5:
				my_game.RTTI();
				break;
			case 6:
				my_game.display_all();
				break;
			//exits the game and it ends 
			case 10:
				done = 1; //done gets value 1
				break;
		}
	}	
	if(name)
		delete [] name;

	my_game.delete_all();
	test.delete_all();
	return 0;
}

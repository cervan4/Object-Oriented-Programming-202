/*
	Luis Cervantes Oropeza
	Program 1
	In this program the purpose was to make a OOP the task was to create a game that I'm calling WAR in this game the user's have the choice 
	to chose a character or they have the option to create their own as well they can see their match history and have battles with the other player as
	well you can check all of the characters stats.
	This programs is build hierarchys as well the use of dynamic binding to create the program.
*/
#include <iostream>
#include"event.h"
using namespace std;

int main()
{
	/*
		Sets up all of the variables that need to be set as well sets them to their equivalent of NULL
	*/
	char user[100];
	char * name;
	char * name_2;
	int choice;
	int done = 0;
	int option_1 = 0;
	int option_2 = 0;
	int dead =5;
	int random_value;
	int loop =0;
	int number = 0;
	
	char * character_name = NULL;
	int hp = 0;
	int attack = 0;
	int def = 0;
	char * weapon = NULL;
	int custom = 0;
	int custom_2 = 0;

	struct timeval start_time;
	gettimeofday(&start_time, NULL);
	srand(start_time.tv_usec);
	
	character_by_category category;	
	match_history history,history_2;


	player * player_1[4];
	player * player_2[4];
	event * random_events[2];
	player_2[3] = NULL;
	
	random_events[0] = new one_more_attack;
	random_events[1] = new extra_health;
		
	player_1[0] = new attack_character;
	player_2[0] = new attack_character;
	
	player_1[1] = new defensive_character;
	player_2[1] = new defensive_character;

	player_1[2] = new neutral_character;
	player_2[2] = new neutral_character;

	category.new_category_attack();
	category.new_category_defensive();
	category.new_category_neutral();
	/*
		Sets up all of the variables that need to be set as well sets them to their equivalent of NULL
	*/
	

	cout<<"Player 1 please enter your name: ";//asks for player 1 name 
	cin.get(user,100,'\n');
	cin.ignore();
	name = new char[strlen(user) +1];//allocates memory 
	strcpy(name,user);//copys data 
	player_1[0]->set_name(name);// passes in name to class


	cout<<"Player 2 please enter your name: ";//asks for player 2
	cin.get(user,100,'\n');
	cin.ignore();
	name_2 = new char[strlen(user) +1];//allocates memory
	strcpy(name_2,user);//copys data
	player_2[0]->set_name(name_2);//passes in name into class
	
	while(done != 1)// loop so that the game doesnt end until the user decides to end the game 
	{
		for(int loop = 0;loop < 15;loop++) { cout<<endl; }//clears out the screen 

		//Display the Rules & welomes in the players 
		cout<<"Hello welcome to WAR everytime you win a match your character will level up"<<endl;
		cout<<"as well u are allowed to create one charater of your choice & check your match history with your opponent"<<endl;
		cout<<"Good Luck on your journey"<<endl;
		cout<<"*(You might have to scroll down sometimes in order to be able to see everything)*"<<endl;
		cout<<endl;
		//Display the Rules & welomes in the players 
		
		//Displays their option from which they can choose from
		cout<<"1: VS Battle"<<endl;	
		cout<<"2: Check out all characters with their stats(Default Stats)"<<endl;
		cout<<"3: Check match history: "<<name<<endl;
		cout<<"4: Check match history: "<<name_2<<endl;
		cout<<"5: Create own player(You can only create one custom player): "<<name<<endl;
		cout<<"6: Create own player(You can only create one custom player): "<<name_2<<endl;
		cout<<"10: Exit game"<<endl;
		cout<<endl;
		cout<<"CHOOSE FROM OPTIONS (Number)";
		cin >> choice;// reads in data from the user 
		cin.ignore();
		//Displays their option from which they can choose from

		switch(choice)// switch statement to go to the proper case 
		{
			case 1:
				for(int loop = 0;loop < 50;loop++) { cout<<endl; }// clears screen 

				//Shows player 1 all of the characters that can be selected 
				cout<<name<<" please choose a character"<<endl;
				cout<<"1: ";
				player_1[0]->display();//calls  funtion to display character 
				cout<<"2: ";
				player_1[1]->display();//calls funtion to display character 
				cout<<"3: ";
				player_1[2]->display();// calls funtion to display character 
				if(custom >= 1) // if there is a custom player then it will get displayed 
				{
					cout<<"4: ";
					player_1[3]->display();//calls funtion to display character 
				}
				cout<<"CHOOSE FROM OPTIONS (Number * The number is next to the character type *)";
				cin >> option_1;//reads in their choice 
				cin.ignore();
				option_1 -=1;
				//Shows player 1 all of the characters that can be selected 

				for(int loop = 0;loop < 50;loop++) { cout<<endl; }// clears screen 

				//Shows player 1 all of the characters that can be selected 

				cout<<name_2<<" please choose a character"<<endl;
				cout<<"1: ";
				player_2[0]->display();//displays character function 
				cout<<"2: ";
				player_2[1]->display();//display character //funtion 
				cout<<"3: ";
				player_2[2]->display();//display character //funtion 
				if(custom_2 >= 1)// if player 2 has a custom player then it will show 
				{
					cout<<"4: ";
					player_2[3]->display();//calls funtion to display 
				}
				cout<<"CHOOSE FROM OPTIONS (Number * The number is next to the character type *)";
				cin >> option_2;// reads in value 
				option_2 -=1;
				cin.ignore();
				for(int loop = 0;loop < 50;loop++) { cout<<endl; }// clears screen 
				
				cout<<"War has begun"<<endl;
				cout<<endl;
				while(dead != 0)// if someone dies then it will exit the loop 
				{
					random_value = rand() % 2;// generates a random number 
					if(random_value == 2) { random_value = 0; }// if value is 0 then we will get value 2 
					
					if(random_value == 1 && loop < 2 && dead != 0)// random event gets triggered  & if they arent dead 
					{
						random_events[1]->display_event();// calls funtion to display the event 
						random_events[1]->display();// displays the event
						player_1[option_1]->HP();// gives each character HP 
						player_2[option_2]->HP();// gives each character HP
					}
					cout<<name<<" has attacked "<<name_2<<endl;
					dead = player_1[option_1]->strike(player_2[option_2]);// player 1 attacks player 2 and checks & return if player 2 is dead
					if(random_value == 0 && dead != 0 && loop < 2)// Random event if not dead & loop is less than 2
					{
						random_events[0]->display_event();// calls funtion to display event 
						random_events[0]->display();// calls funtion to display the event 
						dead = player_1[option_1]->strike(player_2[option_2]);// player 1 gets another attack on player 2
					}
					cout<<endl;
					if(dead == 0)// checks if player 2 has died after the attack 
					{
						cout<<name_2<<" you have died you lost"<<endl;
						player_1[option_1]->match_won();// calls funtion to say player one won and reset values and give extra points 
						cout<<endl;
						history.win(name_2);// adds a win to the history 
						history_2.lose(name);//adds a lose to player 2 
					}
					else// if not dead then player 2 attacks player 1
					{
						cout<<name_2<<" has attacked "<<name<<endl;
						dead = player_2[option_2]->strike(player_1[option_1]);// player 2 attacks player 1 and returns if player 1 died 
						if(random_value == 0 && dead != 0 && loop < 2)//random event gets envoked if there are true
						{
							random_events[0]->display_event();//calls funtion to display event
							random_events[0]->display();// calls funtion to display what is about to happen 
							dead = player_2[option_2]->strike(player_1[option_1]);// player 2 attacks player 1 again 
						}
						cout<<endl;
						if(dead == 0)// checks if player 1 has died 
						{
							cout<<name<<" has lost this match"<<endl;
							player_2[option_2]->match_won();// calls funtion to declare player 2 as a winner 
							history.lose(name_2);// adds a lose to player 1
							history_2.win(name);// adds a win to player 2
							cout<<endl;
						}
						
					}
					loop++;// ads a one to loop
				}
				dead = 1;// resets value back to 1
					
				break;
			case 2:
				category.display_all();// calls funtion to display all of the character from the CLL of arrays 
				if(custom > 0)// checks if there is a custom player if so displays it 
				{
					cout<<"This is "<<name<<" custom player"<<endl;
					player_1[3]->display();//calls funtion to display information  about the character
				}
				if(custom_2 > 0)//checks if there is a custom character made by player 2
				{
					cout<<"This is "<<name_2<<" custom player"<<endl;
					player_2[3]->display();//calls function to display stats about character
				}
				break;
			case 3:
				for(int loop = 0;loop < 15;loop++) { cout<<endl; }//clears screen 
				history.display_all();//calls funtion to display all of the history for player 1
				break;
			case 4:
				for(int loop = 0;loop < 15;loop++) { cout<<endl; }// clears screen 
				history_2.display_all();//displays all of the wins and lose of player 2
				break;
			case 5:
				for(int loop = 0;loop < 15;loop++) { cout<<endl; }// clears the screen 
				cout<<"ENTER IN THE TYPE OF CHARACTER YOU ARE CREATING (NUMBER)";
				cout<<endl;
				cout<<"1: Attacking character"<<endl;
				cout<<"2: Defensive character"<<endl;
				cout<<"3: Neutral character"<<endl;
				cout<<"Enter in number: ";
				cin >> number;// reads in data from the user
				cin.ignore();
					
				cout<<"Enter name of the character: ";
				cin.get(user,100,'\n');
				cin.ignore();
				character_name = new char[strlen(user)+1];//allocates memory
				strcpy(character_name,user);//copys data 

				cout<<"Enter in HP: ";
				cin>>hp;//reads in data from the user
				cin.ignore();
				
				cout<<"Enter in attack points: ";
				cin>>attack;//reads in data from the user 
				cin.ignore();
				
				cout<<"Enter in defence points: ";
				cin>>def;// reads in data from the user
				cin.ignore();
	
				cout<<"Enter in name of the weapon: ";
				cin.get(user,100,'\n');
				cin.ignore();
				weapon = new char[strlen(user)+1];//creates memory
				strcpy(weapon,user);//copys the data
				
				switch(number)// checks what option they chose 
				{
					case 1:
						player_1[3] = new attack_character;//creates a new attack character class type 
						player_1[3]->insert(character_name,hp,attack,def,weapon);//copys data in 
						custom++;
						break;
					case 2:
						player_1[3] = new defensive_character;//creats a new defensive character class type
						player_1[3]->insert(character_name,hp,attack,def,weapon);//copys data in to class
						custom++;
						break;
					case 3: 
						player_1[3] = new neutral_character;//creates a new neutral character class type 
						player_1[3]->insert(character_name,hp,attack,def,weapon);// copys in data to class 
						custom++;
						break;
				}
				break;
			case 6:
				for(int loop = 0;loop < 15;loop++) { cout<<endl; }// clears screen 
				cout<<"ENTER IN THE TYPE OF CHARACTER YOU ARE CREATING (NUMBER)"<<endl;
				cout<<endl;
				cout<<"1: Attacking character"<<endl;
				cout<<"2: Defensive character"<<endl;
				cout<<"3: Neutral character"<<endl;
				cout<<"Enter in number: ";
				//Displays to screen the options from which they can choose from 
				cin >> number;// reads in data 
				cin.ignore();
					
				cout<<"Enter name of the character: ";
				cin.get(user,100,'\n');
				cin.ignore();
				character_name = new char[strlen(user)+1];//allocates memory 
				strcpy(character_name,user);//copys data 

				cout<<"Enter in HP: ";
				cin>>hp;//reads in data
				cin.ignore();
				
				cout<<"Enter in attack points: ";
				cin>>attack;//reads in data 
				cin.ignore();
				
				cout<<"Enter in defence points: ";
				cin>>def;//reads in data 
				cin.ignore();
	
				cout<<"Enter in name of the weapon: ";
				cin.get(user,100,'\n');
				cin.ignore();
				weapon = new char[strlen(user)+1];//allocates memory
				strcpy(weapon,user);//copys data 
				
				switch(number)// checks what option they chose and go based on that 
				{
					case 1:
						player_2[3] = new attack_character;// creates a new attack character class
						player_2[3]->insert(character_name,hp,attack,def,weapon);//passes in data to the class
						custom_2++;
						break;
					case 2:
						player_2[3] = new defensive_character;// creates a new defensive character class
						player_2[3]->insert(character_name,hp,attack,def,weapon);//passes in the data to the class 
						custom_2++;
						break;
					case 3: 
						player_2[3] = new neutral_character;//creates a new neutral character class 
						player_2[3]->insert(character_name,hp,attack,def,weapon);//passes in the data to the class 
						custom_2++;
						break;
				}	
				break;
			case 10:
				done = 1;// sets done to 1 and exits loop and program ends 
				break;
		}
	cout<<"THANKS FOR PLAYING"<<endl;
		
	}

	return 0;
}

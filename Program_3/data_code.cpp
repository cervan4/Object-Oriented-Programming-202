/*
	Luis Cervantes Oropeza 
	Program 3
	The purpose of this program was to use the operatros and overload so like that we can compare classes and add a node with doing node++
	so the main pupose of the program was to use operator overloading to make it easier for ourself. As well this was alll done using OOP as well the program was to 
	essentially create a text editor that will fix your stntax erros and the text is read from a text file and a word from the user
*/
#include"data.h"
using namespace std;
//constructors for node class 
l_node::l_node()
{
	//sets data members to NULL
	data = NULL;
	next = NULL;
}
l_node::~l_node()// destructor deallocates the data if there is data 
{
	//check if there is data and if so deletes the data 
	if(data)
		delete [] data;
		data = NULL;
}
//this funtion will display every thing inside the LLL
int l_node::display_all(l_node *& head) const 
{
	// checks of head or data is NULL and if so exits the prgram 
	if(head == NULL || head->data == NULL) return 0;
	cout<<head->data<<" ";//displays the data 
	display_all(head->traverse());//recursive call to go to next node
}
ostream& operator << (ostream & out,l_node *& head)// astream operator overloa 
{
	//makes a tmp node 
	l_node * tmp = head;
	//calls funtion to display everything in the LLL
	tmp->display_all(tmp);

	return out;
}
//isream operator to insert new node to LLL
istream& operator >> (istream & in, l_node *& head)
{
	char tmp[500];
	cout<<"Enter in word / sentence you are trying to add to the document"<<endl;
	//reads in data from user 
	cin.get(tmp,500,'\n');
	cin.ignore(500,'\n');
	
	if(head == NULL)// check if there is data there already 
	{
		//allocates the a new node
		l_node * temp = new l_node;
		//allocates new memory 
		temp->data = new char[strlen(tmp) +1];
		//copys data 
		strcpy(temp->data,tmp);
		//calls funtion to set the next funtion 
		temp->next = NULL;
		head = temp;
	}
	else
	{
		//creates new node
		l_node * temp = new l_node;
		//allocates a memory 
		temp->data = new char[strlen(tmp) +1];
		//copys the data 
		strcpy(temp->data,tmp);
		//calls funtion to add to the end of the LLL
		head->add_end(head,temp);
	}
	return in;
}
//funtion to add to the end of the LLL
int l_node::add_end(l_node *& head, l_node *& adding)
{
	//checls if head is NULL and if so it exits the program 
	if(head == NULL) return 0;
	if(head ->next == NULL)// checks if its at the last node 
	{
		head->next = adding;//head->next gets the value adding 
		return 1;
	}
	else//else it traverses to the next node 
	{
		add_end(head->traverse(),adding);// recursive call 
	}
}
//funtion to traverse to the next node 
l_node *& l_node::traverse()
{
	return this->next;// returns the this->next pointer 
}
//funtion to overload the operator += this funtion will add a new node 
l_node*& l_node:: operator += (const l_node *& adding)
{
	//will make a tmp node that pointd to the this pointer
	l_node * tmp = this;
	// calls the ostream operator 
	cin>>tmp;
}
//funtion to insert a new node
int l_node::insert(l_node *& head, char * word)
{
	if(head->data != NULL) return 0;
	head->data = new char[strlen(word) +1];//allocates memory 
	strcpy(head->data, word);//copys the data 
	head->next = NULL;//sets next pointer to NULL
}
//funtion to insert into the LLL when there is data there already 
int l_node::insert(l_node *& head,l_node *& adding, char * word)
{
	if(adding->data != NULL) return 0;
	//allocates the memory 
	adding->data = new char[strlen(word) +1];
	//copys the data 
	strcpy(adding->data, word);
	//calls funtion to add to the end of the LLL
	add_end(head,adding);
}
//funtion to call the funtion to capatalized the first character in the sentence 
int l_node::fix_first_letter()
{
	capital.fix(data[0]);//calls funtion and passes in the first index 
}
//funtion to check if there are repeated words next to each other and if so it deletes one of the copies
int l_node::fix_repeated(l_node *& head)
{
	//checks if NULL
	if(head == NULL) return 0;
	char * current = NULL;
	//allocates the memory 
	char * previous = new char[strlen(head->data)+1];
	//copys the data
	strcpy(previous,head->data);
	//calls recursive funtion to traverse entire list and delete it 
	fix_repeated(head->next,previous,current);

	if(current)
		delete [] current;
		current = NULL;
	if(previous) 
		delete [] previous;
		previous = NULL;
}
//recurive funtion to delete repeated words
int l_node::fix_repeated(l_node *& head, char *& previous, char * current)
{
	//checks if head is NULL and if so exits the funtion
	if(head == NULL) return 0;
	//checks if current has data and if so it will delete it and set it to NULL
	if(current)
	{
		//deletes the data 
		delete [] current;
		current = NULL;
	}
	//allcoates the memory
	current = new char[strlen(head->data)+1];
	//copys the data 
	strcpy(current,head->data);
	//has and int to catch the value and calls funtionto check if the words are the same 
	int value = repeated.fix(current,previous);
	//if value is one then that measn that the values are the same 
	if(value == 1)
	{
		//tmp node
		l_node * tmp = head;
		head = head->next;
		//deletes the node
		delete tmp ;
		//calls recursive function 
		fix_repeated(head,previous,current);
		//return 1;
	}
	else//This means that data isnt the same so ity goes to the next node
	{
		//checks if there is data and if so it will delete it 
		if(previous)
		{
			delete [] previous;
			previous = NULL;
		}
		//alloates the data 
		previous = new char[strlen(head->data)+1];
		//copys the data 
		strcpy(previous,head->data);
		//calls recurive funtion 
		fix_repeated(head->traverse(),previous,current);
	}
}
//this is the funtion to capatalize all of the i
int l_node::fix_i(l_node *& head)
{
	//checks if NULL and if so it will exit funtion
	if(head == NULL) return 0;
	char letter = 'i';
	//checks if its lowecase i
	if(letter == head->data[0])
	{
		capital_all_i.fix(head->data);//calls funtion to capatalize the letter
	}
	fix_i(head->traverse());//traverses to the next node
}
//funtion to delete everything 
int l_node::delete_all(l_node *& head)
{
	if(head == NULL) return 0;
	l_node * tmp = head;
	head = head->next;
	delete tmp;
	//calls funtion 
	delete_all(head);
}
//funtion to copy the data to a node
int l_node::copy(l_node *& head, l_node *& source)
{
	//checks if NULL
	if(source == NULL) return 0;
	if(head == NULL)
	{
		//calls funtoin to insert
		insert(head,source->data);
	}
	else
	{
		//makes tmp new node
		l_node * tmp = new l_node;
		tmp->next = NULL;
		//allocates the memory
		tmp->data = new char[strlen(source->data) +1];
		//calls funtion to insert
		insert(head,tmp,source->data);
	}
	//calls recursive call
	copy(head->next,source->next);
}
int l_node::compare(l_node *& head,l_node *& source)
{
	//check if either are NULL
	if(head == NULL || source == NULL) return 0;
	//compares the data
	if(strcmp(head->data,source->data) == 0)
	{
		//calls function 
		compare(head->next,source->next);
	}
	else
	{
		//return value 1
		return 1;
	}
}
int l_node:: write_to_file(l_node * head)
{
	//chekcs if head is NULL
	if(head == NULL) return 0;
	ofstream file_out;
	file_out.open("sentence.txt",ios::app);
	l_node * tmp = head;
	// checks if file exist
	if(file_out)
	{
		//traverses entire list
		while(tmp != NULL)
		{
			file_out<<tmp->data<<':';
			tmp = tmp->next;
		}
		//file_out<<'\n'<<endl;
	}
	file_out.close();
}
bool l_node::operator > (const l_node *& user)
{
	if(user == NULL) return false;
	//checks if its greater to the data
	if(strcmp(this->data,user->data) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool l_node::operator < (const l_node *& user)
{
	if(user == NULL) return false;
	//checks if its less  to the data
	if(strcmp(this->data,user->data) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool l_node::operator >= (const l_node *& user)
{
	if(user == NULL) return false;
	//checks if its greater or equal to the data
	if(strcmp(this->data,user->data) >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool l_node::operator <= (const l_node *& user)
{
	if(user == NULL) return false;
	//checks if its less or equal to the data
	if(strcmp(this->data,user->data) <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//constructor this will read in data from the text file and add it to the array of LLL
document::document()
{
	head = new l_node*[2];
	head[0] = NULL;
	head[1] = NULL;
	char tmp[500];
	char * data;
	ifstream file_ins("sentence.txt");//gets file 
	if(file_ins)// checks if file exist 
	{
		//reads in data 
		file_ins.get(tmp,500,':');
		file_ins.ignore(500,':');
		//loop to go on until it reaches the end of the file
		while(!file_ins.eof() &&  file_ins)
		{
			//allcates the memory
			data = new char[strlen(tmp) +1];
			//copys the data
			strcpy(data,tmp);
			
			//checks if its NULL
			if(head[0] == NULL) 
			{
				//makes a new node 
				l_node * tmp = new l_node;
				//inserst a new node
				tmp->insert(tmp,data);
				//head gets value tmp
				head[0] = tmp;
			}
			else
			{
				//makes new node
				l_node * tmp = new l_node;
				//calls  funtion to insert
				head[0]->insert(head[0],tmp,data);
			}	
			//checks if there is data
			if(data)
				delete [] data;
				data = NULL;
			//checks if there is still data 
			file_ins.get(tmp,500,':');
			file_ins.ignore(500,':');
				
		}
	}
	if(data)
		delete [] data;
		data = NULL;
}
//destructor
document::~document()
{
	delete_all();//calls funtion to delete all 
}
int document::delete_all_wrapper()
{
	ofstream file_out("sentence.txt");//gets file 
	file_out.open("sentence.txt",ios::app | ios::trunc);
	file_out.close();
	head[0]->write_to_file(head[0]);
	head[1]->write_to_file(head[1]);
	delete_all();//calls funtion to delete all 
}
//ostream operator
ostream& operator << (ostream & out, const document & obj)
{
	cout<<obj.head[0]<<endl;//display everything in the first index
	cout<<obj.head[1]<<endl;//displays everything in the second index
	return out;
}
istream& operator >> (istream& in, document & obj)//istream operator 
{
	obj.insert();//calls funtion to insert
	return in;//return the istrean
}
//operator to copy data
document& document::operator = (const document & obj)
{
	//checks if its it self
	if(this == &obj) return *this;
	//calls the copy funtion 
	copy(obj.head[0]);
	return *this;
}
bool document::operator == (const document & obj)
{
	int value = compare(obj.head[0]);
	value += compare(obj.head[1]);
	if(value == 0)
	{
		return true;
	}	
	else
	{
		return false;
	}
}
int document::compare(l_node *& source)
{
	if(source == NULL) return 0;
	int value = compare(head[0],source);
	value += compare(head[1],source);
	return value;
}
int document::compare(l_node *& head,l_node *& source)
{
	int value = head->compare(head,source);
	return value;
}
document& document::operator + (const document & obj)
{
	//checks if its it self
	if(this == &obj) return *this;
	add_end(obj.head[0]);
	add_end(obj.head[1]);
}
int document::add_end(l_node *& source)
{
	if(source == NULL) return 0;
	//calls funtion to copy the data
	copy(head[0],source);	
	//calls funtion to copy the data
	copy(head[1],source);	
}
//funtion to dealocate all of the nodes
int document::copy(l_node *& source)
{
	//deletes existing data that might exist 
	delete_all();
	//calls funtion to copy the data
	copy(head[0],source);	
	//calls funtion to copy the data
	copy(head[1],source);	
}
int document::copy(l_node *& my_copy,l_node *& source)
{
	//checks if NULL
	if(source == NULL) return 0;
	//calls funtion 
	my_copy->copy(my_copy,source);
}
//funtion to delete all in the array on LLL
int document::delete_all()
{
	//checjs if NULL
	if(head == NULL) return 0;
	//checks if there is data 
	if(head[0] != NULL)
		//calls funtion to delete data 
		head[0]->delete_all(head[0]);
	//checks if there is data 
	if(head[1] != NULL) 
		//calls fuintion to get rid of memory
		head[1]->delete_all(head[1]);
	//sets to NULL
	head[0] = NULL;
	head[1] = NULL;\
	//checks if there is data and if so deletes it 
	if(head != NULL)
	{
		delete [] head;
		//sets to NULL
		head = NULL;
	}
}
//funtion to insert a new word//sentence 
int document::insert()
{
/*
	char tmp[100];
	char copy[100];
	char * word;
	for(int loop = 0;loop < 100;loop++)
	{
		tmp[loop] = '\0';
		copy[loop] = '\0';
	}	
	cout<<"Enter in sentence/words into here"<<endl;		
	cin.get(tmp,100,'\n');
	cin.ignore();
	int loop = 0;
	int loop2 = 0;
	while(loop < 100 && tmp[loop] != '\0')
	{
		if(tmp[loop] == ' ')
		{
			word = new char[strlen(copy) +1];
			strcpy(word,copy);
			if(head[1] == NULL) 
			{
				//makes a new node 
				l_node * tmp = new l_node;
				//inserst a new node
				tmp->insert(tmp,word);
				//head gets value tmp
				head[1] = tmp;
			}
			else
			{
				//makes new node
				l_node * tmp = new l_node;
				//calls  funtion to insert
				head[1]->insert(head[1],tmp,word);
			}	
			for(int value = 0;value < 100;value++)
			{
				copy[value] = '\0';
			}	
			if(word)
				delete [] word;
				word = NULL;
			loop2 = 0;
			loop++;
		}
		copy[loop2] = tmp[loop];
		loop++;
		loop2++;
	}
	if(word)
		delete [] word;
		word = NULL;*/
	cin>>head[1];//calls of the ostream operator 
}
//funtion to fix the the errors that are from the text file
int document::fix()
{
	if(head[0] != NULL)
	{
		//calls function to capatalize the first letter 
		head[0]->fix_first_letter();
		//calls function to delete repreated words that are rigth next to each other 
		head[0]->fix_repeated(head[0]);
		//calls function to capatalize all of the i in the list 
		head[0]->fix_i(head[0]);
	}

	if(head[1] != NULL)
	{	
		//calls function to capatalize the first letter 
		head[1]->fix_first_letter();
		//calls function to delete repreated words that are rigth next to each other 
		head[1]->fix_repeated(head[1]);
		//calls function to capatalize all of the i in the list 
		head[1]->fix_i(head[1]);
	}
	
}
//constructor
highlight::highlight()
{
	root = NULL;
}
//destructor
highlight::~highlight()
{
	//calls funtion to delete everything inside the 2-3 tree
	root->delete_all(root);
	//checks if there is data still there and if so delete the data and sets to NULL;
	if(root)
	{
		delete root;
	}
	root = NULL;
}
//funtion to insert into the 2-3 tree
int highlight::insert(char * memory)
{	
	//sets variables to NULL
	char * user3 = NULL;
	char * user = NULL;
	char * user2 = NULL;

	char data[2];
	data[0] = 'i';
	//allocates the memory and copys the data
	user3 = new char[strlen(data)+1];
	strcpy(user3,data);

	//allocates the memory and copys the data
	char array[5] = "Hi";
	user2 = new char[strlen(array) +1];
	strcpy(user2,array);

	char red[4] = "red";

	//allocates the memory and copys the data
	user = new char[strlen(red) +1];
	strcpy(user,red);
	//calls funtion to insert into the 2-3 tree
	root->insert(user2,user2,user3,root);
	//calls funtion to insert into the 2-3 tree
	root->insert(user,user2,user3,root);
	//checks if there is data and if so deletes it
	if(user3)
		delete [] user3;
		user3 = NULL;
	//allocates new memory and copys it
	user3 = new char[strlen(data)+1];
	strcpy(user3,data);
	//calls funtion to insert into the 2-3 tree
	root->insert(user3,user2,user,root);

	if(user)
		delete [] user;
		user = NULL;

	if(user2)
		delete [] user2;
		user2 = NULL;
	if(user3)
		delete [] user3;
		user3 = NULL;
}
//wrapper funtion to display eveyrthing in the 2-3 tree
int highlight::display_all()
{
	//calls display funtion 
	root->display(root);
}
//constructor
node::node()
{
	//sets variable to NULL
	data = NULL;
	data2 = NULL;
	left = NULL;
	right = NULL;
	middle = NULL;
}
//destructot
node::~node()
{
	//if there is data it will dealocate it 
	if(data)
		delete [] data;
		data = NULL;
	//if there is data it will dealocate it 
	if(data2)
		delete [] data2;
		data2 = NULL;

}
//delete all function 
int node::delete_all(node *& root)
{
	//if null exits the code
	if(root == NULL) return 0;
	//calls the left & right & middle pointer to delete it
	delete_all(root->left);
	//calls the left & right & middle pointer to delete it
	delete_all(root->right);
	//calls the left & right & middle pointer to delete it
	delete_all(root->middle);
	//deletes the node and sets to NULL
	delete root;
	root = NULL;
}
//display funtion 
int node::display(node * head)
{
	//checks if null
	if(head == NULL) return 0;
	//recursive call
	display(head->left);
	//calls display funtion;
	if(head->data != NULL)
		cout<<head->data<<endl;
	if(head->data2 != NULL)
		cout<<head->data2<<endl;
	//recursive call
	display(head->middle);
	//recursive call
	display(head->right);
}
//display funtion 
int node::display()
{
	//checks if it null and if not display the data
	if(data != NULL)
		cout<<data<<endl;
	//checks if it null and if not display the data
	if(data2 != NULL)
		cout<<data2<<endl;
}
// insert funtion  to the 2-3 tree
int node::insert(char *& value,char *& tmp2, char *& tmp3, node *& root)
{
	//checks if NULL and if so insert into the 2-3 tree
	if(root == NULL)
	{
		//alloates a new node and allocates memory for the char * and copys the data over  
		node * tmp = new node;
		tmp->data = new char [strlen(value) +1];
		strcpy(tmp->data,value);
		//root gets the value tmp
		root = tmp;
		return 1;
	}
	//gets the size of the char *
	int size = strlen(root->data);
	int size2 = 0;
	//checks if its not NULL
	if(root->data2 != NULL)
	{
		//gets the size of the char *
		size2 = strlen(root->data2);
	}
	//gets the size of the char *
	int size3 = strlen(value);
	//cheks if there is only a root
	if(root->left == NULL && root->right == NULL && root->middle == NULL)
	{
		//checks if NULL and if so adds to it
		if(root->data2 == NULL)
		{
			//allocates the memory
			root->data2 = new char[strlen(value) +1];
			//copys the data
			strcpy(root->data2,value);
			return 1;
		}
		else
		{
			//allocates the memory
			char * tmp = new char[strlen(root->data)+1];
			//copys the data
			strcpy(tmp,root->data);	
			//checks if there is data and if so deletes it and sets to NULL
			if(tmp2)
				delete [] tmp2;
				tmp2 = NULL;
			
			//allocates the memory
			tmp2 = new char [strlen(root->data) +1];
			strcpy(tmp2,root->data2);

			//checks if there is data and if so deletes it and sets to NULL
			if(tmp3)
				delete [] tmp3;
				tmp3 = NULL;

			//allocates the memory
			tmp3 = new char [strlen(root->data) +1];
			//copys the data
			strcpy(tmp3,value);
			//checks the sizes
			if(size < size2 && size > size3)
			{
				//checks if there is data and if so delets it
				if(root->data)
					delete [] root->data;

				//checks if there is data and if so delets it
				if(root->data2)
					delete [] root->data2;
					root->data2 = NULL;
				//allocates the memory and copys the data
				root->data = new char [strlen(tmp) +1];
				strcpy(root->data,tmp);
				//calls recursive funtion again
				insert(tmp3,tmp2,value,root->left);
				//calls recursive funtion again
				insert(tmp2,tmp3,value,root->right);
			}
			if(tmp)
				delete [] tmp;
				tmp = NULL;
		}
		return 1;
	}
	//checks if size is larger
	else if(size3 > size)
	{
		//calls recursive funtion
		insert(value,tmp2,tmp3,root->right);
	}
	else if(size3 < size)
	{
		//calls recursive funtion
		insert(value,tmp2,tmp3,root->left);
	}
}

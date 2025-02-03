#include<iostream>
using namespace std;

class Node{
	private:
		int info;
		Node *first, *previous, *current, *temp, *last, *next;
	public:
		void create();
		void access();
		void insertFront();
		void insertLast();
		void insertBetween();
		void del();
};
void Node::create(){
	int item;
	char ch;
	first= new(Node);		
	cout<<"\nEnter the item : "; 		
	cin>>item;
	first->info = item;					
	first->next = NULL;
	current = previous = last = first ;			
	cout<<"\nDo you want to add further items(y/n) : ";
	cin>>ch;
	while(ch == 'y' || ch == 'Y'){
		current= new(Node);
		current -> next = NULL;
		cout<<"\nEnter the item : "; 		
		cin>>item;
		current -> info = item;
		previous-> next = current;			
		previous = current;					
		cout<<"\nDo you want to add further items(y/n) : ";
		cin>>ch;
	}
}
void Node::access(){
	current = first;		
	int i = 1;
	while(current){
		cout<<"\nElement "<<i++<<" = "<<current->info;	
		previous = current;			
		current = current ->next;
	}
}

void Node::insertFront(){
	int item;
	temp = new(Node);		
	cout<<"\nEnter the info to insert : "; 		
	cin>>item;
	temp -> info = item;
	temp -> next = first;	
	first = temp;			
}
void Node::insertBetween(){
	int item, r;
	temp = new(Node);					
	cout<<"\nEnter the info to insert : "; 		
	cin>>item;
	temp -> info = item;
	cout<<"\nEnter the info after which you want to insert the element: ";
	cin>> r;
	current = previous = first;
	while (current->info != r){		
		previous = current;			
		current = current ->next;
	}
	if(current->info == r){			
		temp -> next = current ->next;
		current ->next = temp;
	}else
		cout<<"\nItem not found !!";
}
void Node::insertLast(){
	int item;
	temp = new(Node);		
	cout<<"\nEnter the info to insert : "; 		
	cin>>item;
	temp -> info = item;
	current ->next = last = current = previous = temp;
	temp -> next = NULL;
}
void Node::del(){
	int r;
	cout<<"\nEnter the info to delete : "; 		
	cin>>r;
	current = previous = first;		
	while(current -> info != r){
		previous = current;
		current = current ->next;
	}
	if (current -> info == r){
		previous ->next = current -> next;
	} else
		cout<<"\nItem to be deleted not found !";
}

int main(){
	Node n1;
	int ch;
	do{
		cout<<endl<<"\nOne way Linked List\n1- Create\n2- Access\n3- Insert at Front";
		cout<<"\n4- Insert in Between\n5- Insert at Last\n6- Delete item\n7- Exit"<<endl;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				n1.create();
				break;
			case 2:
				n1.access();
				break;
			case 3:
				n1.insertFront();
				break;
			case 4:
				n1.insertBetween();
				break;
			case 5:
				n1.insertLast();
				break;
			case 6:
				n1.del();
				break;
			case 7:
				break;
			default:
				cout<<"\nInvalid choice entered !!";
				break;
		} 
	}while(ch != 7);
	return 0;
}

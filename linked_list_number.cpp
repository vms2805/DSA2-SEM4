


#include <bits/stdc++.h>
using namespace std;

class Node{
	int data;
	Node* next;
	friend class LinkedList;
	public:
	Node(){
		data=0;
		next=NULL;
	}
};

class LinkedList{
	Node* head;
	Node* tail;

	public:
	LinkedList(){
		head=NULL;
		tail=NULL;
	}
	
	void InsertAtEnd(int d){
		if(head==NULL){
			Node *newnode=new Node;
			newnode->data=d;
			newnode->next=NULL;
			head=newnode;
			tail=newnode;
		}else{
			Node *newnode=new Node;
			newnode->data=d;
			newnode->next=NULL;
			tail->next=newnode;
			tail=newnode;
		}
	}
	void InsertAtFront(int d){
		if(head==NULL){
			Node *newnode=new Node;
			newnode->data=d;
			newnode->next=NULL;
			head=newnode;
			tail=newnode;
		}else{
			Node *newnode=new Node;
			newnode->data=d;
			newnode->next=NULL;
			newnode->next=head;
			head=newnode;
		}
	}
	void display(){
		Node *ptr=head;
		while(ptr!=NULL){
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
		cout<<endl;
	}
	bool evencheck(int n){
		int temp=n;
		if(temp%2==0){
			return true;
		}else{
			return false;
		}
	}
	int sum_digit(int n)
    {
        int sum=0;
        while(n>0)
        {
            int place=(n%10);
            sum+=place;
            n=n/10;
        }
         return sum;
    }
	int oddplaceaddition(){
		int ans=0;
		int place=1;
		Node* ptr=head;
		while(ptr!=NULL){
			if((place%2)!=0){
				ans=ans+(ptr->data);
			}
			place++;
			ptr=ptr->next;
		}
		return ans;
	}
	int evenplaceaddition(){
		int ans=0;
		int place=1;
		Node* ptr=head;
		while(ptr!=NULL){
			if((place%2)==0){
				ans=ans+(ptr->data);
			}
			place++;
			ptr=ptr->next;
		}
		return ans; 
	}
	bool primecheck(int n){
		int temp=n;
		if(n==1 or n==0 or n<0){
			return false;
		}else if(n==2){
			return true;
		}else{
			int div;
			for(int i=2;i<=n;i++){
				if(temp%i==0){
					div=i;
					break;
				}
			}
			if(div==n){
				return true;
			}else{
				return false;
			}
		}
	}
	int  primeaddition(){
		int ans=0;
		Node* ptr=head;
		while(ptr!=NULL){
			if(primecheck(ptr->data)){
				ans=ans+ptr->data;
			}
			ptr=ptr->next;
		}
		return ans;
	}
	void deleteoddprime(){
		int temp;
		Node* ptr=head;
		while(ptr!=NULL){
			temp=ptr->data;
			if(temp%2!=0 and primecheck(temp)){
				if(ptr==head){
					head=ptr->next;
					ptr->next=NULL;
				}else{
					Node* ptr2=head;
					while(ptr2->next->data!=ptr->data){
						ptr2=ptr2->next;
					}
					ptr2->next=ptr2->next->next;
				}
			}
			ptr=ptr->next;
		}
	}
};

int main(){
	LinkedList ll;
	int opt;
	char res='y';
	while(res=='y'){
		cout<<"OPTIONS : \n1. Insert a number.\n2. Do addition of odd places numbers and display.\n3. Do addition of even places numbers and display.\n4. Do addition of prime numbers.\n5. Delete odd numbers which are prime.\nChoose an option : "<<endl;
		cin>>opt;
		if(opt==1){
			int num;
			cout<<"Enter number you want to insert : "<<endl;
			cin>>num;
			int ans=ll.sum_digit(num);
			if(ans%2==0){
				ll.InsertAtFront(num);
				cout<<"Number has been inserted at start."<<endl;
				cout<<"List : "<<endl;
			    ll.display();
			}else{
				ll.InsertAtEnd(num);
				cout<<"Number has been inserted at end."<<endl;
				cout<<"List : "<<endl;
			     ll.display();
			}
		}else if(opt==2){
			cout<<"The addition of odd places numbers is : "<<ll.oddplaceaddition()<<endl;
		}else if(opt==3){
			cout<<"The addition of even places numbers is : "<<ll.evenplaceaddition()<<endl;
		}else if(opt==4){
			cout<<"The addition of prime numbers is : "<<ll.primeaddition()<<endl;
		}else if(opt==5){
			ll.deleteoddprime();
			cout<<"Odd prime numbers have been deleted."<<endl;
			cout<<"List : "<<endl;
			ll.display();
		}else{
			cout<<"Please enter valid number!"<<endl;
			continue;
		}
		cout<<"Do you want to continue? y/n"<<endl;
		cin>>res;
	}
	cout<<"Thank you!"<<endl;
	return 0;
}

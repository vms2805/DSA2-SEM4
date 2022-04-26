#include <bits/stdc++.h>
#include <string>
using namespace std;

class Node{
    char data;
    Node* next;
    friend class LinkedList;
    public:
    Node(){
        data='#';
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

    void InsertAtEnd(char d){
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
	void InsertAtFront(char d){
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
    bool lowercasecheck(char d){
        if(d>=97&&d<=122){
            return true;
        }else{
            return false;
        }
    }
    bool uppercasecheck(char d){
        if(d>=65 && d<=90){
            return true;
        }else{
            return false;
        }
    }
    bool consonantcheck(char d){
        if(d=='a' or d=='e' or d=='i' or d=='o' or d=='u' or d=='A' or d=='E' or d=='I' or d=='O' or d=='U'){
            return false;
        }else{
            return true;
        }
    }
    void deluppercaseconsonants(){
        Node* ptr=head;
        while(ptr!=NULL){
            if(uppercasecheck(ptr->data) and consonantcheck(ptr->data)){
                Node* ptr2=head;
				while(ptr2->next->data!=ptr->data){
					ptr2=ptr2->next;
				}
				ptr2->next=ptr2->next->next;
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
		cout<<"OPTIONS : \n1. Input string.\n2. Delete all consonants in upper case.\nChoose an option : "<<endl;
		cin>>opt;
		if(opt==1){
			string ss;
			cout<<"Enter the string : "<<endl;
            cin.ignore();
			getline(cin, ss);
			for(int i=0;i<ss.size();i++){
                if(ll.uppercasecheck(ss[i])){
                    ll.InsertAtEnd(ss[i]);
                    if(not ll.consonantcheck(ss[i])){
                        ll.InsertAtEnd('#');
                    }
                }else if(ll.lowercasecheck(ss[i])){
                    if(not ll.consonantcheck(ss[i])){
                        ll.InsertAtFront('#');
                    }
                    ll.InsertAtFront(ss[i]);
                }
            }
            cout<<"List has been created."<<endl;
            cout<<"List : "<<endl;
			ll.display();
		}else if(opt==2){
			ll.deluppercaseconsonants();
			cout<<"All consonants in upper case have been deleted."<<endl;
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
   string s;
   getline(cin,s);
   cout<<s;
   return 0;
}


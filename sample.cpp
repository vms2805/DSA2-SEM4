#include <iostream>
using namespace std;
class Node{
string word,meaning;
Node *lchild;
Node *rchild;
public:
    Node(){
    lchild=rchild=Nullptr;

    }
    Node(string w,string n){
    word=w;
    meaning=n;

    }

    friend class BST;

};

class BST{
Node *root;
public:
BST(){

root=nullptr;
}
void Insert(string w,string m);
int search(string word,Node*&loc,Node*&parent);

void search_count(string s);

void Inorder_ass(Node *p);

void Inorder(){
    Inorder_ass(root);
}

void Inorder_dec(Node *t);
void Inorder_dec(){
    Inorder_dec(root);
}

void update_meaning(string word,string meaning);

void deleteBst(string key);
void deleteBst1(string key,Node *loc,Node *par);
void deleteBst2(string key,Node *loc,Node *par);

};

void BST::update_meaning(string word,string newmeaning){
    Node *loc=nullptr;
    Node *par=nullptr;
    int c=search(word,loc,par);
    if(loc==nullptr){
        cout<<"element not found"<<endl;
    }
    else{
        loc->meaning=newmeaning;
    }
}

void BST::Inorder_dec(Node *p){
    if(p!=nullptr){
        Inorder_dec(p->rchild);
        cout<<p->word<<" : "<<p->meaning<<endl;
        Inorder_ass(p->lchild);
    }
}

void BST::Inorder_ass(Node *p){

    if(p!=NULL)
    {
        Inorder_ass(p->lchild);
        cout<<p->word<<": "<<p->meaning<<endl;
        Inorder_ass(p->rchild);
    }
}

void BST::Insert(string x, string y)
     {
         if(root==NULL)
         {
             root=new Node(x,y);
         }
         else{
             Node* p;
             Node* q;
             Node* t;
             p=q=root;
             while(p!=NULL)
             {
                 q=p;
                 if(x < p->word)
                 {
                     p=p->lchild;
                 }
                 else{
                     p=p->rchild;
                 }
             }
             if(x< q->word)
             {
                 t=new Node(x,y);
                 q->lchild=t;
             }
             else if(x>q->word)
             {
                 t=new Node(x,y);
                 q->rchild=t;
             }
             else{
                 cout<<"Duplicate data"<<endl;
             }
         }
     }

int BST::search(string word,Node*&loc,Node*&parent){
int count=0;
Node *ptr=root;
if(root==nullptr){
  return 0;
}

else{
    while(ptr!=nullptr){
        count++;
        if(ptr->word==word){
            loc=ptr;
            return count;
        }
        else if(ptr->word>word){
            parent=ptr;
            ptr=ptr->lchild;
        }
        else if(ptr->word<word){
            parent=ptr;
            ptr=ptr->rchild;
        }

    }
}
}

void BST::search_count(string s){
Node *loc=nullptr;
Node *par=nullptr;
int c=search(s,loc,par);
if(loc==nullptr){
    cout<<"element Not found"<<endl;
}
else{
    cout<<"element found after "<<c<<"comparission"<<" has parent "<<par->word<<endl;
}

}

void BST::deleteBst1(string key,Node *loc,Node *par){
Node *child = nullptr;

if(loc->lchild != nullptr)
child = loc->lchild;
else if(loc->rchild != nullptr){
child = loc->rchild;
}

if(par->lchild == loc){
par->lchild = child;
}
else{
par->rchild = child;
}

delete loc;
}

void BST::deleteBst2(string key,Node *loc,Node *par){   //the node which is to be deleted
                                                       //have  both the childs
Node *ptr = loc->rchild,*ptrpar = nullptr;

while(ptr->lchild != NULL){
ptrpar = ptr;
ptr = ptr->lchild;
}

loc->word = ptr->word;
loc->meaning = ptr->meaning;

deleteBst1(ptr->word,ptr,ptrpar);

}

void BST::deleteBst(string key){
Node *loc = nullptr,*par = nullptr;

int c=search(key,loc,par);

if(loc == nullptr){
cout << "Element not found" << "\n";
return;
}

if(loc != nullptr && par==nullptr){
if(loc->rchild == nullptr && loc->rchild == nullptr){
root = nullptr;
return;
}
}

if(loc->lchild != nullptr && loc->rchild != nullptr){
deleteBst2(key,loc,par);                                //both childs are present.
}
else{
deleteBst1(key,loc,par);
}
}

int main()
{
   BST b1;
   int ch;
   string s1,s2;
   do{
      cout<<"enter your choice"<<endl;

      cout<<"you have the following options to perform"<<endl;
      cout<<"1.Inserting into a dectionary"<<endl;
      cout<<"2.Dipslaying the data in asscending order"<<endl;
      cout<<"3.Displaying the data in descending order"<<endl;
      cout<<"4.searching the element"<<endl;
      cout<<"5.Updating the keywords"<<endl;
      cout<<"6.Deleting the keywords"<<endl;
      cin>>ch;
   switch(ch){

   case 1:
   {
       cout<<"enter the number of words you want to enter"<<endl;
       int n;
       cin>>n;

       for(int i=0;i<n;i++){

          cout<<"enter the word you want to enter"<<endl;
          cin>>s1;
          cout<<"enter the meaning you want to enter"<<endl;
          cin>>s2;
          b1.Insert(s1,s2);
      }
       break;
   }
   case 2:
   {
       cout<<"Inorder-traversal for asscending"<<endl;
       b1.Inorder();


       break;
   }
 case 3:
   cout<<"descending order traversal"<<endl;
   b1.Inorder_dec();
   break;

  case 4:
    cout<<"enter the element you want to search "<<endl;
    cin>>s1;
    b1.search_count(s1);
    break;

   case 5:
     cout<<"Updating the meaning of the particular word"<<endl;
     cout<<"enter the word you want to change the meaning"<<endl;
     cin>>s1;
     cout<<"enter the meaning after the change"<<endl;
     cin>>s2;

       b1.update_meaning(s1,s2);
       b1.Inorder();
       break;
   case 6:
       cout<<"enter the keyword you want to delete"<<endl;
       cin>>s1;
       b1.deleteBst(s1);
       cout<<"keyword deleted successfully!"<<endl;
       break;


   }
   }while(ch!=7);
    return 0;
}

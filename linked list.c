    #include<iostream>
    using namespace std;
struct Node{
int data;
Node *next;
};
  int main()
    {
      Node *head=NULL;
      cout<<"Welcome to Linked List Program"<<endl;
    do{
        cout<<"Enter your choice-"<<endl;
        cout<<"1. Insertion\n2. Deletion\n3. Traverse\n0. Exit\n";
      int N;
      cin>>N;
      if(N==0){
      cout<<"Thank You";
      break;
      }
    if(N==3){
    Node *ptr=head;
    cout<<"The list till now is-"<<endl;
    while(ptr->next!=NULL){
    cout<<ptr->data<<"->";
    ptr=ptr->next;
    }
     cout<<ptr->data<<"->";
    cout<<"NULL"<<endl;
    }
    if(N==1){
    cout<<"You have entered choice 1.\nNow choose from given choices-\n1. Insert at beginning\n2. Insert at end\n3. Insert at specific location"<<endl;
    int n;
    cin>>n;
    if(n==1){
    Node *cpt=new Node();
    cin>>cpt->data;
    cpt->next=head;
    head=cpt;
    cout<<"You have entered choice 1.\nNow enter the value to be inserted at beginning\n"<<cpt->data<<" inserted in a linked list at starting position."<<endl;
    }
    else if(n==2){
    Node *cpt=new Node();
    cin>>cpt->data;
    cpt->next=NULL;
    Node *ptr=head;
    while(ptr->next!=NULL){
    ptr=ptr->next;
    }
    ptr->next=cpt;
    cout<<"You have entered choice 2.\nNow enter the value to be inserted at last\n"<<cpt->data<<" inserted in a linked list at last position."<<endl;
    }
    else if(n==3){
    Node *cpt=new Node();
    cpt->next=NULL;
    cin>>cpt->data;
    int x;
    cin>>x;
    int i=2;
    Node *ptr=head;
    while(i<x){
    ptr=ptr->next;
    i++;
    }
    Node *tmp=ptr->next;
    ptr->next=cpt;
    cpt->next=tmp;
    cout<<"You have entered choice 3.\nNow enter the value and location address\n"<<cpt->data<<" inserted in a linked list at "<<x<<" position."<<endl;
    }
    else{
    cout<<"Wrong choice"<<endl;}
    }
     if(N==2){
     cout<<"You have entered choice 2.\nNow choose from given choices-\n1. Delete from start\n2. Delete from end\n3. Delete from specific location"<<endl;
    int n;
    cin>>n;
    if(n==1){
    head=head->next;
    cout<<"You have entered choice 1.\nFirst node deleted"<<endl;
    }
    else if(n==2){
    Node *ptr=head;
    Node *tmp;
    while(ptr->next!=NULL){
    tmp=ptr;
    ptr=ptr->next;
    }
    tmp->next=NULL;
    cout<<"You have entered choice 2.\nLast node deleted"<<endl;
     } 
     else if(n==3){
     cout<<"You have entered choice 3.\nNow enter the location address\n";
    int x;
    cin>>x;
    cout<<x<<" node deleted"<<endl;
    int i=2;
    Node *ptr=head;
    while(i<x){
    ptr=ptr->next;
    i++;
    }
    Node *tmp=ptr->next;
    ptr->next=tmp->next;
     }
     else{
    cout<<"Wrong choice"<<endl;}}
      }while(1);
       
        
        return 0;
    }

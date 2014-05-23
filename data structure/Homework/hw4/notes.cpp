//Inserting a Node

//Deleting a Node


//Copy ALL
template<class T> void copyAll(Node <T> * old_head,Node<T>* & new new_head){
	
	Node<T>* tmp=old_head;
	Node<T>* tmp2=new_head;

	new_head=new Node<T>;
	new_head->value=old_head->value;
	if(old_head->next!=NULL){
		copyAll(old_head->next,new_head->next);
	}
	else{
		new_head->next=NULL;
	}
}

//remove All
template<class T> void RemoveAll(Node<T>*& head){
	if(head==NULL){
	Node <T>* tmp=head->next;
        
	delete head;
	head=tmp;
	RemoveALL(head->next);
	}
}


//Doubly Linked list
template<class T> class Node{
	public:
		Node():next_(NULL),prev(NULL)
		T value_;
		Node<T>* next;
		Node<T>* prev;
}
//Doubly linked insert
void insert(){
	Node<T>* p=new Node<T>;
	Node<T>* tmp=new Node<T>(val);
	tmp->next=p->next;
	tmp->prev=p;
	p->next=tmp;	
	tmp->next=tmp;
}
//
void delete()){
p->prev->next=p->next;
p_next->prev=p->prev;
delete p;
}

// delte in first 
head=NULL;
tail=NULL;

=======================================================================================
  7th March,2014
  
Recursion
    
Merge sort
    while(j<high && i<mid){
    merge(){
     if  values[low]< values[j+1]
         scratch[k]=values[i];
        i++;
        k++;
    else
         scratch[k]=values[j]
            j++;
        k++;
            
    }
    
    }








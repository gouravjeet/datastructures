void Graph::pass_messages(MTRand &mtrand){
	//std::cout<<"WOW I am HERE";
    
	for (std::vector<Person*>::const_iterator p = m_people.begin(); p != m_people.end(); ++p){
        std::list<Person*> friends=((*p)->get_friends());
        std::list<Message*> messages_lst=((*p)->get_messages());
        
        std::list<Message*>::const_iterator it4=messages_lst.back();
        Message* c=messages_lst.back();
        const std::string z=((*c)->get_message());
        int random_num=mtrand.randInt(friends.size());
        // find the random number from the friends list and send the message to that number
        std::list<Person*>::const_iterator it3=friends.begin();
        
        for(int i=0;i<random_num-1;i++){
            it3++;
        }
        
        //Person* p1=it3;
        std::string pers=(*it3)->get_name();
        // we need to add the message into the graph also and that will call message of person.
        // We need to change the owner of the function also
        bool a=add_message(pers,z);
        bool b=((*it3)->remove_message(it4));
        
	}
	
}

template <class T>
TreeNode<T>* in_order_successor(){

    if(n->right==NULL){
        //needs tweaking
        TreeNode<T>* p=n->parent;
        while(p!=NULL && p->value <= n->value){

            p=p->parent;
        }

        return p;
    }
    else{

        TreeNode<T>* tmp=n->right;
        while(tmp->left !=NULL){
            tmp=tmp->left;
        }
        return tmp;
    }

}



















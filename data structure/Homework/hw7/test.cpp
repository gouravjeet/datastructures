void print_order(const TreeNode<T> * p){
	if(p){
	print_order(p->left);
	std::cout<<p->value;
	print_order(p->right);
	}
}
breadth first



while(current.size() !=0){	// tree height
	for(int i=0;i<current.size();i++){ // tree width
	std::cout<<current[i]->value;
	}	
	if(current[i]-.left !=NULL){
	next.push_back(current[i]->left)
	}
	if(current[i]-.right !=NULL){
	next.push_back(current[i]->right)
	}
	}
	current=next;
	next.clear();

}

}
// tree height
//tree width=best case =1
// tree width balanced =n/2
running time-O(N)
memory use-O(n	)
memory use

// n nodes, tree height log n 
template <class T>
T& smallest_value(TreeNode<T> *p){
	assert(p!= NULL)
	if(p->left==NULL)
	return p->value;
	return smallest_value(p->left);
}
template <class T>
int count_odd(const TreeNode<T> *p){
	if(p==NULL) return 0;
	return int(p->value%2==1) + count_odd(p->left) +count_odd(p->right);
}
O(log n) assuming balanced tree
O(n) assuming worst case, unbalanaced tree

//Find function
iterator find(const T& key_value,TreeNode<T>* p)
if(p==NULL) return end();

if(p->value==key_value)
	return tree_iterator<T>(TreeNode<T>* p);// we can use typedef
if(p->value<key_value){
	return find(key_value,p->right);
}
	return find(key_value,p->left);

iterator end() const{
	return iterator(NULL);}
}		
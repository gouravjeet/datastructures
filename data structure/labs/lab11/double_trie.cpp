#include <iostream>
#include <cassert>


// the data structure
class Node {
public:
  int value;
  Node *a;
  Node *b;
  Node *c;
  Node *parent;
};


// a very simple sideways tree visualization
void print(Node *n, const std::string &prefix) {
  if (n == NULL) return;
  if (n->a != NULL) assert (n->a->parent == n);
  if (n->b != NULL) assert (n->b->parent == n);
  if (n->c != NULL) assert (n->c->parent == n);
  print(n->c,prefix+" c ");
  print(n->b,prefix+" b ");
  std::cout << prefix << n->value << std::endl;
  print(n->a,prefix+" a ");
}


// cleanup the whole tree
void destroy(Node *n) {
  if (n == NULL) return;
  destroy (n->a);
  destroy (n->b);
  destroy (n->c);
  delete n;
}


// problem 2.1
bool insert(Node* &root, int value, Node* parent = NULL) 
{
if(root==NULL)
{
  root=new Node();
  root->value=value;
  root->parent=NULL;
  root->a=NULL;
  root->b=NULL;
  root->c=NULL;
  return true;
}
if(root->value > value && root->a == NULL)
{
  Node * new_node=new Node();
  new_node->value=value;
  new_node->parent=root;
  root->a=new_node;
  new_node->a=NULL;
  new_node->b=NULL;
  new_node->c=NULL;
  return true;
}
else if(root->value > value && root->a != NULL)
{
  insert(root->a, value);
}
if(root->value < value && value<=root->value*2 && root->b == NULL)
{
  Node * new_node=new Node();
  new_node->value=value;
  new_node->parent=root;
  root->b=new_node;
  new_node->a=NULL;
  new_node->b=NULL;
  new_node->c=NULL;
  return true;
}
else if(root->value < value && value<=root->value*2 && root->b != NULL)
{
  insert(root->b, value);
}
if(value > 2*root->value && root->c == NULL)
{
  Node * new_node=new Node();
  new_node->value=value;
  new_node->parent=root;
  root->c=new_node;
  new_node->a=NULL;
  new_node->b=NULL;
  new_node->c=NULL;
  return true;
}
else if(value > 2*root->value && root->c != NULL)
{
  insert(root->c, value);
}
}


// problem 2.2
Node* find_largest(Node *root) 
{
if(root==NULL || (root->b==NULL && root->c==NULL))
{
  return root;
}
if(root->c==NULL && root->b!=NULL)
{
  find_largest(root->b);
}
else
{
  find_largest(root->c);
}
}


// problem 2.3
Node* find_previous(Node *root) 
{
  if(root==NULL)
  {
    return root;
  }
  Node * parent=root->parent;
  if(root->a != NULL)
  {
    return find_largest(root->a);
  }
  if(parent==NULL)
  {
    return parent;
  }
  if(parent->c!=NULL && parent->c->value==root->value)
  {
    if(parent->b!=NULL)
      return find_largest(parent->b);
    else
      return parent;
  }
   if(parent->b!=NULL && parent->b->value==root->value)
  {
      return parent;
  }
  if(parent->a!=NULL && parent->a->value==root->value)
  {
      return find_previous(parent);
  }
}



int main() {

  Node* root = NULL;

  // create the diagram on the test handout
  insert(root,30);
  insert(root,10);
  insert(root,32);
  insert(root,70);
  insert(root,5);
  insert(root,16);
  insert(root,24);
  insert(root,31);
  insert(root,52);
  insert(root,64);
  insert(root,92);
  insert(root,200);
  insert(root,12);
  insert(root,19);
  insert(root,45);
  insert(root,59);
  insert(root,150);
  insert(root,210);
  insert(root,450);
  insert(root,13);
  insert(root,4);
  insert(root,1);

  // print the tree before iteration
  print(root,"");
  std::cout << std::endl;
  std::cout << std::endl;

  // loop over the structure
  int count = 0;
   Node *tmp = find_largest(root);
   std::cout<<tmp->value;
  int prev = tmp->value;
  while (tmp != NULL) {
    std::cout << tmp->value << " ";
    tmp = find_previous(tmp);
    if (tmp != NULL) { 
      assert (prev > tmp->value);
      prev = tmp->value;
    }
    count++;
  }
  std::cout << std::endl;
  assert (count == 22);

  // cleanup so we have no memory leaks
  destroy (root);
}
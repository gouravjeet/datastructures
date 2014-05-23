#ifndef priority_queue_h_
#define priority_queue_h_

#include <iostream>
#include <vector>
#include <cassert>


template <class T>
class priority_queue {
private:
  std::vector<T> m_heap;

public:
  priority_queue() {}

  priority_queue( std::vector<T> const& values )
  {
    for (int i = 0; i < values.size(); ++i)
    {
      push(values[i]);
    }
  }

  const T& top() const 
  {
    assert( !m_heap.empty() );
    return m_heap[0]; 
  }

  void push( const T& entry )
  {

    m_heap.push_back(entry);
    
    int current=(m_heap.size()-1);
    int parent=(current-1)/2;

    while(current>=0 && current!=parent)
          {
            if(m_heap[current]<m_heap[parent]){
              T m=m_heap[parent];
              m_heap[parent]=m_heap[current];
              m_heap[current]=m;
                
                if(parent>2){
                current=parent;
                parent=(current-1)/2;
                }
                else{
                  current=parent;
                  parent=0;
                }
            }
            else{
              break;
            }

          }
  }

  void pop() 
  {
    assert( !m_heap.empty() );
      m_heap[0]=m_heap[m_heap.size()-1];
    m_heap.pop_back();
     if (m_heap.size()<=1)
    {
      return;
    }
    int current=0;
    int child=0;
    while(2*current+1<m_heap.size())
    {
      if(2*current+2<m_heap.size() && m_heap[2*current+2]<m_heap[2*current+1])
      {
        child=2*current+2;
      }
      else
      {
        child=2*current+1;
      }
      if(m_heap[current]>m_heap[child])
      {
        T temp=m_heap[current];
        m_heap[current]=m_heap[child];
        m_heap[child]=temp;
        current=child;
      }
      else
      {
        break;
      }
    }
   
}
  int size() { return m_heap.size(); }
  bool empty() { return m_heap.empty(); }


  //  The following three functions are used for debugging.

  //  Check to see that internally the heap property is realized.
  bool check_heap( )
  {
    return this->check_heap( this->m_heap );
  }

  //  Check an external vector to see that the heap property is realized.
  bool check_heap( const std::vector<T>& heap )
  {
    int count=0;
    
    int current=(m_heap.size()-1);
    int parent=(current-1)/2;
    
      while(current>=0 && current!=parent)
          {
            if(m_heap[current]<m_heap[parent]){
                
                if(parent>2){
                current=parent;
                parent=(current-1)/2;
                count++;
                }
                else{
                  current=parent;
                  parent=0;
                }
            }
            else{
              break;
            }

          }
    


    // for(int i=0;i<(heap.size());i++){
    //   //left child and right child needs to be checked that if it is greater than or equal to the parent
    //   if(heap[(i-1)/2]>=heap[i]){

    //   }
    //   else{
    //     count++;
    //   }
    // }
    if(count>0){
      return false;
    }
    return true;
  }

  //  A utility to print the contents of the heap.  Use it for debugging.
  void print_heap( std::ostream & ostr )
  {
    for ( unsigned int i=0; i<m_heap.size(); ++i )
      ostr << i << ": " << m_heap[i] << std::endl;
  }
  
};


template <class T>
void heap_sort( std::vector<T> & v )
{
  priority_queue<float> a(v);
  for (int i = 0; i < v.size(); ++i)
  {
    v[i]=a.top();
    a.pop();
  }
}

#endif
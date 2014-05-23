// Simple implementation of the Table class 
#include <vector>

template <class T> class Table{
	public:
		//TYPEDEFS
		typedef T* iterator;
		typedef const T* const_iterator;
		tydef unsigned int size_type;
		// Constructors, assignment operators and Destructor
		
		Table(size_type rows,size_type cols, const T& t=T()){ this->create(rows,cols,t);}
		Table(const Table& t) { copy(t); }
		const Table& operator={const Table& t};
		~Table(){delete [] m_data;}

		//Member functions and other operators
		
		void push_back_row(const std::vector<T> & v);
		void push_back_column(const std::vector<T> & v);
		void pop_back_row();
		void pop_Back_column();
		
		
		private:
		
		void create(size_type row,size_type cols,const T& val);
		void copy(const Table<T>& t);
		//Private Member Functions

		//Representation
		T **values;  // Pointer to first location in the allocated array
		size_type m_rowsize;		// No of rows stored 
		size_type m_colsize;		// No of columns stored
		size_type m_alloc ;					
		
}; 
// create an empty Table(null pointers everywhere)
/*template <class T>  void Table<T>::create() {
  m_data = NULL;
  m_rowsize = 0;  // No memory allocated yet
  m_colsize = 0;
}
*/
// Create a table with rows and column, each location having the given value
template <class T> void Table<T>::create(size_type m_rowsize, size_type m_colsize, const T& val) {
  values = new T*[m_rowsize];
  m_rowsize=m_alloc_row;
  m_colsize=m_alloc_col;
  for (int i = 0; i<m_rowsize; i++)
    {
    	values[i]= new T[m_colsize];

    	for(int j=0;j<m_colsize;j++)
    	{
    		 values[i][j]= val;
    	}
    } 
}


template <class T> void Table<T>::push_back_row(const Vector<T>& vec){
	
	// Allocate and copy the old array
	
	m_rowsize=m_rowsize+1;
	T** new_data= new T[m_rowsize];

	for(size_type i=0;i<m_rowsize-1;++i)
	{
		new_data[i]=values[i];
	}
	
	T *p=new T[m_colsize];
	for(unsigned int i=0;i<vec.size();i++){
			*(p+i)=vec[i];
	}
	// I think that values will point to the pointers of vectors
	//Delete the old array and reset the pointers
	delete [] values;
	values=new_data;
	// Add the row at the end of the array
	values[m_rowsize-1]=p;
}
/*
template <class T> void Table<T>::push_back_column(const T& t){

}
template <class T> void Table<T>::pop_back_row(){

}
template <class T> void Table<T>::pop_Back_column(){

}
*/





void compute_squares(unsigned int *c,unsigned int *b,unsigned int n){
  for(unsigned int i=0;i<n;i++){
    *(b+i)=(*(c+i) * *(c+i));
    std::cout<< *(b+i);
  }
}

unsigned int n=5;
  unsigned int c[]={2,3,5} ;
  unsigned int b[n] ;

  compute_squares(c[],b[n],n);
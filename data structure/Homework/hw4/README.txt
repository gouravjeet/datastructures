HOMEWORK 4: DVD LISTS


NAME:  < Gouravjeet Singh >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Aayush Chaabra,Sameer,Chetan,Krishna,Yuvraj >

Remember: Your implementation for this assignment must be done on your
Maown, as described in "Academic Integrity for Homework" handout.


ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < insert 20 hours >


ORDER NOTATION:
For each function, using the variables:
  d = number of different movie DVD titles
  k = average or maximum copies of each DVD
  c = number of customers
  p = average or maximum movies ranked on each customer’s preference list
Include a short description of your order notation analysis.

dvd: O(d)-> Only one if else loop 

customer: O(p+c)-> loop through p movies plus c customers

add_preference:O(d+c+p)->first it will find customers and then it will check for movies in inventory and for maximum ,it will check for maximum and O(p) for movies on preference list and o(1) operations

ship:O(p*d*c)-> It will loop through all the customers and then it will loop through preference list and then it will find the dvd from the inventory

return_oldest:O(c+d)-> first it will find the customers and find the inventory

return_newest:O(c+d)-> first it will find the customers and find the inventory

print_customer:O(c+p)-> first it will find the customers and then it will go through preference list 

print_dvd:O(d)-> it will print the dvd by finding the dvd



EXTRA CREDIT:
Describe the analysis you performed on customer satisfaction.  Paste
in a small amount of sample analysis output and/or specify a sample
output file.  Describe your improved algorithm and compare the
analysis results of your new algorithm.  Please be concise!



MISC. COMMENTS TO GRADER:  
Optional, please be concise!







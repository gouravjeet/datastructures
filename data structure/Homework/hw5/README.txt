HOMEWORK 5: LINKED TRAIN CARS


NAME:  < Gouravjeet Singh >


COLLABORATORS AND OTHER RESOURCES:
List the names of everyone you talked to about this assignment
(classmates, TAs, ALAC tutors, upperclassmen, students/instructor via
LMS, etc.), and all of the resources (books, online reference
material, etc.) you consulted in completing this assignment.

< Sameer Sawla, Krishna, Chetan, Saurabh, Yuvraj , Aayush, Max >

Remember: Your implementation for this assignment must be done on your
own, as described in "Academic Integrity for Homework" handout.



ESTIMATE OF # OF HOURS SPENT ON THIS ASSIGNMENT:  < 19 >



DESCRIPTION OF IMPROVED SHIPFREIGHT ALGORITHM FOR EXTRA CREDIT
Aiming for optimal (fastest train speed and fewest number of engines
and trains) for any input.

Till now i have implemented the train will allocate the engine and then will keep adding freight till it ends.
Mor eimproved algorith would be to automate the process by calculating the number of  
Your second priority is to perform the fewest
link/unlink operations and minimize the length of track that cars must be dragged to complete the separation
task. Note there may be multiple different good solutions to a particular input.
I would prioritx the task by minimizing the number of operations done ie linking and unlinking operations.


DESCRIPTION OF IMPROVED SEPARATE ALGORITHM FOR EXTRA CREDIT
Aiming for optimally comfortable trains (smaller values for average
distance to dining and larger values for closest engine to sleeper)
and/or handling cases with > 2 engines.

I have implemented the separte function by separating one engine and then allocating sleeper class and then allocating dining so that customers will be more comfortable and engine is far away from sleeper. 
In case that there are more than 2 engine, it will divide it into 2 and 1 engine.
Also, separating the engine. Because the original train in this example had an odd number of non-engine cars, no more speed-equal
separation of cars is possible. Of course not all equal-speed train separations are as simple as cutting one
link. Sometimes multiple links must be cut and cars must be pushed around the yard and re-attached in a
different configuration.
I have written the separate test but it is not working well.

MISC. COMMENTS TO GRADER:  
Optional, please be concise!

There are no memory leaks in my code but due to separate , they are coming.


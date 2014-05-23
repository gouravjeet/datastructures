// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//
//    This file provides the code for ASCII art printing of trains.
//    You should implement all of the functions prototyped in
//    "traincar_prototypes.h" in this file.
//
// =======================================================================


#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include "traincar.h"
#include "traincar_prototypes.h"


// =======================================================================
// =======================================================================

// This helper function checks that the forward and backward pointers
// in a doubly-linked structure are correctly and consistently assigned.
void SanityCheck(TrainCar* train) {
  // an empty train is valid
  if (train == NULL) return;
  assert (train->prev == NULL);
  TrainCar *tmp = train;
  while (tmp->next != NULL) {
    // the next train better point back to me
    assert (tmp->next->prev == tmp);
    tmp = tmp->next;
  }
}



// This helper function prints one of the 5 rows of the TrainCar ASCII art
void PrintHelper(TrainCar* t, int which_row) {
  if (t == NULL) {
    // end of the line
    std::cout << std::endl;
    return;
  }

  if (which_row == 0) {
    // the top row only contains "smoke" for engine traincars
    if (t->isEngine()) {
      std::cout << "     ~~~~";
    } else {
      std::cout << "         ";
    }
  } else if (which_row == 1) {
    // the 2nd row only contains the smoke stack for engine traincars
    if (t->isEngine()) {
      std::cout << "    ||   ";
    } else {
      std::cout << "         ";
    }
  } else if (which_row == 2) {
    // the 3rd row contains the ID for each traincar
    // (and engine traincars are shaped a little differently)
    if (t->isEngine()) {
      std::cout << "   " << std::setw(6) << std::setfill('-') << t->getID();
    } else {
      std::cout << std::setw(9) << std::setfill('-') << t->getID();
    }
    std::cout << std::setfill(' ');
  } else if (which_row == 3) {
    // the 4th row is different for each TrainCar type
    if (t->isEngine()) {
      std::cout << " / ENGINE";
    } else if (t->isFreightCar()) {
      // freight cars display their weight
      std::cout << "|" << std::setw(5) << t->getWeight() << "  |";
    } else if (t->isPassengerCar()) {
      // passenger cars are simple empty boxes
      std::cout << "|       |";
    } else if (t->isDiningCar()) {
      std::cout << "|  dine |";
    } else {
      assert (t->isSleepingCar());
      std::cout << "| sleep |";
    }
  } else if (which_row == 4) {
    // final row is the same for all cars, just draw the wheels
    std::cout << "-oo---oo-";
  }

  // between cars display the '+' link symbol on the 5th row 
  // (only if there is a next car)
  if (t->next != NULL) {
    if (which_row == 4) {
      std::cout << " + ";
    } else {
      std::cout << "   ";
    }
  }

  // recurse to print the rest of the row
  PrintHelper(t->next, which_row);
}


void PrintTrain(TrainCar* train) {
  
  if (train == NULL) { 
    std::cout << "PrintTrain: empty train!" << std::endl; 
    return; 
  }

  // Print each of the 5 rows of the TrainCar ASCII art
  PrintHelper(train, 0);
  PrintHelper(train, 1);
  PrintHelper(train, 2);
  PrintHelper(train, 3);
  PrintHelper(train, 4);

    
  // UNCOMMENT THESE ADDITIONAL STATISTICS AS YOU WORK

  int total_weight = 0;
  int num_engines = 0;
  int num_freight_cars = 0;
  int num_passenger_cars = 0;
  int num_dining_cars = 0;
  int num_sleeping_cars = 0;
  CountEnginesAndTotalWeight(train, total_weight,num_engines,num_freight_cars, num_passenger_cars, num_dining_cars, num_sleeping_cars);
  int total_cars = num_engines+num_freight_cars+num_passenger_cars+num_dining_cars+num_sleeping_cars;
  float speed = CalculateSpeed(train);
  std::cout << "#cars = " << total_cars;
  std::cout << ", total weight = " << total_weight;
  std::cout << ", speed on 2% incline = " << std::setprecision(1) << std::fixed << speed;

  // If there is at least one passenger car, print the average
  // distance to dining car statistic
  if (num_passenger_cars > 0) {
    float dist_to_dining = AverageDistanceToDiningCar(train);
    if (dist_to_dining < 0) {
      // If one or more passenger cars are blocked from accessing the
      // dining car (by an engine car) then the distance is infinity!
      std::cout << ", avg distance to dining = inf";
    } else {
      std::cout << ", avg distance to dining = " << std::setprecision(1) << std::fixed << dist_to_dining;
    }
  }

  // If there is at least one sleeping car, print the closest engine
  // to sleeper car statistic
  if (num_sleeping_cars > 0) {
    int closest_engine_to_sleeper = ClosestEngineToSleeperCar(train);
    std::cout << ", closest engine to sleeper = " << closest_engine_to_sleeper;
  }

  std::cout << std::endl;
  
}
//To be defined
int ClosestEngineToSleeperCar(TrainCar* train){
  TrainCar* p=train;

  //std::cout<<"*"<<p->getID()<<std::endl;
  while(p!=NULL ){
        if((p->isSleepingCar())){
          break;
        }
      //  std::cout<<"*"<<p->getID();
    //std::cout<<"*"<<p->getID()<<std::endl;    
        p=p->next;

  }
  //std::cout<<"*"<<p->getID();
  
  //std::cout<<"^^";
  TrainCar* q=p;
  TrainCar* r=p;
  //std::cout<<"((("<<r->getID()<<")))";
  //std::cout<<"((("<<q->getID()<<")))";
  while(q->prev!=NULL ){
    if(q->isEngine()){
      break;
    }
    q=q->prev;
  }
  while(r->next!=NULL ){
    if(r->isEngine())
    {
      break;
    }
    r=r->next;
  }
  //std::cout<<std::endl<<r->getID();
 
  int diff1=(r->getID())-(p->getID());
  //std::cout<<std::endl<<diff1<<"^";
  int diff2=(p->getID())-(q->getID());
  if(diff1!=0){
    if(diff2>diff1){
    return diff1;
  }
  else
  {
    return diff2;
  }
  }
  else{
    return diff2;
  }
  
}
float AverageDistanceToDiningCar(TrainCar* train)
{
  int count=0;
  int total=0;
  float avg=0.0;
  TrainCar* p=train;
  while(p!=NULL ){
        if((p->isDiningCar())){
          break;
        }  
        p=p->next;
  }
    TrainCar* q=p;
    TrainCar* r=p;
    while(q->prev!=NULL ){
    if(q->isPassengerCar()){
      count++;
      int diff1=(p->getID())-(q->getID());
      total=total+diff1;
    }
    q=q->prev;
  }
  while(r->next!=NULL ){
    if(r->isPassengerCar())
    {
      count++;
      int diff2=(r->getID())-(p->getID());
      total=total+diff2;
    }
    r=r->next;
  }
  avg=(float)total/(float)count;
 return avg;
}
// =======================================================================
// =======================================================================

void PushBack(TrainCar* &simple, TrainCar* tr){
    //test for empty list
   
    if(simple==NULL){
      simple=tr;
      tr->next=NULL;
      simple->prev=NULL;
    }
    else{
      TrainCar *p=simple;
      while(p->next!=NULL)
      {
        //It will walk through the end of the linked list 
      p=p->next;
      
      }
      p->next=tr;
      tr->prev=p;
    }

}

std::vector<TrainCar*> ShipFreight(TrainCar* & all_engines,TrainCar* & all_freight, float min_speed, int cars){
  
  std::vector<TrainCar *> a;
  TrainCar* temp;
  TrainCar* temp1;
  TrainCar* temp2;
  TrainCar* newtrain;
  float speedtrain;
  
  while(all_freight->next!=NULL)
  {
  temp=all_engines;
  all_engines=all_engines->next;
  temp->next=NULL;
  temp->prev=NULL;
  all_engines->prev=NULL;
  speedtrain=CalculateSpeed(temp);
    

          while(all_freight->next!=NULL && CalculateSpeed(temp)>60)
          {
                temp1=all_freight;
                all_freight=all_freight->next;
                temp1->next=NULL;
                temp1->prev=NULL;
                all_freight->prev=NULL;
                
                temp2=temp;
                while(temp2->next!=NULL)
                {
                  temp2=temp2->next;
                }

              

                temp2->next=temp1;
                temp1->prev=temp2;

                if(CalculateSpeed(temp)<60)
                {
                  temp2->next=NULL;
                  temp1->next=all_freight;
                  temp1->next->prev=temp1;
                  all_freight=all_freight->prev;
                  break;
                }

                
          }


        //std::cout<<temp1->getID()<<"))";
          a.push_back(temp);  


}

  // Since we need to use only 5 engines , we divide it into 2 2 1
  //Engine is 1 and first we will calculate the weight according to the minimum speed given for each train engine
  return a;
}

void Separate(TrainCar* train1,TrainCar* train2,TrainCar* train3){

}
void CountEnginesAndTotalWeight(TrainCar* & train,int & total_weight,int & num_engines,int & num_freight_cars,int & num_passenger_cars,int & num_dining_cars,int & num_sleeping_cars){
  TrainCar* p=train;
  while(p!=NULL){
    if(p->isEngine()){ num_engines++;}
    else if(p->isFreightCar()){ num_freight_cars++;
      total_weight=total_weight+p->getWeight();
      }
    else if(p->isPassengerCar()){ num_passenger_cars++;}
    else if(p->isDiningCar()){ num_dining_cars++;}
    else if(p->isSleepingCar()){ num_sleeping_cars++;}
    
    p=p->next;
  }

  total_weight=(num_engines*150)+(num_freight_cars* 50)+(num_dining_cars*50)+(num_passenger_cars*50)+(num_sleeping_cars*50);

}
float CalculateSpeed(TrainCar* & train){
  double horsepower=0.0;
  float speed=0.0;
  int total_weight = 0;
  int num_engines = 0;
  int num_freight_cars = 0;
  int num_passenger_cars = 0;
  int num_dining_cars = 0;
  int num_sleeping_cars = 0;
  CountEnginesAndTotalWeight(train, total_weight,num_engines,num_freight_cars, num_passenger_cars, num_dining_cars, num_sleeping_cars);
  horsepower=num_engines*3000;
  //std::cout<<horsepower;
  double abc=(double)(horsepower*550*3600);
  double def=(double)(20*2*5280*total_weight);
  double m=abc/def;
  speed=(float)m;
  
  return speed;
}
void DeleteAllCars(TrainCar* simple){
  if(simple!=NULL){
    TrainCar* tmp=simple->next;
    
    //simple->next->prev=tmp;
    delete simple;
    simple=tmp;
    DeleteAllCars(simple);
  } else return;
}


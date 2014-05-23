// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//                 This file is #include'd from traincar.h
//
// =======================================================================
//
// There are a number of additional functions used in main.cpp that
// you need to declare and implement.  Study main.cpp and the provided
// output to determine the arguments, return type, and overall
// behavior.
//
// Add all required additional function prototypes here
// (you may also add your own helper function prototypes here too)
//
// Implement these functions in "traincar.cpp"
//

#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <vector>
#include "traincar.h"
// pseudo-random number generator

void PushBack(TrainCar* &simple, TrainCar* tr);
int ClosestEngineToSleeperCar(TrainCar* train);
float AverageDistanceToDiningCar(TrainCar* train);
std::vector<TrainCar*> ShipFreight(TrainCar* & all_engines,TrainCar* & all_freight, float min_speed, int cars);
void Separate(TrainCar* train1,TrainCar* train2,TrainCar* train3);
float CalculateSpeed(TrainCar* & train1);		
void CountEnginesAndTotalWeight(TrainCar* & train,int & total_weight,int & num_engines,int & num_freight_cars,int & num_passenger_cars,int & num_dining_cars,int & num_sleeping_cars);
void DeleteAllCars(TrainCar* simple);

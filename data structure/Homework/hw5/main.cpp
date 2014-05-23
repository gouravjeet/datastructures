// =======================================================================
//
// IMPORTANT NOTE: You should edit this file to uncomment test cases
//    and add your own additional test cases
//
// =======================================================================

#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include <vector>

// pseudo-random number generator
#include "MersenneTwister.h"

#include "traincar.h"


// Testing Function Prototypes
void SimpleTrainTest();
void ShipFreightTest(MTRand &mtrand);
void SeparateTests();
void StudentTests();


// Helper Functions for the Separate Tests
void SeparateTestHelper(TrainCar* &t, const std::string &which_test);
std::vector<int> RecordIDs(TrainCar* t1);
void SeparateStatistics(const std::vector<int> &original,
                        const std::vector<int> &left,
                        const std::vector<int> &right,
                        int &num_unlinks, int &num_links, int &num_shifts);

// =======================================================================
// =======================================================================

int main() {

  SimpleTrainTest();

  
  // We make two different pseudo-random number generators.
  // With a fixed seed, we will see the same sequence of numbers
  // everytime we run the program (very helpful for debugging).
  MTRand mtrand_fixed_seed(24);
  // Alternatively, we can let the seed be set from the computer
  // clock, so the number sequence will constantly change.
  MTRand mtrand_autoseed;

  // you can change the random number generator...
  ShipFreightTest(mtrand_fixed_seed);
  //ShipFreightTest(mtrand_autoseed);
  

  
  SeparateTests();
  

  StudentTests();

  return 0;
}

// =======================================================================
// =======================================================================

void SimpleTrainTest() {
  std::cout << "============================================================================" << std::endl;
  std::cout << "SIMPLE TRAIN TEST" << std::endl;

  // create a train with 6 dynamically-allocated cars in a doubly-linked list structure
  TrainCar* simple = NULL;
  PushBack(simple, TrainCar::MakeEngine()); 
  PushBack(simple, TrainCar::MakePassengerCar());
  PushBack(simple, TrainCar::MakePassengerCar());
  PushBack(simple, TrainCar::MakeDiningCar());
  PushBack(simple, TrainCar::MakePassengerCar());
  PushBack(simple, TrainCar::MakeSleepingCar());
   assert (simple->isEngine());
  assert (simple->prev == NULL);
  assert (simple->next->isPassengerCar());
  assert (simple->next->prev->isEngine());
  assert (simple->next->next->isPassengerCar());
  assert (simple->next->next->next->isDiningCar());
  assert (simple->next->next->next->next->isPassengerCar());
  assert (simple->next->next->next->next->next->isSleepingCar());
  assert (simple->next->next->next->next->next->next == NULL);
  assert (simple->next->getID() == simple->getID()+1);
  assert (simple->next->next->getID() == simple->next->getID()+1);
  assert (simple->next->next->next->getID() == simple->next->next->getID()+1);
  assert (simple->next->next->next->next->getID() == simple->next->next->next->getID()+1);
  assert (simple->next->next->next->next->next->getID() == simple->next->next->next->next->getID()+1);

  SanityCheck(simple);
  PrintTrain(simple);

  // fully delete all TrainCar nodes to prevent a memory leak
  DeleteAllCars(simple);
}

// =======================================================================
// =======================================================================


// This function takes a random number generator to create variety in
// the freight car weights
void ShipFreightTest(MTRand &mtrand) {
  std::cout << "============================================================================" << std::endl;
  std::cout << "SHIP FREIGHT TEST" << std::endl;

  // create a chain with 10 engines
  TrainCar* all_engines = NULL;
  for (int i = 0; i < 10; i++) {
    PushBack(all_engines, TrainCar::MakeEngine());
  }
  // create a chain with 25 freight cars
  TrainCar* all_freight = NULL;
  for (int i = 0; i < 25; i++) {    
    // the weight for each car is randomly generated in the range of 30->100 tons
    int weight = 30 + mtrand.randInt(14)*5;
    PushBack(all_freight, TrainCar::MakeFreightCar(weight));
  }

  // rearrange the two structures into a collection of trains
  // with minimum speed 60 mph & maximum length 12 cars
  std::vector<TrainCar*> trains = ShipFreight(all_engines, all_freight, 60, 12);

  // print the remaining engines or freight cars
  if (all_engines != NULL) {
    std::cout << "Remaining Unused Engines:" << std::endl;
    SanityCheck(all_engines);
    PrintTrain(all_engines);
  }
  if (all_freight != NULL) {
    std::cout << "Remaining UnShipped Freight:" << std::endl;
    SanityCheck(all_freight);
    PrintTrain(all_freight);
  }

  // print the trains
  std::cout << "Prepared Trains for Shipment:" << std::endl;  
  for (unsigned int i = 0; i < trains.size(); i++) {
    SanityCheck(trains[i]);
    PrintTrain(trains[i]);
  }

  // fully delete all TrainCar nodes to prevent memory leaks
  DeleteAllCars(all_engines);
  DeleteAllCars(all_freight);
  for (unsigned int i = 0; i < trains.size(); i++) {
    DeleteAllCars(trains[i]);
  }
}


// =======================================================================
// =======================================================================


// A coordinating function for testing multiple different
// configurations of input for Separate
void SeparateTests() {

  TrainCar* t;

  t = NULL;
  PushBack(t, TrainCar::MakeEngine()); 
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeEngine());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakePassengerCar());
  SeparateTestHelper(t, "#1");
  
  t = NULL;  
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeEngine());  
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  PushBack(t, TrainCar::MakeEngine());  
  SeparateTestHelper(t, "#2");

  t = NULL;
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeEngine());  
  PushBack(t, TrainCar::MakeEngine());  
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  SeparateTestHelper(t, "#3");

  t = NULL;
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  PushBack(t, TrainCar::MakeEngine());  
  PushBack(t, TrainCar::MakeEngine());  
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  SeparateTestHelper(t, "#4");

  t = NULL;
  PushBack(t, TrainCar::MakeEngine());  
  PushBack(t, TrainCar::MakeEngine());  
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeDiningCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakePassengerCar());
  PushBack(t, TrainCar::MakeSleepingCar());
  SeparateTestHelper(t, "#5");

  // Note: SeparateTestHelper takes care of deleting all memory
  // associated with these tests
}


// Each different input train configuration to Separate is handled similarly
void SeparateTestHelper(TrainCar* &train1, const std::string &which_test) {
  std::cout << "============================================================================" << std::endl;
  std::cout << "SEPARATE TRAINS " << which_test << std::endl;

  SanityCheck(train1);
  // record the original IDs for later comparison and statistics calculation
  std::vector<int> original = RecordIDs(train1);
  PrintTrain(train1);
  float speed_original = CalculateSpeed(train1);
  
  TrainCar* train2;
  TrainCar* train3;
  Separate(train1, train2, train3);
  assert (train1 == NULL);
  SanityCheck(train2);
  SanityCheck(train3);
  // record the IDs after separation
  std::vector<int> left = RecordIDs(train2);
  std::vector<int> right = RecordIDs(train3);

  // calculate the number of links, unlinks, and train shifts
  // (all of these counts should be kept small to minimize train yard costs
  int num_unlinks, num_links, num_shifts;
  SeparateStatistics(original, left, right, num_unlinks, num_links, num_shifts);
  std::cout << "Separate Statistics: num unlinks = " << num_unlinks;
  std::cout << ", num links = " << num_links;
  std::cout << ", num shifts = " << num_shifts << ", " << std::endl;

  float speed_left = CalculateSpeed(train2);
  float speed_right = CalculateSpeed(train3);
  float left_percent = 100.0 * (speed_original-speed_left) / speed_original;
  float right_percent = 100.0 * (speed_original-speed_right) / speed_original;
  if (speed_left < 0.99*speed_original) {
    assert (speed_right > speed_original);
    std::cout << "  left train is " << std::setprecision(1) << std::fixed << left_percent 
              << "% slower than the original and the right train is " << std::setprecision(1) << std::fixed 
              << -right_percent << "% faster than the original." << std::endl;
  } else if (speed_right < 0.99*speed_original) {
    assert (speed_left > speed_original);
    std::cout << "  right train is " << std::setprecision(1) << std::fixed << right_percent 
              << "% slower than the original and the left train is " << std::setprecision(1) << std::fixed 
              << -left_percent << "% faster than the original." << std::endl;
  } else {
    std::cout << "  left and right train speeds are equal to the original." << std::endl;
  }


  PrintTrain(train2);
  PrintTrain(train3);
  // cleanup memory usage
  DeleteAllCars(train2);
  DeleteAllCars(train3);
}


// A helper function to store the IDs for later separate statistics comparison
std::vector<int> RecordIDs(TrainCar* t1) {
  std::vector<int> answer;
  TrainCar* tmp = t1;
  // loop over all the train cars and store the car IDs in a vector
  while (tmp != NULL) {
    answer.push_back(tmp->getID());
    tmp = tmp->next;
  }    
  return answer;
}


// Given the vectors of IDs before & after separation, verify that no
// cars are missing or duplicated, and determine the number of unlink,
// link, and train shifts that are necessary to create these two trains
void SeparateStatistics(const std::vector<int> &original,
                          const std::vector<int> &left,
                          const std::vector<int> &right,
                          int &num_unlinks, int &num_links, int &num_shifts) {

  // Simple checks on the number ot total cars in the trains
  if (original.size() < (left.size() + right.size())) {
    std::cerr << "ERROR: One or more extra cars after Separate" << std::endl;
    return;
  }
  if (original.size() > (left.size() + right.size())) {
    std::cerr << "ERROR: One or more missing cars after Separate" << std::endl;
    return;
  }

  // initialize the counter variables
  num_links = 0;
  num_unlinks = 0;
  num_shifts = 0;

  // loop over all of the cars in the original train
  for (int i = 0; i < int(original.size()); i++) {
    int found = false;
    // before and after will store the car's new neighbors
    int before = -1;
    int after = -1;
    // find this car in the left or right separated trains
    for (int j = 0; j < int(left.size()); j++) {
      if (original[i] == left[j]) {
        assert (found == false);
        found = true;
        num_shifts += abs(i-j);
        if (j > 0) before = left[j-1];
        if (j < int(left.size())-1) after = left[j+1];
      }
    }
    for (int k = 0; k < int(right.size()); k++) {
      if (original[i] == right[k]) {
        assert (found == false);
        found = true;
        num_shifts += abs(i-(int(left.size())+k));
        if (k > 0) before = right[k-1];
        if (k < int(right.size())-1) after = right[k+1];
      }
    }

    if (found == false) {
      std::cerr << "ERROR: Missing ID=" << original[i] << std::endl;
      return;
    }

    // special cases for first & last car links
    if (i == 0 && before != -1) { num_links++; }
    if (i == int(original.size())-1 && after != -1) { num_links++; }
    // middle links
    if (i > 0) {
      if (original[i-1] != before) { 
        num_unlinks++;
        if (before != -1) num_links++;
      }
    }
  }
  // don't double count shifts (swapping neighboring cars counts as a
  // shift of 1 unit)
  assert (num_shifts %2 == 0);
  num_shifts /= 2;
}


// =======================================================================
// =======================================================================

void StudentTests(){
  //
  // Write your own test cases here
  //
  //

}

// =======================================================================
// =======================================================================

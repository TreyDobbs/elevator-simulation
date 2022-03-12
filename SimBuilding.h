// --------------------------------------------------------------------------
// Name: Trey Dobbs
// Course-Section: CS 255-01
// Assignment: Project #7
// Date Due: 12/2/2020
// Description: This C++ project implements all the required pieces for the 
// SimBuilding class to build a building elevator simulation. Creation of the
// class constructor, the step method, and the printServiceStats() method are
// the emphasis of this project.
// --------------------------------------------------------------------------
#include "Floor.h"
#include "Elevator.h"
#include "linkedList.h"
#include <math.h>

class SimBuilding{
   private:
   	//SERVICE STATISTICS
	double avgwaittime;
	int totalWaitTime;   //total wait time of served riders
	int totalServed;     //made to destination
	int totalInTransit;  //waiting in line or on elevator
	int stepcount;

	//Floor and Elevator Lists
	unorderedLinkedList<Floor*>* buildingFloors;
	unorderedLinkedList<Elevator*>* buildingElevators;

	//Building Stats
	int numFloors;
	int numElevators;

   public:
	/* Initializing the lists used to create the list of all the elevators 
     * and floors. It is also responsible for initializing all the variables
     * used to save the different values to be used in the Statistics 
     * function.
     */
	   SimBuilding(int numElevators, int numFloors, int arrivalRate, int carSize) {
		   this->numElevators = numElevators;

		   buildingElevators = new unorderedLinkedList<Elevator*>;

		   for (int i = 0; i < numElevators; i++) {
			   Elevator* newElev = new Elevator(numFloors,carSize);
			   
			   buildingElevators->insert(newElev);
		   }

		   this->numFloors = numFloors;

		   buildingFloors = new unorderedLinkedList<Floor*>;

		   for (int i = 0; i < numFloors; i++) {
			   Floor* newFloor = new Floor(i+1,arrivalRate);
			   buildingFloors->insert(newFloor);
		   }
		   
		   this->avgwaittime=0;
		   this->totalWaitTime=0;
		   this->totalServed=0;
		   this->totalInTransit=0;
		   this->stepcount=0;
	   }

	   void print() {
		   for (int i = 0; i < numElevators; i++) {
			   buildingElevators[i].print();
		   }
	   }


	/* On each step when the step function is called, riders arrive, the 
     * elevator is unloaded, the elevator is loaded, and the elevator moves.
     *
     * Riders Arrive: on each floor according to the arrival rate. These 
     * riders are saved in the two queues of each floor. On for those going
     * upward and on for those going downward. 
     *
     * Elevator is unloaded: the elevator rider whose destination is the 
     * current floor is removed from elevator’s list
     *
     * Elevator is Loaded: elevator loads riders to the elevator from the 
     * queue, if elevator direction is downward riders from down queue of 
     * that floor are moved to elevator’s riders list and if elevator 
     * direction is upward riders from up queue of that floor are moved into
     * the elevator’s riders list
     *
     * Elevator Move: on movement, floor number of elevator is incremented or
     * decremented based on the direction of the elevator
     *
     * This function is also responsible for changing the values of variables
     * of SimBuilding Class including TotalWaitTime, StepCount, 
     * TotalRidersInTransit, and TotalRidersServed
     */
	   void step(int stepNum) {

		   //Riders arrive at each step
		   nodeType<Floor*>* firstFloor = buildingFloors->getFirst();

		   while (firstFloor!=NULL) {
			   //It is assumed that a rider arives at each floor after arrival rate
			   firstFloor->info->arrive(stepNum,firstFloor->info->getFloorNum(), totalInTransit);
			   firstFloor = firstFloor->link;
		   }

		   //Elevator Loads and Unloads

		   nodeType<Elevator*>* firstElevator = buildingElevators->getFirst();

		   while (firstElevator !=NULL) {
			   totalWaitTime = totalWaitTime + (firstElevator->info->unload(stepNum, totalServed,totalInTransit));
			   firstElevator->info->load(buildingFloors->getFirst());
			   firstElevator->info->move(numFloors);

			   firstElevator = firstElevator->link;
		   }

		   stepcount++;
	   }

	/*The printServiceStats() function is printing the statistics of that 
     * elevator after it has completed its work.
     */
	   void printServiceStats() {
		   cout << "\tTotal Wait Time for Riders who reached the destinations: "<< totalWaitTime << endl;
		   cout << "\tTotal Riders who reached the destinations: "<< totalServed << endl;

		   avgwaittime = totalWaitTime / totalServed;

		   cout << "\tAverage wait time of served riders: " << avgwaittime << endl;
		   cout << "\tTotal Riders in Transit (On Elevator + In Line): " << totalInTransit << endl;

		   int totalRiders = totalServed + totalInTransit;

		   cout << "\tPercentage of riders who reached the destination: " << ((float)totalServed / (float)totalRiders) * 100 << "%" << endl;
	   }

};

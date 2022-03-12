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
#ifndef H_Rider
#define H_Rider

class Rider{
	private:
		int destFloor;
		int arrivalTime;
		int direction; //1-up, 0-down
		//Function used to generate a random destination floor (and thus direction)
		void setDest(int numFloors, int startFloor){
			destFloor = rand()%numFloors + 1;
			if(destFloor > startFloor){
				direction = 1;
			}
			else{
				direction = 0;
			}
		}
	public:
        //2 Constructors
		Rider(int numFloors, int aT, int startFloor){
			arrivalTime = aT;
			setDest(numFloors, startFloor);
		}
		int getArrivalTime(){
			return arrivalTime;
		}
		int getDestFloor(){
			return destFloor;
		}
		int getDirection(){
			return direction;
		}
};

#endif

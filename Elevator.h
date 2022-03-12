// --------------------------------------------------------------------------
// Name: Trey Dobbs
// Description: This C++ project implements all the required pieces for the 
// SimBuilding class to build a building elevator simulation. Creation of the
// class constructor, the step method, and the printServiceStats() method are
// the emphasis of this project.
// --------------------------------------------------------------------------
#include "Rider.h"
#include "linkedList.h"

class Elevator{
     private:
		int floorNum;
		int capacity;
		int numRiders;
		int direction; //(0=going down, 1=going up)
		unorderedLinkedList<Rider*> riders;

     public:
	void move(int numFloors){
        //Elevators move in their current direction until they reach either the bottom floor or the top floor
        //from that point, they turn around and head in the opposite direction.
        //cout<<"**On the Move: Floor "<<floorNum<<" : Headed:" << direction<<endl;
		if(direction==1){
			floorNum++;
			if(floorNum==numFloors){direction=0;}
		}
		else if(direction==0){
			floorNum--;
			if(floorNum==1){direction=1;}
		}
		//cout<<"**Have Moved: Floor "<<floorNum<<" : Headed:" << direction<<endl;
	}

	void load(nodeType<Floor*>* flptr){
        //The load method is responsible for taking Riders (who are going in the elevators direction) from the
        //current floor and adding them to the Elevator's list of Rider*s

		//1. Find the current floor
        //cout<<"**Trying to get to floorNum: "<<floorNum<<endl;
		while(flptr->info->getFloorNum() != floorNum){
            //cout<<"**Currently pointing at floorNum: "<<flptr->info->getFloorNum()<<endl;
			if(flptr == nullptr){
				cout<<"Ooof: Error1: end of list"<<endl;
				break;
			}
			flptr = flptr->link;
		}
		//2. While capacity is available in the elvator load all available riders
		while(capacity-numRiders > 0){
			Rider* rdrptr;
			//3. Call the current floor's leave() to identify the next rider and remove from floor queue,
			//leave() returns a pointer to a Rider
			rdrptr = flptr->info->leave(direction);
			if(rdrptr!=nullptr){
                //4. Add the rider * to the elevator list
                //cout<<"Loaded Rider Stats(aT, dest, dir):"<<rdrptr->getArrivalTime()<<":"<<rdrptr->getDestFloor()<<":"<<rdrptr->getDirection()<<endl;
                riders.insert(rdrptr);
                numRiders++;
            }
            else{
                break; //there are no riders on this floor going this direction
            }
		}
	}

	int unload(int stepcnt, int& ttlServ, int& ttlInTrans){
        //The unload method unloads Riders (removes Rider*s) who have reached their destination
        //It is also in charge of updating some statistics
            //total served-- total number of Riders who have reached destination
            //total in transit -- total number of Riders still on elevators

		int departArrTimeTTL = 0;
		nodeType<Rider*>* nextRid;
		nodeType<Rider*>* temp;
		if(!riders.isEmptyList()){
            nextRid = riders.getFirst();
		}
		else{
            nextRid = nullptr;
		}

		//cout<<"**Current Floor: "<<floorNum<<endl;
		//For all riders on the elevator
		while(nextRid != nullptr && numRiders>0){
			//If this is the riders destination
			if(nextRid->info->getDestFloor() == floorNum){
                //cout<<"UnLoading Rider Stats(aT, dest, dir):"<<nextRid->info->getArrivalTime()<<":"<<nextRid->info->getDestFloor()<<":"<<nextRid->info->getDirection()<<endl;
                //Add departing rider's wait time to ttl count for this floor
				departArrTimeTTL += (stepcnt - nextRid->info->getArrivalTime());
				//remove item from list
				temp = nextRid -> link;
				riders.deleteNode(nextRid->info);
				nextRid = temp;
				//update statistics
				numRiders--;
				ttlServ++;
				ttlInTrans--;
			}
			else{
                nextRid = nextRid->link;
			}
		}
		return departArrTimeTTL; //if no one left return a 0
	}

	Elevator(int numFloors, int carSize){
		floorNum = rand()%numFloors+1; //elevator begins on a random floor of the building

		capacity = carSize;
		numRiders = 0;
		direction = rand()%2; //elevator begins sim going up or down randomly
	}
};

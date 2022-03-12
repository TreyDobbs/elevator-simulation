// --------------------------------------------------------------------------
// Name: Trey Dobbs
// Description: This C++ project implements all the required pieces for the 
// SimBuilding class to build a building elevator simulation. Creation of the
// class constructor, the step method, and the printServiceStats() method are
// the emphasis of this project.
// --------------------------------------------------------------------------
#include "linkedQueue.h"
#include "Rider.h"

class Floor{
   private:
    //EACH floor has 2 queues, 1 queue for those going up, 1 queue for those going down
   	linkedQueueType<Rider*>* waitinglineUP;
   	linkedQueueType<Rider*>* waitinglineDOWN;
   	int floorNum;
   	int arrivalRate;

   public:
	Floor(int fN, int aR){
		waitinglineUP = new linkedQueueType<Rider*>;
		waitinglineDOWN = new linkedQueueType<Rider*>;
		floorNum = fN;
		arrivalRate = aR;
	}
	//Function called (by SimBuilding) to have riders "arrive" at the given floor
	void arrive(int step, int nF, int& ttlInTran){
        //if it's the correct step to have new riders arrive
		if(step%arrivalRate==0){
            //cout<<"**Rider arrived at floor "<<floorNum<<endl;
			//a new rider arrives
			Rider* newRid = new Rider(nF, step, floorNum);
			//place the new Rider (pointer to Rider to be precise) in the correct queue based on direction
			if(newRid->getDirection() == 0){ //headed down
				waitinglineDOWN->addQueue(newRid);
				ttlInTran++;
			}
			else{ //headed up
				waitinglineUP->addQueue(newRid);
				ttlInTran++;
			}
			//cout<<"New Rider Stats(aT, dest, dir):"<<newRid->getArrivalTime()<<":"<<newRid->getDestFloor()<<":"<<newRid->getDirection()<<endl;
		}
	}
	//Function called (by Elevator) when it requests Riders (dir represents the requesting elevator's current direction)
	Rider* leave(int dir){
		Rider* copyRid;
		//if elevator is going down
		if(dir==0){
            //if the DOWN queue is not empty
            if(!waitinglineDOWN->isEmptyQueue()){
                //copy Rider* out of the front of the queue, deleteQueue, return pointer
                copyRid = waitinglineDOWN->front();
                waitinglineDOWN->deleteQueue();
                return copyRid;
			}
			else{return nullptr;}
		}
		//if elevator is going up
		else{
            //if the UP queue is not empty
            if(!waitinglineUP->isEmptyQueue()){
                //copy Rider* out of the front of the queue, deleteQueue, return pointer
                copyRid = waitinglineUP->front();
                waitinglineUP->deleteQueue();
                return copyRid;
            }
            else{return nullptr;}
		}
	}

    int getFloorNum(){
        return floorNum;
    }
};

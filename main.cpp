// --------------------------------------------------------------------------
// Name: Trey Dobbs
// Description: This C++ project implements all the required pieces for the 
// SimBuilding class to build a building elevator simulation. Creation of the
// class constructor, the step method, and the printServiceStats() method are
// the emphasis of this project.
// --------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "SimBuilding.h"

int main(){
    srand (time(NULL));
    //SET BUILDING STATS -- CHANGE THESE AS NECESSARY
    int numElevators = 3;
    int numFloors = 60;
    int arrivalRate = 25; //a rider arrives once every arrivalRate steps
    int carSize = 15; //capacity of elevator cars

    SimBuilding myBuilding(numElevators, numFloors, arrivalRate, carSize);

    

    //Note: simulation will last for 24 simulated hours (2880 steps: 1 step is 30 seconds)
    for(int i=0; i<2880; i++){ //2880 is 24 hours worth of steps
        myBuilding.step(i + 1);
    }


    cout << endl << endl;
    cout << "*******************" << endl;
    cout << "Service Statistics:" << endl;
    cout << "*******************" << endl;
    myBuilding.printServiceStats();
    return 0;
}


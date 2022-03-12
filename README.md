# elevator-simulation
A C++ program of a simulation of elevators in a building.

Files:

• Node.h - defines a templated nodeType struct

• linkedList.h - defines a templated linkedList implementation

• linkedQueue.h - defines a templated linked-list implementation of a queue

• Rider.h - defines class Rider; Riders arrive, wait, and eventually depart on specific floors (by floor number); Riders are the clients served by Elevators

• Elevator.h - defines class Elevator; these are the servers that travel from floor to floor, dropping off and picking up Riders

• Floor.h - defines class Floor; these are the waiting areas (queues) for Riders who are waiting to be served by an Elevator

• main.cpp - simple main function that creates and uses an instance of the SimBuilding

• SimBuilding.h - a STUB for a class called SimBuilding



The point of the simulation is to capture and report on several statistics:

• Total Wait Time - the total amount of steps that riders who reached their destination floors waited from arriving at a floor to leaving an elevator

• Total Riders who Reached Destination (a.k.a. - "served" riders)

• Average Wait Time of Served Riders

• Total Riders in Transit { the total number of riders who remain "unserved" (those still in a floor queue or riding an elevator)

• The Percentage of Riders who Reached Destination

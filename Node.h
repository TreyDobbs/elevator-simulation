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
#ifndef H_NODE
#define H_NODE

//Definition of templated node type
template <class Type>
struct nodeType
{
	Type info;
	nodeType *link;
};

#endif

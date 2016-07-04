
/*
 * File: edge.hpp
 * Author: Felipe Lopes
 * Created on 22 de Junho de 2016, 16:27
 */

#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

using namespace std;

class Edge{
protected:
	int coordinate;	// Coordinate of vertex that connects
	double weight;	// Weight this edge

public:
	Edge(); // Constructor this class
	// Sets: Coordinate and weight	
	void setCoordinate(int x);
	void setWeight(float w);
	// Gets: Coordinate and weight
	int getCoordinate();
	float getWeight();
};

#endif
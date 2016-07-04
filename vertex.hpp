
/*
 * File: vertex.hpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:00
 */

#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include "edge.hpp"

using namespace std;

class Vertex{
protected:
	float x;	// Store x coordinate.
	float y;	// Store y coordinate.
	int visited;

public:
	vector<Edge> edges;	// vector edges of the vertice.
	Vertex();	// Constructor this class
	// Sets coordinates X and Y
	void setX(float x);
	void setY(float y);
	// Set visited true
	void setVisited();
	// Gets coordinates X and Y
	float getX();
	float getY();
	// Get visited, 0 false, 1 true
	int getVisited();
};

#endif
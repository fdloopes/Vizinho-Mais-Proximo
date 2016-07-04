
/*
 * File: edge.cpp
 * Author: Felipe Lopes
 * Created on 22 de Junho de 2016, 16:31
 */

#include <iostream>
#include "edge.hpp"

Edge::Edge(){ }

//===============================
// Sets: Coordenate and weight
void Edge::setCoordinate(int x){
	this->coordinate = x;	// connection to coordinate
}

void Edge::setWeight(float w){
	this->weight = w;	// weight this edge
}

//===============================
// Gets: Coordenate and weight
float Edge::getWeight(){
	return this->weight;
}

int Edge::getCoordinate(){
	return this->coordinate;
}

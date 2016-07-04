/*
 * File: vertex.cpp
 * Author: Felipe Lopes
 * Created on 21 de Junho de 2016, 20:09
 */

#include <iostream>
#include "vertex.hpp"

Vertex::Vertex(){
	this->visited = 0;
}

//================================
// Sets coordinates X and Y
void Vertex::setX(float x){
	this->x = x;
}

void Vertex::setY(float y){
	this->y = y;
}
// ===============================

// Set visited 1, true
void Vertex::setVisited(){
	this->visited = 1;
}

// get visited, 0 false, 1 true
int Vertex::getVisited(){
	return this->visited;
}

//================================
// Gets coordinates X and Y
float Vertex::getX(){
	return this->x;
}

float Vertex::getY(){
	return this->y;
}
// =============================
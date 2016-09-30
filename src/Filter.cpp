#include "Filter.h"
using namespace std;

//Constructor por movimiento
Filter::Filter(Filter &&other){
	this->structuringElement = std::move(other.structuringElement);
}

//COPIA X MOVIMIENTO
Filter& Filter::operator=(Filter &&other){
	this->structuringElement = std::move(other.structuringElement);
	return *this;
}

const Image& Filter::getStructuringElement() const {
	return structuringElement;
}

void Filter::setStructuringElement(const Image& structuringElement) {
	//this->structuringElement = std::move(*structuringElement);
}

/*const Image& Image:: getSrc() const{
	return this->src;
}
void Image::setSrc(const Image& src){
	//this->src = src;
}

const Image& Image::getDest() const{
	return this->dest;
}

void Image::setDest(const Image& dest){

}*/


Filter::~Filter() {

}



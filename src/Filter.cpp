#include "Filter.h"
using namespace std;

//Constructor por movimiento
Filter::Filter(Filter &&other){
	this->structuringElement = std::move(other.structuringElement);
	this->src = std::move(other.src);
	this->dest = std::move(other.dest);

	//other.structuringElement
}

//COPIA X MOVIMIENTO
Filter& Filter::operator=(Filter &&other){
	this->structuringElement = std::move(other.structuringElement);
	this->src = std::move(other.src);
	this->dest = std::move(other.dest);

	return *this;
}

const Image& Filter::getStructuringElement() const {
	return structuringElement;
}

void Filter::setStructuringElement(Image& structuringElement) {
	this->structuringElement = std::move(structuringElement);
}

const Image& Filter::getSrc() const{
	return this->src;
}

void Filter::setSrc(Image& src){
	this->src = std::move(src);
}

const Image& Filter::getDest() const{
	return this->dest;
}

void Filter::setDest(Image& dest){
	this->dest = std::move(dest);
}


Filter::~Filter() {

}



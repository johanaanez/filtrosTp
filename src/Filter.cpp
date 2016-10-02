#include "Filter.h"
using namespace std;

Filter::Filter(){

}

Filter::Filter(Image&& structuringElement, Image&& src){
	this->structuringElement = std::move(structuringElement);
	this->src = std::move(src);
}

//Constructor por movimiento
Filter::Filter(Filter &&other){
	this->structuringElement = std::move(other.structuringElement);
	this->src = std::move(other.src);
	this->dest = std::move(other.dest);

	other.structuringElement = Image();
	other.src = Image();
	other.dest = Image();
}

//COPIA X MOVIMIENTO
Filter& Filter::operator=(Filter &&other){
	this->structuringElement = std::move(other.structuringElement);
	this->src = std::move(other.src);
	this->dest = std::move(other.dest);

	other.structuringElement = Image();
	other.src = Image();
	other.dest = Image();

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

bool Filter::isTotalUnion(int x, int y){
	/*if(){
		return true;
	}*/

	return false;
}
bool Filter::isPartialUnion(int x, int y){
	return false;
}


Filter::~Filter() {

}



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

/*
 Image& Image::operator=(Image &&other){
	this->columns = other.columns;
	this->rows = other.rows;
	//this->representation = std::move( other.representation);

	other.rows = 0;
	other.columns = 0;
	//other.representation = nullptr;

	return *this;
}

//Constructor por movimiento
Image::Image(Image &&other){
	this->columns = other.columns;
	this->rows = other.rows;
	//this->representation(char, vector<char>) = other.representation();

	other.rows = 0;
	other.columns = 0;
	//other.representation = nullptr;

}
 */



const Image& Filter::getStructuringElement() const {
	return structuringElement;
}

void Filter::setStructuringElement(const Image& structuringElement) {
	//this->structuringElement = structuringElement;
}


Filter::~Filter() {

}



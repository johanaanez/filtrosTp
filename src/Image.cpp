#include "Image.h"

Image::Image() {
	rows= 0 ;
	columns = 0;
}

Image::~Image() {
	rows= 0 ;
	columns = 0;
}

int Image::transform(char zero, char one){
	for(int i=0; i<rows; i++){

	}
	return 0;
}

int Image::getColumns() const {
		return columns;
}

void Image::setColumns(int columns) {
	this->columns = columns;
}

int Image::getRows() const {
		return rows;
}

void Image::setRows(int rows) {
	this->rows = rows;
}

//Asignacion x movimiento
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




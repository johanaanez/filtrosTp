#include "Image.h"

Image::Image() {
	rows= 0 ;
	columns = 0;

}

Image::~Image() {
	rows= 0 ;
	columns = 0;
}

Image::Image(int rows, int columns, vector<vector<char>> matrix ){
	this->representation = matrix;
	this->rows = rows;
	this->columns = columns;
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
	this->representation =  other.representation;

	other.rows = 0;
	other.columns = 0;
	other.representation = vector< vector<char> >() ;

	return *this;
}

//Constructor por movimiento
Image::Image(Image &&other){
	this->columns = other.columns;
	this->rows = other.rows;
	this->representation = other.representation;

	other.rows = 0;
	other.columns = 0;
	other.representation = vector< vector<char> >() ;
}

vector<vector<char> > Image::getRepresentation() const{
    return representation;
}

void Image::setRepresentation(vector<vector<char> > representation){
    this->representation = representation;
}

char Image::getCenter(){
	return representation[rows/2][columns /2];
}

bool Image::isCenter(int i,int j){
	if (rows%2 !=0 && columns %2 !=0){
		int centerX = rows /2;
		int centerY = columns /2;

		if (i== centerX && j== centerY){
			return true;
		}
	}

	return false;
}

bool Image::isBorder(const int i,const int j) const{
	if(i == (this->getRows()-1) || i==0 || j==0 || j==(this->getColumns()-1)){
		return true;
	}
	return false;
}

const char Image::getOnes() const{
    return ones;
}

const char Image::getZeros() const{
    return zeros;
}

void Image::setPixel(int posX, int posY, char c){
	this->representation.at(posX).at(posY) = c;
}








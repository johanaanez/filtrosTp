#include "Image.h"


Image::Image() {
	rows= 0 ;
	columns = 0;
}

Image::Image(int rows, int columns, vector<vector<char>> matrix ){
	this->representation = matrix;
	this->rows = rows;
	this->columns = columns;
	//vector< vector< bool > > wasChanged( rows, vector<bool>( columns, false ) );
	//this->wasChanged = wasChanged;
	//initializeWasChanged();
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

Image::~Image() {
	rows= 0 ;
	columns = 0;
	representation = vector< vector<char> >() ;
}

vector<vector<bool> > Image::getWasChanged() const{
    return wasChanged;
}

void Image::setWasChanged(vector<vector<bool> > wasChanged){
    this->wasChanged = wasChanged;
}

void Image::initializeWasChanged(){

	for(int i=0; i< this->rows;i++){
		for(int j=0; j<this->columns; j++){
			wasChanged.at(i).at(j) = false;
		}
	}
}

void Image::setPixelWasChanged(int i, int j, bool wasChanged){
	this->wasChanged.at(i).at(j) = true;
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

vector<vector<char> > Image::getRepresentation() const{
    return representation;
}

void Image::setRepresentation(vector<vector<char> > representation){
    this->representation = representation;
}

char Image::getCenter()const{
	return representation[rows/2][columns /2];
}

bool Image::isCenter(int i,int j)const{
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

bool Image::isTopBorder(const int i,const int j) const{
	if(i==0){
		return true;
	}
	return false;
}

bool Image::isBottomBorder(const int i,const int j) const{
	if(i== (this->rows-1) ){
		return true;
	}
	return false;
}

bool Image::isRightBorder(const int i,const int j) const{
	if(j == (this->columns-1) ){
		return true;
	}
	return false;
}

bool Image::isLeftBorder(const int i,const int j) const{
	if( j==0){
			return true;
		}
	return false;
}

bool Image::isCorner(const int i,const int j) const{
	if(( isTopBorder(i,j)    && isLeftBorder(i,j)  ) ||
	   ( isTopBorder(i,j)    && isRightBorder(i,j) ) ||
	   ( isBottomBorder(i,j) && isLeftBorder(i,j)  ) ||
	   ( isBottomBorder(i,j) && isRightBorder(i,j) ) ){
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

bool Image::isEquals(const Image &other,int xDesde,int yDesde) const{
	//Compara los pixeles de la imagen this y la imagen other en los  pixeles
	//this es el patron, other es la imagen
	//Compara solos los bits en 1

	int x = xDesde;
	int y = yDesde;
	char c, c2;

	for(int i=0; i< this->rows; i++){
		for(int j=0; j<columns; j++){
			if(this->representation[i][j] == this->ones){
				c = this->representation[i][j];
				c2 =  other.representation[x][y];
				if( c!= c2){
					return false;
				}
			}
			y++;
		}
		x++;
		y = yDesde;
	}

	return true;
}









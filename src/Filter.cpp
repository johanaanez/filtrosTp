#include "Filter.h"
using namespace std;

Filter::Filter(){

}

Filter::Filter(Image& structuringElement, Image& src){
	this->structuringElement = Image(structuringElement.getRows(),structuringElement.getColumns(), structuringElement.getRepresentation());
	this->src = Image(src.getRows(),src.getColumns(), src.getRepresentation());
	this->dest = Image(src.getRows(),src.getColumns(), src.getRepresentation());
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

int Filter::aply(){
	int rows = this->getSrc().getRows()-this->getStructuringElement().getRows();
	int columns = this->getSrc().getColumns()-this->getStructuringElement().getColumns();
	int dimension = this->structuringElement.getRows();

	if(dimension > rows || dimension > columns){
		return -1;
	}

	char p = this->getStructuringElement().getRepresentation()[0][0];

	for(int i=0;i <=rows; i++){
		for(int j=0; j<= columns ; j++){
			char c = this->getSrc().getRepresentation()[i][j];
			if( c == p ){
				erosion(i,j);
			}

		}
	}

	return 0;
}

int Filter::erosion(int x, int y){
	int dimension = this->structuringElement.getRows();
	int resta = dimension/2;
	int posX = x-resta;
	int posY = y-resta;

	for(int i=0;i <dimension; i++){
		for(int j=0; j< dimension ; j++){
			char c= this->getStructuringElement().getRepresentation()[i][j];
			this->dest.setPixel(posX,posY,c);
			posY++;
		}
		posX++;
		posY= y-resta;
	}

	return 0;
}

Filter::~Filter() {

}



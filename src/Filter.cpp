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
	int posXLastChanged = 0, posYLastChanged = 0;

	if(dimension > rows || dimension > columns){
		return -1;
	}

	int i,j;

	for( i=0;i <=rows; i++){
		for( j=0; j<= columns ; j++){
			if( this->structuringElement.isEquals(this->getSrc(),i, j) ){
				erosion(i,j, &posXLastChanged ,  &posYLastChanged );
			}
		}
	}

	return 0;
}

int Filter::erosion(int x, int y, int  *posXLastChanged , int *posYLastChanged){
	int dimension = this->structuringElement.getRows();
	char zero = this->getStructuringElement().getZeros();
	char center = this->getStructuringElement().getCenter();
	int posX= x, posY = y;

	for(int i=0;i <dimension; i++){
		for(int j=0; j< dimension ; j++){
			if(this->getStructuringElement().isCenter(i,j)){
				this->dest.setPixel(posX,posY,center);
				*posXLastChanged = posX;
				*posYLastChanged = posY;
			}
			else{
				if( posY > *posYLastChanged || posX > *posXLastChanged){
					this->dest.setPixel(posX,posY,zero);
				}
			}

			posY++;
		}
		posX++;
		posY= y;
	}

	return 0;
}

Filter::~Filter() {

}



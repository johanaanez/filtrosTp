#include "DilationFilter.h"

namespace DilationFilter {

DilationFilter::~DilationFilter() {

}

int DilationFilter::aply(Image *image){
	int rows = this->getSrc().getRows();
	int columns = this->getSrc().getColumns();
	char center = this->structuringElement.getCenter();

	for(int i=0;i <rows; i++){
		for(int j=0; j< columns ; j++){
			char c= this->getSrc().getRepresentation()[i][j];
			if( c== center){
				if(this->getSrc().isBorder(i,j)){
					dilateBorder(i,j);
				}
				else{
					dilate(i,j);
				}

			}
		}

	}

	return 0;
}

int DilationFilter::dilateBorder(int i, int j){
	this->src.setPixel(i,j,'#');
	return 0;
}

int DilationFilter::dilate(int x, int y){
	int dimension = this->structuringElement.getRows();
	int posX = x-1;
	int posY = y-1;

	for(int i=0;i <dimension; i++){
		for(int j=0; j< dimension ; j++){
			char c= this->getStructuringElement().getRepresentation()[i][j];
			this->src.setPixel(posX,posY,c);
			posY++;
		}
		posX++;
	}

	return 0;
}

} /* namespace ErosionFilter */

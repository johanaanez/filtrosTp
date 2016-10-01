#include "DilationFilter.h"

namespace DilationFilter {

DilationFilter::~DilationFilter() {

}

int DilationFilter::aply(Image *image){
	int rows = this->getSrc().getRows();
	int columns = this->getSrc().getColumns();
	char center = this->structuringElement.getCenter();
	int dimension = this->structuringElement.getRows();

	if(dimension > rows || dimension > columns){
		return -1;
	}

	for(int i=0;i <rows; i++){
		for(int j=0; j< columns ; j++){
			char c= this->getSrc().getRepresentation()[i][j];
			if( c== center){
				if(this->getSrc().isBorder(i,j) && this->structuringElement.getColumns()>1){
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

int DilationFilter::dilateBorder(int x, int y){
	int dimensionX = this->structuringElement.getRows();
	int dimensionY = this->structuringElement.getRows();
	int resta = dimensionX/2;
	int posX = x-resta;
	int posY = y-resta;

	if(this->src.isCorner(x,y)){
		dimensionX -= resta; //si el patron es de 3X3
		dimensionY -= resta;
	}

	if(this->src.isTopBorder(x,y)){
		posX = x;
	}
	if(this->src.isLeftBorder(x,y)){
		posY = y;
	}

	for(int i=0;i <dimensionX; i++){
		for(int j=0; j< dimensionY ; j++){
			char c= this->getStructuringElement().getRepresentation()[i][j];
			this->src.setPixel(posX,posY,c);
			posY++;
		}
		posX++;
	}

	return 0;
}

int DilationFilter::dilate(int x, int y){
	int dimension = this->structuringElement.getRows();
	int resta = dimension/2;
	int posX = x-resta;
	int posY = y-resta;

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

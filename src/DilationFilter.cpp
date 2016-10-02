#include "DilationFilter.h"

//Constructor x movimiento heredado
DilationFilter::DilationFilter(DilationFilter&& o): Filter(std::move(o)){

}

DilationFilter::DilationFilter(Image& structuringElement, Image& src){
	this->structuringElement =  Image(structuringElement.getRows(),structuringElement.getColumns(), structuringElement.getRepresentation());
	this->src = Image(src.getRows(),src.getColumns(), src.getRepresentation());
	this->dest = Image(src.getRows(),src.getColumns(), src.getRepresentation());
}

//COPIA X MOVIMIENTO
DilationFilter& DilationFilter::operator=(DilationFilter &&other){
	this->structuringElement = std::move(other.structuringElement);
	this->src = std::move(other.src);
	this->dest = std::move(other.dest);

	return *this;
}

DilationFilter::~DilationFilter() {
	this->src = Image();
	this->dest = Image();
	this->structuringElement = Image();
}

int DilationFilter::aply(){
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
				if(this->src.isBorder(i,j) && this->structuringElement.getColumns()>1){
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
	int dimension = this->structuringElement.getRows();
	int dimensionY = this->structuringElement.getRows();
	int resta = dimension/2;
	int posX = x-resta;
	int posY = y-resta;

	if(this->src.isCorner(x,y)){
		int dimensionX = dimension- resta; //si el patron es de 3X3
		dimensionY -= resta;
	}

	if(this->src.isTopBorder(x,y)){
		posX = x;
	}
	if(this->src.isLeftBorder(x,y)){
		posY = y;
	}

	if(this->src.isTopBorder(x,y)){
		for(int i=resta;i <dimension; i++){
			for(int j=resta; j< dimension ; j++){
				char c= this->getStructuringElement().getRepresentation()[i][j];
				this->dest.setPixel(posX,posY,c);
				posY++;
			}
			posX++;
			posY= posY- dimensionY;
		}
	}

	if(this->src.isBottomBorder(x,y)){
		if(this->src.isLeftBorder(x,y)){
				posY = y;
		}

		int posX = x-resta;

		//DESDE QUE POSICION DEL PATRON HASTA CUAL SE VA A COPIAR?
		for(int i=0;i <2; i++){
			for(int j=1; j< 3 ; j++){
				char c= this->getStructuringElement().getRepresentation()[i][j];
				this->dest.setPixel(posX,posY,c);
				posY++;
			}
			posX++;
			posY= posY- dimensionY;
		}

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
			this->dest.setPixel(posX,posY,c);
			posY++;
		}
		posX++;
		posY= y-resta;
	}

	return 0;
}



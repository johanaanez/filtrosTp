#include "DilationFilter.h"

namespace DilationFilter {

DilationFilter::~DilationFilter() {

}

int DilationFilter::aply(Image *image){
	int rows = this->getSrc().getRows();
	int columns = this->getSrc().getColumns();
	char ones = this->getStructuringElement().getOnes();

	for(int i=0;i <rows; i++){
		for(int j=0; j< columns ; j++){
			char c= this->getSrc().getRepresentation()[i][j];
			if( c== ones){
				if(this->getSrc().isBorder(i,j)){
					dilateBorder();
				}
				else{
					dilate();
				}

			}
		}

	}

	return 0;
}

int DilationFilter::dilateBorder(){



	return 0;
}

int DilationFilter::dilate(){


	return 0;
}

} /* namespace ErosionFilter */

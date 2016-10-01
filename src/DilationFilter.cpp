#include "DilationFilter.h"

namespace DilationFilter {

DilationFilter::~DilationFilter() {

}

int DilationFilter::aply(Image *image){
	int rows = this->getSrc().getRows();
	int columns = this->getSrc().getColumns();

	for(int i=0;i <rows; i++){
			for(int j=0; j< columns ; j++){
				char c= this->getSrc().getRepresentation()[i][j];
				if( c=='#'){

				}
			}
			cout<<endl;
		}
	return 0;
}

} /* namespace ErosionFilter */

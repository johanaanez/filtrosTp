#include <iostream>
using namespace std;
#include <vector>
#include "DilationFilter.h"
#include "Filter.h"
#include "Image.h"

int main(int argc, char *argv[]) {

	int rows=3;
	int columns=3;
	vector<vector<char> > pattern(rows, std::vector<char>(columns));
	vector<char> row1=  {'.','#','.'};
	pattern.at(0) = row1;
	vector<char> row2=  {'#','#','#'};
	pattern.at(1) =row2;
	vector<char> row3=  {'.','#','.'};
	pattern.at(2) = row3;

	rows=6;
	columns=6;
	vector<vector<char> > matrix(rows, std::vector<char>(columns));
	row1=  {'.','.','.','.','.', '.'};
	matrix.at(0) = row1;
	row2=  {'.','#','.','.','.', '.'};
	matrix.at(1) =row2;
	row3=  {'.','.','.','.','.', '.'};
	matrix.at(2) = row3;
	vector<char> row4=  {'.','.','.','.','.', '.'};
	matrix.at(3) = row4;
	vector<char> row5=  {'.','.','.','#','.', '.'};
	matrix.at(4) = row5;
	vector<char> row6=  {'.','.','.','.','.', '.'};
	matrix.at(5) = row6;

	Image patron(3,3,pattern);
	Image image(6,6,matrix);

	DilationFilter *f = new DilationFilter((Image&&)patron,image);
	//f->setSrc(image);
	//f->setStructuringElement(patron);



	f->aply();

	for(int i=0;i <rows; i++){
			for(int j=0; j<columns; j++){
				cout<<f->getDest().getRepresentation()[i][j];
			}
			cout<<endl;
	}


	return 0;
}




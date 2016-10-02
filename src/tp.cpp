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
	row1=  {'#','.','.','.','.', '#'};
	matrix.at(0) = row1;
	row2=  {'.','.','.','.','.', '.'};
	matrix.at(1) =row2;
	row3=  {'.','.','#','.','.', '.'};
	matrix.at(2) = row3;
	vector<char> row4=  {'.','.','.','.','.', '.'};
	matrix.at(3) = row4;
	vector<char> row5=  {'.','.','.','.','.', '.'};
	matrix.at(4) = row5;
	vector<char> row6=  {'#','.','.','.','.', '#'};
	matrix.at(5) = row6;

	Image patron(3,3,pattern);
	Image image(6,6,matrix);

	DilationFilter *f = new DilationFilter(patron,image);

	for(int i=0;i <rows; i++){
				for(int j=0; j<columns; j++){
					cout<<f->getSrc().getRepresentation()[i][j];
				}
				cout<<endl;
		}

	cout<<"\n";
	f->aply();

	for(int i=0;i <rows; i++){
		for(int j=0; j<columns; j++){
			cout<<f->getDest().getRepresentation()[i][j];
		}
		cout<<endl;
	}

	vector<vector<char> > matrix2(rows, std::vector<char>(columns));
	row1=  {'.','#','.','.','.', '.'};
	row2=  {'#','#','#','.','.', '.'};
	row3=  {'.','#','.','.','.', '.'};
	row4=  {'.','.','#','#','#', '#'};
	row5=  {'.','.','#','#','#', '#'};
	row6=  {'.','.','#','#','#', '#'};

	matrix2.at(0) = row1;
	matrix2.at(1) =	row2;
	matrix2.at(2) = row3;
	matrix2.at(3) = row4;
	matrix2.at(4) = row5;
	matrix2.at(5) = row6;

	Image image2(6,6,matrix2);
	Filter *erosion = new Filter(patron,image2);
	cout<<"\n";
	erosion->aply();

	for(int i=0;i <rows; i++){
		for(int j=0; j<columns; j++){
			cout<<erosion->getDest().getRepresentation()[i][j];
		}
		cout<<endl;
	}

	return 0;
}




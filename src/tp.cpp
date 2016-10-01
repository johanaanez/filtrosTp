#include <iostream>
using namespace std;
#include <vector>


int main(int argc, char *argv[]) {

	int rows=6;
	int columns=6;
	vector<vector<char> > matrix(rows, std::vector<char>(columns));
	vector<char> row1=  {'.','.','.','.','.', '.'};
	matrix.at(0) = row1;
	vector<char> row2=  {'.','#','.','.','.', '.'};
	matrix.at(1) =row2;
	vector<char> row3=  {'.','.','.','.','.', '.'};
	matrix.at(2) = row3;
	vector<char> row4=  {'.','.','.','.','.', '.'};
	matrix.at(3) = row4;
	vector<char> row5=  {'.','.','.','#','.', '.'};
	matrix.at(4) = row5;
	vector<char> row6=  {'.','.','.','.','.', '.'};
	matrix.at(5) = row6;

	for(int i=0;i <rows; i++){
		for(int j=0; j<columns; j++){
			cout<<matrix[i][j];
		}
		cout<<endl;
	}

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}




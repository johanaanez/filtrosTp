#ifndef IMAGE_H_
#define IMAGE_H_

#include <vector>
using namespace std;

class Image {
private:

	int rows;
	int columns;
	vector<vector<char> > representation;

	//Aca se puede setear si inicialmente se desea que los 0 y 1 sean representados por otro caracter
	const char ones = '#';
    const char zeros = '.';

public:
	Image();
	Image(int rows, int columns, vector<vector<char> > matrix );
	//CONSTRUCTOR POR MOVIMIENTO
	Image(Image&& other);

	//Constructor por copia
	Image(const Image &other) = delete;

	//Asignacion x copia
	Image& operator=(const Image &other)=delete;

	//ASIGNACION X MOVIMIENTO
	Image& operator=(Image &&other);

	int transform(char zero, char one);
	virtual ~Image();
	int getColumns() const;
	void setColumns(int columns);
	int getRows() const;
	void setRows(int rows);
    vector<vector<char> > getRepresentation() const;
    void setRepresentation(vector<vector<char> > representation);
    const char getOnes() const;
    const char getZeros() const;
    char getCenter()const;
    bool isCenter(int i,int j)const;
    bool isCorner(int i,int j)const;
    bool isBorder(const int i,const int j) const;
    bool isTopBorder(const int i,const int j) const;
    bool isRightBorder(const int i,const int j) const;
    bool isLeftBorder(const int i,const int j) const;
    bool isBottomBorder(const int i,const int j) const;
    void setPixel(int posX, int posY, char c);
    bool isEquals(const Image& other, int xDesde, int yDesde,  int xHasta, int yHasta) const;
};

#endif /* IMAGE_H_ */

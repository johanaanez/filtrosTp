#ifndef IMAGE_H_
#define IMAGE_H_

#include <vector>
using namespace std;

class Image {
private:

	int rows;
	int columns;
	vector<vector<char> > representation(char, vector<char>(columns));

	Image(const Image&)=delete;
	Image(Image&& other);


public:
	Image();
	Image(int rows, int columns);
	Image& operator=(Image &&other);
	int transform(char zero, char one);
	virtual ~Image();
	int getColumns() const;
	void setColumns(int columns);
	int getRows() const;
	void setRows(int rows);
};

#endif /* IMAGE_H_ */

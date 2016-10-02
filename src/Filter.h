#ifndef FILTER_H_
#define FILTER_H_


#include <stdio.h>
#include <iostream>
#include "Image.h"

class Filter {

private:
	int erosionBorder(int i, int j);
	int erosion(int i, int j);

protected:
	Image structuringElement;
	Image src;
	Image dest;

public:
	Filter();
	Filter(int x);
	Filter(Image& structuringElement, Image& src);
	Filter(Filter&& other);     				           //Constructor x movimiento
	Filter(const Filter &other) = delete;                  //Constructor x copia
	Filter& operator=(Filter &&other);                     //asignacion x movimiento;
	Filter& operator=(const Filter &other)=delete;         //Asignacion x copia
	virtual ~Filter();
	const Image& getStructuringElement() const;
	void setStructuringElement(Image& structuringElement);
	const Image& getSrc() const;
	void setSrc(Image& src);
	const Image& getDest() const;
	void setDest(Image& dest);
	bool isTotalUnion(int x, int y);
	bool isPartialUnion(int x, int y);
	virtual int aply();
};

#endif /* FILTER_H_ */

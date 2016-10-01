#ifndef FILTER_H_
#define FILTER_H_


#include <stdio.h>
#include <iostream>
#include "Image.h"

class Filter {

protected:
	Image structuringElement;
	Image src;
	Image dest;

public:
	Filter& operator=(Filter &&other);
	Filter(const Filter &other) = delete;
	Filter(Filter&& other);
	virtual int aply(Image *image)=0;
	virtual ~Filter();
	const Image& getStructuringElement() const;
	void setStructuringElement(Image& structuringElement);
	const Image& getSrc() const;
	void setSrc(Image& src);
	const Image& getDest() const;
	void setDest(Image& dest);
	bool isTotalUnion(int x, int y);
	bool isPartialUnion(int x, int y);
};

#endif /* FILTER_H_ */

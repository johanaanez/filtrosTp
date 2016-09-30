#ifndef FILTER_H_
#define FILTER_H_


#include <stdio.h>
#include <iostream>
#include "Image.h"

class Filter {

private:
	Image structuringElement;
	Filter(const Filter&)=delete;
	Filter(Filter&& other);

public:
	Filter& operator=(Filter &&other);
	virtual int aply(Image *image)=0;
	virtual ~Filter();
	const Image& getStructuringElement() const;
	void setStructuringElement(const Image& structuringElement);

};

#endif /* FILTER_H_ */

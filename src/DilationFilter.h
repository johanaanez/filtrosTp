#ifndef DILATIONFILTER_H_
#define DILATIONFILTER_H_

#include"Filter.h"

class DilationFilter:  public Filter {

private:
	int dilateBorder(int i, int j);
	int dilate(int i, int j);

public:
	DilationFilter();
	DilationFilter(DilationFilter&& other);
	DilationFilter& operator=(DilationFilter &&other);
	DilationFilter(const DilationFilter &other) = delete;
	int aply(Image *image);
	virtual ~DilationFilter();
};



#endif /* DILATIONFILTER_H_ */

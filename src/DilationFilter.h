
#ifndef DILATIONFILTER_H_
#define DILATIONFILTER_H_

#include"Filter.h"

namespace DilationFilter{

class DilationFilter:  public Filter {

private:
	int dilateBorder(int i, int j);
	int dilate(int i, int j);

public:
	DilationFilter();
	int aply(Image *image);
	virtual ~DilationFilter();
};

}  /* namespace ErosionFilter */

#endif /* DILATIONFILTER_H_ */

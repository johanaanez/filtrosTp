#ifndef EROSIONFILTER_H_
#define EROSIONFILTER_H_

#include "Filter.h"



class ErosionFilter: public Filter {
public:
	ErosionFilter();
	int aply(Image *image);
	virtual ~ErosionFilter();
};



#endif /* EROSIONFILTER_H_ */

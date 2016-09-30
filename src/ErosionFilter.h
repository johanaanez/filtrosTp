#ifndef EROSIONFILTER_H_
#define EROSIONFILTER_H_

#include "Filter.h"

namespace ErosionFilter {

class ErosionFilter: public Filter {
public:
	ErosionFilter();
	int aply(Image *image);
	virtual ~ErosionFilter();
};

} /* namespace ErosionFilter */

#endif /* EROSIONFILTER_H_ */

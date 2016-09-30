/*
 * ErosionFilter.h
 *
 *  Created on: Sep 28, 2016
 *      Author: pdg
 */

#ifndef EROSIONFILTER_H_
#define EROSIONFILTER_H_

#include "Filter.h"

namespace ErosionFilter {

class ErosionFilter: public Filter {
public:
	ErosionFilter();
	virtual ~ErosionFilter();
};

} /* namespace ErosionFilter */

#endif /* EROSIONFILTER_H_ */

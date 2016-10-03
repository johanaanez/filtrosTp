/*
 * Pixel.h
 *
 *  Created on: 02/10/2016
 *      Author: joha
 */

#ifndef PIXEL_H_
#define PIXEL_H_

class Pixel {

private:
	char caracter;
	bool wasChanged;
public:
	Pixel();
	Pixel(char caracter);
	virtual ~Pixel();
    char getCaracter() const;
    bool getWasChanged() const;
    void setCaracter(char caracter);
    void setWasChanged(bool wasChanged);
};

#endif /* PIXEL_H_ */

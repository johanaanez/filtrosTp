#include "Pixel.h"

Pixel::Pixel() {
	caracter = '.';
	wasChanged = false;
}

Pixel::Pixel(char caracter){
	this->caracter = caracter;
	this->wasChanged = false;
}

char Pixel::getCaracter() const
{
    return caracter;
}

bool Pixel::getWasChanged() const
{
    return wasChanged;
}

void Pixel::setCaracter(char caracter)
{
    this->caracter = caracter;
}

void Pixel::setWasChanged(bool wasChanged)
{
    this->wasChanged = wasChanged;
}

Pixel::~Pixel() {
	// TODO Auto-generated destructor stub
}

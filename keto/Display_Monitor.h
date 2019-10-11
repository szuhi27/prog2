#include <exception>
using namespace std;

#ifndef __Display_Monitor_h__
#define __Display_Monitor_h__

#include "Output_Device.h"

// class Output_Device;
class Display_Monitor;

class Display_Monitor: public Output_Device
{
	private: string _color;
	private: string _brightness;
	private: string _contrast;
	private: string _graphicsMemory;

	public: void setBrightness();

	public: void setContrast();

	public: void setColor();

	public: void display(String aS);
};

#endif

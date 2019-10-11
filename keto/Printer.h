#include <exception>
using namespace std;

#ifndef __Printer_h__
#define __Printer_h__

#include "Output_Device.h"

// class Output_Device;
class Printer;

class Printer: public Output_Device
{
	private: string _ready;
	private: string _buffer;

	public: void formFeed();

	public: void lineFeed();

	public: void printLine(String aS);

	public: void display(String aS);
};

#endif

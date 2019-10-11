#include <exception>
using namespace std;

#ifndef __File_h__
#define __File_h__

#include "User.h"
#include "Name.h"
#include "Output_Device.h"

class User;
class Name;
class Output_Device;
class File;

class File
{
	private: String _name;
	private: User _owner;

	public: void create(Name aN, User aO);

	public: void delete_1();

	public: void display(Output_Device aD);

	public: void execute();
};

#endif

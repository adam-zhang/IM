#ifndef __USER__H
#define __USER__H
#include <string>
#include "Property.h"



class User
{
public:
	User();
	~User();

	PROPERTY(std::string, id, setID);
	PROPERTY(std::string, userName, setUserName);
	PROPERTY(std::string, mobile, setMobile);
};
#endif//__USER__H

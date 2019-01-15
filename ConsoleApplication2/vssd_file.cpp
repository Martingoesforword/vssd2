
#include "pch.h" 


 


std::string vssd_file::gettype()
{
	return vssdtypename;
}

vssd_file::vssd_file(std::string aname, std::string aformat, int asize)
{
	name = aname;
	format = aformat;
	size = asize;
}

vssd_file::~vssd_file()
{
}

#include "pch.h" 
vssd_link::vssd_link()
{

}


vssd_link::vssd_link(std::string aname, std::string apointtotype, vssd_canbelinked *apointto)
{
	name = aname; 
	pointtotype = apointto->gettype();
	pointto = apointto;
}

vssd_link::~vssd_link()
{
}

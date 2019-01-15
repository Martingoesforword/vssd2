#pragma once 
class vssd_link
{
private:
	std::string name;
	std::string pointtotype;
	
	vssd_canbelinked *pointto;

public:
	std::string vssdtypename = "LINK";
	vssd_link();
	vssd_link(std::string name,std::string pointtotype,vssd_canbelinked *pointto);
	~vssd_link();
}; 

#pragma once 
class vssd_file:public vssd_canbelinked
{
private: 
	std::string name;
	std::string format;
	
	int size;

public:
	virtual std::string gettype();
	vssd_file(std::string name, std::string format, int size);
	std::string vssdtypename = "FILE";
	~vssd_file();
};
 
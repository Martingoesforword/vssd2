#pragma once 
class vssd
{
private:
	std::string name;
	vssd_foldertop *nowtop;
	vssd_foldertop *tops[100];
	int tabletops_size = 100;
	int tabletops_length = 0;
	
public: 
	vssd_foldertop *getnowtop();
	void setnowtop(vssd_foldertop * afoldertop);
	void linktop(vssd_foldertop *anowtop);
	vssd(vssd_foldertop * Now, std::string aname);
	vssd(std::string aname);
	vssd_foldertop *findtop(std::string &aname);
	
	~vssd();
};
 
#include "pch.h"  
 
 
vssd_foldertop * vssd::getnowtop()
{
	return nowtop;
}
vssd_folder * vssd::getgenius()
{
	return genius;
}
void vssd::setnowtop(vssd_foldertop * afoldertop)
{
	nowtop = afoldertop;
}
 
 

void vssd::linktop(vssd_foldertop * anowtop)
{
	if (tabletops_length == 0) {
		nowtop = anowtop;
	}
	if (tabletops_length < tabletops_size) {
		tops[tabletops_length] = anowtop;
		tabletops_length++;
	}
	
}

vssd::vssd(vssd_foldertop * Now, vssd_folder * agenius, std::string aname)
{
	nowtop = Now;
	name = aname;
	genius = agenius;
}

 
vssd::vssd()
{
	
}
 
vssd_foldertop * vssd::findtop(std::string & aname)
{
	for (int i = 0; i < tabletops_length; i++)
	{
		if (aname == tops[i]->root->getname() ) {
			return tops[i];
		}
	}
	return nullptr; 
}
 

vssd::~vssd()
{

}

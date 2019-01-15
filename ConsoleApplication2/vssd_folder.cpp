#include "pch.h"  
void vssd_folder::vssd_folder_init()
{
	foldersize = 100;
	filesize = 100;
	linksize = 100;
	folderlength = 0;
	filelength = 0;
	linklength = 0; 
	std::memset(subfolders, 0, sizeof(subfolders));
	std::memset(subfiles, 0, sizeof(subfiles));
	std::memset(sublinks, 0, sizeof(sublinks));
}

std::string vssd_folder::gettype()
{
	return vssdtypename;
}

vssd_folder::vssd_folder(std::string aname)
{
	name = aname;
	vssd_folder_init();

}

void vssd_folder::vssd_folder_link(vssd_folder *linktosub)
{
	 
	
	if (folderlength < foldersize) {
		vssd_folder ** p = findnext();
		*p = linktosub;
		folderlength++;
	}  
	else std::cout << "This folder had overflowed for folders!" << std::endl;
}
 
std::string vssd_folder::getname()
{
	return name;
}

void vssd_folder::build(tool_path &a) {
	 
	 
	vssd_folder *now = this;
	int flag = 0;
	for (int i = 0; i < a.folderlength; i++)
	{	
		if (flag || !now->find(a.folders[i])) {
			vssd_folder *f1 = new vssd_folder(a.folders[i]);
			now->vssd_folder_link(f1);
			now = f1;
			flag = 1;
		}
		else {
			now = now->find(a.folders[i]);
		}
		

	}

}

void vssd_folder::setname(std::string &aname) {

	name = aname;
}

void vssd_folder::vssd_file_link(vssd_file *linktosub)
{
	if (filelength < filesize)
		subfiles[filelength++] = linktosub;
	else std::cout << "This folder had overflowed for files!" << std::endl;
}

void vssd_folder::showoffsub() {
	
	int p = 0;
	for (size_t i = 0; i < folderlength; i++)
	{
		
	defeatfolder:
		
		if (subfolders[p] != NULL) {
			std::cout << subfolders[p]->name <<"\t<"<< subfolders [p]->gettype()<<">\t无大小"<< std::endl;
		}
		else { p++; goto defeatfolder;}
		p++;
	}
	p = 0;
	for (size_t i = 0; i < linklength; i++)
	{

	defeatlink:

		if (subfolders[p] != NULL) {
			std::cout << subfolders[p]->name << "\t<" << subfolders[p]->gettype() << ">\t无大小" << std::endl;
			p++;
		}
		else { p++;  goto defeatlink; }
		
	}
	p = 0;
	for (size_t i = 0; i < filelength; i++)
	{

	defeatfile:

		if (subfolders[p] != NULL) {
			std::cout << subfolders[p]->name << "\t<" << subfolders[p]->gettype() << ">\t" << subfolders[p]->filesize << "KB" << std::endl;
			p++;
		}
		else { p++; goto defeatfile; }
		 
	}
}

void vssd_folder::deletone(vssd_folder * deletfolder)
{
	int j = 0; 
	for (int i = 0; i < folderlength; i++)
	{

		for (; j < foldersize; j++)
		{
			if (subfolders[j] == NULL) {
				continue;
			}
			else {

				break;
			}
		}

		if (subfolders[j]->getname() == deletfolder->getname()) {
			subfolders[j]->deletevery();
			subfolders[j]->~vssd_folder();
			subfolders[j] = nullptr;
			folderlength--;
			return;
		}
		else {
			j++;
		}

	} 
}

void vssd_folder::offone(vssd_folder * deletfolder)
{
	int j = 0;
	for (int i = 0; i < folderlength; i++)
	{

		for (; j < foldersize; j++)
		{
			if (subfolders[j] == NULL) {
				continue;
			}
			else { 
				break;
			}
		}

		if (subfolders[j]->getname() == deletfolder->getname()) { 
			folderlength--;
			subfolders[j] = nullptr;
			return;
		}
		else {
			j++;
		}

	}
}

void vssd_folder::deletevery() {
	int j = 0;
	for (int i = 0; i < folderlength; i++)
	{

		for (; j < foldersize; j++)
		{
			if (subfolders[j] == NULL) {
				continue;
			}
			else {
				subfolders[j]->deletevery();
				subfolders[j]->~vssd_folder();
				break;
			}
		}

		 
		j++;
		 

	}
}

void vssd_folder::vssd_link_link(vssd_link * linktosub)
{
	if (linklength < linksize)
		sublinks[linklength++] = linktosub;
	else std::cout << "This folder had overflowed for links!" << std::endl;
}

vssd_folder ** vssd_folder::findnext() {
	if (folderlength < foldersize) {
		for (int i = 0; i < foldersize; i++)
		{
			if (subfolders[i] == nullptr) {
				return &subfolders[i];
			}

		}
	}
	else {

	}
	
	 
}

vssd_folder * vssd_folder::find(std::string & folder)
{
	int j = 0;
	for (int i = 0; i < folderlength; i++)
	{  
		 
		if (subfolders[j] != NULL) {
			if (subfolders[j]->getname() == folder) {

				return subfolders[j];
			}
			else {
				j++;
			}
			if (j > foldersize) {
				break;
			}
		}

	}
	return nullptr;
}

vssd_folder * vssd_folder::find(tool_path * apath, int pathpos)
{

	vssd_folder* reserchout;
	reserchout = find(apath->folders[0]);
	 
	return nullptr;
	 
}
 
vssd_folder::~vssd_folder()
{
}

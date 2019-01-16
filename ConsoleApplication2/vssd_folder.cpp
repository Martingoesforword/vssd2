#include "pch.h"  
void vssd_folder::vssd_folder_init()
{  
}

std::string vssd_folder::gettype()
{
	return vssdtypename[vssdtypecode];
}

vssd_folder::vssd_folder(std::string aname, int acode)
{
	name = aname;
	vssdtypecode = acode;
	vssd_folder_init();
	
}
 

void vssd_folder::vssd_folder_link(vssd_folder *linktosub)
{
	 
	
	if (subfolders.size() < subfolders.max_size()) {
		subfolders.push_back(linktosub); 
		 
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
	for (int i = 0; i < a.folders.size(); i++)
	{	
		if (flag || !now->find(a.folders[i])) {
			vssd_folder *f1 = new vssd_folder(a.folders[i],1);
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

 

void vssd_folder::showoffsub() {
	
	int p = 0;
	for (size_t i = 0; i < subfolders.size(); i++)
	{
		
	defeatfolder:
		
		if (subfolders.at(p) != NULL) {
			std::cout << subfolders.at(p)->name <<"\t<"<< subfolders [p]->gettype()<<">\t无大小"<< std::endl;
		}
		else { p++; goto defeatfolder;}
		p++;
	}
	 
}

void vssd_folder::deletone(vssd_folder * deletfolder)
{
	int j = 0; 
	for (int i = 0; i < subfolders.size(); i++)
	{

		for (; j < subfolders.max_size(); j++)
		{
			if (subfolders.at(j) == NULL) {
				continue;
			}
			else {

				break;
			}
		}

		if (subfolders.at(j)->getname() == deletfolder->getname()) {
			subfolders.at(j)->deletevery();
			subfolders.at(j)->~vssd_folder();
			std::vector<vssd_folder *>::iterator it = subfolders.begin();
			 
			subfolders.erase(it + j);
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
	for (int i = 0; i < subfolders.size(); i++)
	{

		for (; j < subfolders.max_size(); j++)
		{
			if (subfolders.at(j) == NULL) {
				continue;
			}
			else { 
				break;
			}
		}

		if (subfolders.at(j)->getname() == deletfolder->getname()) { 
			std::vector<vssd_folder*>::iterator it = subfolders.begin(); 
			subfolders.erase(it + j); 
			return;
		}
		else {
			j++;
		}

	}
}

void vssd_folder::deletevery() {
	int j = 0;
	for (int i = 0; i < subfolders.size(); i++)
	{

		for (; j < subfolders.max_size(); j++)
		{
			if (subfolders.at(j) == NULL) {
				continue;
			}
			else {
				subfolders.at(j)->deletevery();
				subfolders.at(j)->~vssd_folder();
				break;
			}
		}

		 
		j++;
		 

	}
}

 

vssd_folder ** vssd_folder::findnext() {
	if (subfolders.size() < subfolders.max_size()) {
		for (int i = 0; i < subfolders.max_size(); i++)
		{
			if (subfolders.at(i) == nullptr) {
				return &subfolders.at(i);
			}

		}
	}
	else {

	}
	
	 
}

vssd_folder * vssd_folder::find(std::string & folder)
{
	int j = 0;
	for (int i = 0; i < subfolders.size(); i++)
	{  
		 
		if (subfolders.at(j) != NULL) {
			if (subfolders.at(j)->getname() == folder) {

				return subfolders.at(j);
			}
			else {
				j++;
			}
			if (j > subfolders.max_size()) {
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
 
void vssd_folder::setcontent(unsigned char byte)		//追加字符
{
	if (isFile()) {
		content.push_back(byte);
	}
	else {
		std::cout << "Can not write to or read from a folder or a link" << std:: endl;
	}
}

unsigned char vssd_folder::readcontent()			//返回NULL 和 下一个字符
{
	static int index = -1;
	if (isFile()) {
		std::vector<unsigned char>::iterator it = content.begin(); 
		index++;
		if(it + index != content.end())
			return *(it+ index);
		else {
			return NULL;
		}
	}
	else {
		std::cout << "Can not write to or read from a folder or a link" << std::endl;
	}
}

vssd_folder::~vssd_folder()
{
}

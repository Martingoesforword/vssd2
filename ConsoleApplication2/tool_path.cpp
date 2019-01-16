
#include "pch.h"   

tool_path::tool_path()
{
	type = 1;   
}

void tool_path::getpath(std::string apath, int atype)
{
	type = atype;   
	pathtofolders(apath);
}
void tool_path::setrealpath(vssd_folder *apath, int pos)
{
	 
	realfolders.push_back(apath);
}
void tool_path::testprint()
{
	for (int i = 0; i < folders.size(); i++)
	{
		std::cout << folders.at(i)<< std::endl;
	}
}

bool tool_path::include(tool_path & path1)
{
	for (int i = 1; i < path1.folders.size(); i++)
	{
		if (path1.folders.at(i)== folders[i]) continue;
		else {
			if (path1.folders.size() == folders.size()) {
				return 0;
			}
		}
	}
}

vssd_folder * tool_path::getnowfather()
{
	return realfolders.at(realfolders.size() - 2); 
}

vssd_folder * tool_path::getnow()
{
	return realfolders.at(realfolders.size() - 1);
}


void tool_path::pathtofolders(std::string path)
{
									   
	 

	//将路径准换为folders并赋值给folders
	std::string::size_type pos = 0;
	std::string::size_type beforepos = 0;
	std::string nowstring;
	while (folders.size() <= folders.max_size() && pos != std::string::npos) {
		if ((pos = path.find('\\', beforepos)) != std::string::npos) {
			if (pos != 0 && beforepos <= pos - 1) {
				//找到beforepos+1到pos-1的字符串放入folders数组里，并更改记录
				nowstring = path.substr(beforepos, pos - beforepos);
				if (nowstring != "." && nowstring != "..") {
					vssd_tool::trim(&nowstring);
					folders.push_back(nowstring) ; 
				}
				else if (nowstring == ".." &&folders.size() > 0 && folders.at(folders.size() - 1)!= "..") {
					folders.pop_back();
				}
				else if (nowstring == "..") {
					vssd_tool::trim(&nowstring);
					folders.push_back(nowstring); 
				}

			}
		}
		else if ((pos = path.find('/', beforepos)) != std::string::npos) {
			if (pos != 0 && beforepos <= pos - 1) {
				//找到beforepos+1到pos-1的字符串放入folders数组里，并更改记录
				nowstring = path.substr(beforepos, pos - beforepos);

				if (nowstring != "." && nowstring != "..") {
					vssd_tool::trim(&nowstring);
					folders.push_back(nowstring); 
				}
				else if (nowstring == ".." && folders.at(folders.size() - 1)!= "..") {
					folders.pop_back();
				}
			}
		}
		if (pos != std::string::npos)
			beforepos = pos + 1;
	}
	if (beforepos <= path.length() - 1) {
		nowstring = path.substr(beforepos, path.length() - beforepos);
		vssd_tool::trim(&nowstring);
		if (nowstring != "." && nowstring != "..") {
			vssd_tool::trim(&nowstring);
			folders.push_back(nowstring); 
		}
		else if (nowstring == ".." &&folders.size()>1&& folders.at(folders.size() - 1)!= "..") {
			folders.pop_back();
		}
		else if (nowstring == "..") {
			folders.push_back(".."); 
		}

	}



}
void tool_path::deletone() {
	folders.pop_back();
	realfolders.pop_back(); 

}
void tool_path::addone(vssd_folder *folder) {
	folders.push_back(folder->getname()); 
	realfolders.push_back(folder); 
	
}

tool_path::~tool_path()
{

}

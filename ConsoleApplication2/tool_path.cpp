
#include "pch.h"   

tool_path::tool_path()
{
	type = 1;
	foldersize = 100;
	folderlength = 0;
	realfolderlength = 0;
	realfoldersize = 100;
}

void tool_path::getpath(std::string apath, int atype)
{
	type = atype;
	foldersize = 100;
	folderlength = 0;
	realfolderlength = 0;
	realfoldersize = 100;
	pathtofolders(apath);
}
void tool_path::setrealpath(vssd_folder *apath, int pos)
{
	realfolderlength++;
	realfolders[pos] = apath;
}
void tool_path::testprint()
{
	for (int i = 0; i < folderlength; i++)
	{
		std::cout << folders[i] << std::endl;
	}
}

bool tool_path::include(tool_path & path1)
{
	for (int i = 1; i < path1.folderlength; i++)
	{
		if (path1.folders[i] == folders[i]) continue;
		else {
			if (path1.folderlength == folderlength) {
				return 0;
			}
		}
	}
}

vssd_folder * tool_path::getnowfather()
{
	return realfolders[realfolderlength - 2]; 
}

vssd_folder * tool_path::getnow()
{
	return realfolders[realfolderlength - 1];
}


void tool_path::pathtofolders(std::string path)
{
									   


	//将路径准换为folders并赋值给folders
	std::string::size_type pos = 0;
	std::string::size_type beforepos = 0;
	std::string nowstring;
	while (folderlength <= foldersize && pos != std::string::npos) {
		if ((pos = path.find('\\', beforepos)) != std::string::npos) {
			if (pos != 0 && beforepos <= pos - 1) {
				//找到beforepos+1到pos-1的字符串放入folders数组里，并更改记录
				nowstring = path.substr(beforepos, pos - beforepos);
				if (nowstring != "." && nowstring != "..") {
					vssd_tool::trim(&nowstring);
					folders[folderlength++] = nowstring;
				}
				else if (nowstring == ".." &&folderlength > 0 && folders[folderlength - 1] != "..") {
					folderlength--;
				}
				else if (nowstring == "..") {
					vssd_tool::trim(&nowstring);
					folders[folderlength++] = nowstring;
				}

			}
		}
		else if ((pos = path.find('/', beforepos)) != std::string::npos) {
			if (pos != 0 && beforepos <= pos - 1) {
				//找到beforepos+1到pos-1的字符串放入folders数组里，并更改记录
				nowstring = path.substr(beforepos, pos - beforepos);

				if (nowstring != "." && nowstring != "..") {
					vssd_tool::trim(&nowstring);
					folders[folderlength++] = nowstring;
				}
				else if (nowstring == ".." && folders[folderlength - 1] != "..") {
					folderlength--;
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
			folders[folderlength++] = nowstring;
		}
		else if (nowstring == ".." &&folderlength>1&& folders[folderlength - 1] != "..") {
			folderlength--;
		}
		else if (nowstring == "..") {
			folders[folderlength++] = ".."
		}

	}



}
void tool_path::deletone() {
	folderlength--;
	realfolderlength--;

}
void tool_path::addone(vssd_folder *folder) {
	folders[folderlength++] = folder->getname();
	realfolders[realfolderlength++] = folder;
}

tool_path::~tool_path()
{

}

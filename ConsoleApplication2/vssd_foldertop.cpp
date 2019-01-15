#include "pch.h" 
 


 
void vssd_foldertop::shownowpositionforcmd() {
	std::cout << "VSSD : Now at " ;
	for (size_t i = 0; i < nowpath.folderlength; i++)
	{
		std::cout << nowpath.realfolders[i]->getname() << '/';
	}
	
	std::cout << " , you will say:";
}
void vssd_foldertop::shownowposition() {
	std::cout << "VSSD : Now at ";
	for (size_t i = 0; i < nowpath.folderlength; i++)
	{
		std::cout<< nowpath.realfolders[i]->getname() << '/';
	}
	std::cout << std::endl;
}
vssd_foldertop::vssd_foldertop(vssd_folder * aroot )
{
	 
	root = aroot;
	nowposition = aroot;
	nowpath.getpath("C:", 1);
	nowpath.getrealpath(aroot);
}

void vssd_foldertop::newroot(vssd_folder * aroot)
{
	root = aroot;
}
//根据目前目录位置和相对路径查找
vssd_folder * vssd_foldertop::find(tool_path & apath)		
{
	vssd_folder * nowfolder = nowposition;
	for (int i = 0; i < apath.folderlength; i++)
	{
		nowfolder = nowfolder->find(apath.folders[i]);
		if (!nowfolder) {
			//无

			return nullptr;
		} 
	}
	return nowfolder;


}
 

void vssd_foldertop::refresh()
{
	nowposition = nowpath.realfolders[nowpath.realfolderlength - 1];

}

vssd_foldertop::~vssd_foldertop()
{
}

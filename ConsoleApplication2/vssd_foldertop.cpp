#include "pch.h" 
 


 
vssd_folder * vssd_foldertop::getnowposition()
{
	return nowpath.getnow();
}

void vssd_foldertop::shownowpositionforcmd() {
	std::cout << "VSSD : Now at " ;
	for (size_t i = 1; i < nowpath.folderlength; i++)
	{
		std::cout << nowpath.realfolders[i]->getname() << '/';
	}
	
	std::cout << " , you will say:";
}
void vssd_foldertop::shownowposition() {
	std::cout << "VSSD : Now at ";
	for (size_t i = 1; i < nowpath.folderlength; i++)
	{
		std::cout<< nowpath.realfolders[i]->getname() << '/';
	}
	std::cout << std::endl;
}
vssd_foldertop::vssd_foldertop(vssd_folder * aroot, vssd_folder * agenius)
{
	root = aroot; 
	nowpath.getpath(" \\c:\\", 1);
	nowpath.setrealpath(agenius,0);
	nowpath.setrealpath(aroot,1);

}
 
void vssd_foldertop::newroot(vssd_folder * aroot)
{
	root = aroot;
}
//根据目前目录位置和相对路径查找
vssd_folder * vssd_foldertop::find(tool_path & apath)		
{
	vssd_folder * nowfolder = getnowposition();
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
 

 

vssd_foldertop::~vssd_foldertop()
{
}

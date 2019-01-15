#pragma once 


class tool_path
{ 

public: 
	int type;		//2相对 1绝对（root开头）
	vssd_folder *relatverealfolder;
	int folderlength;  
	int foldersize;
	void pathtofolders(std::string path); //路径字符串到路径对象
	std::string folders[100];
	vssd_folder *realfolders[100];
	int realfolderlength;
	int realfoldersize;
	void deletone();
	void addone(vssd_folder * folder); 
	tool_path();
	void getpath(std::string path, int type);
	void setrealpath(vssd_folder * apath,int pos);
	void testprint();
	bool include(tool_path & path1);			//未完成
	vssd_folder *getnowfather();
	vssd_folder *getnow();
	~tool_path();
}; 

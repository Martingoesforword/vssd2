#pragma once 


class tool_path
{ 

public: 
	int type;		//2相对 1绝对（root开头） 
	void pathtofolders(std::string path); //路径字符串到路径对象
	 
	std::vector<std::string> folders; 
	std::vector<vssd_folder *>realfolders; 
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

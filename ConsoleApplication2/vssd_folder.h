#pragma once 
class vssd_folder :public vssd_canbelinked
{
private:
	
	 

public: 
	std::string name;




	vssd_folder *subfolders[100];
	int foldersize;
	int folderlength;
	vssd_file *subfiles[100];
	int filesize;
	int filelength;
	vssd_link *sublinks[100];
	int linksize;
	int linklength;
	 
	virtual std::string gettype();
	vssd_folder(std::string name); 
	void vssd_folder_link(vssd_folder * linktosub);
	std::string getname();
	void build(tool_path & a); 
	void vssd_folder_init(); 
	void vssd_file_link(vssd_file * linktosub);
	void showoffsub();
	void deletone(vssd_folder *deletfolder);
	void offone(vssd_folder * deletfolder);
	void deletevery(); 
	void setname(std::string &name);
	void vssd_link_link(vssd_link *linktosub);
	vssd_folder ** findnext(); 
	vssd_folder *find(std::string &folder);//搜索本目录下文件
	vssd_folder *find(tool_path * apath,int pathpos);//搜索本目录下包括子目录文件
	std::string vssdtypename = "FOLDER";
	~vssd_folder();
};

#pragma once
class tool_vcmd
{
private:

public:
	static void comein(vssd & myvssd, std::string &command); 
	static void vdir(vssd_foldertop* top);
	static void vrd(vssd & myvssd, std::string & dircommand);
	static void vdir(vssd & myvssd, std::string & dircommand);
	static vssd_folder * v_findpath(vssd & myvssd, std::string & dircommand, tool_path & apath); 
	static void vcd(vssd & myvssd, std::string & command);
	static void vmd(vssd & myvssd, std::string & command); //根据目前文件夹或者根据绝对路径创建
	static void vmove(vssd & myvssd, std::string & src, std::string & dis);
	static void vmove(vssd & myvssd, std::string & src);
	static void vcd(vssd_foldertop* top);
	static void vrd(vssd & myvssd); 
	static void vren(vssd & myvssd, std::string & command);
	static void vren(vssd & myvssd, std::string & srccommand, std::string & disname);
	static void vcls();
	static void v_jump(vssd & myvssd, std::string & jumpto);
	static void vmove(vssd & myvssd, tool_path & dispath);
	
	tool_vcmd();
	~tool_vcmd();
};


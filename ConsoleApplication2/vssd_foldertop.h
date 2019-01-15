#pragma once
#include "pch.h"   
class vssd_foldertop
{
private:
	
public:
	tool_path nowpath;
	vssd_folder* root;
	vssd_folder* nowposition;  
	void shownowpositionforcmd();
	void shownowposition();
	vssd_foldertop(vssd_folder* root);
	void newroot(vssd_folder* root);
	vssd_folder* find(tool_path &apath);
	void refresh();
	~vssd_foldertop();
}; 

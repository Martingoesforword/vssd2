#pragma once 

#include <string>
#include <iostream> 
#include <vector> 
class vssd_folder;
class vssd_foldertop;
class tool_path;
class vssd_file;
class canbelinked;
class vssd;
class vcmd;
class vssd_link;
class vssd_tool;


#include "vssd_tool.h"
#include "tool_path.h"				//tool_path在下面类中的属性里以实例存在，需要提前写 
#include "vssd_foldertop.h"			 
#include "vssd_canbelinked.h"			//基类canbelinked放到vssd_file vssd_folder vssd_link 之前 
#include "vssd_folder.h"  
#include "vssd.h" 
#include "tool_vcmd.h" 



/*



*/

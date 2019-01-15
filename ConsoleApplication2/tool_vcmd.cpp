#include "pch.h" 

//当下文件夹下dir
void tool_vcmd::vdir(vssd_foldertop * top)
{
	top->nowposition->showoffsub();
}
//当下文件夹下cd
void tool_vcmd::vcd(vssd_foldertop * mytop) 
{

	mytop->shownowposition();
}
//当下文件夹下rd
void tool_vcmd::vrd(vssd & myvssd) {
	if (myvssd.getnowtop()->nowpath.realfolderlength >= 2) {
		myvssd.getnowtop()->nowpath.realfolders[myvssd.getnowtop()->nowpath.realfolderlength - 2]->deletone(myvssd.getnowtop()->nowposition);

		myvssd.getnowtop()->nowpath.deletone();
		myvssd.getnowtop()->refresh();
		std::cout << "VSSD ERROR : Nowposition folder is deleted just！" << std::endl;
	}
	else {
		std::cout << "VSSD ERROR : Root folder cannot be deleted！" << std::endl;
	}
	

}

void tool_vcmd::vrd(vssd & myvssd, std::string & dircommand)
{
	std::string aa = dircommand;
	vssd_tool::trim(aa);
	vssd_folder * f = myvssd.getnowtop()->nowposition->find(aa);
	if (f == nullptr) {
		//未发现			//还是通过链表实现比较好
		std::cout << "VSSD ERROR : The folder is not exist! " << std::endl;
	}
	else {
		 //删除某个文件夹，应该是父文件夹的功能
		myvssd.getnowtop()->root->deletone(f);

	}
}
void tool_vcmd::vdir(vssd & myvssd, std::string & dircommand)
{
	vssd_foldertop *mytop = myvssd.getnowtop();
	tool_path nowpath = mytop->nowpath;
	std::string a = dircommand;
	vssd_tool::trim(&a);
	if (a.length() == 2 && a.at(1) == ':') {	//直接跳长度为2的盘符名  dir d:    不可dir d:\

		vssd_foldertop* top = myvssd.findtop(a);
		top->root->showoffsub();

	}
	else if (a.compare("..") == 0) {		
		if (nowpath.folderlength >= 2) {
			nowpath.folderlength--;
			nowpath.realfolderlength--;
			nowpath.realfolders[nowpath.realfolderlength-1]->showoffsub();
		}
		else {		//可以实现显示磁盘的功能
			std::cout << "VSSD ERROR : The father of topfolder is always not exist! " << std::endl;
		}
	}
	else if (a.compare(".") == 0) {
		mytop->nowposition->showoffsub();
	}
	else {
		tool_path dirrear_path;
		dirrear_path.pathtofolders(a);
		
		vssd_folder * longnowf;
		for (int i = 0; i < dirrear_path.folderlength; i++)
		{
			if (dirrear_path.folders[i] == "..") {
				nowpath.deletone();
			}
			else if (dirrear_path.folders[i] == ".") {
			}
			else{
				longnowf = nowpath.realfolders[nowpath.realfolderlength-1]->find(dirrear_path.folders[i]);
				if (!longnowf) {
					std::cout << "VSSD ERROR : The folder is not exist! " << std::endl;
					 
					return;
				}
				nowpath.addone(longnowf);
			}
			
		}
		nowpath.realfolders[nowpath.realfolderlength - 1]->showoffsub();

	}
}

void tool_vcmd::vcd(vssd & myvssd, std::string & cdcommand)
{
	vssd_foldertop *mytop = myvssd.getnowtop();
	tool_path cdpath;
	tool_path nowpath = mytop->nowpath;
	std::string a = cdcommand;
	//cdpath.getpath(a,2); 
	vssd_tool::trim(&a);
	if (a.length() == 2 && a.substr(1,1).compare(":") == 0) {	//直接跳长度为2的盘符名
		 
		vssd_foldertop* top = myvssd.findtop(a);
		myvssd.setnowtop(top);

	}else if (a.compare("..") == 0) {
		if (mytop->nowpath.folderlength >= 2) {
			mytop->nowpath.folderlength--;
			mytop->nowpath.realfolderlength--;
			mytop->nowposition = mytop->nowpath.realfolders[mytop->nowpath.folderlength - 1];
			mytop->shownowposition();
		}
		else {
			std::cout << "VSSD ERROR : The father of topfolder is always not exist! " << std::endl;
		}
	}
	else if (a.compare(".") == 0) {
		mytop->shownowposition();
	}
	else {

		tool_path dirrear_path;
		dirrear_path.pathtofolders(a);

		vssd_folder * longnowf;
		for (int i = 0; i < dirrear_path.folderlength; i++)
		{
			if (dirrear_path.folders[i] == ".." ) {
				if (nowpath.realfolderlength < 2) {
					std::cout << "VSSD ERROR : The father of topfolder is always not exist! "  << std::endl;
				}
				else {
					nowpath.deletone();
				}
				
			}
			else if (dirrear_path.folders[i] == ".") {
			}
			else {
				longnowf = nowpath.realfolders[nowpath.realfolderlength - 1]->find(dirrear_path.folders[i]);
				if (!longnowf) {
					std::cout << "VSSD ERROR : The folder is not exist! " << std::endl;

					return;
				}
				nowpath.addone(longnowf);
			}

		}
		mytop->nowpath = nowpath;
		mytop->nowposition = nowpath.realfolders[nowpath.realfolderlength - 1];
	  
	}
}

//改名--目前路径
void tool_vcmd::vren(vssd & myvssd, std::string & rencommand) {




	if (!myvssd.getnowtop()->nowpath.realfolders[myvssd.getnowtop()->nowpath.realfolderlength - 2]->find(rencommand)) {
		if (myvssd.getnowtop()->nowposition->getname() != myvssd.getnowtop()->root->getname())
			myvssd.getnowtop()->nowposition->setname(rencommand);
	}
	else {
		std::cout << "VSSD ERROR : The folder has already existed! " << std::endl;

	}
	
}

void tool_vcmd::vren(vssd & myvssd, tool_path & srccommand, std::string & disname) {
	vssd_folder *folder =  myvssd.getnowtop()->find(srccommand);
	if (folder) {
		folder->setname(disname);
	}
	else {
		std::cout << "VSSD ERROR : The folder is not exist! "  << std::endl;
	}
}

void tool_vcmd::vmd(vssd & myvssd, std::string & mdcommand)
{

	tool_path mdpath;
	mdpath.getpath(mdcommand,2);
	if (mdpath.folderlength == 1) {
		if (!myvssd.getnowtop()->nowposition->find(mdpath.folders[0])) {
			vssd_folder *newfolder = new vssd_folder(mdpath.folders[0]);
			myvssd.getnowtop()->nowposition->vssd_folder_link(newfolder);
		}
		else {
			std::cout << "VSSD ERROR : The folder has already existed! " << std::endl;
		}
		
	}

	
}
void tool_vcmd::vmove(vssd & myvssd, tool_path & dispath) {

	vssd_folder *folder = myvssd.getnowtop()->find(dispath);
	if (folder) {
		folder->vssd_folder_link(myvssd.getnowtop()->nowposition); 
	}

}
 
void tool_vcmd::vcls()
{
	system("cls");
}
void tool_vcmd::vjump(vssd & myvssd, std::string & jumpto)
{
	vssd_foldertop* top = myvssd.findtop(jumpto);
	myvssd.setnowtop(top);
}

void tool_vcmd::comein(vssd & myvssd, std::string & cmdcommand)
{
	vssd_foldertop *mytop = myvssd.getnowtop();
	vssd_tool::trim(cmdcommand);
	std::string rear;

	//分析命令名与命令参数
	if (cmdcommand.length() == 0) {
			
	}
	//dir命令解析
	else if (cmdcommand.length() >= 3 && cmdcommand.substr(0,3).compare("dir") == 0) {			
		if (cmdcommand.length() == 3) {
			vdir(mytop);
		}
		else {
			rear = cmdcommand.substr(3, cmdcommand.length() - 3);
			vssd_tool::trim(rear);
			vdir(myvssd,rear);
		}
		
	}

	//cd命令解析
	else if (cmdcommand.length() >= 2 && cmdcommand.substr(0, 2).compare("cd") == 0) {
		if (cmdcommand.length() == 2) {
			vcd(mytop);
		}
		else {
			rear = cmdcommand.substr(2, cmdcommand.length() - 2);
			vssd_tool::trim(rear);
			vcd(myvssd, rear);
		}

	} 
	//rd命令解析
	else if (cmdcommand.length() >= 2 && cmdcommand.substr(0, 2).compare("rd") == 0) {
		if (cmdcommand.length() == 2) {
			vrd(myvssd);
		}
		else {
			rear = cmdcommand.substr(2, cmdcommand.length() - 2);
			vssd_tool::trim(rear);
			vrd(myvssd, rear);
		}

	}
	//ren命令解析
	else if (cmdcommand.length() > 3 && cmdcommand.substr(0, 3).compare("ren") == 0) {
		
		tool_path rensrcpath;	 

		rear = cmdcommand.substr(3, cmdcommand.length() - 3);
		int spacepos = rear.find(" ", 1);
		if (spacepos != -1) {

			std::string rearsrc = rear.substr(0, spacepos);
			std::string reardisname = rear.substr(spacepos + 1, rear.length() - spacepos);
			rensrcpath.getpath(rearsrc,2);
			
			vren(myvssd, rensrcpath, reardisname);

		}
		else {
			std::string rearsrc = rear;
			vssd_tool::trim(rear);
			vren(myvssd, rear);
		}
		
		 
		//解释
		//0123456789
		//023203 323

	}
	//move命令解析
	else if (cmdcommand.length() > 4 && cmdcommand.substr(0, 4).compare("move") == 0) {

		tool_path rensrcpath;
		tool_path rendispath;
		rear = cmdcommand.substr(4, cmdcommand.length() - 4);
		vssd_tool::trim(rear);
		int spacepos = rear.find(" ", 0);
		if (spacepos != -1) {

			std::string rearsrc = rear.substr(0, spacepos);
			std::string reardis = rear.substr(spacepos + 1, rear.length() - spacepos);
			rensrcpath.getpath(rearsrc, 2);
			rendispath.getpath(reardis, 2);
			//vmove(myvssd, rensrcpath, rendispath);

		}
		else {
			std::string rearsrc = rear;
			rendispath.getpath(rear, 2);
			vssd_tool::trim(rear);
			vmove(myvssd, rendispath);
		}


		//解释
		//0123456789
		//023203 323

	}
	//跳转盘命令解析
	else if (cmdcommand.length() == 2 && cmdcommand.at(1) == ':') {
		rear = cmdcommand;
		vjump(myvssd, rear);
	}
	//清屏命令解析
	else if (cmdcommand.length() == 3 && cmdcommand.compare("cls") == 0) {
		vcls();
	}
	//创建文件夹命令解析
	else if (cmdcommand.length() > 2 && cmdcommand.substr(0, 2).compare("md") == 0) {
		 
		rear = cmdcommand.substr(2, cmdcommand.length() - 2);
		vssd_tool::trim(rear);
		vmd(myvssd, rear);

	}
	  
}


tool_vcmd::tool_vcmd()
{
}


tool_vcmd::~tool_vcmd()
{
}

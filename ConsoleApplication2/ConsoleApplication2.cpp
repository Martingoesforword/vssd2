// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
 
#include "pch.h" 
 
int main()
{
	 

    std::cout << "Hello! My name is VirtualSSD, Now you will type command for my work\n"; 
	std::string command;
	/**
	std::cin >> command;
	vssd_path p1(command,1);
	p1.testprint();
	*/

	vssd_folder genius("",1); 
	
	vssd_folder c_pan("c:",1);//新建根目录
	vssd_foldertop mytopcpan(&c_pan, &genius);//加载根目录
	vssd myvssd(&mytopcpan, &genius,"firstvssd");
	myvssd.linktop(&mytopcpan);
	

	vssd_folder sjhc("sjh",1);
	vssd_folder f1c("src",1);
	vssd_folder f2c("app",1);
	vssd_folder f3c("src",1);
	vssd_folder f4c("app",1);

	vssd_foldertop *mytop = myvssd.getnowtop();
	vssd_folder * Now = mytop->root;

	Now->vssd_folder_link(&sjhc);
	Now->vssd_folder_link(&f1c);
	Now->vssd_folder_link(&f2c);
	f2c.vssd_folder_link(&f3c);
	f2c.vssd_folder_link(&f4c); 
	
	//创建卷2:d盘
	vssd_folder d_pan("d:",1);//新建根目录
	vssd_foldertop mytopdpan(&d_pan, &genius);//加载根目录
	myvssd.linktop(&mytopdpan);
	vssd_folder sjhd("sjh2",1);
	vssd_folder songtxt("song.txt", 0);
	vssd_folder f1d("src2",1);
	vssd_folder f2d("app2",1);
	vssd_folder f3d("src2",1);
	vssd_folder f4d("app2",1); 
	vssd_folder * nowd = mytopdpan.root; 
	nowd->vssd_folder_link(&sjhd);
	nowd->vssd_folder_link(&f1d);
	nowd->vssd_folder_link(&f2d);
	nowd->vssd_folder_link(&songtxt);
	f2d.vssd_folder_link(&f3d);
	f2d.vssd_folder_link(&f4d);  
	/*std::cout << "目前磁盘无文件，文件夹有：\n c:\\sjh c:\\src c:\\app c:\\app\\src c:\\app\\app \n d:\\sjh2 d:\\src2 d:\\app2 d:\\app2\\src2 d:\\app2\\app2" << std::endl;
	std::cout << "目前实现命令：cd [磁盘:][..][.][无..和.的相对路径]\n 例如:cd app/sjh"<<std::endl;
	std::cout << "\t命令：cls 命令：dir " << std::endl;*/

	genius.vssd_folder_link(&d_pan);
	genius.vssd_folder_link(&c_pan); 
	songtxt.setcontentstring("fdhhgdfjgh草");
	//非1
	//非2
	while(1){
		mytop = myvssd.getnowtop();
		mytop->shownowpositionforcmd();
		std::getline(std::cin, command); 
		tool_vcmd::comein(myvssd, command);



		

	}

	//获得命令command（命令）的首字符串code
	//对比code进入选项
	//若为dir，则分析之后的command并将之后的转化为路径（对象）

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

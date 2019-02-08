// blogTidyTool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
using namespace std;
bool firstRun();

int main(int argc, char *argv){
	cout << firstRun() << endl;
	printf("	-请将博客文本文件置于in文件夹");
	printf("	-请选择博客文本文件");
}

bool firstRun() {
	fstream runingSpace;
	runingSpace.open("configurationFile", ios::in);
	if (!runingSpace)return false;
	runingSpace.close();

	string g_sSamplePath = "./train/";
	DIR *dir;
	if ((dir = opendir(g_sSamplePath.c_str())) == NULL)
	return true;
}

/**
	  *最初以txt文件输入，整理出第一版xml文件
	  *在第一版xml文件中编辑html内容，最终输出第二版xml文件
	  *
	  *txt文件需加入适当段落排版：换行、断句
	  *第一版xml文件需包含：生成日期、是否存在引用、作者、基于bootstrap的排版要求。
	  *第二版xml文件需继承第一版xml文件所有内容，并将文本置于合法的bootstrap排版中。
	  *
	  *需生成历史文件，按时间留备份档。
   */

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
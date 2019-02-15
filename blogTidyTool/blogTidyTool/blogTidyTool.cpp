// blogTidyTool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include "source.h"
using namespace std;
using namespace tinyxml2;

Source user;

int main(int argc, char *argv){
	readyRun(user)? printf("	-发现历史文件与目录"): firstReadyRun(user);
	system("pause");
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
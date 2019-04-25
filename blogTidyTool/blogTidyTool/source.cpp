#include "pch.h"
#include "source.h"

using namespace std;
using namespace tinyxml2;

bool readyRun(Source user) {
	if (_access("con.xml",0))return false;

	DIR *dir;
	if ((dir = opendir(user.getPath('i').c_str())) == NULL)return false;
	if ((dir = opendir(user.getPath('o').c_str())) == NULL)return false;
	if ((dir = opendir(user.getPath('b').c_str())) == NULL)return false;
	if ((dir = opendir(user.getPath('l').c_str())) == NULL)return false;
	return true;
}

bool firstReadyRun(Source user) {
	printf("	-程序第一次运行或关键文件缺失，输入‘N’以退出，输入其他以继续（单个字符）");
	char order[10];
	cin.getline(order,10);
	switch (order[0]) {
	case 'N':
		system("exit"); 
		break;
	default:
		if (!(	system(("md " + user.getPath('i')).c_str()		)&
				system(("md " + user.getPath('o')).c_str()	)&
				system(("md " + user.getPath('b')).c_str()	)&
				system(("md " + user.getPath('l')).c_str()		)))return false;

		XMLDocument con = new XMLDocument;
		auto decl_con = con.NewDeclaration();//添加默认的xml头
		con.InsertFirstChild(decl_con);
		//输出节点，需包含使用者，使用日期，使用次数
		//创建节点对象
		auto root_carrier = con.NewElement("carrier");//根元素
		auto second_usedReoras = root_carrier->FirstChildElement("usedReord");//记录：创建使用记录。

		// 输出XML至文件	
		cout << "output xml to 'con.xml'" << endl;
		system("type nul>con.xml");
		con.SaveFile( "con.xml" );	// 输出XML至内存
		cout << endl;
		cout << "output xml to memory" << endl		 << "--------------------" << endl;	
		XMLPrinter con_printer;
		con.Print( &con_printer );	
		cout << con_printer.CStr();
		break;
	}

	return true;
}
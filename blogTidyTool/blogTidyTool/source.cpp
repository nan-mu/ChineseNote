#include "pch.h"
#include "source.h"

using namespace std;
using namespace tinyxml2;

bool readyRun(Source user) {
	fstream runingSpace;
	runingSpace.open("configurationFile.xml", ios::in);
	if (!runingSpace)return false;
	runingSpace.close();

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
	default:
		if (!(	system(("md " + user.getPath('i')).c_str()		)&
				system(("md " + user.getPath('o')).c_str()	)&
				system(("md " + user.getPath('b')).c_str()	)&
				system(("md " + user.getPath('l')).c_str()		)))return false;

		XMLDocument configurationFile;
		configurationFile.Parse("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>");
		//输出节点，需包含使用者，使用日期，使用次数

		printf("%d",configurationFile.SaveFile("configurationFile.xml"));
		XMLElement* root_Operating = configurationFile.RootElement();
		XMLElement* first_User = configurationFile.NewElement("User");

		break;

	}

	return true;
}
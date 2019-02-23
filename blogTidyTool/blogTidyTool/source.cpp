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
	printf("	-�����һ�����л�ؼ��ļ�ȱʧ�����롮N�����˳������������Լ����������ַ���");
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
		//����ڵ㣬�����ʹ���ߣ�ʹ�����ڣ�ʹ�ô���

		printf("%d",configurationFile.SaveFile("configurationFile.xml"));
		XMLElement* root_Operating = configurationFile.RootElement();
		XMLElement* first_User = configurationFile.NewElement("User");

		break;

	}

	return true;
}
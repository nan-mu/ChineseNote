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
	printf("	-�����һ�����л�ؼ��ļ�ȱʧ�����롮N�����˳������������Լ����������ַ���");
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
		auto decl_con = con.NewDeclaration();//���Ĭ�ϵ�xmlͷ
		con.InsertFirstChild(decl_con);
		//����ڵ㣬�����ʹ���ߣ�ʹ�����ڣ�ʹ�ô���
		//�����ڵ����
		auto root_carrier = con.NewElement("carrier");//��Ԫ��
		auto second_usedReoras = root_carrier->FirstChildElement("usedReord");//��¼������ʹ�ü�¼��

		// ���XML���ļ�	
		cout << "output xml to 'con.xml'" << endl;
		system("type nul>con.xml");
		con.SaveFile( "con.xml" );	// ���XML���ڴ�
		cout << endl;
		cout << "output xml to memory" << endl		 << "--------------------" << endl;	
		XMLPrinter con_printer;
		con.Print( &con_printer );	
		cout << con_printer.CStr();
		break;
	}

	return true;
}
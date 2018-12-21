// tinyTool.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
using namespace std;

string Lpcwstr2String(LPCWSTR lps);
string get_path();

int main()
{
	fstream  Fenglish, Fchina, Fout;
	printf("选择英文单词文件");
	Fenglish.open(get_path(), ios::in);
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b选择中文翻译文件\n");
	Fchina.open(get_path(), ios::in);

	Fout.open("d:\\a.txt", ios::app);
	string BeWorkWord; int BeWordLanguage = 0;
	while (getline(Fenglish, BeWorkWord)) {
		Fout << BeWorkWord;
		for (int i = 0; i < interval; i++)Fout << '。';
		getline(Fchina, BeWorkWord);
		Fout << BeWorkWord;
		for (int i = 0; i < interval; i++)Fout << '。';
		Fout << endl;
	}
	Fchina.close();
	Fenglish.close();
	Fout.close();
	printf("编排完成");
}

string Lpcwstr2String(LPCWSTR lps) {//将一个LPCWSTR转换为string
	int len = WideCharToMultiByte(CP_ACP, 0, lps, -1, NULL, 0, NULL, NULL);
	if (len <= 0) { return ""; }
	else {
		char *dest = new char[len];
		WideCharToMultiByte(CP_ACP, 0, lps, -1, dest, len, NULL, NULL);
		dest[len - 1] = 0;
		string str(dest);
		delete[] dest;
		return str;
	}
}

string get_path() {//新建一个对话窗口，选择文件
	OPENFILENAME ofn;	char szFile[300];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = (LPWSTR)szFile;
	ofn.lpstrFile[0] = '\0';
	LPTSTR lpstrCustomFilter;
	DWORD nMaxCustFilter;
	ofn.nFilterIndex = 1;
	LPTSTR lpstrFile;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"ALL\0*.*\0Text\0*.TXT\0";
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	string path = "";
	if (GetOpenFileName(&ofn)) { path = Lpcwstr2String(ofn.lpstrFile);		return path; }
	else { return ""; }
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

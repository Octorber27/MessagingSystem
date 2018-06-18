#include "Myfunction.h"
#include "NekoparaSPG.h"

int main()
{
	NekoparaSPG a;
	int i;
	bool flag = true;
	while (flag = true) {
		flag = false;
		system("COLOR 0b");       //背景和字体颜色
		cout << "-------------------------欢迎来到简易QQ-------------------------\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "|                          请选择要进行的操作                          |\n";
		cout << "-----------------------------------------------------------------------|\n";
		cout << "|         1.申请QQ                  |         2.查询QQ信息             |\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "|         3.管理好友信息            |         4.微博相关操作           |\n";
		cout << "---------------------------------------------- --------------------------\n";
		cout << "|         5.微信相关操作            |         6.群管理                 |\n";
		cout << "------------------------------------------------------------------------\n";
		cin >> i;
		switch (i) {
		case 1:
			InformationSPG(a);
			flag = true;
			break;
		case 2:
			SearchSPG(a);
			flag = true;
			break;
		case 3:
			ChooseSPG(a);
			flag = true;
			break;
		case 4:
			NekoparaWeiboSPG(a);
			flag = true;
			break;
		case 5:
			NekoparaWeixinSPG(a);
			flag = true;
			break;
		case 6:
			NekoparaQunSPG(a);
			flag = true;
			break;
		default:
			cout << "error!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}
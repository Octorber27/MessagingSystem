#include "Myfunction.h"
#include "NekoparaSPG.h"

int main()
{
	NekoparaSPG a;
	int i;
	bool flag = true;
	while (flag = true) {
		flag = false;
		system("COLOR 0b");       //������������ɫ
		cout << "-------------------------��ӭ��������QQ-------------------------\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "|                          ��ѡ��Ҫ���еĲ���                          |\n";
		cout << "-----------------------------------------------------------------------|\n";
		cout << "|         1.����QQ                  |         2.��ѯQQ��Ϣ             |\n";
		cout << "------------------------------------------------------------------------\n";
		cout << "|         3.���������Ϣ            |         4.΢����ز���           |\n";
		cout << "---------------------------------------------- --------------------------\n";
		cout << "|         5.΢����ز���            |         6.Ⱥ����                 |\n";
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
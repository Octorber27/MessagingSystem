#include "Myfunction.h"


int TimeSPG(int a, int b, int c)
{
	int  i;
	i = 1;
	if ((b == 1) || (b == 3) || (b == 5) || (b == 7) || (b == 8) || (b == 10) || (b == 12)) {
		if ((c >= 1) || (c <= 31)) {
			i = 1;
		}
		else
			i = 2;
		if ((b == 4) || (b == 6) || (b == 9) || (b == 11)) {
			if ((c >= 1) || (c <= 30)) {
				i = 1;
			}
			else
				i = 2;
		}
		if (b == 2) {
			if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {
				if ((c >= 1) || (c <= 29)) {
					i = 1;
				}
				else
					i = 2;
			}
			else
				if ((c >= 1) || (c <= 28)) {
					i = 1;
				}
				else
					i = 2;
		}
	}
	return i;
}

void SaveSPG(NekoparaSPG a)
{
	string x;
	x = a.number;
	ofstream outfile((x + "_QQ.txt").c_str(), ios::out);
	ofstream outfil((x + "Py.txt").c_str(), ios::out);
	outfile << a.number << " ";
	outfile << a.nich << " ";
	outfile << a.birthday.y << " " << a.birthday.m << " " << a.birthday.d << " ";
	outfile << a.hometown.nation << " ";
	outfile << a.hometown.province << " ";
	outfile << a.hometown.city << endl;
	outfile.close();
	outfil.close();
}

void InformationSPG(NekoparaSPG a)
{
	int i;
	cout << "请输入您的个人信息\n" << endl;
	cout << "昵称：" << endl;
	cin >> a.nich;
	cout << "出生日期（年 月 日*中间用空格间隔）：" << endl;
	cin >> a.birthday.y >> a.birthday.m >> a.birthday.d;
	cout << "所在地（国家 省份 城市*中间用空格间隔）：" << endl;
	cin >> a.hometown.nation >> a.hometown.province >> a.hometown.city;
	i = TimeSPG(a.birthday.y, a.birthday.m, a.birthday.d);
	while (i != 1) {
		cout << "格式错误，请重新填写";
		cout << "请重新输入您的个人信息：" << endl;
		cout << "昵称：" << endl;
		cin >> a.nich;
		cout << "出生日期（年 月 日*中间用空格间隔）：" << endl;
		cin >> a.birthday.y >> a.birthday.m >> a.birthday.d;
		cout << "所在地（国家 省份 城市*中间用空格间隔）：" << endl;
		cin >> a.hometown.nation >> a.hometown.province >> a.hometown.city;
	}
	int j, b[6];
	for (j = 0; j<6; j++) {
		b[j] = 0;
		srand(time(0));
		for (int j = 0; j<6; j++) {
			b[j] = rand() % 6;
		}
		char str[16];
		for (j = 0; j<6; j++) {
			sprintf_s(&str[j], 2, "%d", b[j]);
		}
		str[j] = '\0';
		a.number = str;
	}
	cout << "注册成功，您的QQ号为" << a.number << endl;
	SaveSPG(a);
	struct tm t_tm;
	time_t timer;
	time(&timer);
	localtime_s(&t_tm, &timer);
	a.tm.y = t_tm.tm_year + 1900;
	a.tm.m = t_tm.tm_mon + 1;
	a.tm.d = t_tm.tm_mday;
}

int SearchSPG(NekoparaSPG a)
{
	string x;
	int m, n;
	struct tm t_tm;
	time_t timer;
	time(&timer);
	localtime_s(&t_tm, &timer);
	m = t_tm.tm_year + 1900;
	n = m - a.tm.y + 1;
	cout << "请输入您要查询的QQ号:";
	cin >> x;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "您要查询的QQ不存在" << endl;
		return 0;
	}
	infile >> a.number;
	infile >> a.nich;
	infile >> a.birthday.y;
	infile >> a.birthday.m;
	infile >> a.birthday.d;
	infile >> a.hometown.nation;
	infile >> a.hometown.province;
	infile >> a.hometown.city;
	cout << "QQ：";
	cout << a.number << " ";
	cout << "昵称：";
	cout << a.nich << " ";
	cout << "出生日期：";
	cout << a.birthday.y << " " << a.birthday.m << " " << a.birthday.d << " ";
	cout << "所在地：";
	cout << a.hometown.nation << " " << a.hometown.province << " " << a.hometown.city << " " << endl;
	infile.close();
	return 0;
}

int AddPySPG(NekoparaSPG a)
{
	string x, y, z;
	cout << "请输入您要添加的QQ号：";
	cin >> z;
	x = z;
	y = a.number;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "该QQ不存在";
		return 0;
	}
	ofstream outfil((y + "Py.txt").c_str(), ios::app);
	outfil << z << endl;
	outfil.close();
	cout << "好友已添加";
	return 0;
}

int DeletePySPG(NekoparaSPG a)
{
	string x, z;
	NekoparaSPG*y = new NekoparaSPG[10];
	int i, j, k;
	i = 0, j = 0, k = 0;
	cout << "请输入您要删除的好友QQ：";
	cin >> z;
	x = a.number + "Py.txt";
	const char*in = x.c_str();
	ifstream infil(in, ios::in);
	while (!infil.eof()) {
		infil >> y[i].number;
		i = i + 1;
	}
	if (y[j].number != z) {
		j += 1;
	}
	infil.close();
	ofstream outfile(in, ios::out);
	for (k = 0; k<j; k++) {
		outfile << y[k].number << endl;
	}
	for (k = j + 1; k<10; k++) {
		outfile << y[k].number << endl;
	}
	cout << "该好友已移除";
	return 0;
}

int SearchPySPG(NekoparaSPG a)
{
	NekoparaSPG*y = new NekoparaSPG[10];
	string x, z;
	int i, j;
	i = 0;
	j = 0;
	cout << "请输入您要查询的QQ号";
	cin >> z;
	x = a.number + "Py.txt";
	const char*in = x.c_str();
	ifstream infil(in, ios::in);
	while (!infil.eof()) {
		infil >> y[i].number;
		i = i + 1;
	}
	while (y[j].number != z) {
		if (j = 10) {
			cout << "您没有该用户好友。" << endl;
			return 0;
		}
		j = j + 1;
	}
	z = z + "_QQ.txt";
	const char* cin = z.c_str();
	ifstream infile(cin, ios::in);
	if (!infile) {
		cout << "查询的QQ不存在";
		return 0;
	}
	infile >> a.number;
	infile >> a.nich;
	infile >> a.birthday.y;
	infile >> a.birthday.m;
	infile >> a.birthday.d;
	infile >> a.hometown.nation;
	infile >> a.hometown.province;
	infile >> a.hometown.city;
	cout << a.number << " ";
	cout << a.nich << " ";
	cout << a.birthday.y << " " << a.birthday.m << " " << a.birthday.d << " ";
	cout << a.hometown.nation << " " << a.hometown.province << " " << a.hometown.city << " ";
	infile.close();
	return 0;
}

int SearchSamePySPG(NekoparaSPG a)
{
	NekoparaSPG b;
	string x, s, m;
	int i, j, k, l;
	i = 0;
	j = 0;
	k = 0;
	m = "";
	string*y = new string[10];
	string*z = new string[10];
	cout << "请输入您要查询的QQ号：";
	cin >> b.number;
	s = b.number + "Py.txt";
	const char*cin = s.c_str();
	ifstream infil(cin, ios::in);
	while (!infil.eof()) {
		infil >> z[i];
		i = i + 1;
	}
	x = a.number + "Py.txt";
	const char*in = x.c_str();
	ifstream infile(in, ios::in);
	while (!infile.eof()) {
		infile >> y[j];
		j = j + 1;
	}
	for (k = 0; k<i + 1; k++) {
		cout << z[k];
		for (l = 0; l<j + 1; l++) {
			if (z[k] == y[l])
				m = z[k];
			return 0;
		}
	}
	if (m == "") {
		cout << "您与该用户并没有共同的好友";
		return 0;
	}
	infil.close();
	infile.close();
	return 0;
}

int ChooseSPG(NekoparaSPG a)
{
	string x;
	int i;
	cout << "请输入您的QQ号：";
	cin >> a.number;
	x = a.number;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "您输入的QQ不存在";
		return 0;
	}
	infile >> a.number;
	infile >> a.nich;
	infile >> a.birthday.y;
	infile >> a.birthday.m;
	infile >> a.birthday.d;
	infile >> a.hometown.nation;
	infile >> a.hometown.province;
	infile >> a.hometown.city;
	cout << "------------------------------------------------------------------------\n";
	cout << "|                          请选择要进行的操作                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.添加好友                |         2.删除好友               |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.查询信息                |         4.返回主界面             |\n";
	cout << "------------------------------------------------------------------------\n";
	cin >> i;
	switch (i) {
	case 1:
		AddPySPG(a);
		break;
	case 2:
		DeletePySPG(a);
		break;
	case 3:
		SearchPySPG(a);
		break;
	case 4:
		SearchSamePySPG(a);
		break;
	}
}

void SaveWbSPG(WeiboSPG b)
{
	string x;
	x = b.number;
	ofstream outfile((x + "Wb.txt").c_str(), ios::out);
	ofstream outfil((x + "WbPy.txt").c_str(), ios::out);
	outfile << b.number << " ";
	outfile << b.nich << " ";
	outfile << b.birthday.y << " " << b.birthday.m << " " << b.birthday.d << " ";
	outfile << b.hometown.nation << " ";
	outfile << b.hometown.province << " ";
	outfile << b.hometown.city << endl;
	outfile.close();
	outfil.close();
}

int KaiWbSPG(NekoparaSPG a)
{
	WeiboSPG b;
	string x;
	cout << "请输入您的QQ号：" << endl;
	cin >> a.number;
	x = a.number;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "您输入的QQ不存在" << endl;
		return 0;
	}
	infile >> a.number;
	infile >> a.nich;
	infile >> a.birthday.y;
	infile >> a.birthday.m;
	infile >> a.birthday.d;
	infile >> a.hometown.nation;
	infile >> a.hometown.province;
	infile >> a.hometown.city;
	b.number = a.number;
	b.nich = a.nich;
	b.birthday.y = a.birthday.y;
	b.birthday.m = a.birthday.m;
	b.birthday.d = a.birthday.d;
	b.hometown.nation = a.hometown.nation;
	b.hometown.province = a.hometown.province;
	b.hometown.city = a.hometown.city;
	SaveWbSPG(b);
	cout << "开通微博成功" << endl;
}

int SearchWbSPG()
{
	WeiboSPG b;
	string x;
	cout << "请输入您要查询的微博号:";
	cin >> x;
	x = x + "Wb.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "您要查询的微博不存在";
		return 0;
	}
	infile >> b.number;
	infile >> b.nich;
	infile >> b.birthday.y;
	infile >> b.birthday.m;
	infile >> b.birthday.d;
	infile >> b.hometown.nation;
	infile >> b.hometown.province;
	infile >> b.hometown.city;
	cout << b.nich << " ";
	cout << b.birthday.y << " " << b.birthday.m << " " << b.birthday.d << " ";
	cout << b.hometown.nation << " " << b.hometown.province << " " << b.hometown.city << " ";
	infile.close();
	return 0;
}

int AddWbPySPG(WeiboSPG b)
{
	string x, y, z;
	cout << "请输入您要加的微博号：";
	cin >> z;
	x = z;
	y = b.number;
	x = x + "Wb.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "您要加的微博不存在";
		return 0;
	}
	ofstream outfil((y + "WbPy.txt").c_str(), ios::app);
	outfil << z << endl;
	outfil.close();
	cout << "添加成功";
	return 0;
}

void DeleteWbPySPG(WeiboSPG b)
{
	string x, z;
	WeiboSPG*y = new WeiboSPG[10];
	int i, j, k;
	i = 0, j = 0, k = 0;
	cout << "您要删除的好友微博为：";
	cin >> z;
	x = b.number + "WbPy.txt";
	const char*in = x.c_str();
	ifstream infil(in, ios::in);
	while (!infil.eof()) 
	{
		infil >> y[i].number;
		i = i + 1;
	}
	if (y[j].number != z) 
	{
		j += 1;
	}
	infil.close();
	ofstream outfile(in, ios::out);
	for (k = 0; k<j; k++)
	{
		outfile << y[k].number << endl;
	}
	for (k = j + 1; k<10; k++)
	{
		outfile << y[k].number << endl;
	}
	cout << "删除成功";
}

int SearchWbPySPG(WeiboSPG b)
{
	NekoparaSPG*y = new NekoparaSPG[10];
	string x, z;
	int i, j;
	i = 0;
	j = 0;
	cout << "请输入您要查询的好友微博为";
	cin >> z;
	x = b.number + "WbPy.txt";
	const char*in = x.c_str();
	ifstream infil(in, ios::in);
	while (!infil.eof()) 
	{
		infil >> y[i].number;
		i = i + 1;
	}
	while (y[j].number != z)
	{
		if (j = 10) 
		{
			cout << "您没有该用户好友" << endl;
			return 0;
		}
		j = j + 1;
	}
	z = z + "Wb.txt";
	const char* cin = z.c_str();
	ifstream infile(cin, ios::in);
	if (!infile)
	{
		cout << "您要查询的微博不存在";
		return 0;
	}
	infile >> b.number;
	infile >> b.nich;
	infile >> b.birthday.y;
	infile >> b.birthday.m;
	infile >> b.birthday.d;
	infile >> b.hometown.nation;
	infile >> b.hometown.province;
	infile >> b.hometown.city;
	cout << b.number << " ";
	cout << b.nich << " ";
	cout << b.birthday.y << " " << b.birthday.m << " " << b.birthday.d << " ";
	cout << b.hometown.nation << " " << b.hometown.province << " " << b.hometown.city << " ";
	infile.close();
	return 0;
}

int ChooseWbSPG()
{
	WeiboSPG b;
	string x;
	int i;
	cout << "请输入您的微博号：";
	cin >> b.number;
	x = b.number;
	x = x + "Wb.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "您输入的微博不存在";
		return 0;
	}
	infile >> b.number;
	infile >> b.nich;
	infile >> b.birthday.y;
	infile >> b.birthday.m;
	infile >> b.birthday.d;
	infile >> b.hometown.nation;
	infile >> b.hometown.province;
	infile >> b.hometown.city;
	cout << "------------------------------------------------------------------------\n";
	cout << "|                          请选择要进行的操作                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.添加好友                |         2.删除好友               |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.查询好友信息            |         4.返回主界面             |\n";
	cout << "------------------------------------------------------------------------\n" << endl;
	cin >> i;
	switch (i) {
	case 1:
		AddWbPySPG(b);
		break;
	case 2:
		DeleteWbPySPG(b);
		break;
	case 3:
		SearchWbPySPG(b);
		break;
	}
}

int NekoparaWeiboSPG(NekoparaSPG a)
{
	int i;
	cout << "------------------------------------------------------------------------\n";
	cout << "|                          请选择要进行的操作                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.开通微博                |         2.查询微博信息           |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.管理好友信息            |         4.返回主界面             |\n";
	cout << "------------------------------------------------------------------------\n" << endl;
	cin >> i;
	switch (i) {
	case 1:
		KaiWbSPG(a);
		break;
	case 2:
		SearchWbSPG();
		break;
	case 3:
		ChooseWbSPG();
		break;
	}
	return 0;
}

void SaveWxSPG(WechatSPG x)
{
	string s;
	s = x.number;
	ofstream outfile((s + "Wx.txt").c_str(), ios::out);
	ofstream outfil((s + "WxPy.txt").c_str(), ios::out);
	outfile << x.number << " ";
	outfile << x.nich << " ";
	outfile << x.birthday.y << " " << x.birthday.m << " " << x.birthday.d << " ";
	outfile << x.hometown.nation << " ";
	outfile << x.hometown.province << " ";
	outfile << x.hometown.city << endl;
	outfile.close();
	outfil.close();
}

int KaiWxSPG(NekoparaSPG a)
{
	WechatSPG x;
	int i;
	string s, c;
	cout << "请输入您的个人信息：\n" << endl;
	cout << "昵称：" << endl;
	cin >> x.nich;
	cout << "出生日期（年 月 日*中间用空格间隔）：" << endl;
	cin >> x.birthday.y >> x.birthday.m >> x.birthday.d;
	cout << "所在地（国家 省份 城市*中间用空格间隔）：" << endl;
	cin >> x.hometown.nation >> x.hometown.province >> x.hometown.city;
	i = TimeSPG(x.birthday.y, x.birthday.m, x.birthday.d);
	while (i != 1) {
		cout << "信息有误，请重新填写" << endl;
		cout << "请重新输入您的个人信息\n" << endl;
		cout << "昵称：" << endl;
		cin >> x.nich;
		cout << "出生日期（年 月 日*中间用空格间隔）：" << endl;
		cin >> x.birthday.y >> x.birthday.m >> x.birthday.d;
		cout << "所在地（国家 省份 城市*中间用空格间隔）：" << endl;
		cin >> x.hometown.nation >> x.hometown.province >> x.hometown.city;
	}
	int j, b[6];
	for (j = 0; j<6; j++) {
		b[j] = 0;
		srand(time(0));
		for (int j = 0; j<6; j++) {
			b[j] = rand() % 6;
		}
		char str[16];
		for (j = 0; j<6; j++) {
			sprintf_s(&str[j], 2, "%d", b[j]);
		}
		str[j] = '\0';
		x.number = str;
	}
	cout << "申请成功，您的微信号为" << x.number << endl;
	SaveWxSPG(x);
	cout << "请输入您要绑定的QQ：" << endl;
	cin >> a.number;
	c = a.number;
	c = c + "_QQ.txt";

	const char* in = c.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "您输入的QQ不存在" << endl;
		return 0;
	}

	ofstream outfill((x.number + "xq.txt").c_str(), ios::out);
	outfill << c << endl;
	outfill.close();
	cout << "绑定成功" << endl;
}

int SearchWxSPG()
{
	WechatSPG x;
	string s;
	cout << "请输入您要查询的微信号:" << endl;
	cin >> s;
	s = s + "Wx.txt";
	const char* in = s.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "您查询的微信号不存在" << endl;
		return 0;
	}
	infile >> x.number;
	infile >> x.nich;
	infile >> x.birthday.y;
	infile >> x.birthday.m;
	infile >> x.birthday.d;
	infile >> x.hometown.nation;
	infile >> x.hometown.province;
	infile >> x.hometown.city;
	cout << x.nich << " ";
	cout << x.birthday.y << " " << x.birthday.m << " " << x.birthday.d << " ";
	cout << x.hometown.nation << " " << x.hometown.province << " " << x.hometown.city << " ";
	infile.close();
	return 0;
}

int AddWxPySPG(WechatSPG x)
{
	string s, y, z;
	cout << "请输入您要加的微信号：";
	cin >> z;
	s = z;
	y = x.number;
	s = s + "Wx.txt";
	const char* in = s.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "您要加的微信不存在";
		return 0;
	}
	ofstream outfil((y + "WxPy.txt").c_str(), ios::app);
	outfil << z << endl;
	outfil.close();
	cout << "添加成功";
	return 0;
}

void DeleteWxPySPG(WechatSPG x)
{
	string s, z;
	WeiboSPG*y = new WeiboSPG[10];
	int i, j, k;
	i = 0, j = 0, k = 0;
	cout << "您要删除的好友微信为：";
	cin >> z;
	s = x.number + "WxPy.txt";
	const char*in = s.c_str();
	ifstream infil(in, ios::in);
	while (!infil.eof()) 
	{
		infil >> y[i].number;
		i = i + 1;
	}
	if (y[j].number != z)
	{
		j += 1;
	}
	infil.close();
	ofstream outfile(in, ios::out);
	for (k = 0; k<j; k++)
	{
		outfile << y[k].number << endl;
	}
	for (k = j + 1; k<10; k++)
	{
		outfile << y[k].number << endl;
	}
	cout << "删除成功";
}

int SearchWxPySPG(WechatSPG x)
{
	NekoparaSPG*y = new NekoparaSPG[10];
	string s, z;
	int i, j;
	i = 0;
	j = 0;
	cout << "请输入您要查询的好友微信为";
	cin >> z;
	s = x.number + "WxPy.txt";
	const char*in = s.c_str();
	ifstream infil(in, ios::in);
	while (!infil.eof()) 
	{
		infil >> y[i].number;
		i = i + 1;
	}
	while (y[j].number != z)
	{
		if (j = 10)
		{
			cout << "您没有该好友微信。" << endl;
			return 0;
		}
		j = j + 1;
	}
	z = z + "Wx.txt";
	const char* cin = z.c_str();
	ifstream infile(cin, ios::in);
	if (!infile) 
	{
		cout << "您要查询的微信不存在";
		return 0;
	}
	infile >> x.number;
	infile >> x.nich;
	infile >> x.birthday.y;
	infile >> x.birthday.m;
	infile >> x.birthday.d;
	infile >> x.hometown.nation;
	infile >> x.hometown.province;
	infile >> x.hometown.city;
	cout << x.number << " ";
	cout << x.nich << " ";
	cout << x.birthday.y << " " << x.birthday.m << " " << x.birthday.d << " ";
	cout << x.hometown.nation << " " << x.hometown.province << " " << x.hometown.city << " ";
	infile.close();
	return 0;
}

int ChooseWxSPG()
{
	WechatSPG x;
	string s;
	int i;
	cout << "请输入您的微信号：";
	cin >> x.number;
	s = x.number;
	s = s + "Wx.txt";
	const char* in = s.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "您输入的微信不存在";
		return 0;
	}
	infile >> x.number;
	infile >> x.nich;
	infile >> x.birthday.y;
	infile >> x.birthday.m;
	infile >> x.birthday.d;
	infile >> x.hometown.nation;
	infile >> x.hometown.province;
	infile >> x.hometown.city;
	cout << "------------------------------------------------------------------------\n";
	cout << "|                          请选择要进行的操作                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.添加好友                |         2.删除好友               |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.查询好友信息            |         4.返回主界面             |\n";
	cout << "------------------------------------------------------------------------\n";
	cin >> i;
	switch (i) {
	case 1:
		AddWxPySPG(x);
		break;
	case 2:
		DeleteWxPySPG(x);
		break;
	case 3:
		SearchWxPySPG(x);
		break;
	}
}

void NekoparaWeixinSPG(NekoparaSPG a)
{
	int i;
	cout << "------------------------------------------------------------------------\n";
	cout << "|                          请选择要进行的操作                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.开通微信                |         2.查询微信信息           |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.管理好友                |         4.返回主界面            |\n";
	cout << "------------------------------------------------------------------------\n";
	cin >> i;
	switch (i) {
	case 1:
		KaiWxSPG(a);
		break;
	case 2:
		SearchWxSPG();
		break;
	case 3:
		ChooseWxSPG();
		break;
	}
}

int SaveQunSPG(string x, string y)
{
	ofstream outfile((y + "qun.txt").c_str(), ios::out);
	outfile << x << endl;
	outfile.close();
	return 0;
}

void CreateQunSPG(NekoparaSPG a)
{
	string x, y;
	cout << "请输入您的QQ号：";
	cin >> x;
	int j, b[6];
	for (j = 0; j<6; j++) 
	{
		b[j] = 0;
		srand(time(0));
		for (int j = 0; j<6; j++) {
			b[j] = rand() % 6;
		}
		char str[16];
		for (j = 0; j<6; j++) {
			sprintf_s(&str[j], 2, "%d", b[j]);             //sprintf函数
		}
		str[j] = '\0';
		y = str;
	}
	cout << "建立群成功，群号为：" << y;
	SaveQunSPG(x, y);
}

int AddQunSPG(NekoparaSPG a)
{
	string x, y, z;
	cout << "请输入您的QQ号：";
	cin >> y;
	cout << "请输入您要加入群的群号：";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "您要加的群不存在";
		return 0;
	}
	ofstream outfil((z + "qun.txt").c_str(), ios::app);
	outfil << y << endl;
	outfil.close();
	cout << "加入群成功";
}

int SignoutQunSPG()
{
	string x, y, z;
	int i, j, k, c, v;
	i = 0;
	j = 0;
	k = 0;
	c = 0;
	v = 0;
	string*p = new string[10];
	cout << "请输入您的QQ号：";
	cin >> y;
	cout << "请输入您要退出的群的群号：";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infil(in, ios::in);
	if (!infil) {
		cout << "您要退出的群不存在";
		return 0;
	}
	while (!infil.eof()) {
		infil >> p[i];
		i = i + 1;
	}
	if (p[0] == y) {
		cout << "您是群主，无法退出该群";
		return 0;
	}
	for (c = 0; c<i + 1; c++) {
		if (p[j] == z)
			v = 1;
	}
	if (v = 0) {
		cout << "您没有加入该群";
		return 0;
	}
	if (p[j] != z) {
		j += 1;
	}
	infil.close();
	ofstream outfile(in, ios::out);
	for (k = 0; k<j; k++) {
		outfile << p[k] << endl;
	}
	for (k = j + 1; k<10; k++) {
		outfile << p[k] << endl;
	}
	cout << "退出群成功";
}

int SearchCySPG()
{
	string x, y, z;
	int i, j, k, c, v;
	i = 0;
	j = 0;
	k = 0;
	v = 0;
	string*p = new string[10];
	cout << "请输入您的QQ号：";
	cin >> y;
	cout << "请输入您要查询的群的群号：";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infil(in, ios::in);
	if (!infil) {
		cout << "您要查询的群不存在";
		return 0;
	}
	while (!infil.eof()) {
		infil >> p[i];
		i = i + 1;
	}
	for (c = 0; c<i + 1; c++) {
		if (p[j] == z)
			v = 1;
	}
	if (v = 0) {
		cout << "您没有加入该群";
		return 0;
	}
	cout << "群主：" << p[0] << endl;
	for (k = 1; k<i + 1; k++) {
		cout << "成员：" << p[k] << endl;
	}
}

int DeleteCySPG()
{
	string x, y, z, d;
	int i, j, k, c, v;
	i = 0;
	j = 0;
	k = 0;
	v = 0;
	string*p = new string[10];
	cout << "请输入您的QQ号：";
	cin >> y;
	cout << "请输入您要查询的群的群号：";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infil(in, ios::in);
	if (!infil) {
		cout << "您要查询的群不存在";
		return 0;
	}
	while (!infil.eof()) {
		infil >> p[i];
		i = i + 1;
	}
	for (c = 0; c<i + 1; c++) {
		if (p[j] == z)
			v = 1;
	}
	if (v = 0) {
		cout << "您没有加入该群";
		return 0;
	}
	if (p[0] != y) {
		cout << "您不是群主，没有此权限";
		return 0;
	}
	infil.close();
	cout << "请输入您要踢出的群成员的QQ号：";
	cin >> d;
	v = 0;
	for (c = 0; c<i + 1; c++) {
		if (p[j] == d)
			v = 1;
	}
	if (v = 0) {
		cout << "群内不存在此成员";
		return 0;
	}
	if (p[j] != d) {
		j += 1;
	}
	ofstream outfile(in, ios::out);
	for (k = 0; k<j; k++) {
		outfile << p[k] << endl;
	}
	for (k = j + 1; k<10; k++) {
		outfile << p[k] << endl;
	}
	cout << "踢出该成员成功";
}

int NekoparaQunSPG(NekoparaSPG a)
{
	int i;
	cout << "------------------------------------------------------------------------\n";
	cout << "|                          请选择要进行的操作                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.建立群                  |         2.加入群                 |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.退出群                  |         4.查询群成员             |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         5.踢出群成员              |         6.返回主界面            |\n";
	cout << "------------------------------------------------------------------------\n";
	cin >> i;
	switch (i) {
	case 1:
		CreateQunSPG(a);
		break;
	case 2:
		AddQunSPG(a);
		break;
	case 3:
		SignoutQunSPG();
		break;
	case 4:
		SearchCySPG();
		break;
	case 5:
		DeleteCySPG();
		break;
	}
	return 0;
}
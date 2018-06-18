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
	cout << "���������ĸ�����Ϣ\n" << endl;
	cout << "�ǳƣ�" << endl;
	cin >> a.nich;
	cout << "�������ڣ��� �� ��*�м��ÿո�������" << endl;
	cin >> a.birthday.y >> a.birthday.m >> a.birthday.d;
	cout << "���ڵأ����� ʡ�� ����*�м��ÿո�������" << endl;
	cin >> a.hometown.nation >> a.hometown.province >> a.hometown.city;
	i = TimeSPG(a.birthday.y, a.birthday.m, a.birthday.d);
	while (i != 1) {
		cout << "��ʽ������������д";
		cout << "�������������ĸ�����Ϣ��" << endl;
		cout << "�ǳƣ�" << endl;
		cin >> a.nich;
		cout << "�������ڣ��� �� ��*�м��ÿո�������" << endl;
		cin >> a.birthday.y >> a.birthday.m >> a.birthday.d;
		cout << "���ڵأ����� ʡ�� ����*�м��ÿո�������" << endl;
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
	cout << "ע��ɹ�������QQ��Ϊ" << a.number << endl;
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
	cout << "��������Ҫ��ѯ��QQ��:";
	cin >> x;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "��Ҫ��ѯ��QQ������" << endl;
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
	cout << "QQ��";
	cout << a.number << " ";
	cout << "�ǳƣ�";
	cout << a.nich << " ";
	cout << "�������ڣ�";
	cout << a.birthday.y << " " << a.birthday.m << " " << a.birthday.d << " ";
	cout << "���ڵأ�";
	cout << a.hometown.nation << " " << a.hometown.province << " " << a.hometown.city << " " << endl;
	infile.close();
	return 0;
}

int AddPySPG(NekoparaSPG a)
{
	string x, y, z;
	cout << "��������Ҫ��ӵ�QQ�ţ�";
	cin >> z;
	x = z;
	y = a.number;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "��QQ������";
		return 0;
	}
	ofstream outfil((y + "Py.txt").c_str(), ios::app);
	outfil << z << endl;
	outfil.close();
	cout << "���������";
	return 0;
}

int DeletePySPG(NekoparaSPG a)
{
	string x, z;
	NekoparaSPG*y = new NekoparaSPG[10];
	int i, j, k;
	i = 0, j = 0, k = 0;
	cout << "��������Ҫɾ���ĺ���QQ��";
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
	cout << "�ú������Ƴ�";
	return 0;
}

int SearchPySPG(NekoparaSPG a)
{
	NekoparaSPG*y = new NekoparaSPG[10];
	string x, z;
	int i, j;
	i = 0;
	j = 0;
	cout << "��������Ҫ��ѯ��QQ��";
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
			cout << "��û�и��û����ѡ�" << endl;
			return 0;
		}
		j = j + 1;
	}
	z = z + "_QQ.txt";
	const char* cin = z.c_str();
	ifstream infile(cin, ios::in);
	if (!infile) {
		cout << "��ѯ��QQ������";
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
	cout << "��������Ҫ��ѯ��QQ�ţ�";
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
		cout << "������û���û�й�ͬ�ĺ���";
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
	cout << "����������QQ�ţ�";
	cin >> a.number;
	x = a.number;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "�������QQ������";
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
	cout << "|                          ��ѡ��Ҫ���еĲ���                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.��Ӻ���                |         2.ɾ������               |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.��ѯ��Ϣ                |         4.����������             |\n";
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
	cout << "����������QQ�ţ�" << endl;
	cin >> a.number;
	x = a.number;
	x = x + "_QQ.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "�������QQ������" << endl;
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
	cout << "��ͨ΢���ɹ�" << endl;
}

int SearchWbSPG()
{
	WeiboSPG b;
	string x;
	cout << "��������Ҫ��ѯ��΢����:";
	cin >> x;
	x = x + "Wb.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "��Ҫ��ѯ��΢��������";
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
	cout << "��������Ҫ�ӵ�΢���ţ�";
	cin >> z;
	x = z;
	y = b.number;
	x = x + "Wb.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "��Ҫ�ӵ�΢��������";
		return 0;
	}
	ofstream outfil((y + "WbPy.txt").c_str(), ios::app);
	outfil << z << endl;
	outfil.close();
	cout << "��ӳɹ�";
	return 0;
}

void DeleteWbPySPG(WeiboSPG b)
{
	string x, z;
	WeiboSPG*y = new WeiboSPG[10];
	int i, j, k;
	i = 0, j = 0, k = 0;
	cout << "��Ҫɾ���ĺ���΢��Ϊ��";
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
	cout << "ɾ���ɹ�";
}

int SearchWbPySPG(WeiboSPG b)
{
	NekoparaSPG*y = new NekoparaSPG[10];
	string x, z;
	int i, j;
	i = 0;
	j = 0;
	cout << "��������Ҫ��ѯ�ĺ���΢��Ϊ";
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
			cout << "��û�и��û�����" << endl;
			return 0;
		}
		j = j + 1;
	}
	z = z + "Wb.txt";
	const char* cin = z.c_str();
	ifstream infile(cin, ios::in);
	if (!infile)
	{
		cout << "��Ҫ��ѯ��΢��������";
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
	cout << "����������΢���ţ�";
	cin >> b.number;
	x = b.number;
	x = x + "Wb.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "�������΢��������";
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
	cout << "|                          ��ѡ��Ҫ���еĲ���                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.��Ӻ���                |         2.ɾ������               |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.��ѯ������Ϣ            |         4.����������             |\n";
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
	cout << "|                          ��ѡ��Ҫ���еĲ���                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.��ͨ΢��                |         2.��ѯ΢����Ϣ           |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.���������Ϣ            |         4.����������             |\n";
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
	cout << "���������ĸ�����Ϣ��\n" << endl;
	cout << "�ǳƣ�" << endl;
	cin >> x.nich;
	cout << "�������ڣ��� �� ��*�м��ÿո�������" << endl;
	cin >> x.birthday.y >> x.birthday.m >> x.birthday.d;
	cout << "���ڵأ����� ʡ�� ����*�м��ÿո�������" << endl;
	cin >> x.hometown.nation >> x.hometown.province >> x.hometown.city;
	i = TimeSPG(x.birthday.y, x.birthday.m, x.birthday.d);
	while (i != 1) {
		cout << "��Ϣ������������д" << endl;
		cout << "�������������ĸ�����Ϣ\n" << endl;
		cout << "�ǳƣ�" << endl;
		cin >> x.nich;
		cout << "�������ڣ��� �� ��*�м��ÿո�������" << endl;
		cin >> x.birthday.y >> x.birthday.m >> x.birthday.d;
		cout << "���ڵأ����� ʡ�� ����*�м��ÿո�������" << endl;
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
	cout << "����ɹ�������΢�ź�Ϊ" << x.number << endl;
	SaveWxSPG(x);
	cout << "��������Ҫ�󶨵�QQ��" << endl;
	cin >> a.number;
	c = a.number;
	c = c + "_QQ.txt";

	const char* in = c.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "�������QQ������" << endl;
		return 0;
	}

	ofstream outfill((x.number + "xq.txt").c_str(), ios::out);
	outfill << c << endl;
	outfill.close();
	cout << "�󶨳ɹ�" << endl;
}

int SearchWxSPG()
{
	WechatSPG x;
	string s;
	cout << "��������Ҫ��ѯ��΢�ź�:" << endl;
	cin >> s;
	s = s + "Wx.txt";
	const char* in = s.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "����ѯ��΢�źŲ�����" << endl;
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
	cout << "��������Ҫ�ӵ�΢�źţ�";
	cin >> z;
	s = z;
	y = x.number;
	s = s + "Wx.txt";
	const char* in = s.c_str();
	ifstream infile(in, ios::in);
	if (!infile)
	{
		cout << "��Ҫ�ӵ�΢�Ų�����";
		return 0;
	}
	ofstream outfil((y + "WxPy.txt").c_str(), ios::app);
	outfil << z << endl;
	outfil.close();
	cout << "��ӳɹ�";
	return 0;
}

void DeleteWxPySPG(WechatSPG x)
{
	string s, z;
	WeiboSPG*y = new WeiboSPG[10];
	int i, j, k;
	i = 0, j = 0, k = 0;
	cout << "��Ҫɾ���ĺ���΢��Ϊ��";
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
	cout << "ɾ���ɹ�";
}

int SearchWxPySPG(WechatSPG x)
{
	NekoparaSPG*y = new NekoparaSPG[10];
	string s, z;
	int i, j;
	i = 0;
	j = 0;
	cout << "��������Ҫ��ѯ�ĺ���΢��Ϊ";
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
			cout << "��û�иú���΢�š�" << endl;
			return 0;
		}
		j = j + 1;
	}
	z = z + "Wx.txt";
	const char* cin = z.c_str();
	ifstream infile(cin, ios::in);
	if (!infile) 
	{
		cout << "��Ҫ��ѯ��΢�Ų�����";
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
	cout << "����������΢�źţ�";
	cin >> x.number;
	s = x.number;
	s = s + "Wx.txt";
	const char* in = s.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "�������΢�Ų�����";
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
	cout << "|                          ��ѡ��Ҫ���еĲ���                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.��Ӻ���                |         2.ɾ������               |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.��ѯ������Ϣ            |         4.����������             |\n";
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
	cout << "|                          ��ѡ��Ҫ���еĲ���                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.��ͨ΢��                |         2.��ѯ΢����Ϣ           |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.�������                |         4.����������            |\n";
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
	cout << "����������QQ�ţ�";
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
			sprintf_s(&str[j], 2, "%d", b[j]);             //sprintf����
		}
		str[j] = '\0';
		y = str;
	}
	cout << "����Ⱥ�ɹ���Ⱥ��Ϊ��" << y;
	SaveQunSPG(x, y);
}

int AddQunSPG(NekoparaSPG a)
{
	string x, y, z;
	cout << "����������QQ�ţ�";
	cin >> y;
	cout << "��������Ҫ����Ⱥ��Ⱥ�ţ�";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infile(in, ios::in);
	if (!infile) {
		cout << "��Ҫ�ӵ�Ⱥ������";
		return 0;
	}
	ofstream outfil((z + "qun.txt").c_str(), ios::app);
	outfil << y << endl;
	outfil.close();
	cout << "����Ⱥ�ɹ�";
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
	cout << "����������QQ�ţ�";
	cin >> y;
	cout << "��������Ҫ�˳���Ⱥ��Ⱥ�ţ�";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infil(in, ios::in);
	if (!infil) {
		cout << "��Ҫ�˳���Ⱥ������";
		return 0;
	}
	while (!infil.eof()) {
		infil >> p[i];
		i = i + 1;
	}
	if (p[0] == y) {
		cout << "����Ⱥ�����޷��˳���Ⱥ";
		return 0;
	}
	for (c = 0; c<i + 1; c++) {
		if (p[j] == z)
			v = 1;
	}
	if (v = 0) {
		cout << "��û�м����Ⱥ";
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
	cout << "�˳�Ⱥ�ɹ�";
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
	cout << "����������QQ�ţ�";
	cin >> y;
	cout << "��������Ҫ��ѯ��Ⱥ��Ⱥ�ţ�";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infil(in, ios::in);
	if (!infil) {
		cout << "��Ҫ��ѯ��Ⱥ������";
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
		cout << "��û�м����Ⱥ";
		return 0;
	}
	cout << "Ⱥ����" << p[0] << endl;
	for (k = 1; k<i + 1; k++) {
		cout << "��Ա��" << p[k] << endl;
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
	cout << "����������QQ�ţ�";
	cin >> y;
	cout << "��������Ҫ��ѯ��Ⱥ��Ⱥ�ţ�";
	cin >> z;
	x = z;
	x = x + "qun.txt";
	const char* in = x.c_str();
	ifstream infil(in, ios::in);
	if (!infil) {
		cout << "��Ҫ��ѯ��Ⱥ������";
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
		cout << "��û�м����Ⱥ";
		return 0;
	}
	if (p[0] != y) {
		cout << "������Ⱥ����û�д�Ȩ��";
		return 0;
	}
	infil.close();
	cout << "��������Ҫ�߳���Ⱥ��Ա��QQ�ţ�";
	cin >> d;
	v = 0;
	for (c = 0; c<i + 1; c++) {
		if (p[j] == d)
			v = 1;
	}
	if (v = 0) {
		cout << "Ⱥ�ڲ����ڴ˳�Ա";
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
	cout << "�߳��ó�Ա�ɹ�";
}

int NekoparaQunSPG(NekoparaSPG a)
{
	int i;
	cout << "------------------------------------------------------------------------\n";
	cout << "|                          ��ѡ��Ҫ���еĲ���                          |\n";
	cout << "-----------------------------------------------------------------------|\n";
	cout << "|         1.����Ⱥ                  |         2.����Ⱥ                 |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         3.�˳�Ⱥ                  |         4.��ѯȺ��Ա             |\n";
	cout << "------------------------------------------------------------------------\n";
	cout << "|         5.�߳�Ⱥ��Ա              |         6.����������            |\n";
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
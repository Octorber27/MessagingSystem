#pragma once
#include "NekoparaSPG.h"
#include "WeiboSPG.h"
#include "WechatSPG.h"


int TimeSPG(int a, int b, int c);//�ж�������������Ƿ����
void SaveSPG(NekoparaSPG a);//����QQ��Ϣ
void InformationSPG(NekoparaSPG a);//ע��QQ
int SearchSPG(NekoparaSPG a);//��ѯQQ��Ϣ
int AddPySPG(NekoparaSPG a);//���QQ����
int DeletePySPG(NekoparaSPG a);//ɾ��QQ����
int SearchPySPG(NekoparaSPG a);//����QQ����
int SearchSamePySPG(NekoparaSPG a);//��ѯ��ͬ����
int ChooseSPG(NekoparaSPG a);//QQ���ѹ���
void SaveWbSPG(WeiboSPG b);//����΢��
int KaiWbSPG(NekoparaSPG a);//��ͨ΢��
int SearchWbSPG();//��ѯ΢��
int AddWbPySPG(WeiboSPG b);//���΢������
void DeleteWbPySPG(WeiboSPG b);//ɾ��΢������
int SearchWbPySPG(WeiboSPG b);//��ѯ΢������
int ChooseWbSPG();//����΢������
int NekoparaWeiboSPG(NekoparaSPG a);//����΢��
void SaveWxSPG(WechatSPG x);//����΢��
int KaiWxSPG(NekoparaSPG a);//��ͨ΢��
int SearchWxSPG();//��ѯ΢��
int AddWxPySPG(WechatSPG x);//���΢�ź���
void DeleteWxPySPG(WechatSPG x);//ɾ��΢�ź���
int SearchWxPySPG(WechatSPG x);//��ѯ΢�ź���
int ChooseWxSPG();//΢�ź��ѹ���
void NekoparaWeixinSPG(NekoparaSPG a);	//����΢��
int SaveQunSPG(string x, string y);//����Ⱥ��Ϣ
void CreateQunSPG(NekoparaSPG a);//����Ⱥ
int AddQunSPG(NekoparaSPG a);//����Ⱥ
int SignoutQunSPG();//�˳�Ⱥ
int SearchCySPG();//��ѯȺ��Ա
int DeleteCySPG();//ɾ��Ⱥ��Ա
int NekoparaQunSPG(NekoparaSPG a);//����Ⱥ
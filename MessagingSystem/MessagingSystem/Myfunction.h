#pragma once
#include "NekoparaSPG.h"
#include "WeiboSPG.h"
#include "WechatSPG.h"


int TimeSPG(int a, int b, int c);//判断输入的年月日是否合理
void SaveSPG(NekoparaSPG a);//保存QQ信息
void InformationSPG(NekoparaSPG a);//注册QQ
int SearchSPG(NekoparaSPG a);//查询QQ信息
int AddPySPG(NekoparaSPG a);//添加QQ好友
int DeletePySPG(NekoparaSPG a);//删除QQ好友
int SearchPySPG(NekoparaSPG a);//搜索QQ好友
int SearchSamePySPG(NekoparaSPG a);//查询相同好友
int ChooseSPG(NekoparaSPG a);//QQ好友管理
void SaveWbSPG(WeiboSPG b);//保存微博
int KaiWbSPG(NekoparaSPG a);//开通微博
int SearchWbSPG();//查询微博
int AddWbPySPG(WeiboSPG b);//添加微博好友
void DeleteWbPySPG(WeiboSPG b);//删除微博好友
int SearchWbPySPG(WeiboSPG b);//查询微博好友
int ChooseWbSPG();//管理微博好友
int NekoparaWeiboSPG(NekoparaSPG a);//操作微博
void SaveWxSPG(WechatSPG x);//保存微信
int KaiWxSPG(NekoparaSPG a);//开通微信
int SearchWxSPG();//查询微信
int AddWxPySPG(WechatSPG x);//添加微信好友
void DeleteWxPySPG(WechatSPG x);//删除微信好友
int SearchWxPySPG(WechatSPG x);//查询微信好友
int ChooseWxSPG();//微信好友管理
void NekoparaWeixinSPG(NekoparaSPG a);	//操作微信
int SaveQunSPG(string x, string y);//保存群信息
void CreateQunSPG(NekoparaSPG a);//创建群
int AddQunSPG(NekoparaSPG a);//加入群
int SignoutQunSPG();//退出群
int SearchCySPG();//查询群成员
int DeleteCySPG();//删除群成员
int NekoparaQunSPG(NekoparaSPG a);//操作群
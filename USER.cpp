#pragma warning(disable:4996)
#include"admin.h"
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;

User::User()
{
	user_ID = "null";
	user_password = "null";
}

User::~User()
{

}

bool User::userID_create()
{
	string userID;
	string password;
	char input_userID[16];
	char input_password[16];
	
	userID_list = fopen("D:/代码/2019寒假/淘宝/咩咩咩/file/User/用户账号/新建文本文档.txt", "w");

	if (userID_list==NULL){
			cout << "打开文件失败！" << std::endl;
			exit(-1);
	}

	cout << "输入用户名：";
	cin >> userID;
	if (userID.size() > 20)
	{
		fclose(userID_list);
		cout << "用户名长度应小于16！" << endl;
		return false;
	}
	cout << "输入密码：";
	cin >> password;
	if (password.size() > 20)
	{
		fclose(userID_list);
		cout << "密码长度应小于16！" << endl;
		return false;
	}
	
	fscanf_s(userID_list, "%s", input_userID, 16);
	fscanf_s(userID_list, "%s", input_password, 16);
	while (!feof(userID_list))
	{
		if (userID == input_userID) {
			fclose(userID_list);
			cout << "用户名已存在！" << endl;
			return false;
		}
		fscanf_s(userID_list, "%s", input_userID, 16);
		fscanf_s(userID_list, "%s", input_password, 16);
		cout << "?";
	}
	this->user_ID = userID;
	this->user_password = password;
	fprintf_s(userID_list, "%-16s%-16s\n", userID.c_str(), password.c_str());
	cout << "新用户创建成功" << endl;
	fclose(userID_list);

	shop_list = fopen("D: / 代码 / 2019寒假 / 淘宝 / 咩咩咩 / file / User / 购物车 / 新建文本文档.txt", "w");
	paid_list = fopen("D: / 代码 / 2019寒假 / 淘宝 / 咩咩咩 / file / User / 已购商品 / 新建文本文档.txt", "w");
	if(shop_list==NULL||paid_list==NULL){
		cout << "请检查文件配置！" << endl;
		exit(-1);
	}

	fprintf_s(shop_list, "%-16s%-16s%-16s%-16s%-16s\n", "ID", "名称", "品牌", "价格", "数量");
	fprintf_s(paid_list, "%-16s%-16s%-16s%-16s%-16s\n", "ID", "名称", "品牌", "价格", "数量");
	fclose(shop_list);
	fclose(paid_list);
	cout << "用户文件注册成功！" << endl;
	return true;
}

bool User::userID_cheak()
{
	string input_userID;
	string input_password;
	char list_userID[16];
	char list_password[16];

	userID_list = fopen("D: / 代码 / 2019寒假 / 淘宝 / 咩咩咩 / file / User / 用户账号 / 新建文本文档.txt", "r");

	if (userID_list == NULL) {
		cout << "打开文档失败！" << endl;
		exit(-1);
	}

	cout << "输入用户名：";
	cin >> input_userID;
	cout << "输入密码";
	cin >> input_password;

	fscanf_s(userID_list, "%s", list_userID, 16);
	fscanf_s(userID_list, "%s", list_password, 16);
	while (!feof(userID_list))
	{
		if (strcmp(list_userID, input_userID.c_str()) == 0)
		{
			if (strcmp(list_password, input_password.c_str()) == 0)
			{
				this->user_ID = input_userID;
				this->user_password = input_password;
				cout << "*********" << endl;
				cout << "登录成功！" << endl;
				cout << "*********" << endl;
				fclose(userID_list);
				return true;
			}
		}
		fscanf_s(userID_list, "%s", list_userID, 16);
		fscanf_s(userID_list, "%s", list_password, 16);
	}
	return false;
}

void User::view_store_list()
{
	char ID[16], name[16], brand[16];
	double price;
	int num;
	store_list = fopen("D:/代码/2019寒假/淘宝/咩咩咩/file/Admin/库存记录/新建文本文档.txt", "r");
	if (store_list == NULL)
	{
		cout << "文件打开失败" << endl;
		exit(-1);
	}
	fscanf_s(store_list, "%s%s%s%lf%d", ID, 16, name, 16, brand, 16, &price, &num);
	shop_goods_list[0].ID = ID;
	shop_goods_list[0].name = name;
	shop_goods_list[0].brand = brand;
	shop_goods_list[0].price = price;
	shop_goods_list[0].num = num;
	for (int i(1); !feof(store_list); i++)
	{
		fscanf_s(store_list, "%s%s%s%lf%d", ID, 16, name, 16, brand, 16, &price, &num);
		shop_goods_list[i].ID = ID;
		shop_goods_list[i].name = name;
		shop_goods_list[i].brand = brand;
		shop_goods_list[i].price = price;
		shop_goods_list[i].num = num;
	}

	cout << "**********************************************************************" << endl;
	cout << setiosflags(ios::left) << setw(16) << "ID" << setw(16) << "名称" << setw(16) << "品牌" << setw(16) << "价格" << setw(16) << "数量" << setw(16) << endl;
	for (int i(0); shop_goods_list[i].ID != "NULL"; i++)
	{
		if (shop_goods_list[i].num == -1) {
			continue;
		}
		cout << setiosflags(ios::left) << shop_goods_list[i].ID << setw(16) << shop_goods_list[i].name << setw(16) << shop_goods_list[i].brand << setw(16) << shop_goods_list[i].price << setw(16) << shop_goods_list[i].num << setw(16) << endl;
	}
	fclose(store_list);
	cout << "**********************************************************************" << endl;
	cout << "库存记录加载完毕！" << endl;
	return;
}

void User::writein_store()
{
	store_list = fopen("D:/代码/2019寒假/淘宝/咩咩咩/file/Admin/库存记录/新建文本文档.txt", "w");
	int i = 0;
	for (; shop_goods_list[i + 1].ID != "NULL"; i++)
	{
		fprintf(store_list, "%s %s %s %lf %d\n", shop_goods_list[i].ID.c_str(), shop_goods_list[i].name.c_str(), shop_goods_list[i].brand.c_str(), shop_goods_list[i].price, shop_goods_list[i].num);
	}
	fprintf(store_list, "%s %s %s %lf %d", shop_goods_list[i].ID.c_str(), shop_goods_list[i].name.c_str(), shop_goods_list[i].brand.c_str(), shop_goods_list[i].price, shop_goods_list[i].num);
	fclose(store_list);
	return;
}

void User::search_goods()
{
	string goodsID;
	int j = 1;
	cout << "输入商品名称：";
	cin >> goodsID;
	for (int i(0); shop_goods_list[i].ID != "NULL"; i++)
	{
		if (goodsID == shop_goods_list[i].ID) {
			if (j) {
				cout << "**********************************************************************" << endl;
				cout << setiosflags(ios::left) << setw(16) << "ID" << setw(16) << "名称" << setw(16) << "品牌" << setw(16) << "价格" << setw(16) << "数量" << setw(16) << endl;
			}
			cout << setiosflags(ios::left) << shop_goods_list[i].ID << setw(16) << shop_goods_list[i].name << setw(16) << shop_goods_list[i].brand << setw(16) << shop_goods_list[i].price << setw(16) << shop_goods_list[i].num << setw(16) << endl;
		}
	}
	if (!j) {
		cout << "库存中没有此商品！" << endl;
	}
	return;
}

void User::view_shop_list()
{
	char ID[16], name[16], brand[16];
	double price;
	int num;
	shop_list = fopen("D:/代码/2019寒假/淘宝/咩咩咩/file/Admin/库存记录/新建文本文档.txt", "r");
	if (store_list == NULL)
	{
		cout << "文件打开失败" << endl;
		exit(-1);
	}
	fscanf_s(shop_list, "%s%s%s%lf%d", ID, 16, name, 16, brand, 16, &price, &num);
	shop_car_list[0].ID = ID;
	shop_car_list[0].name = name;
	shop_car_list[0].brand = brand;
	shop_car_list[0].price = price;
	shop_car_list[0].num = num;
	for (int i(1); !feof(shop_list); i++)
	{
		fscanf_s(shop_list, "%s%s%s%lf%d", ID, 16, name, 16, brand, 16, &price, &num);
		shop_car_list[i].ID = ID;
		shop_car_list[i].name = name;
		shop_car_list[i].brand = brand;
		shop_car_list[i].price = price;
		shop_car_list[i].num = num;
	}

	cout << "**********************************************************************" << endl;
	cout << setiosflags(ios::left) << setw(16) << "ID" << setw(16) << "名称" << setw(16) << "品牌" << setw(16) << "价格" << setw(16) << "数量" << setw(16) << endl;
	for (int i(0); shop_car_list[i].ID != "NULL"; i++)
	{
		if (shop_car_list[i].num == 0) {
			continue;
		}
		cout << setiosflags(ios::left) << shop_car_list[i].ID << setw(16) << shop_car_list[i].name << setw(16) << shop_car_list[i].brand << setw(16) << shop_car_list[i].price << setw(16) << shop_car_list[i].num << setw(16) << endl;
	}
	fclose(shop_list);
	cout << "**********************************************************************" << endl;
	cout << "库存记录加载完毕！" << endl;
	return;
}

void User::writein_shop_list() 
{
	shop_list = fopen("D:/代码/2019寒假/淘宝/咩咩咩/file/Admin/库存记录/新建文本文档.txt", "w");
	int i = 0;
	for (; shop_car_list[i + 1].ID != "NULL"; i++)
	{
		fprintf(shop_list, "%s %s %s %lf %d\n", shop_car_list[i].ID.c_str(), shop_car_list[i].name.c_str(), shop_car_list[i].brand.c_str(), shop_car_list[i].price, shop_car_list[i].num);
	}
	fprintf(shop_list, "%s %s %s %lf %d", shop_car_list[i].ID.c_str(), shop_car_list[i].name.c_str(), shop_car_list[i].brand.c_str(), shop_car_list[i].price, shop_car_list[i].num);
	fclose(shop_list);
	//cout << "购物车更新成功！" << endl;
	return;
}

void User::add_shop_list()
{
	string ID;
	int num;
	int j = 0;
	int i = 0;
	cout << "输入商品ID和数量：";
	cin >> ID >> num;

	for (; shop_goods_list[j].ID != "NULL"; j++) {
		if (shop_goods_list[j].ID == ID) {
			if (shop_goods_list[j].num >= num) {
				break;
			}
		}
	}
	if (shop_goods_list[j].ID == "NULL") {
		cout << "库存中没有此商品或库存不足！" << endl;
		return;
	}
	else {
		for (; shop_car_list[i].ID != "NULL";i++) {
			if (shop_car_list[i].ID == ID) {
				shop_car_list[i].num += num;
				break;
			}
		}
		if (shop_car_list[i].ID == "NULL") {
			shop_car_list[i].ID = shop_goods_list[j].ID;
			shop_car_list[i].name = shop_goods_list[j].name;
			shop_car_list[i].brand = shop_goods_list[j].brand;
			shop_car_list[i].num = num;
			shop_car_list[i].price = shop_goods_list[j].price;
		}
	}
	cout << "购物车添加成功！" << endl;
	this->writein_shop_list();
	return;
}

void User::drop_shop_list()
{
	cout << "**********************************" << endl;
	cout << "请输入您查询的方式：" << endl;
	cout << "1.商品ID  2.商品品牌  3.商品ID和品牌" << endl;
	cout << "**********************************" << endl;
	int n = 0;
	cin >> n;
	int num = 0;
	string ID, brand;
	if (n == 1) {
		cout << "请输入商品ID和删除数量：";
		cin >> ID >> num;
		for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
			if (shop_car_list[i].ID == ID) {
				if (shop_car_list[i].num >= num) {
					shop_car_list[i].num -= num;
					cout << "购物车删除成功！" << endl;
					this->writein_shop_list();
					return;
				}
				else{
					cout << "购物车商品库存不足！" << endl;
					return;
				}
			}
		}
		cout << "商品不存在！" << endl;
	}
	else if (n == 2) {
		cout << "请输入商品品牌和删除数量：";
		cin >> brand >> num;
		for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
			if (shop_car_list[i].brand == brand) {
				if (shop_car_list[i].num >= num) {
					shop_car_list[i].num -= num;
					cout << "购物车删除成功！" << endl;
					this->writein_shop_list();
					return;
				}
				else {
					cout << "购物车商品库存不足！" << endl;
					return;
				}
			}
		}
		cout << "商品不存在！" << endl;
	}
	else if (n == 3) {
		cout << "请输入商品ID、品牌和删除数量：";
		cin >> ID >> brand >> num;
		for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
			if ((shop_car_list[i].ID == ID) && (shop_car_list[i].brand == brand)) {
				if (shop_car_list[i].num >= num) {
					shop_car_list[i].num -= num;
					cout << "购物车删除成功！" << endl;
					this->writein_shop_list();
					return;
				}
				else {
					cout << "购物车商品库存不足！" << endl;
					return;
				}
			}
		}
		cout << "商品不存在！" << endl;
	}
	else {
		cout << "操作非法！" << endl;
	}
	return;
}

void User::pay()
{
	this->view_shop_list();
	double sum = 0;
	int n = 0;
	for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
		sum = sum + (shop_car_list[i].price*shop_car_list[i].num);
	}
	cout << "****************************************" << endl;
	cout << "一共需要付款" << sum << "!" << endl;
	cout << "1.确认支付  2.取消支付" << endl;
	cin >> n;
	if (n == 1) {
		for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
			for (int j(0); shop_goods_list[j].ID != "NULL"; j++) {
				if (shop_car_list[i].ID == shop_goods_list[j].ID) {
					shop_goods_list[j].num -= shop_car_list[i].num;
				}
			}
		}
		shop_car_list[0].ID = "NULL";
		this->writein_shop_list();
		this->writein_store();
		cout << "付款成功！" << endl;
	}
	else if (n == 2) {
		return;
	}
	else {
		cout << "操作非法!" << endl;
	}
	return;
}

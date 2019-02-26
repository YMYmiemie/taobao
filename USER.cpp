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
	
	userID_list = fopen("D:/����/2019����/�Ա�/������/file/User/�û��˺�/�½��ı��ĵ�.txt", "w");

	if (userID_list==NULL){
			cout << "���ļ�ʧ�ܣ�" << std::endl;
			exit(-1);
	}

	cout << "�����û�����";
	cin >> userID;
	if (userID.size() > 20)
	{
		fclose(userID_list);
		cout << "�û�������ӦС��16��" << endl;
		return false;
	}
	cout << "�������룺";
	cin >> password;
	if (password.size() > 20)
	{
		fclose(userID_list);
		cout << "���볤��ӦС��16��" << endl;
		return false;
	}
	
	fscanf_s(userID_list, "%s", input_userID, 16);
	fscanf_s(userID_list, "%s", input_password, 16);
	while (!feof(userID_list))
	{
		if (userID == input_userID) {
			fclose(userID_list);
			cout << "�û����Ѵ��ڣ�" << endl;
			return false;
		}
		fscanf_s(userID_list, "%s", input_userID, 16);
		fscanf_s(userID_list, "%s", input_password, 16);
		cout << "?";
	}
	this->user_ID = userID;
	this->user_password = password;
	fprintf_s(userID_list, "%-16s%-16s\n", userID.c_str(), password.c_str());
	cout << "���û������ɹ�" << endl;
	fclose(userID_list);

	shop_list = fopen("D: / ���� / 2019���� / �Ա� / ������ / file / User / ���ﳵ / �½��ı��ĵ�.txt", "w");
	paid_list = fopen("D: / ���� / 2019���� / �Ա� / ������ / file / User / �ѹ���Ʒ / �½��ı��ĵ�.txt", "w");
	if(shop_list==NULL||paid_list==NULL){
		cout << "�����ļ����ã�" << endl;
		exit(-1);
	}

	fprintf_s(shop_list, "%-16s%-16s%-16s%-16s%-16s\n", "ID", "����", "Ʒ��", "�۸�", "����");
	fprintf_s(paid_list, "%-16s%-16s%-16s%-16s%-16s\n", "ID", "����", "Ʒ��", "�۸�", "����");
	fclose(shop_list);
	fclose(paid_list);
	cout << "�û��ļ�ע��ɹ���" << endl;
	return true;
}

bool User::userID_cheak()
{
	string input_userID;
	string input_password;
	char list_userID[16];
	char list_password[16];

	userID_list = fopen("D: / ���� / 2019���� / �Ա� / ������ / file / User / �û��˺� / �½��ı��ĵ�.txt", "r");

	if (userID_list == NULL) {
		cout << "���ĵ�ʧ�ܣ�" << endl;
		exit(-1);
	}

	cout << "�����û�����";
	cin >> input_userID;
	cout << "��������";
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
				cout << "��¼�ɹ���" << endl;
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
	store_list = fopen("D:/����/2019����/�Ա�/������/file/Admin/����¼/�½��ı��ĵ�.txt", "r");
	if (store_list == NULL)
	{
		cout << "�ļ���ʧ��" << endl;
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
	cout << setiosflags(ios::left) << setw(16) << "ID" << setw(16) << "����" << setw(16) << "Ʒ��" << setw(16) << "�۸�" << setw(16) << "����" << setw(16) << endl;
	for (int i(0); shop_goods_list[i].ID != "NULL"; i++)
	{
		if (shop_goods_list[i].num == -1) {
			continue;
		}
		cout << setiosflags(ios::left) << shop_goods_list[i].ID << setw(16) << shop_goods_list[i].name << setw(16) << shop_goods_list[i].brand << setw(16) << shop_goods_list[i].price << setw(16) << shop_goods_list[i].num << setw(16) << endl;
	}
	fclose(store_list);
	cout << "**********************************************************************" << endl;
	cout << "����¼������ϣ�" << endl;
	return;
}

void User::writein_store()
{
	store_list = fopen("D:/����/2019����/�Ա�/������/file/Admin/����¼/�½��ı��ĵ�.txt", "w");
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
	cout << "������Ʒ���ƣ�";
	cin >> goodsID;
	for (int i(0); shop_goods_list[i].ID != "NULL"; i++)
	{
		if (goodsID == shop_goods_list[i].ID) {
			if (j) {
				cout << "**********************************************************************" << endl;
				cout << setiosflags(ios::left) << setw(16) << "ID" << setw(16) << "����" << setw(16) << "Ʒ��" << setw(16) << "�۸�" << setw(16) << "����" << setw(16) << endl;
			}
			cout << setiosflags(ios::left) << shop_goods_list[i].ID << setw(16) << shop_goods_list[i].name << setw(16) << shop_goods_list[i].brand << setw(16) << shop_goods_list[i].price << setw(16) << shop_goods_list[i].num << setw(16) << endl;
		}
	}
	if (!j) {
		cout << "�����û�д���Ʒ��" << endl;
	}
	return;
}

void User::view_shop_list()
{
	char ID[16], name[16], brand[16];
	double price;
	int num;
	shop_list = fopen("D:/����/2019����/�Ա�/������/file/Admin/����¼/�½��ı��ĵ�.txt", "r");
	if (store_list == NULL)
	{
		cout << "�ļ���ʧ��" << endl;
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
	cout << setiosflags(ios::left) << setw(16) << "ID" << setw(16) << "����" << setw(16) << "Ʒ��" << setw(16) << "�۸�" << setw(16) << "����" << setw(16) << endl;
	for (int i(0); shop_car_list[i].ID != "NULL"; i++)
	{
		if (shop_car_list[i].num == 0) {
			continue;
		}
		cout << setiosflags(ios::left) << shop_car_list[i].ID << setw(16) << shop_car_list[i].name << setw(16) << shop_car_list[i].brand << setw(16) << shop_car_list[i].price << setw(16) << shop_car_list[i].num << setw(16) << endl;
	}
	fclose(shop_list);
	cout << "**********************************************************************" << endl;
	cout << "����¼������ϣ�" << endl;
	return;
}

void User::writein_shop_list() 
{
	shop_list = fopen("D:/����/2019����/�Ա�/������/file/Admin/����¼/�½��ı��ĵ�.txt", "w");
	int i = 0;
	for (; shop_car_list[i + 1].ID != "NULL"; i++)
	{
		fprintf(shop_list, "%s %s %s %lf %d\n", shop_car_list[i].ID.c_str(), shop_car_list[i].name.c_str(), shop_car_list[i].brand.c_str(), shop_car_list[i].price, shop_car_list[i].num);
	}
	fprintf(shop_list, "%s %s %s %lf %d", shop_car_list[i].ID.c_str(), shop_car_list[i].name.c_str(), shop_car_list[i].brand.c_str(), shop_car_list[i].price, shop_car_list[i].num);
	fclose(shop_list);
	//cout << "���ﳵ���³ɹ���" << endl;
	return;
}

void User::add_shop_list()
{
	string ID;
	int num;
	int j = 0;
	int i = 0;
	cout << "������ƷID��������";
	cin >> ID >> num;

	for (; shop_goods_list[j].ID != "NULL"; j++) {
		if (shop_goods_list[j].ID == ID) {
			if (shop_goods_list[j].num >= num) {
				break;
			}
		}
	}
	if (shop_goods_list[j].ID == "NULL") {
		cout << "�����û�д���Ʒ���治�㣡" << endl;
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
	cout << "���ﳵ��ӳɹ���" << endl;
	this->writein_shop_list();
	return;
}

void User::drop_shop_list()
{
	cout << "**********************************" << endl;
	cout << "����������ѯ�ķ�ʽ��" << endl;
	cout << "1.��ƷID  2.��ƷƷ��  3.��ƷID��Ʒ��" << endl;
	cout << "**********************************" << endl;
	int n = 0;
	cin >> n;
	int num = 0;
	string ID, brand;
	if (n == 1) {
		cout << "��������ƷID��ɾ��������";
		cin >> ID >> num;
		for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
			if (shop_car_list[i].ID == ID) {
				if (shop_car_list[i].num >= num) {
					shop_car_list[i].num -= num;
					cout << "���ﳵɾ���ɹ���" << endl;
					this->writein_shop_list();
					return;
				}
				else{
					cout << "���ﳵ��Ʒ��治�㣡" << endl;
					return;
				}
			}
		}
		cout << "��Ʒ�����ڣ�" << endl;
	}
	else if (n == 2) {
		cout << "��������ƷƷ�ƺ�ɾ��������";
		cin >> brand >> num;
		for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
			if (shop_car_list[i].brand == brand) {
				if (shop_car_list[i].num >= num) {
					shop_car_list[i].num -= num;
					cout << "���ﳵɾ���ɹ���" << endl;
					this->writein_shop_list();
					return;
				}
				else {
					cout << "���ﳵ��Ʒ��治�㣡" << endl;
					return;
				}
			}
		}
		cout << "��Ʒ�����ڣ�" << endl;
	}
	else if (n == 3) {
		cout << "��������ƷID��Ʒ�ƺ�ɾ��������";
		cin >> ID >> brand >> num;
		for (int i(0); shop_car_list[i].ID != "NULL"; i++) {
			if ((shop_car_list[i].ID == ID) && (shop_car_list[i].brand == brand)) {
				if (shop_car_list[i].num >= num) {
					shop_car_list[i].num -= num;
					cout << "���ﳵɾ���ɹ���" << endl;
					this->writein_shop_list();
					return;
				}
				else {
					cout << "���ﳵ��Ʒ��治�㣡" << endl;
					return;
				}
			}
		}
		cout << "��Ʒ�����ڣ�" << endl;
	}
	else {
		cout << "�����Ƿ���" << endl;
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
	cout << "һ����Ҫ����" << sum << "!" << endl;
	cout << "1.ȷ��֧��  2.ȡ��֧��" << endl;
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
		cout << "����ɹ���" << endl;
	}
	else if (n == 2) {
		return;
	}
	else {
		cout << "�����Ƿ�!" << endl;
	}
	return;
}

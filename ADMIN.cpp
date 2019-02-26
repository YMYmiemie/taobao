#pragma warning(disable:4996)
#include"admin.h"
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;

Admin::Admin()
{
	ID = "null";
	password = "null";
}

Admin::~Admin()
{

}

bool Admin::IDcheak()
{
	string input_ID;
	string input_password;
	char correct_ID[16];
	char correct_password[16];

	cout << "�������ԱID��"; 
	cin >> input_ID;
	cout << "�������Ա���룺";
	cin >> input_password;

	
	ID_list = fopen("D:/����/2019����/�Ա�/������/file/Admin/����Ա�˺�/�½��ı��ĵ�.txt", "r");


	if (ID_list == NULL)
	{
		cout << "�ļ���ʧ��" << endl;
		exit(-1);
	}

	//cout << ID_list << endl;

	
	while (!feof(ID_list))
	{

		// cout << "here" << endl;
		fscanf_s(ID_list, "%s", correct_ID, 16);

		
		fscanf_s(ID_list, "%s", correct_password, 16);
		if (strcmp(correct_ID, input_ID.c_str()) == 0)
		{
			if (strcmp(correct_password, input_password.c_str()) == 0)
			{
				this->ID = input_ID;
				this->password = input_password;
				cout << "*********" << endl;
				cout << "��¼�ɹ���" << endl;
				cout << "*********" << endl;
				fclose(ID_list);
				return true;
			}
		}
	}
	fclose(ID_list);
	cout << "����ԱID���������" << endl;
	return false;
}

void Admin::output_store_list()
{
	char ID[16], name[16], brand[16];
	double price;
	int num;
	store_list = fopen( "D:/����/2019����/�Ա�/������/file/Admin/����¼/�½��ı��ĵ�.txt", "r");
	if (store_list == NULL)
	{
		cout << "�ļ���ʧ��" << endl;
		exit(-1);
	}
	fscanf_s(store_list, "%s%s%s%lf%d", ID, 16, name, 16, brand, 16, &price, &num);
	goods_list[0].ID = ID;
	goods_list[0].name = name;
	goods_list[0].brand = brand;
	goods_list[0].price = price;
	goods_list[0].num = num;
	for (int i(1); !feof(store_list);i++)
	{
		fscanf_s(store_list, "%s%s%s%lf%d", ID, 16, name, 16, brand, 16, &price, &num);
		goods_list[i].ID = ID;
		goods_list[i].name = name;
		goods_list[i].brand = brand;
		goods_list[i].price = price;
		goods_list[i].num = num;
	}

	cout << "**********************************************************************" << endl;
	cout << setiosflags(ios::left) << setw(16) << "ID" << setw(16) << "����" << setw(16) << "Ʒ��" << setw(16) << "�۸�" << setw(16) << "����" << setw(16) << endl;
	for (int i(0); goods_list[i].ID!="NULL"; i++)
	{
		/*if (goods_list[i].num == -1) {
			continue;
		}*/
		cout << setiosflags(ios::left) << goods_list[i].ID << setw(16) << goods_list[i].name << setw(16) << goods_list[i].brand << setw(16) << goods_list[i].price << setw(16) << goods_list[i].num << setw(16) << endl;
	}
	fclose(store_list);
	cout << "**********************************************************************" << endl;
	cout << "����¼������ϣ�" << endl;
	return;
}

void Admin::write_store()
{
	store_list = fopen("D:/����/2019����/�Ա�/������/file/Admin/����¼/�½��ı��ĵ�.txt", "w");
	int i = 0;
	for (; goods_list[i+1].ID != "NULL"; i++)
	{
		fprintf(store_list, "%s %s %s %lf %d\n", goods_list[i].ID.c_str(), goods_list[i].name.c_str(), goods_list[i].brand.c_str(), goods_list[i].price, goods_list[i].num);
	}
	fprintf(store_list, "%s %s %s %lf %d", goods_list[i].ID.c_str(), goods_list[i].name.c_str(), goods_list[i].brand.c_str(), goods_list[i].price, goods_list[i].num);
	fclose(store_list);
	return;
}

void Admin::input_goods()
{
	string name, brand;
	double price;
	int num;
	cout << "��������Ʒ���ƣ�";
	cin >> name;
	cout << "��������ƷƷ�ƣ�";
	cin >> brand;
	cout << "��������Ʒ�۸�";
	cin >> price;
	cout << "��������Ʒ������";
	cin >> num;
	
	int i(0);
	for (; goods_list[i].ID != "NULL"; i++)
	{
		if (goods_list[i].name == name && goods_list[i].brand == brand)
		{
			if (goods_list[i].num < 0) {
				goods_list[i].num = num;
			}
			else {
				goods_list[i].num += num;
			}
			this->write_store();
			return;
		}
	}
	
	char ID[16];
	int n(0);
	n = atoi(&(goods_list[i - 1].ID[1]));
	n++;
	if (n > 999) {
		sprintf(ID, "F%d", n);
	}
	else if (n > 99) {
		sprintf(ID, "F0%d", n);
	}
	else if (n > 9) {
		sprintf(ID, "F00%d", n);
	}
	else {
		sprintf_s(ID, "F000%d", n);
	}
	goods_list[i].ID = ID;
	goods_list[i].name = name;
	goods_list[i].brand = brand;
	goods_list[i].price = price;
	goods_list[i].num = num;

	this->write_store();
	return;
}

void Admin::drop_goods()
{
	string ID;
	bool judge = false;
	cout << "��������Ҫɾ����Ʒ��ID��";
	cin >> ID;
	for (int i = 0; goods_list[i].ID != "NULL"; i++)
	{
		if (goods_list[i].ID == ID)
		{
			goods_list[i].num = -1;
			judge = true;
			break;
		}
	}
	if (judge) {
		this->write_store();
		cout << "��Ʒɾ���ɹ���" << endl;
	}
	return;
}

void Admin::modify_goods()
{
	string ID;
	double price;
	int num,n(0);
	cout << "��������Ҫ�޸���Ʒ��ID��";
	cin >> ID;
	for (int i = 0; goods_list[i].ID != "NULL"; i++)
	{
		if (goods_list[i].ID == ID)
		{
			while (n != 3)
			{
				cout << "��ѡ����Ҫ�޸ĵ���Ʒ����" << endl;
				cout << "1.��Ʒ�۸�  2.��Ʒ����  3.�˳��޸�" << endl;
				cin >> n;
				if (n == 1) {
					cout << "��������Ʒ�۸�";
					cin >> price;
					goods_list[i].price = price;
				}
				else if (n == 2) {
					cout << "��������Ʒ������";
					cin >> num;
					goods_list[i].num = num;
				}
			}
			this->write_store();
			return;
		}
	}
	cout << "��Ʒ�����ڣ�" << endl;
	return;
}

void Admin::output_sold_list()
{
	string ID, name, brand;
	double price;
	int num;
	sold_list = fopen("D:/����/2019����/�Ա�/������/file/Admin/�ۻ��嵥/�½��ı��ĵ�.txt", "r");
	fscanf_s(sold_list, "%s%s%s%lf%d", ID.c_str(), 16, name.c_str(), 16, brand.c_str(), 16, &price, &num);
	cout << "**************************************************************************************************" << endl;
	cout << "ID" << setw(16) << "����" << setw(16) << "Ʒ��" << setw(16) << "�۸�" << setw(16) << "����" << setw(16) << endl;
	while (!feof(sold_list))
	{
		cout << ID << setw(16) << name << setw(16) << brand << setw(16) << price << setw(16) << num << setw(16) << endl;
		fscanf_s(store_list, "%s%s%s%lf%d", ID.c_str(), 16, name, 16, brand, 16, &price, &num);
	}
	fclose(sold_list);
	return;
}

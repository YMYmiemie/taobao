#pragma once
#include"admin.h"
#include<iostream>
using namespace std;

int main()
{
	int n(0);
	cout << "��ӭ�������㹺�����ϵͳ" << endl;
	cout << "==========================================" << endl;
	cout << "1.�û���¼  2.�û�ע��  3.����Ա��¼  4.�˳�" << endl;
	cout << "==========================================" << endl;
	cout << "���������";
	cin >> n;
	while (n != 4)
	{
		if (n == 1) {
			User user1;
			if (user1.userID_cheak()){
				int n = 0;
				cout << "========================================================================================" << endl;
				cout << "0.ע����½  1.�鿴��Ʒ  2.��Ʒ����  3.�����Ʒ�����ﳵ  4.ɾ�����ﳵ��Ʒ  5.�鿴���ﳵ  6.����" << endl;
				cout << "========================================================================================" << endl;
				cout << "���������";
				cin >> n;
				while (n != 0) {
					if (n == 1) {
						user1.view_store_list();
					}
					else if (n == 2) {
						user1.search_goods();
					}
					else if (n == 3) {
						user1.add_shop_list();
					}
					else if (n == 4) {
						user1.drop_shop_list();
					}
					else if (n == 5) {
						user1.view_shop_list();
					}
					else if (n == 6) {
						user1.pay();
					}
					else {
						cout << "�����Ƿ���" << endl;
					}
					cout << "���������";
					cin >> n;
				}
			}
		}
		else if (n == 2) {
			User user2;
			user2.userID_create();
		}
		else if (n == 3) {
			Admin admin1;
			if (admin1.IDcheak())
			{
				int n = 0;
				cout << "======================================================================" << endl;
				cout << "0.ע����½  1.��ѯ��Ʒ  2.������Ʒ  3.ɾ����Ʒ  4.�޸���Ʒ  5.�ۻ��嵥" << endl;
				cout << "======================================================================" << endl;
				cout << "���������";
				cin >> n;
				while (n != 0)
				{
					if (n == 1)
					{
						admin1.output_store_list();
					}
					else if (n == 2)
					{
						admin1.input_goods();
					}
					else if (n == 3)
					{
						admin1.drop_goods();
					}
					else if (n == 4)
					{
						admin1.modify_goods();
					}
					else if (n == 5)
					{
						admin1.output_sold_list();
					}
					else
					{
						cout << "����������" << endl;
					}
					cout << "���������";
					cin >> n;
				}
			}
		}
	}
	return 0;
}
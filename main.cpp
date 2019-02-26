#pragma once
#include"admin.h"
#include<iostream>
using namespace std;

int main()
{
	int n(0);
	cout << "欢迎进入网点购物管理系统" << endl;
	cout << "==========================================" << endl;
	cout << "1.用户登录  2.用户注册  3.管理员登录  4.退出" << endl;
	cout << "==========================================" << endl;
	cout << "输入操作：";
	cin >> n;
	while (n != 4)
	{
		if (n == 1) {
			User user1;
			if (user1.userID_cheak()){
				int n = 0;
				cout << "========================================================================================" << endl;
				cout << "0.注销登陆  1.查看商品  2.商品搜索  3.添加商品至购物车  4.删除购物车商品  5.查看购物车  6.结账" << endl;
				cout << "========================================================================================" << endl;
				cout << "输入操作：";
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
						cout << "操作非法！" << endl;
					}
					cout << "输入操作：";
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
				cout << "0.注销登陆  1.查询商品  2.增加商品  3.删除商品  4.修改商品  5.售货清单" << endl;
				cout << "======================================================================" << endl;
				cout << "输入操作：";
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
						cout << "操作数错误！" << endl;
					}
					cout << "输入操作：";
					cin >> n;
				}
			}
		}
	}
	return 0;
}
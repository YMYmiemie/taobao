#include<iostream>
using namespace std;

typedef struct LIST
{
	string ID = "NULL";
	string name;
	string brand;
	double price;
	int num;
}list;

class Admin
{
private:
	string ID;
	string password;
	FILE* ID_list;
	FILE* store_list;
	FILE* sold_list;
	list goods_list[100];
public:
	Admin();
	~Admin();
	bool IDcheak();
	void output_store_list();
	//void print_store_list();
	void write_store();
	void input_goods();
	void drop_goods();
	void modify_goods();
	void output_sold_list();
	//void print_sold_list();
};

class User
{
private:
	string user_ID;
	string user_password;
	FILE* userID_list;
	FILE* store_list;
	FILE* shop_list;
	FILE* paid_list;
	list shop_goods_list[100];
	list shop_car_list[100];
public:
	User();
	~User();
	bool userID_cheak();
	bool userID_create();
	void view_store_list();
	void search_goods();
	void writein_shop_list();
	void writein_store();
	void add_shop_list();
	void drop_shop_list();
	void view_shop_list();
	void pay();
};
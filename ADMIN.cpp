#pragma warning(disable:4996)
#include<string>
#include<iostream>
using namespace std;

class Admin
{
private:
	string ID;
	string password;
	FILE *ID_list;
	FILE *store_list;
	FILE *sold_list;
public:
	Admin();
	~Admin();
	bool IDcheak();
	void store_list();
	void print_store_list();
	void input_goods();
	void drop_goods();
	void modify_goods();
	void sold_list();
	void print_sold_list();
};

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

	cout << "输入管理员ID：";
	cin >> input_ID;
	cout << "输入管理员密码：";
	cin >> input_password;
	fopen_s(&ID_list,".\\file\\Admin\\管理员账号.txt", "r");
	while (!feof(ID_list))
	{
		fscanf(ID_list, "%s", correct_ID, 16);
		fscanf(ID_list, "%s", correct_password, 16);
		if (strcmp(correct_ID, input_ID.c_str()) == 0)
		{
			if (strcmp(correct_password, input_password.c_str()) == 0)
			{
				this->ID = input_ID;
				this->password = input_password;
				cout << "*********" << endl;
				cout << "登录成功！" << endl;
				cout << "*********" << endl;
				fclose(ID_list);
				return true;
			}
		}
	}
	fclose(ID_list);
	cout << "管理员ID或密码错误" << endl;
	return false;
}

void Admin::store_list()
{

}

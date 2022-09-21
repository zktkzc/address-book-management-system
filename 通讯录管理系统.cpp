#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

// 联系人结构体
struct Person
{
	// 姓名
	string name;
	// 性别  1 男   2 女
	int sex;
	// 年龄
	int age;
	// 电话
	string phone;
	// 住址
	string address;
};

// 通讯录结构体
struct Addressbooks
{
	// 通讯录中保存的联系人数组
	struct Person personArray[MAX];

	// 通讯录中当前记录联系人个数
	int size;
};

// 显示菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

// 添加联系人
void addPerson(Addressbooks* abs)
{
	// 判断通讯录是否已满，如果满了就不再添加
	if (abs->size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		// 添加具体联系人
		// 姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;

		// 性别
		int sex;
		cout << "请输入性别：" << endl;
		cout << "1—男  2—女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		// 年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->size].age = age;

		// 电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		// 家庭住址
		string address;
		cout << "请输入住址：" << endl;
		cin >> address;
		abs->personArray[abs->size].address = address;

		// 更新通讯录人数
		abs->size++;

		cout << "添加成功！" << endl;

		system("pause");
		// 清屏
		system("cls");
	}
}

// 显示联系人
void showPerson(Addressbooks* abs)
{
	// 判断通讯录中人数是否位0，如果位0，提示记录为空
	if (abs->size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		// 显示联系人信息
		for (int i = 0; i < abs->size; i++)
		{
			cout << "姓名：" << abs->personArray[i].name << "\t";
			cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话：" << abs->personArray[i].phone << "\t";
			cout << "住址：" << abs->personArray[i].address << endl;
		}
	}

	system("pause");
	system("cls");
}

// 检测联系人是否存在，如果存在，就返回联系人所在数组中的具体位置，不存在就返回-1
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return 1;
		}
	}
	return -1;
}

// 删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res != -1)
	{
		for (int i = res; i < abs->size; i++)
		{
			// 数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		// 更新一下通讯录中的人员数
		abs->size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

// 查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;

	// 判断联系人是否存在通讯录中
	int res = isExist(abs, name);
	if (res != -1)
	{
		// 找到了
		cout << "姓名：" << abs->personArray[res].name << "\t";
		cout << "性别：" << abs->personArray[res].sex << "\t";
		cout << "年龄：" << abs->personArray[res].age << "\t";
		cout << "电话：" << abs->personArray[res].phone << "\t";
		cout << "家庭住址：" << abs->personArray[res].address << endl;
	}
	else
	{
		// 未找到
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

// 修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;

	int res = isExist(abs, name);
	if (res != -1)
	{
		// 姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[res].name = name;

		// 性别
		int sex;
		cout << "请输入姓名性别：" << endl;
		cout << "1—男  2—女" << endl;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		// 年龄
		int age;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->size].age = age;

		// 电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		// 家庭住址
		string address;
		cout << "请输入住址：" << endl;
		cin >> address;
		abs->personArray[abs->size].address = address;

		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

// 清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

int main()
{

	// 创建通讯录结构体变量
	Addressbooks abs;

	// 初始化通讯录中当前的人员个数
	abs.size = 0;

	// 用户选择输入的变量
	int select = 0;

	while (true)
	{
		// 菜单的调用
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&abs); // 利用地址传递，可以修饰实参
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
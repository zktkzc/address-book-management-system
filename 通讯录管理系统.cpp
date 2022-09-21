#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

// ��ϵ�˽ṹ��
struct Person
{
	// ����
	string name;
	// �Ա�  1 ��   2 Ů
	int sex;
	// ����
	int age;
	// �绰
	string phone;
	// סַ
	string address;
};

// ͨѶ¼�ṹ��
struct Addressbooks
{
	// ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	// ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int size;
};

// ��ʾ�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

// �����ϵ��
void addPerson(Addressbooks* abs)
{
	// �ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		// ��Ӿ�����ϵ��
		// ����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->size].name = name;

		// �Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1����  2��Ů" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		// ����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->size].age = age;

		// �绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		// ��ͥסַ
		string address;
		cout << "������סַ��" << endl;
		cin >> address;
		abs->personArray[abs->size].address = address;

		// ����ͨѶ¼����
		abs->size++;

		cout << "��ӳɹ���" << endl;

		system("pause");
		// ����
		system("cls");
	}
}

// ��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	// �ж�ͨѶ¼�������Ƿ�λ0�����λ0����ʾ��¼Ϊ��
	if (abs->size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		// ��ʾ��ϵ����Ϣ
		for (int i = 0; i < abs->size; i++)
		{
			cout << "������" << abs->personArray[i].name << "\t";
			cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].age << "\t";
			cout << "�绰��" << abs->personArray[i].phone << "\t";
			cout << "סַ��" << abs->personArray[i].address << endl;
		}
	}

	system("pause");
	system("cls");
}

// �����ϵ���Ƿ���ڣ�������ڣ��ͷ�����ϵ�����������еľ���λ�ã������ھͷ���-1
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

// ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int res = isExist(abs, name);
	if (res != -1)
	{
		for (int i = res; i < abs->size; i++)
		{
			// ����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		// ����һ��ͨѶ¼�е���Ա��
		abs->size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

// ������ϵ��
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	// �ж���ϵ���Ƿ����ͨѶ¼��
	int res = isExist(abs, name);
	if (res != -1)
	{
		// �ҵ���
		cout << "������" << abs->personArray[res].name << "\t";
		cout << "�Ա�" << abs->personArray[res].sex << "\t";
		cout << "���䣺" << abs->personArray[res].age << "\t";
		cout << "�绰��" << abs->personArray[res].phone << "\t";
		cout << "��ͥסַ��" << abs->personArray[res].address << endl;
	}
	else
	{
		// δ�ҵ�
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

// �޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int res = isExist(abs, name);
	if (res != -1)
	{
		// ����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[res].name = name;

		// �Ա�
		int sex;
		cout << "�����������Ա�" << endl;
		cout << "1����  2��Ů" << endl;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		// ����
		int age;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->personArray[abs->size].age = age;

		// �绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->size].phone = phone;

		// ��ͥסַ
		string address;
		cout << "������סַ��" << endl;
		cin >> address;
		abs->personArray[abs->size].address = address;

		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

// �����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{

	// ����ͨѶ¼�ṹ�����
	Addressbooks abs;

	// ��ʼ��ͨѶ¼�е�ǰ����Ա����
	abs.size = 0;

	// �û�ѡ������ı���
	int select = 0;

	while (true)
	{
		// �˵��ĵ���
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			addPerson(&abs); // ���õ�ַ���ݣ���������ʵ��
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
			cout << "��ӭ�´�ʹ��" << endl;
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
#include"User.h"
//�û��Ĺ��캯��
User::User()
{
}

User::~User()
{
}

bool User::Register(User user)
{
	if (user.userName == NULL)
		return false;
	userId = user.userId;
	strcpy(this->userName, user.userName);
	strcpy(this->userPassword, user.userPassword);
	cout << "ע��ɹ�" << endl;
	return true;
}

bool User::deleteUser(int userId)
{
	if (userId == 0)
		return false;
	//дһ�����ݿ��ļ���ȥ
}


#include "Register.h"
#include <QMessageBox> 

Register::Register(QWidget *parent)
	: QDialog(parent), ui(new Ui::Register)   //�������Ҫ��Ҫ�Թ��캯����ʼ����
{
	ui->setupUi(this);
}

Register::~Register()
{
	delete ui;
}
//���ע��
void Register::Click_Login()
{
	QMessageBox msg;
	msg.setText("hello world!");
	msg.exec();
}

////��ת��ע�ᴰ��
//void Register::Click_Register()
//{
//	this->hide();			//���ε�¼����
//	emit showRegister();	//�����źţ����źŴ��͵��ض�ҳ��
//}

//�����ź�
void Register::receiveLogin()
{
	this->show();   //��ʾע�ᴰ��
}
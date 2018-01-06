#include "Login.h"
#include "Database.h"
#include <QMessageBox> 
#include <QDialog>
Login::Login(QWidget *parent)
	: QDialog(parent), ui(new Ui::Login)
{
	ui->setupUi(this);
	ui->passwordLine->setEchoMode(QLineEdit::Password);//����������ʱ����ʾΪ*******
}

Login::~Login()
{
	delete ui;
}

//�����¼
void Login::Click_Login()
{
	QString name = this->ui->nameLine->text();
	QString passwd = this->ui->passwordLine->text();

	QString sql = "select userName, userPassword from user where userName = '"
		+ name + "'and userPassword ='" + passwd + "'";
	MySql mySql;
	if (mySql.queryDB(sql))
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��¼�ɹ�"),
			QString::fromLocal8Bit("��¼�ɹ�����ӭ���뱾ϵͳ��"),
			QMessageBox::Ok);
		this->hide();
		emit showMain();
	}
	else
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��¼ʧ��"),
			QString::fromLocal8Bit("�û�������������Ƿ����µ�¼��"),
			QMessageBox::Yes | QMessageBox::No);
		ui->passwordLine->clear();  //�������passwardLine
		ui->passwordLine->setFocus();  //��������¶�λ��nameLine
	}
}

//��ת��ע�ᴰ��
void Login::Click_Register()
{
	this->hide();			//���ε�¼����
	emit showRegister();	//�����źţ����źŴ��͵��ض�ҳ��
}

void Login::receiveRegister()
{
	this->show();  //��ʾ��¼����
}
#include "Register.h"
#include "Database.h"
#include "Login.h"
#include <QMessageBox> 
#include <qdebug.h>

Register::Register(QWidget *parent)
	: QDialog(parent), ui(new Ui::Register)   //�������Ҫ��Ҫ�Թ��캯����ʼ����
{
	ui->setupUi(this);
	isAvailableUserName = false;
}

Register::~Register()
{
	delete ui;
}
//���ע��
void Register::Click_Register()
{
	if (!isAvailableUserName)
	{
		qDebug() << "please check your username!";
		
		QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
			QString::fromLocal8Bit("���ȼ���û����Ƿ���ã�"),
			QMessageBox::Yes);
	}
	else
	{
		qDebug() << "get into the register";
		QString name = this->ui->userName->text();
		QString password = this->ui->userPassword->text();
		QString password2 = this->ui->userPassword2->text();

		if (QString::compare(password, password2) == 0)
		{
			qDebug() << "password is same!";
			QString sql1 = "select userName, userPassword from user where userName = '"
				+ name + "'";

			QString sql = "insert into user (userName,userPassword)values('" + name + "','" + password + "')";
			MySql mySql;
			if(!mySql.queryDB(sql1))
				if (mySql.insertDB(sql))
				{
					qDebug() << "insert sucess!";
					QMessageBox::information(this, QString::fromLocal8Bit("tips!"),
						QString::fromLocal8Bit("ע��ɹ���������ص�¼���棡"),
						QMessageBox::Yes);
					this->hide();
					emit showLogin();
				}
				else
				{
					qDebug() << "insert false!";
					QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
						QString::fromLocal8Bit("ע��ʧ�ܣ���"),
						QMessageBox::Yes);
				}
			else 
			{
				qDebug() << "insert false! the user has exist!";
				QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
					QString::fromLocal8Bit("ע��ʧ�ܣ��û��Ѵ���"),
					QMessageBox::Yes);
			}
		}
		else
		{
			qDebug() << " please check your password!";
			QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
				QString::fromLocal8Bit("���벻һ�£�"),
				QMessageBox::Yes);
		}
	}
}

void Register::Click_CheckUser()
{
	QString name = this->ui->userName->text();
	QString sql = "select userName, userPassword from user where userName = '"
		+ name + "'";
	MySql mySql;
	//����û����ظ���
	if (mySql.queryDB(sql))
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("Warning!"),
			QString::fromLocal8Bit("�û����ظ���"),
			QMessageBox::Yes);
		ui->userName->setFocus();  //��������¶�λ��nameLine
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("���û������ã�"),
			QMessageBox::Ok);
		isAvailableUserName = true;
	}

}


void Register::Click_Reset()
{
	ui->userName->clear();  //�������passwardLine
	ui->userPassword->clear();  //�������passwardLine
	ui->userPassword2->clear();  //�������passwardLine
}
//�����ź�
void Register::receiveLogin()
{
	this->show();   //��ʾע�ᴰ��
}

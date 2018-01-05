#include "Login.h"
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
	if (this->ui->nameLine->text().trimmed() == tr("123") &&
		this->ui->passwordLine->text().trimmed() == tr("123"))  //ȥ��lineEdit�ڵ��û������������У��
	{
		//��½�ɹ�����ʾ�Ի���
		QMessageBox msg;
		msg.setText(QString::fromLocal8Bit("��¼�ɹ���"));
		msg.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		msg.exec();
		this->hide();
		emit showMain();

	}
	else
	{
		//�û�������ڴ���
		QMessageBox::warning(this, tr("waring"), tr("your passward is wrong"), QMessageBox::Yes);
		//ui->nameLine->clear();  //�������nameLine
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
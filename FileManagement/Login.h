#pragma once

#include <QtWidgets/QDialog>
#include "ui_Login.h"

class Login : public QDialog
{
	Q_OBJECT

public:
	Login(QWidget *parent = Q_NULLPTR);
	~Login();
	

private:
	Ui::Login *ui;   //��������װ��һϵ�е������֮��ģ��Ͳ����ظ�������

public slots:
	void Click_Login();  //�����½
	void Click_Register();  //�����ת��ע���\

	void receiveRegister();   //����ע�����ź�

signals:
	void showMain();
	void showRegister();
};

#ifndef LOGIN_H_
#define LOGIN_H_

#endif // LOGIN_H_


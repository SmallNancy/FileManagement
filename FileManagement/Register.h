#pragma once

#include <QtWidgets/QDialog>
#include "ui_Register.h"

class Register : public QDialog
{
	Q_OBJECT

public:
	Register(QWidget *parent = Q_NULLPTR);
	~Register();

private:
	Ui::Register *ui;
	bool isAvailableUserName;

	//�ۺ���
public slots:
	void Click_Register();
	void Click_CheckUser();
	void Click_Reset();

	void receiveLogin();  //����login�з�����źŹ����Ĳۺ���
signals:
	void showMain();
	void showLogin();
};

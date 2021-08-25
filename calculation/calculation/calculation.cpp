#include "calculation.h"
#include <QMessageBox>
#include <QtCore/QTextCodec>
calculation::calculation(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(caculate()));//ת��
    connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(clear()));//���
}

calculation::~calculation()
{

}

void calculation::caculate()//���ת���Ĳۺ���
{	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));//��������
	QString estr2 = tr("�����<=180 ��<60 ��<60");
	float result;
	double n1;//�ȵ�����
	double n2;//�ֵ�����
	double n3;//�������
	double out;//�ȷ���С��������
	bool isshow1 = toMatchNum(ui.lineEdit_input1->text(),result);//����Ƿ���ڷǷ��ַ�
	bool isshow2 = toMatchNum(ui.lineEdit_input2->text(),result);
	bool isshow3 = toMatchNumX(ui.lineEdit_input3->text(),result);
	bool isshow4 = toMatchNumX(ui.lineEdit->text(),result);
	if (isshow1 && isshow2 && isshow3 && isshow4) {
		n1 = ui.lineEdit_input1->text().toDouble();
		n2 = ui.lineEdit_input2->text().toDouble();
		n3= ui.lineEdit_input3->text().toDouble();
		out= ui.lineEdit->text().toDouble();
	}
	 
	
	
    if((out!=0))//��ʼ���жȷ���С�����ȷ����λ��ת��
	{		
		
		n1 = int(out);
		/*float ii = float(out);*/
		float iii = fmod(out,int(out))*60;
		n2 = int(iii);

		
		n3 = fmod(iii,int(n2))*60;
		
		ui.lineEdit_input1->setText(QString::number(n1,'f',0));
		ui.lineEdit_input2->setText(QString::number(n2,'f',0));
		ui.lineEdit_input3->setText(QString::number(n3,'f',4));
	}
	else if ((n1<=180)&&(n2<=59)&&(n3<=60)&&(out == 0))
	{
		out = (n1 + n2 / 60.0 + n3 / 3600.0);
		ui.lineEdit->setText(QString::number(out,'f',10));
	}
	
	else
	{
		ui.lineEdit->setText(estr2);
		return;
	}
 
	
}

bool calculation::toMatchNum(const QString &str, float &result)//�������������'��''��'���ַ��Ƿ�����
{	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	bool isShow;
	// ����һ��������ʽ , 4~23 λ���ֺ���ĸ�����
	QString  reg("[0-9]{0,23}");
	// ����ƥ��������
	QRegExp rx(reg);
	bool ok = rx.exactMatch(str);
	// ����ƥ��
	if (ok)
	{
		result =  str.toFloat();
		isShow = true;
	} else {
		QMessageBox msg(this);//�Ի������ø����
		msg.setWindowTitle("Window Title");//�Ի������
		msg.setText(tr("���� �� �� ��������!"));//�Ի�����ʾ�ı�
		msg.setIcon(QMessageBox::Information);//����ͼ������
		msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//�Ի����ϰ����İ�ť

		if(msg.exec() == QMessageBox::Ok)//ģ̬����
		{
			//qDebug() << " Ok is clicked!";//���ݴ���
		}
		isShow = false;
	}
	return isShow;
}
bool calculation::toMatchNumX(const QString &str, float &result)//�������������'��''�ȷ���С��'���ַ��Ƿ�����
{	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	bool isShow;
	// ����һ��������ʽ , 4~23 λ���ֺ���ĸ�����
	QString  reg("[0-9.0-9]*");
	// ����ƥ��������
	QRegExp rx(reg);
	bool ok = rx.exactMatch(str);
	// ����ƥ��
	if (ok)
	{
		result =  str.toFloat();
		isShow = true;
	} else {
		QMessageBox msg(this);//�Ի������ø����
		msg.setWindowTitle("Window Title");//�Ի������
		msg.setText(tr("��������������С��!"));//�Ի�����ʾ�ı�
		msg.setIcon(QMessageBox::Information);//����ͼ������
		msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//�Ի����ϰ����İ�ť

		if(msg.exec() == QMessageBox::Ok)//ģ̬����
		{
			//qDebug() << " Ok is clicked!";//���ݴ���
		}
		isShow = false;
	}
	return isShow;
}
void calculation::clear()//��ʼ��QLineEdit
{
	
	QString estr2 = "";
	
	double n1 = ui.lineEdit_input1->text().toDouble();
	double n2 = ui.lineEdit_input2->text().toDouble();	
	double n3 = ui.lineEdit_input3->text().toDouble();
	double out= ui.lineEdit->text().toDouble();

		ui.lineEdit->setText(estr2);
		
		ui.lineEdit_input1->setText(estr2);
		ui.lineEdit_input2->setText(estr2);
		ui.lineEdit_input3->setText(estr2);
		return;
	
 
	
}
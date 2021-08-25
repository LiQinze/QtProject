#include "calculation.h"
#include <QMessageBox>
#include <QtCore/QTextCodec>
calculation::calculation(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(caculate()));//转换
    connect(ui.pushButton_2,SIGNAL(clicked()),this,SLOT(clear()));//清空
}

calculation::~calculation()
{

}

void calculation::caculate()//点击转换的槽函数
{	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));//中文输入
	QString estr2 = tr("请检查度<=180 分<60 秒<60");
	float result;
	double n1;//度的输入
	double n2;//分的输入
	double n3;//秒的输入
	double out;//度分秒小数的输入
	bool isshow1 = toMatchNum(ui.lineEdit_input1->text(),result);//检测是否存在非法字符
	bool isshow2 = toMatchNum(ui.lineEdit_input2->text(),result);
	bool isshow3 = toMatchNumX(ui.lineEdit_input3->text(),result);
	bool isshow4 = toMatchNumX(ui.lineEdit->text(),result);
	if (isshow1 && isshow2 && isshow3 && isshow4) {
		n1 = ui.lineEdit_input1->text().toDouble();
		n2 = ui.lineEdit_input2->text().toDouble();
		n3= ui.lineEdit_input3->text().toDouble();
		out= ui.lineEdit->text().toDouble();
	}
	 
	
	
    if((out!=0))//开始进行度分秒小数到度分秒各位的转换
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

bool calculation::toMatchNum(const QString &str, float &result)//正则函数检测输入'度''分'的字符是否有误
{	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	bool isShow;
	// 定义一个正则表达式 , 4~23 位数字和字母的组合
	QString  reg("[0-9]{0,23}");
	// 声明匹配结果变量
	QRegExp rx(reg);
	bool ok = rx.exactMatch(str);
	// 进行匹配
	if (ok)
	{
		result =  str.toFloat();
		isShow = true;
	} else {
		QMessageBox msg(this);//对话框设置父组件
		msg.setWindowTitle("Window Title");//对话框标题
		msg.setText(tr("请检查 度 分 输入整数!"));//对话框提示文本
		msg.setIcon(QMessageBox::Information);//设置图标类型
		msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮

		if(msg.exec() == QMessageBox::Ok)//模态调用
		{
			//qDebug() << " Ok is clicked!";//数据处理
		}
		isShow = false;
	}
	return isShow;
}
bool calculation::toMatchNumX(const QString &str, float &result)//正则函数检测输入'秒''度分秒小数'的字符是否有误
{	QTextCodec::setCodecForTr(QTextCodec::codecForName("gb18030"));
	bool isShow;
	// 定义一个正则表达式 , 4~23 位数字和字母的组合
	QString  reg("[0-9.0-9]*");
	// 声明匹配结果变量
	QRegExp rx(reg);
	bool ok = rx.exactMatch(str);
	// 进行匹配
	if (ok)
	{
		result =  str.toFloat();
		isShow = true;
	} else {
		QMessageBox msg(this);//对话框设置父组件
		msg.setWindowTitle("Window Title");//对话框标题
		msg.setText(tr("请输入整数或者小数!"));//对话框提示文本
		msg.setIcon(QMessageBox::Information);//设置图标类型
		msg.setStandardButtons(QMessageBox::Ok | QMessageBox:: Cancel);//对话框上包含的按钮

		if(msg.exec() == QMessageBox::Ok)//模态调用
		{
			//qDebug() << " Ok is clicked!";//数据处理
		}
		isShow = false;
	}
	return isShow;
}
void calculation::clear()//初始化QLineEdit
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
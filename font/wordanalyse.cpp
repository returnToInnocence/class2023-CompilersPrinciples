#include "wordanalyse.h"
#include "ui_wordanalyse.h"

int line_number = 1;


WordAnalyse::WordAnalyse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordAnalyse)
{
    ui->setupUi(this);
    setWindowTitle("词法分析过程");
    path="";
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(ShowTextToWindow()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(enableButton1()));
}

WordAnalyse::~WordAnalyse()
{
    delete ui;
}

void WordAnalyse::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QFont font;
    painter.setRenderHint(QPainter:: Antialiasing, true);

    //填充背景图
    QPalette pal =this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/image/b2.png")));
    setPalette(pal);

    //画背景
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(380, 5, 500, 640);
    //设置画笔为红
    painter.setPen(QPen(Qt::red,3));

    //任务1
    font.setPixelSize(30); //设置字体像素大小为12
    font.setBold(5);
    painter.setFont(font);

    //画横线的部分
    if(x==0){//默认状态
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.drawLine(480,570,840,570);//第八行横线
    }
    if(x==1){//走第一行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.drawLine(480,570,840,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(460,80,840,80);//第一行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(x==2){//走第二行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.drawLine(480,570,840,570);//第八行横线
        if(y==1){
            //走上边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(480,160,740,160);//第二行横线
            painter.drawLine(740,140,840,140);//标识符横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(740,180,840,180);//关键字横线
        }
        if(y==2){
            //走下边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(480,160,740,160);//第二行横线
            painter.drawLine(740,180,840,180);//关键字横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(740,140,840,140);//标识符横线
        }
    }
    if(x==3){//走第三行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.drawLine(480,570,840,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(480,220,840,220);//第三行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(x==4){//走第四行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.drawLine(480,570,840,570);//第八行横线
        if(y==1){
            //走上边
            painter.drawLine(480,300,840,300);//第四行横线
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(570,255,840,255);//第四行上部横线
            painter.drawLine(480,300,550,300);//第四行横线
            painter.setPen(QPen(Qt::red,3));
        }
        if(y==2){
            //走下边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(480,300,840,300);//第四行横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(570,255,840,255);//第四行上部横线
        }
    }
    if(x==5){//走第五行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.drawLine(480,570,840,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(480,380,840,380);//第五行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(x==6){//走第六行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.drawLine(480,570,840,570);//第八行横线
        if(y==1){
            //走上边
            painter.drawLine(480,460,840,460);//第六行横线
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(570,420,840,420);//第六行上部分横线
            painter.drawLine(480,460,550,460);//第六行横线
            painter.setPen(QPen(Qt::red,3));
        }
        if(y==2){
            //走下边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(480,460,840,460);//第六行横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(570,420,840,420);//第六行上部分横线
        }
    }
    if(x==7){//走第七行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,570,840,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(480,520,840,520);//第七行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(x==8){//走第八行
        painter.drawLine(410,80,840,80);//第一行横线
        painter.drawLine(480,160,740,160);//第二行横线
        painter.drawLine(740,140,840,140);//标识符横线
        painter.drawLine(740,180,840,180);//关键字横线
        painter.drawLine(480,220,840,220);//第三行横线
        painter.drawLine(480,300,840,300);//第四行横线
        painter.drawLine(570,255,840,255);//第四行上部横线
        painter.drawLine(480,380,840,380);//第五行横线
        painter.drawLine(480,460,840,460);//第六行横线
        painter.drawLine(570,420,840,420);//第六行上部分横线
        painter.drawLine(480,520,840,520);//第七行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(480,570,840,570);//第八行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    //画开始圆S
    painter.drawText(445,90,">");
    painter.drawEllipse(460,60,40,40);
    painter.drawText(472,90,"S");
    //指向Z的线
    painter.drawLine(840,80,840,590);
    painter.drawEllipse(820,590,40,40);
    painter.drawText(830,620,"Z");
    //S指向Z的线
    painter.drawLine(480,105,480,570);
    //任务1
    painter.drawText(555,90,">");
    painter.drawText(580,60,"↷");
    painter.drawEllipse(570,60,40,40);
    //任务2
    painter.drawLine(740,140,740,180);//第二行竖线
    //分支
    painter.drawText(825,150,">");
    painter.drawText(825,190,">");
    painter.drawText(555,170,">");
    painter.drawText(580,140,"↷");
    painter.drawEllipse(570,140,40,40);
    //任务3
    painter.drawText(825,230,">");
    //任务4
    painter.drawText(535,310,">");
    painter.drawEllipse(550,280,40,40);
    //分支
    painter.drawLine(570,280,570,255);
    painter.drawText(825,265,">");
    painter.drawText(635,310,">");
    painter.drawEllipse(650,280,40,40);
    painter.drawText(825,310,">");
    //任务5
    painter.drawText(535,390,">");
    painter.drawText(560,360,"↷");
    painter.drawEllipse(550,360,40,40);
    painter.drawText(635,390,">");
    painter.drawEllipse(650,360,40,40);
    painter.drawText(825,390,">");
    //任务6
    painter.drawText(535,470,">");
    //分支
    painter.drawLine(570,440,570,420);
    painter.drawText(825,430,">");
    painter.drawEllipse(550,440,40,40);
    painter.drawText(635,470,">");
    painter.drawEllipse(650,440,40,40);
    painter.drawText(825,470,">");
    //任务7
    painter.drawText(535,530,">");
    painter.drawEllipse(550,500,40,40);
    painter.drawText(635,530,">");
    painter.drawEllipse(650,500,40,40);
    painter.drawText(825,530,">");
    //其他符号
    painter.drawText(825,580,">");
    //添加文字
    font.setPixelSize(15); //设置字体像素大小为12
    painter.setFont(font);
    //任务1
    painter.drawText(510,75,"数字");
    painter.drawText(580,60,"   数字");
    painter.drawText(740,75,"无符号整数");
    //任务2
    painter.drawText(510,155,"字母");
    painter.drawText(580,140,"   字母、数字");
    painter.drawText(640,155,"    LookUp");
    painter.drawText(720,135,"    标识符");
    painter.drawText(720,175,"    关键字");
    //任务3
    painter.drawText(500,215,"+,-,*,/,(,),;,[,],=,<");
    painter.drawText(750,215,"单分界符");
    //任务4
    painter.drawText(570,250,"其他符号             单分界符");
    painter.drawText(510,295,":           =              双分界符");
    //任务5
    painter.drawText(560,355,"   其他符号");
    painter.drawText(510,375,"{           }              注释");
    //任务6
    painter.drawText(570,415,"其他符号           程序结束标识");
    painter.drawText(510,455,".           .          数组下标界限符");
    //任务7
    painter.drawText(510,515,"'           '          字符串标识符");
    //其他
    painter.drawText(500,565,"其他符号                     报错");
}

QString WordAnalyse::open()
{
    this->hide();//选择文件时隐藏主窗口
    //测试,打开一个本地文件选择对话框
    QFileDialog *fileDialog = new QFileDialog(this);//创建对象
    fileDialog->setWindowTitle(tr("打开文件"));//设置文件保存对话框的标题
    //设置默认文件路径
    fileDialog->setDirectory("../");

    //设置文件过滤器,支持的文件类型
    fileDialog->setNameFilter(tr("Images(*.txt)"));

    //设置可以选择文件夹内的多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);

    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    fileDialog->setViewMode(QFileDialog::List);//列表的形式显示
    fileDialog->setGeometry(500,300,600,400);//设置文件对话框的显示位置

    if(fileDialog->exec() == QDialog::Accepted)
    {
        path = fileDialog->selectedFiles()[0];//得到用户选择的第一个文件夹名
        qDebug()<<"文件的名字："<<path;
        fileDialog->close();
        this->show();//选择文件后窗口重新显示
        return path;
    }else{
        this->show();//选择文件后窗口重新显示
        return "未找到文件";
    }
}
void WordAnalyse::ShowTextToWindow()//显示文本文件中的内容
{
    qDebug()<<"进来了";

    QString fileName = "C:/Users/86180/Desktop/SouceCode.txt";
    if(!fileName.isEmpty())
    {
        QFile *file = new QFile;
        file->setFileName(fileName);
        bool ok = file->open(QIODevice::ReadOnly);
        if(ok)
        {
            QTextStream in(file);
            ui->textEdit->setText(in.readAll());
            file->close();
            delete file;
        }
        else
        {
            QMessageBox::information(this,"错误信息","打开文件:" + file->errorString());
            return;
        }
    }
}

void WordAnalyse::showdata()
{
    //统计结果展示窗口，写入你们跑出来的数据
    qDebug()<<"写入";
}

QString WordAnalyse::reCall(QString str,int &i){
    while(1){
       delay();//这里做了延时处理，延时1s才执行下面的代码
       ui->textEdit_2->insertPlainText(allRuleJude(str,i)+"\n");
       repaint();//根据x和y的值来重绘dfa，达到动态展示的目的
       i++;
       if(i >= str.length()-1){
           break;
       }else{
           continue;
       }
    }
    return ">> 分析全部结束 end";
}

QString WordAnalyse::allRuleJude(QString str,int &i){  //规则调用写在这里面，规则函数需要有索引参数i
    //判断结论输出字符串
    QString re = "";
    //判断是不是换行
    if(str[i] == 10){
        i++;
        line_number++;
    }
    //判断当前指针指向的是否是空格，空格跳过
    if(str[i] == ' '){
        int blocklength  = 1;
        int j = i+1;
        while(1)
        {
            if(str[j] == ' '){
                blocklength ++;
            }else{
                break;
            }
            j++;
        }
        i += blocklength;
    }
    //区分单符号和双符号
    bool flag3 = false;
    char array[12] ={'+','-','*','/','(',')','[',']','=','<',';'};
    for(int j = 0 ; j< 12 ;j++){
        if(str[i] == array[j]){
            flag3 = true;
        }
    }
//    if(str[i] == "\n"){
//        qDebug() << "输出了\n";
////        line_number++;
//    }
    //规则判断
    if(str[i] >= 48 && str[i] <= 57){  //进入规则条件
        re = Rule1(str,i);
    }
    else if((str[i] >= 65 &&str[i]<=90)|| (str[i] <= 122 && str[i]>=97)){
        re = Rule2(str,i);
    }else if(flag3){
        re = Rule3(str,i);
    }
    else if(str[i]==":"&&str[i+1]=="="){
        re = Rule4(str,i);
    }
    else if(str[i]==":"&&str[i+1]!="="){
        re = Rule5(str,i);
    }
    else if(str[i]=="{"){
        re = Rule6(str,i);
    }
    else if(str[i]=="."&& str[i+1]=="."){
        re = Rule7(str,i);
    }
    else if(str[i]=="."&&str[i+1]!="."){
        re = Rule8(str,i);
    }
    else if(str[i]=="'"){
        re = Rule9(str,i);
    }
    else{
        re = Rule10(str,i);
    }
    return re;
}

QString WordAnalyse::Rule1(QString str,int &i){
    //正整数
    QString s = "";
    for(int j = 0; i < str.length();++i,++j){
        if(str[i] < 48 || str[i] > 57){
            x=8;
            i--;
            break;
        }
        s[j] = str[i];
    }
    x=1;
    return ">> 正整数: "+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule2(QString str,int &i){
       QString KeyWord[28]={"program","function","procedure","array","const","file","record","set","type","var","case","of",
                    "begin","end","do","if","else","for","repeat","then","while","with","string","integer","class","not",
                    "read","write"};
       QString s = "";
        for(int k = 0;i < str.length();++i,++k){     

            for (int j = 0; j < 28; ++j) {
                if(s == KeyWord[j])
                {
                    x=2;
                    y=2;
                    i--;
                    return ">> 关键字: "+KeyWord[j]+" 行号为："+QString::number(line_number);
                }
            }
            if(str[i] < 65 || (str[i] > 90 && str[i]<97) || str[i] > 122 || str[i] ==' '){
                x=8;
                i--;
                break;
            }
            s[k] = str[i];
        }
        x=2;
        y=1;
        return ">> 标识符: "+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule3(QString str,int &i){
    char array[12] ={'+','-','*','/','(',')','[',']','=','<',';'};
    QString s = "";
    for(int j = 0 ; j<12; ++j){
        if(str[i] == array[j]){
            s[0] = str[i];
            x=3;
            break;
        }
    }
    return ">> 单字符分界符: "+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule4(QString str,int &i){//:=
    QString s = "";
    s = "" + str[i]+str[i+1];
    x = 4;
    y = 2;
    i+=2;
    return ">>双字符分界符: "+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule5(QString str,int &i){//：其他符号
     QString s = "";
     s = str[i];
     x = 4;
     y = 1;
     i++;
     return ">> 单分界符："+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule6(QString str,int &i){//注释
    QString s = "";
    if(str[i]=='{'){
        bool flag = false;
        for(int k = 0;k<str.length();i++,k++){
            if(str[i]==" "){
               break;
            }
             if(str[i]=='}'){
                     flag = true;
                     s[k] = str[i];
                     break;
                 }
             else{
                 s[k] = str[i];
                 continue;
             }
        }
        if(flag);
        else{
            return ">> Error! Please input Rule6\n";
        }
    }
        x=5;
       return ">> 注释："+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule7(QString str,int &i){//.+其他符号(程序结束标识)
    QString s = "";
    s = "" + str[i]+str[i+1];
    i++;
    x = 7;
    y = 2;
    return  ">> 数组下标界限符： "+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule8(QString str,int &i){//..
        QString s = "";
        s = str[i];
        x = 6;
        y = 1;
        return ">> 程序结束标识："+s+" 行号为："+QString::number(line_number);
}

QString WordAnalyse::Rule9(QString str,int &i){
    QString point = "'";
    QString result = ">> 字符串标识符：'\n";
    QString s = "" + str[i];
    bool flag = false;
    i = i+1;
    for(int k = 0; i < str.length(); k++,i++){
        s = s + str[i];
        if(str[i] == point){
            result = result + result;
            flag = true;
            break;
        }
    }
    if(flag == false){
        return result + ">> Error! Please input Rule9\n";
    }
    else{
        return result + ">> 字符串："+s+" 行号为："+QString::number(line_number);
    }
}

QString WordAnalyse::Rule10(QString str,int &i){
    if(str[i] == " "){
        return "";
    }
    else{
        return ">> Other character,error!";
    }
}

void WordAnalyse::enableButton1(void){
    int i = 0;
    qDebug() << ui->textEdit->toPlainText();
    ui->textEdit->insertPlainText(reCall(ui->textEdit->toPlainText(),i)+"\n");
    qDebug()<<ui->textEdit->toPlainText();//获取输入框中输入的数据
}
void WordAnalyse::enableButton2(void){
    //ui->lineEdit->setText("");
    ui->textEdit->setText("");
}

void WordAnalyse::delay(){
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(1000, &loop, SLOT(quit()));//等待1000ms
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}

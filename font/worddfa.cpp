#include "worddfa.h"
#include "ui_worddfa.h"

WordDFA::WordDFA(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WordDFA)
{
    ui->setupUi(this);
    setWindowTitle("词法分析DFA");
}
 
WordDFA::~WordDFA()
{
    delete ui;
}

void WordDFA::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QFont font;
    int i=0;
    int k=1;
    painter.setRenderHint(QPainter:: Antialiasing, true);

    //填充背景图
    QPalette pal =this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/image/b2.png")));
    setPalette(pal);

    //画背景
    painter.setPen(Qt::black);
    painter.setBrush(Qt::white);
    painter.drawRect(200, 5, 500, 700);
    //设置画笔为红
    painter.setPen(QPen(Qt::red,3));

    //任务1
    font.setPixelSize(30); //设置字体像素大小为12
    font.setBold(5);
    painter.setFont(font);

    //画横线的部分
    if(i==0){//默认状态
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.drawLine(280,570,640,570);//第八行横线
    }
    if(i==1){//走第一行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.drawLine(280,570,640,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(260,80,640,80);//第一行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(i==2){//走第二行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.drawLine(280,570,640,570);//第八行横线
        if(k==1){
            //走上边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(280,160,540,160);//第二行横线
            painter.drawLine(540,140,640,140);//标识符横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(540,180,640,180);//关键字横线
        }
        if(k==2){
            //走下边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(280,160,540,160);//第二行横线
            painter.drawLine(540,180,640,180);//关键字横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(540,140,640,140);//标识符横线
        }
    }
    if(i==3){//走第三行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.drawLine(280,570,640,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(280,220,640,220);//第三行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(i==4){//走第四行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.drawLine(280,570,640,570);//第八行横线
        if(k==1){
            //走上边
            painter.drawLine(280,300,640,300);//第四行横线
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(370,255,640,255);//第四行上部横线
            painter.drawLine(280,300,350,300);//第四行横线
            painter.setPen(QPen(Qt::red,3));
        }
        if(k==2){
            //走下边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(280,300,640,300);//第四行横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(370,255,640,255);//第四行上部横线
        }
    }
    if(i==5){//走第五行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.drawLine(280,570,640,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(280,380,640,380);//第五行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(i==6){//走第六行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.drawLine(280,570,640,570);//第八行横线
        if(k==1){
            //走上边
            painter.drawLine(280,460,640,460);//第六行横线
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(370,420,640,420);//第六行上部分横线
            painter.drawLine(280,460,350,460);//第六行横线
            painter.setPen(QPen(Qt::red,3));
        }
        if(k==2){
            //走下边
            painter.setPen(QPen(Qt::blue,3));
            painter.drawLine(280,460,640,460);//第六行横线
            painter.setPen(QPen(Qt::red,3));
            painter.drawLine(370,420,640,420);//第六行上部分横线
        }
    }
    if(i==7){//走第七行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,570,640,570);//第八行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(280,520,640,520);//第七行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }
    if(i==8){//走第八行
        painter.drawLine(210,80,640,80);//第一行横线
        painter.drawLine(280,160,540,160);//第二行横线
        painter.drawLine(540,140,640,140);//标识符横线
        painter.drawLine(540,180,640,180);//关键字横线
        painter.drawLine(280,220,640,220);//第三行横线
        painter.drawLine(280,300,640,300);//第四行横线
        painter.drawLine(370,255,640,255);//第四行上部横线
        painter.drawLine(280,380,640,380);//第五行横线
        painter.drawLine(280,460,640,460);//第六行横线
        painter.drawLine(370,420,640,420);//第六行上部分横线
        painter.drawLine(280,520,640,520);//第七行横线
        painter.setPen(QPen(Qt::blue,3));
        painter.drawLine(280,570,640,570);//第八行横线
        //画完以后将画笔的颜色恢复成红色
        painter.setPen(QPen(Qt::red,3));
    }

    //画开始圆S
    painter.drawText(245,90,">");
    painter.drawEllipse(260,60,40,40);
    painter.drawText(272,90,"S");
    //指向Z的线
    painter.drawLine(640,80,640,590);
    painter.drawEllipse(620,590,40,40);
    painter.drawText(630,620,"Z");
    //S指向Z的线
    painter.drawLine(280,105,280,570);

    //任务1
    painter.drawText(355,90,">");
    painter.drawText(380,60,"↷");
    painter.drawEllipse(370,60,40,40);

    //任务2
    painter.drawLine(540,140,540,180);//第二行竖线
    //分支
    //painter.drawLine(540,140,640,140);//标识符横线
    painter.drawText(625,150,">");
    //painter.drawLine(540,180,640,180);//关键字横线
    painter.drawText(625,190,">");
    painter.drawText(355,170,">");
    painter.drawText(380,140,"↷");
    painter.drawEllipse(370,140,40,40);
    //任务3
    painter.drawText(625,230,">");
    //任务4
    painter.drawText(335,310,">");
    painter.drawEllipse(350,280,40,40);
    //分支
    painter.drawLine(370,280,370,255);
    //painter.drawLine(370,255,640,255);//第四行上部横线
    painter.drawText(625,265,">");
    painter.drawText(435,310,">");
    painter.drawEllipse(450,280,40,40);
    painter.drawText(625,310,">");
    //任务5
    painter.drawText(335,390,">");
    painter.drawText(360,360,"↷");
    painter.drawEllipse(350,360,40,40);
    painter.drawText(435,390,">");
    painter.drawEllipse(450,360,40,40);
    painter.drawText(625,390,">");
    //任务6
    painter.drawText(335,470,">");
    //分支
    painter.drawLine(370,440,370,420);
    //painter.drawLine(370,420,640,420);//第六行上部分横线
    painter.drawText(625,430,">");
    painter.drawEllipse(350,440,40,40);
    painter.drawText(435,470,">");
    painter.drawEllipse(450,440,40,40);
    painter.drawText(625,470,">");
    //任务7
    painter.drawText(335,530,">");
    painter.drawEllipse(350,500,40,40);
    painter.drawText(435,530,">");
    painter.drawEllipse(450,500,40,40);
    painter.drawText(625,530,">");
    //其他符号
    painter.drawText(625,580,">");
    //添加文字
    font.setPixelSize(15); //设置字体像素大小为12
    painter.setFont(font);
    //任务1
    painter.drawText(310,75,"数字");
    painter.drawText(380,60,"   数字");
    painter.drawText(540,75,"无符号整数");
    //任务2
    painter.drawText(310,155,"字母");
    painter.drawText(380,140,"   字母、数字");
    painter.drawText(440,155,"    LookUp");
    painter.drawText(520,135,"    标识符");
    painter.drawText(520,175,"    关键字");
    //任务3
    painter.drawText(300,215,"+,-,*,/,(,),;,[,],=,<");
    painter.drawText(550,215,"单分界符");
    //任务4
    painter.drawText(370,250,"其他符号             单分界符");
    painter.drawText(310,295,":           =              双分界符");
    //任务5
    painter.drawText(360,355,"   其他符号");
    painter.drawText(310,375,"{           }              注释");
    //任务6
    painter.drawText(370,415,"其他符号           程序结束标识");
    painter.drawText(310,455,".           .          数组下标界限符");
    //任务7
    painter.drawText(310,515,"'           '          字符串标识符");
    //其他
    painter.drawText(300,565,"其他符号                     报错");
}

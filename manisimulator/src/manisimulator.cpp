#include "manisimulator.h"
#include "./ui_manisimulator.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <cmath>

#define PI 3.14159265

maniSimulator::maniSimulator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::maniSimulator)
{
    ui->setupUi(this);

    // QGraphicsScene 설정
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    // QSpinBox 및 QSlider 범위 설정
    ui->link1->setRange(1, 100);
    ui->link2->setRange(1, 100);
    ui->link3->setRange(1, 100);

    ui->joint1->setRange(0, 360);
    ui->joint2->setRange(0, 360);
    ui->joint3->setRange(0, 360);
}

maniSimulator::~maniSimulator()
{
    delete ui;
}

void maniSimulator::drawManipulator()
{
    // scene 초기화
    scene->clear();

    // 각 링크의 길이와 각도 가져오기
    int length1 = ui->link1->value();//길이 설정
    int length2 = ui->link2->value();
    int length3 = ui->link3->value();

    double angle1 = ui->joint1->value() * PI / 180.0;//각도 설정
    double angle2 = ui->joint2->value() * PI / 180.0;
    double angle3 = ui->joint3->value() * PI / 180.0;

    // Pen 설정 (선 그리기용)
    QPen pen(Qt::black);//색깔은 검은색, 두께는 4
    pen.setWidth(4);

    // 고정된 시작점 좌표 설정
    static int fixedX = 50;
    static int fixedY = 50;

    // 첫 번째 링크 끝 좌표 계산
    double x1 = fixedX + length1 * cos(angle1);//시작좌표로부터 길이*cos=x좌표
    double y1 = fixedY - length1 * sin(angle1);//시작좌표로부터 길이*sin=y좌표
    QGraphicsLineItem *line1 = new QGraphicsLineItem(fixedX, fixedY, x1, y1);//선을 그려주는 포인터 객체 생성
    line1->setPen(pen);
    scene->addItem(line1);

    // 두 번째 링크 끝 좌표 계산
    double x2 = x1 + length2 * cos(angle1 + angle2);
    //두번째 좌표는 첫번째 좌표로부터 증가, 첫번째 각도와 두번째 각도를 합쳐야 원하는 각도
    double y2 = y1 - length2 * sin(angle1 + angle2);
    QGraphicsLineItem *line2 = new QGraphicsLineItem(x1, y1, x2, y2);//첫번째 두번째 점을 이어 선 긋기
    line2->setPen(pen);
    scene->addItem(line2);

    // 세 번째 링크 끝 좌표 계산
    double x3 = x2 + length3 * cos(angle1 + angle2 + angle3);
    double y3 = y2 - length3 * sin(angle1 + angle2 + angle3);
    QGraphicsLineItem *line3 = new QGraphicsLineItem(x2, y2, x3, y3);
    line3->setPen(pen);
    scene->addItem(line3);

    //점을 나중에 생성하여야 점이 위에 그려짐
    // 첫 번째 조인트에 점 추가
    QGraphicsEllipseItem *point1 = new QGraphicsEllipseItem(x1 - 3, y1 - 3, 6, 6);
    //6크기의 원 그리기,중앙을 맞추기 위해 좌표 각각 -3
    point1->setBrush(Qt::red);
    scene->addItem(point1);

    // 두 번째 조인트에 점 추가
    QGraphicsEllipseItem *point2 = new QGraphicsEllipseItem(x2 - 3, y2 - 3, 6, 6);
    point2->setBrush(Qt::red);
    scene->addItem(point2);

    // 세 번째 조인트에 점 추가
    QGraphicsEllipseItem *point3 = new QGraphicsEllipseItem(x3 - 3, y3 - 3, 6, 6);
    point3->setBrush(Qt::red);
    scene->addItem(point3);
}

void maniSimulator::on_confirmbutton_clicked()
{
    drawManipulator();  // 매니퓰레이터 그리기
}

void maniSimulator::on_joint1_valueChanged(int value)
{
    drawManipulator();  // 조인트 값이 변경될 때마다 그리기
}

void maniSimulator::on_joint2_valueChanged(int value)
{
    drawManipulator();
}

void maniSimulator::on_joint3_valueChanged(int value)
{
    drawManipulator();
}

void maniSimulator::on_clearbutton_clicked()
{
    // 모든 값 초기화
    ui->link1->setValue(1);
    ui->link2->setValue(1);
    ui->link3->setValue(1);
    ui->joint1->setValue(0);
    ui->joint2->setValue(0);
    ui->joint3->setValue(0);

    scene->clear();  // 화면 초기화
}


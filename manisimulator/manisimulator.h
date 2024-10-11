#ifndef MANISIMULATOR_H
#define MANISIMULATOR_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui { class maniSimulator; }
QT_END_NAMESPACE

class maniSimulator : public QMainWindow
{
    Q_OBJECT

public:
    maniSimulator(QWidget *parent = nullptr);
    ~maniSimulator();

    // 매니퓰레이터를 그리는 함수 선언
    void drawManipulator();

private slots:
    void on_confirmbutton_clicked();
    void on_clearbutton_clicked();
    void on_joint1_valueChanged(int value);
    void on_joint2_valueChanged(int value);
    void on_joint3_valueChanged(int value);

private:
    Ui::maniSimulator *ui;

    // QGraphicsScene과 QGraphicsView 추가
    QGraphicsScene *scene;
    QGraphicsView *view;
};
#endif // MANISIMULATOR_H

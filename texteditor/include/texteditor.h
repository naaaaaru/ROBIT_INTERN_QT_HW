#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class texteditor; }
QT_END_NAMESPACE

class texteditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit texteditor(QWidget *parent = nullptr);  // 생성자
    ~texteditor();  // 소멸자

private slots:
    void on_open_clicked();   // 파일 열기
    void on_save_clicked();   // 파일 저장
    void on_saveas_clicked(); // 다른 이름으로 저장
    void on_close_clicked();  // 프로그램 종료

private:
    void showFilename(); //파일 이름 함수
    Ui::texteditor *ui;  // UI 객체 포인터
    QString currentFile; // 현재 열려 있는 파일 경로
};

#endif // TEXTEDITOR_H

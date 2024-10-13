#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QMainWindow>
#include <QTextBrowser>
#include <QClipboard>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class keyboard; }
QT_END_NAMESPACE

class keyboard : public QMainWindow
{
    Q_OBJECT

public:
    keyboard(QWidget *parent = nullptr);
    ~keyboard();

protected:
    void keyReleaseEvent(QKeyEvent *event) override; // Shift 해제 처리

private slots:
    void on_num7_clicked();
    void on_copy_clicked();
    void on_clear_clicked();
    void on_backspace_clicked();
    void on_plus_clicked();
    void on_bar_clicked();
    void on_num0_clicked();
    void on_num9_clicked();
    void on_num8_clicked();
    void on_num6_clicked();
    void on_num5_clicked();
    void on_num4_clicked();
    void on_num3_clicked();
    void on_num2_clicked();
    void on_num1_clicked();
    void on_apostrophe_clicked();
    void on_tab_clicked();
    void on_q_clicked();
    void on_w_clicked();
    void on_e_clicked();
    void on_r_clicked();
    void on_t_clicked();
    void on_y_clicked();
    void on_u_clicked();
    void on_i_clicked();
    void on_o_clicked();
    void on_p_clicked();
    void on_leftbraket_clicked();
    void on_rightbraket_clicked();
    void on_capslock_clicked();
    void on_a_clicked();
    void on_s_clicked();
    void on_d_clicked();
    void on_f_clicked();
    void on_g_clicked();
    void on_h_clicked();
    void on_j_clicked();
    void on_k_clicked();
    void on_l_clicked();
    void on_colon_clicked();
    void on_quotationmark_clicked();
    void on_enter_clicked();
    void on_rightshift_clicked();
    void on_slash_clicked();
    void on_period_clicked();
    void on_comma_clicked();
    void on_m_clicked();
    void on_n_clicked();
    void on_b_clicked();
    void on_v_clicked();
    void on_c_clicked();
    void on_x_clicked();
    void on_z_clicked();
    void on_leftshift_clicked();
    void on_leftctrl_clicked();
    void on_fn_clicked();
    void on_win_clicked();
    void on_leftalt_clicked();
    void on_space_clicked();
    void on_rightalt_clicked();
    void on_rightctrl_clicked();

private:
    Ui::keyboard *ui;
    bool isKoreanMode;
    bool isCapsLockOn;
    bool isShiftPressed;

    void appendToTextBrowser(const QString &text);
    void releaseShift(); // Shift 해제 처리
};

#endif // KEYBOARD_H

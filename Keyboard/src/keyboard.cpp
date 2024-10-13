#include "keyboard.h"
#include "./ui_keyboard.h"

keyboard::keyboard(QWidget *parent)//생성자,한국어,capslock(계속 대문자),shift(한번만 대문자) 포함, 처음에는 다 비활성화
    : QMainWindow(parent), ui(new Ui::keyboard),
      isKoreanMode(false), isCapsLockOn(false), isShiftPressed(false)
{
    ui->setupUi(this);
}

keyboard::~keyboard()//소멸자
{
    delete ui;
}

void keyboard::appendToTextBrowser(const QString &text)
//문자 입력함수,상태에 따라 대소문자 입력
{
    QString charToAdd = isShiftPressed || isCapsLockOn ? text.toUpper() : text.toLower();
    QString currentText = ui->textBrowser->toPlainText();//입력된 글자를 문자열로 가져옴
    currentText.append(charToAdd);//문자열 끝에 문자 추가
    ui->textBrowser->setText(currentText);//새로운 텍스트 설정 명령어
    if (isShiftPressed)
        {
            releaseShift();
        }
}

void keyboard::on_num7_clicked()
{
    appendToTextBrowser("7");
}

void keyboard::on_num0_clicked()
{
    appendToTextBrowser("0");
}

void keyboard::on_num9_clicked()
{
    appendToTextBrowser("9");
}

void keyboard::on_num8_clicked()
{
    appendToTextBrowser("8");
}

void keyboard::on_num6_clicked()
{
    appendToTextBrowser("6");
}

void keyboard::on_num5_clicked()
{
    appendToTextBrowser("5");
}

void keyboard::on_num4_clicked()
{
    appendToTextBrowser("4");
}

void keyboard::on_num3_clicked()
{
    appendToTextBrowser("3");
}

void keyboard::on_num2_clicked()
{
    appendToTextBrowser("2");
}

void keyboard::on_num1_clicked()
{
    appendToTextBrowser("1");
}

void keyboard::on_q_clicked()//한국어이거나 영어에 따라 문제 입력
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅂ");
    }
    else
    {
        appendToTextBrowser("Q");
    }
}

void keyboard::on_w_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅈ");
    }
    else
    {
        appendToTextBrowser("W");
    }
}

void keyboard::on_e_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㄷ");
    }
    else
    {
        appendToTextBrowser("E");
    }
}

void keyboard::on_r_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㄹ");
    }
    else
    {
        appendToTextBrowser("R");
    }
}

void keyboard::on_t_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅁ");
    }
    else
    {
        appendToTextBrowser("T");
    }
}

void keyboard::on_y_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅠ");
    }
    else
    {
        appendToTextBrowser("Y");
    }
}

void keyboard::on_u_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅜ");
    }
    else
    {
        appendToTextBrowser("U");
    }
}

void keyboard::on_i_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅡ");
    }
    else
    {
        appendToTextBrowser("I");
    }
}

void keyboard::on_o_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅗ");
    }
    else
    {
        appendToTextBrowser("O");
    }
}

void keyboard::on_p_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅓ");
    }
    else
    {
        appendToTextBrowser("P");
    }
}

void keyboard::on_a_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅁ");
    }
    else
    {
        appendToTextBrowser("A");
    }
}

void keyboard::on_s_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㄴ");
    }
    else
    {
        appendToTextBrowser("S");
    }
}

void keyboard::on_d_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅇ");
    }
    else
    {
        appendToTextBrowser("D");
    }
}

void keyboard::on_f_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅈ");
    }
    else
    {
        appendToTextBrowser("F");
    }
}

void keyboard::on_g_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅊ");
    }
    else
    {
        appendToTextBrowser("G");
    }
}

void keyboard::on_h_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅋ");
    }
    else
    {
        appendToTextBrowser("H");
    }
}

void keyboard::on_j_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅌ");
    }
    else
    {
        appendToTextBrowser("J");
    }
}

void keyboard::on_k_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅍ");
    }
    else
    {
        appendToTextBrowser("K");
    }
}

void keyboard::on_l_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅎ");
    }
    else
    {
        appendToTextBrowser("L");
    }
}

void keyboard::on_m_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅁ");
    }
    else
    {
        appendToTextBrowser("M");
    }
}

void keyboard::on_n_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㄴ");
    }
    else
    {
        appendToTextBrowser("N");
    }
}

void keyboard::on_b_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅂ");
    }
    else
    {
        appendToTextBrowser("B");
    }
}

void keyboard::on_v_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅅ");
    }
    else
    {
        appendToTextBrowser("V");
    }
}

void keyboard::on_c_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㅈ");
    }
    else
    {
        appendToTextBrowser("C");
    }
}

void keyboard::on_x_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㄷ");
    }
    else
    {
        appendToTextBrowser("X");
    }
}

void keyboard::on_z_clicked()
{
    if (isKoreanMode)
    {
        appendToTextBrowser("ㄱ");
    }
    else
    {
        appendToTextBrowser("Z");
    }
}

void keyboard::on_space_clicked()
{
    appendToTextBrowser(" ");
}

void keyboard::on_backspace_clicked()
{
    QString currentText = ui->textBrowser->toPlainText();
    currentText.chop(1); // 마지막 문자 삭제
    ui->textBrowser->setText(currentText);
}

void keyboard::on_clear_clicked()
{
    ui->textBrowser->clear(); // 텍스트 브라우저 내용 지우기
}

void keyboard::on_rightalt_clicked()
{
    isKoreanMode = !isKoreanMode; // 한/영 전환
    QString modeText = isKoreanMode ? "한글 모드 활성화" : "영문 모드 활성화";
}

void keyboard::on_capslock_clicked()
{
    isCapsLockOn = !isCapsLockOn; // Caps Lock 토글
    QString modeText = isCapsLockOn ? "Caps Lock 활성화" : "Caps Lock 비활성화";
}

void keyboard::on_leftshift_clicked()
{
    isShiftPressed = true;
}

void keyboard::on_rightshift_clicked()
{
    isShiftPressed = true;
}

void keyboard::releaseShift()
{
    isShiftPressed = false;
}

void keyboard::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Shift)
    {
        releaseShift();
    }
}

void keyboard::on_enter_clicked()
{
    appendToTextBrowser("\n");
}

void keyboard::on_comma_clicked()
{
    appendToTextBrowser(",");
}

void keyboard::on_period_clicked()
{
    appendToTextBrowser(".");
}

void keyboard::on_slash_clicked()
{
    appendToTextBrowser("/");
}

void keyboard::on_plus_clicked()
{
    appendToTextBrowser("+");
}

void keyboard::on_bar_clicked()
{
    appendToTextBrowser("|");
}

void keyboard::on_apostrophe_clicked()
{
    appendToTextBrowser("'");
}

void keyboard::on_tab_clicked()
{
    appendToTextBrowser("    "); // 탭은 4칸 공백
}

void keyboard::on_leftbraket_clicked()
{
    appendToTextBrowser("[");
}

void keyboard::on_rightbraket_clicked()
{
    appendToTextBrowser("]");
}

void keyboard::on_colon_clicked()
{
    appendToTextBrowser(":");
}

void keyboard::on_quotationmark_clicked()
{
    appendToTextBrowser("\"");
}

void keyboard::on_copy_clicked()
{
    QString text = ui->textBrowser->toPlainText();
    QApplication::clipboard()->setText(text); // 클립보드에 텍스트 복사
}

void keyboard::on_leftctrl_clicked() {}
void keyboard::on_fn_clicked() {}
void keyboard::on_win_clicked() {}
void keyboard::on_leftalt_clicked() {}
void keyboard::on_rightctrl_clicked() {}

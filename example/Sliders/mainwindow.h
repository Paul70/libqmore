#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QWidget;
namespace QtWidgets {
    class FloatSlider;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

    void onButtonLeftSliderOneClicked();
    void onButtonRightSliderOneClicked();
    void onButtonLeftSliderTwoClicked();
    void onButtonRightSliderTwoClicked();
    void onButtonLeftSliderThreeClicked();
    void onButtonRightSliderThreeClicked();

private:
    void createWidgets();

    QWidget * pCentralWidget_;

    QtWidgets::FloatSlider * pSliderDecPointOne_;
    QtWidgets::FloatSlider * pSliderDecPointTwo_;
    QtWidgets::FloatSlider * pSliderDecPointThree_;

    QLabel * pValueLabelSliderOne_;
    QLabel * pValueLabelSliderTwo_;
    QLabel * pValueLabelSliderThree_;

};
#endif // MAINWINDOW_H

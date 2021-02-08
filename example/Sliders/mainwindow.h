#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QWidget;
class QSlider;
namespace QtWidgets {
    class FloatSlider;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

    void setNewValueSliderOne(const double);
    void setNewValueSliderTwo(const double);
    void setNewValueSliderThree(const double);

    void onButtonLeftSliderOneClicked();
    void onButtonRightSliderOneClicked();
    void onButtonLeftSliderTwoClicked();
    void onButtonRightSliderTwoClicked();
    void onButtonLeftSliderThreeClicked();
    void onButtonRightSliderThreeClicked();

private:
    void setTextLabelSliderOne(const double);
    void setTextLabelSliderTwo(const double);
    void setTextLabelSliderThree(const double);

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

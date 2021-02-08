#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QWidget;
class QLabel;
namespace QtWidgets {
    class LedIndicator;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow() = default;

public slots:
    void changeState();
    void increaseLedRadius();

private:
    void createCentralWidget();


    QWidget * pCentralWidget_;
    QLabel  * pLedStateLabel_;

    QtWidgets::LedIndicator * pLed_;
};
#endif // MAINWINDOW_H

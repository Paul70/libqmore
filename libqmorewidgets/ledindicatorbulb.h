#ifndef LEDINDICATORBULB_H
#define LEDINDICATORBULB_H

#include <QWidget>


enum class LedState : std::uint8_t {
    eNotActive = 0, // grey
    eReady = 1,     // blue
    eSuccess = 2,   // green
    eError = 4,     // red
    eBussy = 8      // orange
};




class LedIndicatorBulb : public QWidget
{

    Q_OBJECT

public:
    explicit LedIndicatorBulb(QWidget *parent = nullptr);

    ~LedIndicatorBulb() override;


    void setLedSize(int size);
    void setCustomColor(const QColor color);

    LedState getState() const;


public slots:
    void setState(const LedState state);


protected:
    virtual void paintEvent(QPaintEvent *) override;


private:
    // Led colors
    QColor color_;

    // Led pattern style
    Qt::BrushStyle ledPattern_;

    // Led state
    LedState state_;

    int ledSize_;
};

#endif // LEDINDICATORBULB_H

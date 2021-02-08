#ifndef LEDINDICATOR_H
#define LEDINDICATOR_H

#include <map>
#include <QWidget>

namespace QtWidgets{

/*! \brief A LED indicator widget for displaying the following states:
 *  - state not active
 *  - state ready
 *  - state success
 *  - state error
 *  - state bussy
 *  - state blinking
 *  - state other (placeholder for a user defined state)
 *
 * LedIndicator calss inherits from QWidget class
 *
 * See the example "LedLights" in the example directory demonstrating the basic usage of this class
 * and the README file
 *
 *
 * For more information also see the QWidget web page:
 * https://doc.qt.io/qt-5/qwidget.html#palette-prop
 *
 */

class LedIndicator : public QWidget
{
    Q_OBJECT

public:
    enum class LedState : std::uint8_t {
        eNotActive    = 0,        // default color: grey
        eReady        = 1,        // default color: blue
        eSuccess      = 2,        // default color: green
        eError        = 3,        // default color: red
        eBussy        = 4,        // default color: yellow
        eBlinking     = 5,        // default color: blinking bussy/not active
        eOther        = 6,        // default color: white
    };


    //!
    //! \brief Constructor - there are six consructors available
    //!
    explicit LedIndicator(QWidget *parent = nullptr);
    explicit LedIndicator(const int size, QWidget *parent = nullptr);
    explicit LedIndicator(LedState ledState, QWidget *parent = nullptr);
    explicit LedIndicator(LedState ledState, QColor color, QWidget *parent = nullptr);
    explicit LedIndicator(const int size, LedState ledState, QWidget *parent = nullptr);
    explicit LedIndicator(const int size, LedState ledState, QColor color, QWidget *parent = nullptr);

    ~LedIndicator() = default;


    //! \brief setLedSize - set the size (diameter) of the led indicator
    //!
    void setLedSize(int size);

    //! \brief getLedSize - returns the size (diameter) of the led indicator
    //!
    int getLedSize() const;

    //! \brief setColor - set a user defined led color for the given state
    ///
    static void setColor(const LedState, const QColor color);

    //! \brief getCustomColor - return the led color
    ///
    static QColor const & getColor(const LedState);

    //! \brief getState - returns the current led indicator state
    ///
    LedIndicator::LedState const & getState() const;


public slots:
    //! \brief doRepaint - repaints the led widget
    ///
    void repaint();

    //! \brief setState - changes the widget's state
    ///
    void setState(const LedState state);


protected:
    virtual void paintEvent(QPaintEvent *) override;
    virtual void timerEvent(QTimerEvent *) override;


signals:
    void repaintWidget() const;



private:
    Q_DISABLE_COPY(LedIndicator)

    static std::map<LedState,QColor> sStateLightMap_;

    int            idTimer_;
    int            size_;
    LedState       state_;
    Qt::BrushStyle pattern_;


}; // class LedIndicator


inline int LedIndicator::getLedSize() const
{
    return size_;
}


inline LedIndicator::LedState const & LedIndicator::getState() const
{
    return state_;
}


inline void LedIndicator::repaint()
{
    QWidget::repaint();
}


}  // namespace QtWidgets
#endif // LEDINDICATOR_H















#ifndef FLOATSLIDER_H
#define FLOATSLIDER_H

/*!
 *   \author:   Paul Heidenreich
 *   \email:    paul-heidenreich@web.de
 *   \github:   https://github.com/Paul70
 */


#include <QSlider>


namespace QtWidgets {

/*! \brief A slider widget for displaying floating point values.
 *
 * FloatSlider calss inherits from QSlider class and shuold be used exactly like the latter
 *
 * The number of decimal places is at the moment limited to three and a basic design feature, i.e the
 * decimal precision is set with the constructor and cannot be changed.
 *
 * Note: The FloatSlider class shall possess the main funtionality as the QSlider class, only for floating point values.
 *       Therefore its interface is very similar to the one of QSlider class. Often, the class functions share the same names
 *       and differ only in their signatures. For example, the QSlider method "setValue" has the signature: <void>(int)
 *       whereas FloarSlider's "setValue"  has <void>(const double).
 *
 * For more information see the Qt QSilder and QAbstractSlider web page:
 * https://doc.qt.io/qt-5/qslider.html#details
 *
 *
 */

 // still to come: Notiz bezgl. der int functions


QT_REQUIRE_CONFIG(slider);

class FloatSlider : public QSlider
{

    Q_OBJECT

public:
    enum class SliderAccuracy : std::uint16_t {
        eDecPlaceOne   = 10,
        eDecPlaceTwo   = 100,
        eDecPlaceThree = 1000
    };


    //!
    //! \brief Constructor
    //!
    explicit FloatSlider(QWidget *parent = nullptr);
    explicit FloatSlider(const SliderAccuracy, QWidget * parent = nullptr);
    explicit FloatSlider(const SliderAccuracy, const Qt::Orientation, QWidget  * parent = nullptr);


    ~FloatSlider();


    //! \brief accuracy - query the slider's deciaml accuracy
    //! \return enum class SliderAccuracy
    //!
    SliderAccuracy accuracy() const;


    //! \brief setMaximum - set the slider's maximal value
    //!
    void setMaximum(const double max);

    //! \brief setMinimum - set the slider's minimal value
    //!
    void setMinimum(const double min);

    //! \brief maximum - return the slider's current maximal value
    //!
    double maximum() const;

    //! \brief minimum - return the slider's current minimal value
    //!
    double minimum() const;


    //! \brief setValue - sets the slider's value to the given input value
    //!
    void setValue(const double value);

    //! \brief value - returns the slider's current value
    //!
    double value() const;


private slots:
    void rescale(const int value);


signals:
    void valueChanged(const double value);
    void rangeChanged(const double min, const double max);
    void sliderMoved(const double value);


    // still to come:
    // test signals with qSpySignal


private:
    Q_DISABLE_COPY(FloatSlider)

    double scaling() const;

    static constexpr double ADD_ {0.00001};
    const SliderAccuracy accuracy_;

}; // class FloatSlider
}  // namespace QtWidget

#endif // FLOATSLIDER_H

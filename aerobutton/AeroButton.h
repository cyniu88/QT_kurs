#ifndef AERO_BUTTON
#define AERO_BUTTON


#include <QPushButton>


class AeroButton : public QPushButton
{
	Q_OBJECT

public:
	AeroButton(QWidget * parent = 0);
	AeroButton(const QString & text, QWidget * parent = 0);
	AeroButton(const QIcon & icon, const QString & text, QWidget * parent = 0);

	//~AeroButton();

	void setColor(const QColor &color)         { m_color = color; }
	void setHighlight(const QColor &highlight) { m_highlight = highlight; }
	void setShadow(const QColor &shadow)       { m_shadow = shadow; }

public slots:
	//Range: 0.0 [invisible] - 1.0 [opaque]
	void setOpacity(double opacity)        { m_opacity = opacity; update();}

	//Range: 0 [rectangle] - 99 [oval]
	void setRoundness(int roundness)      { m_roundness = roundness; update(); }

protected:
	void paintEvent(QPaintEvent * pe);

	void enterEvent(QEvent * e);
	void leaveEvent(QEvent * e);

	void mousePressEvent(QMouseEvent * e);
	void mouseReleaseEvent(QMouseEvent * e);

private:
	QRect calculateIconPosition(QRect button_rect, QSize icon_size);
/**/
private:
	bool m_hovered;
	bool m_pressed;

	QColor m_color;
	QColor m_highlight;
	QColor m_shadow;

	double m_opacity;

	int m_roundness;
};

#endif // AERO_BUTTON

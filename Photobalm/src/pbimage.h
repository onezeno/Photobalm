#ifndef PBIMAGE_H
#define PBIMAGE_H

#include <QColor>
#include <QPainter>
#include <QQuickPaintedItem>
#include <QImage>

#include <QDebug>


class PBImage : public QQuickPaintedItem
{
  Q_OBJECT

public:
  PBImage();
  ~PBImage();

  virtual void paint(QPainter *painter);
  Q_INVOKABLE void setImage(QString url);
  Q_INVOKABLE void highlight(int x, int y, int width, int height);

  void setPixel(int x, int y, QColor color);

  int GetWidth() const;
  int GetHeight() const;

private:
  QImage m_image;

  void highlightArea(int x, int y, int r);

};

#endif // PBIMAGE_H

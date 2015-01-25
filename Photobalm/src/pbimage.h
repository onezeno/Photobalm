#ifndef PBIMAGE_H
#define PBIMAGE_H

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

  virtual void paint(QPainter *painter)
  {
    qDebug() << "paint";
    painter->drawImage(painter->window(), m_image);
  }

  Q_INVOKABLE void setImage(QString url)
  {
    qDebug() << url;
    m_image.load(url);
  }

private:
  QImage m_image;
};

#endif // PBIMAGE_H

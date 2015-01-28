#include "pbimage.h"


PBImage::PBImage() { ; }


PBImage::~PBImage() { ; }


void PBImage::paint(QPainter *painter) { painter->drawImage(painter->window(), m_image); }


void PBImage::setImage(QString url)
{
  // log

  qDebug() << "loading url " << url;

  // NOTE: THE STRING BELOW WAS TRIMMED TO 7 WITH LINUX?
  QString trimmed_string = url.right( url.size() - 8);
  bool loaded = m_image.load(trimmed_string);

  if (loaded)
  {
      qDebug() << "image loaded " << trimmed_string;
  }
  else
  {
      qDebug() << "image not loaded " << trimmed_string;
  }
}


void PBImage::highlight(int x, int y, int width, int height)
{
  // transform the input pixel from the container coordinates to the image coordinates
  float x_f = static_cast<float>(m_image.width()) / static_cast<float>(width);
  float scaled_x_f = x_f * static_cast<float>(x);
  int scaled_x = static_cast<int>(scaled_x_f); // NOTE: always rounds down

  float y_f = static_cast<float>(m_image.height()) / static_cast<float>(height);
  float scaled_y_f = y_f * static_cast<float>(y);
  int scaled_y = static_cast<int>(scaled_y_f);

  highlightArea(scaled_x, scaled_y, 5);
  update();
}


void PBImage::highlightArea(int x, int y, int r)
{
  for (int i= x-r; i<= x+r; ++i )
  {
    // check bounds
    if (i<0 || i>= m_image.width()) { continue; }

    for (int j=y-r; j<=y+r; ++j)
    {
      // check bounds
      if (j<0 || j>= m_image.height()) { continue; }

      QColor black(0, 0, 0);
      m_image.setPixel(i, j, black.rgb());
    }
  }
}




void PBImage::setPixel(int x, int y, QColor color)
{
    m_image.setPixel(x, y, color.rgb());
}


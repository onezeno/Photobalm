#include "pbimage.h"


PBImage::PBImage() { ; }


PBImage::~PBImage() { ; }


void PBImage::paint(QPainter *painter) { painter->drawImage(painter->window(), m_image); }


void PBImage::setImage(QString url)
{
  // log
  QString trimmed_string = url.right( url.size() - 7);
  bool loaded = m_image.load(trimmed_string);
}


void PBImage::highlight(int x, int y)
{
  highlightArea(x, y, 5);
  update();
}


void PBImage::highlightArea(int x, int y, int r)
{
  for (int i= x-r; i<= x+r; ++i )
  {
    // check bounds
    if (i<0 or i>= m_image.width()) { continue; }

    for (int j=y-r; j<=y+r; ++j)
    {
      // check bounds
      if (j<0 or j>= m_image.height()) { continue; }

      QColor black(0, 0, 0);
      m_image.setPixel(i, j, black.rgb());
    }
  }
}


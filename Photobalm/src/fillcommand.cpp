#include "fillcommand.h"
#include <QDebug>



namespace photobalm {




FillCommand::FillCommand(ImageProvider& image_provider, const SelectionList& selection_list, QColor color)
: Command(image_provider, selection_list)
, color(color)
{
    qDebug() << "FillCommand::FillCommand";
}




FillCommand::~FillCommand()
{
    qDebug() << "FillCommand::~FillCommand";
}




void FillCommand::execute()
{
    qDebug() << "FillCommand::execute";

    PBImage* image_ptr = GetImageProvider().GetImage();

    if (!image_ptr)
    {
        return;
    }

    SelectionList& selection_list = GetSelectionList();
    for( SelectionList::iterator selection_it = selection_list.begin();
         selection_it != selection_list.end();
         selection_it++)
    {
        qDebug() << "FillCommand::execute in selection list";

        SelectionSharedPtr selection_ptr = *selection_it;

        for(ImageIterator image_it = selection_ptr->Begin(*image_ptr);
            image_it != selection_ptr->End();
            ++image_it)
        {
            qDebug() << "FillCommand::execute setting pixel";

            Point2D& point = *image_it;
            image_ptr->setPixel(point.x, point.y, color.rgb());
        }
    }

    image_ptr->update();


//    for (int i = x - radius; i <= x + radius; ++i )
//    {
//      // check bounds
//      if (i<0 || i>= m_image.width()) { continue; }
//
//      for (int j=y - radius; j <= y + radius; ++j)
//      {
//        // check bounds
//        if (j<0 || j>= m_image.height()) { continue; }
//
//        QColor black(0, 0, 0);
//        m_image.setPixel(i, j, black.rgb());
//      }
//    }
}




void FillCommand::undo()
{

}




} // namespace photobalm

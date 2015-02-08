#ifndef FILLCOMMAND_H
#define FILLCOMMAND_H


#include "command.h"
#include "imagepoint2d.h"
#include "rect2diterator.h"
#include "selectionsharedptr.h"
#include <QColor>


namespace photobalm {



template <typename ImageType, typename SelectionType>
class FillCommand
: public Command<ImageType, SelectionType>
{
public:
    FillCommand( ImageType&
               , const typename Command<ImageType, SelectionType>::SelectionList&
               , QColor);

    virtual ~FillCommand();

    virtual void operator()();

public:
    FillCommand();

private:
    QColor color;
};




template <class ImageType, class SelectionType>
FillCommand<ImageType, SelectionType>::FillCommand( ImageType& image
                                                  , const typename Command<ImageType, SelectionType>::SelectionList& selection_list
                                                  , QColor color)
: Command<ImageType, SelectionType>(image, selection_list)
, color(color)
{
    qDebug() << "FillCommand::FillCommand";
}




template <typename ImageType, typename SelectionType>
FillCommand<ImageType, SelectionType>::~FillCommand()
{
    qDebug() << "FillCommand::~FillCommand";
}




template <class ImageType, class SelectionType>
void FillCommand<ImageType, SelectionType>::operator()()
{
    qDebug() << "FillCommand::execute";

    ImageType& image = Command<ImageType, SelectionType>::GetImage();

    auto selection_list = Command<ImageType, SelectionType>::GetSelectionList();
    for( auto selection_it = selection_list.begin();
         selection_it != selection_list.end();
         selection_it++)
    {
        qDebug() << "FillCommand::execute in selection list";

        auto selection_ptr = *selection_it;


        int i = 0;
        for(typename SelectionType::Iterator image_it = selection_ptr->Begin();
            image_it != selection_ptr->End();
            ++image_it)
        {

            const ImagePoint2d& point = image_it.AtImagePoint2d();

            qDebug() << "FillCommand::execute setting pixel " << point.x << ", " << point.y;


            image.setPixel(point.x, point.y, color.rgb());

            i++;
            if (i > 100)
            {
                break;
            }
        }
    }

    image.update();
}




} // namespace photobalm


#endif // FILLCOMMAND_H

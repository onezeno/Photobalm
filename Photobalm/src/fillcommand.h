#ifndef FILLCOMMAND_H
#define FILLCOMMAND_H


#include "command.h"
#include "imagepoint2d.h"
#include "selectionsharedptr.h"
#include <QColor>


namespace photobalm {



template <typename ImageType, typename SelectionType>
class FillCommand
: public Command<ImageType, SelectionType>
{
public:
    FillCommand( Image&
               , const SelectionList&
               , QColor);

    virtual ~FillCommand();

    virtual void operator()();

public:
    FillCommand();

private:
    QColor color;
};




template <typename ImageType, typename SelectionType>
FillCommand<ImageType, SelectionType>::FillCommand( ImageType& image
                                                  , const SelectionList& selection_list
                                                  , QColor color)
: Command(image, selection_list)
, color(color)
{
    qDebug() << "FillCommand::FillCommand";
}




template <typename ImageType, typename SelectionType>
FillCommand<ImageType, SelectionType>::~FillCommand()
{
    qDebug() << "FillCommand::~FillCommand";
}




template <typename ImageType, typename SelectionType>
void FillCommand<ImageType, SelectionType>::operator()()
{
    qDebug() << "FillCommand::execute";

    ImageType& image = GetImage();

    SelectionList& selection_list = GetSelectionList();
    for( SelectionList::iterator selection_it = selection_list.begin();
         selection_it != selection_list.end();
         selection_it++)
    {
        qDebug() << "FillCommand::execute in selection list";

        SelectionSharedPtr selection_ptr = *selection_it;


        int i = 0;
        for(typename SelectionType::Iterator image_it = selection_ptr->Begin();
            image_it != selection_ptr->End();
            ++image_it)
        {

            ImagePoint2d& point = image_it.AtImagePoint2d();

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

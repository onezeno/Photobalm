#ifndef FILLCOMMAND_H
#define FILLCOMMAND_H


#include "command.h"
#include <QColor>


namespace photobalm {




class FillCommand : public Command
{
public:
    FillCommand( ImageProvider&
               , const SelectionList&
               , QColor);

    virtual ~FillCommand();

    virtual void execute();

    virtual void undo();

private:
    QColor color;
};




} // namespace photobalm


#endif // FILLCOMMAND_H

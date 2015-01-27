#ifndef SELECTIONLIST_H
#define SELECTIONLIST_H


#include "selection.h"
#include <list>
#include <memory>


namespace photobalm {




typedef std::list< std::shared_ptr<Selection> > SelectionList;




} // namespace photobalm


#endif // SELECTIONLIST_H


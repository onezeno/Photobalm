#include "selection.h"


namespace photobalm {




Selection::Selection()
{

}

Selection::~Selection()
{

}


ImageIterator Selection::End()
{
    return ImageIterator(0);
}



} // namespace photobalm

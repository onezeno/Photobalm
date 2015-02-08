#include "selectorprovider.h"




namespace photobalm {




SelectorProvider::SelectorProvider()
{

}




SelectorProvider::~SelectorProvider()
{

}




SelectorInterface* SelectorProvider::GetSelector()
{
    return this->selector;
}




void SelectorProvider::SetSelector(SelectorInterface* selector)
{
    this->selector = selector;
}




} // namespace photobalm

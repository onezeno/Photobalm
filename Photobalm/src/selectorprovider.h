#ifndef SELECTORPROVIDER_H
#define SELECTORPROVIDER_H


#include "selectorinterface.h"


namespace photobalm {




class SelectorProvider
{
public:
    SelectorProvider();
    ~SelectorProvider();


    SelectorInterface* GetSelector();
    void SetSelector(SelectorInterface*);


private:
    SelectorInterface* selector;
};




} // namespace photobalm


#endif // SELECTORPROVIDER_H



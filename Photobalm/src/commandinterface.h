#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H


namespace photobalm {




class CommandInterface
{
public:
    virtual ~CommandInterface();

    virtual void operator()() = 0;
};




} // namespace photobalm


#endif // COMMANDINTERFACE_H

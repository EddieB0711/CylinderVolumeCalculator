#ifndef IREADER_H
#define IREADER_H

class IModel;

class IReader
{
public:
    inline void Read(IModel& Other) const { DoRead(Other); }
    virtual ~IReader() {}
    
private:
    virtual void DoRead(IModel& Other) const = 0;
};

#endif // IREADER_H

#ifndef IVIEW_H
#define IVIEW_H

class IView
{
public:
    virtual void Render() = 0;
    virtual void Show() = 0;
    virtual ~IView() {}
};

#endif // IVIEW_H

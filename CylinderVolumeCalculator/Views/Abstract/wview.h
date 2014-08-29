#ifndef WVIEW_H
#define WVIEW_H

#include <memory>

class IView;

typedef std::weak_ptr<IView> WView;

#endif // WVIEW_H

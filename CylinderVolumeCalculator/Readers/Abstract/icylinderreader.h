#ifndef ICYLINDERREADER_H
#define ICYLINDERREADER_H
#include "ireader.h"

/* This may be overkill, but I kind of like it because
 * CCylinderReader is the only class that needs the
 * GetKeyIndex function. CCylinderViewerReader only needs
 * to implement the Read function.
 */

class ICylinderReader : public IReader
{
public:
    inline int GetKeyIndex() const { return DoGetKeyIndex(); }

private:
    virtual int DoGetKeyIndex() const = 0;
};

#endif // ICYLINDERREADER_H

#ifndef CYX_EVENT_H
#define CYX_EVENT_H
#include <QEvent>

class Cyx_Event:public QEvent{
public:
    Cyx_Event(Type type);

public:
    static const QEvent::Type Cyx_Event_Type;
};


#endif // CYX_EVENT_H

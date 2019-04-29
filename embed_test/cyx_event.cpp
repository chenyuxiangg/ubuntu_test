#include "cyx_event.h"
#include <QDebug>
const QEvent::Type Cyx_Event::Cyx_Event_Type = (QEvent::Type)QEvent::registerEventType(QEvent::User+1);
Cyx_Event::Cyx_Event(QEvent::Type type):QEvent(type)
{

}

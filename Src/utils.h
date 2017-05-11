#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QMetaType>

class CardType
{
public:
 QString name;
 int width;
 int height;

 CardType(QString n,int w,int h)
 {
     //TODO use initializers instead
     name = n;
     width = w;
     height = h;
 }
};

Q_DECLARE_METATYPE(CardType *)

#endif // UTILS_H

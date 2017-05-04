#ifndef UTILS_H
#define UTILS_H



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
#endif // UTILS_H

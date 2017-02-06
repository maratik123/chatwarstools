#include "commonstringholder.h"

CommonStringHolder::CommonStringHolder() :
    stash({
            { StringID::ATTACK, QT_TR_NOOP("Attack %1") },
            { StringID::DEFENCE, QT_TR_NOOP("Defence %1") },
            { StringID::HEAD, QT_TR_NOOP("head") },
            { StringID::CHEST, QT_TR_NOOP("chest") },
            { StringID::LEGS, QT_TR_NOOP("legs") }
          })
{}

const CommonStringHolder& CommonStringHolder::getInstance()
{
    static CommonStringHolder instance;
    return instance;
}

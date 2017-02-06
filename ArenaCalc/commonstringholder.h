#ifndef COMMONSTRINGHOLDER_H
#define COMMONSTRINGHOLDER_H

#include <QCoreApplication>
#include <unordered_map>
#include "enumclassutil.h"

enum class StringID
{
    UNKNOWN, ATTACK, DEFENCE, HEAD, CHEST, LEGS
};

class CommonStringHolder
{
    Q_DECLARE_TR_FUNCTIONS(CommonStringHolder)

public:
    static const CommonStringHolder& getInstance();

    CommonStringHolder(const CommonStringHolder&) = delete;
    void operator=(const CommonStringHolder&) = delete;

    QString get(StringID stringId) const { return tr(stash.at(stringId)); }

private:
    CommonStringHolder();
    std::unordered_map<StringID, const char*, EnumClassHash> stash;
};

inline QString commonStringHolder(StringID stringId) {
    return CommonStringHolder::getInstance().get(stringId);
}

#endif // COMMONSTRINGHOLDER_H

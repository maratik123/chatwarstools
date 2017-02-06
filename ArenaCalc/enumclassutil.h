#ifndef ENUMCLASSUTIL_H
#define ENUMCLASSUTIL_H

#include <cstddef>

template <typename T>
inline constexpr std::size_t enumToId(T t)
{
    return static_cast<std::size_t>(t);
}

template <typename T>
inline constexpr T idToEnum(std::size_t id)
{
    return static_cast<T>(id);
}

struct EnumClassHash {
    template <typename T>
    constexpr std::size_t operator()(T t) const { return enumToId(t); }
};

#endif // ENUMCLASSUTIL_H

#ifndef ENUMCLASSUTIL_H
#define ENUMCLASSUTIL_H

#include <cstddef>

template <typename T>
inline constexpr std::size_t enumToIndex(T t)
{
    return static_cast<std::size_t>(t);
}

template <typename T>
inline constexpr int enumToId(T t)
{
    return static_cast<int>(t);
}

template <typename T>
inline constexpr T idToEnum(int id)
{
    return static_cast<T>(id);
}

template <typename T1, typename T2>
inline constexpr T1 enumToEnum(T2 t)
{
    return static_cast<T1>(t);
}

struct EnumClassHash {
    template <typename T>
    constexpr std::size_t operator()(T t) const { return static_cast<std::size_t>(t); }
};

#endif // ENUMCLASSUTIL_H

#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <list>
#include <utility>
#include <type_traits>

// Helper to print pair
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

// Helper to print linear containers (vector, deque, list)
template <typename T, template <typename, typename> class Container>
std::ostream &operator<<(std::ostream &os, const Container<T, std::allocator<T>> &container)
{
    os << "[";
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        if (it != container.begin())
            os << ", ";
        os << *it;
    }
    os << "]";
    return os;
}

// Helper to print set and unordered_set
template <typename T, template <typename, typename, typename> class Set>
std::ostream &operator<<(std::ostream &os, const Set<T, std::less<T>, std::allocator<T>> &set)
{
    os << "{";
    for (auto it = set.begin(); it != set.end(); ++it)
    {
        if (it != set.begin())
            os << ", ";
        os << *it;
    }
    os << "}";
    return os;
}

// Helper to print map and unordered_map
template <typename K, typename V, template <typename, typename, typename, typename> class Map>
std::ostream &operator<<(std::ostream &os, const Map<K, V, std::less<K>, std::allocator<std::pair<const K, V>>> &map)
{
    os << "{";
    for (auto it = map.begin(); it != map.end(); ++it)
    {
        if (it != map.begin())
            os << ", ";
        os << it->first << ": " << it->second;
    }
    os << "}";
    return os;
}

// Helper to print nested containers
template <typename T>
std::enable_if_t<!std::is_same_v<T, std::string> && !std::is_arithmetic_v<T>, std::ostream &>
print_element(std::ostream &os, const T &element)
{
    os << element;
}

template <typename T>
std::enable_if_t<std::is_arithmetic_v<T>, std::ostream &>
print_element(std::ostream &os, const T &element)
{
    os << element;
}

// Overload for nested containers
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &nested)
{
    os << "[";
    for (auto it = nested.begin(); it != nested.end(); ++it)
    {
        if (it != nested.begin())
            os << ", ";
        os << *it;
    }
    os << "]";
    return os;
}

// Overload for nested maps
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::map<std::pair<int, int>, std::vector<int>> &nested)
{
    os << "{";
    for (auto it = nested.begin(); it != nested.end(); ++it)
    {
        if (it != nested.begin())
            os << ", ";
        os << "(" << it->first.first << ", " << it->first.second << "): " << it->second;
    }
    os << "}";
    return os;
}

// Debug function to print multiple variables
template <typename T>
void debug(const T &value)
{
    std::cout << value << std::endl;
}

template <typename T, typename... Args>
void debug(const T &first, const Args &...rest)
{
    std::cout << first << " ";
    debug(rest...);
}

#endif // DEBUG_UTILS_H
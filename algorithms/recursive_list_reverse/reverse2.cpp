// 2017 Daniel Varga (vargad88@gmail.com)

#include <iostream>
#include <memory>
#include <iterator>

template <typename T>
struct LinkedList
{
    using NodePtr = std::unique_ptr<LinkedList<T>>;

    LinkedList(T data, NodePtr &&next=nullptr)
        : data(data)
        , next(std::move(next))
    {}

    T data;
    NodePtr next;
};

template <typename T>
typename LinkedList<T>::NodePtr make_link(T data, typename LinkedList<T>::NodePtr &&rest)
{
    return std::move(std::make_unique<LinkedList<T>>(data, std::move(rest)));
}


template <typename T>
std::ostream& operator<<(std::ostream &os, const std::unique_ptr<LinkedList<T>> &list)
{
    os << list->data;
    if (list->next)
    {
        os << ", ";
        os << list->next;
    }
    return os;
}

template <class T>
typename LinkedList<T>::NodePtr make_list(const std::initializer_list<T> &init_list)
{
    typename LinkedList<T>::NodePtr list = nullptr;
    for (auto it = std::rbegin(init_list); it != std::rend(init_list); ++it)
        list = std::make_unique<LinkedList<T>>(*it, std::move(list));
    return std::move(list);
}

template <class ListType>
ListType reverse(ListType &&current)
{
    if (current->next == nullptr) return std::move(current);
    // It's safe to store a pointer as no elements will be freed during reverse
    // pointers will stay valid.
    typename ListType::pointer last = current->next.get();
    // Detach first element reverse the rest of the list
    auto reversed = reverse(std::move(current->next));
    // Move current element to the end
    last->next = std::move(current);
    return reversed;
}

template <class ListType>
ListType reverse2(const ListType &list, ListType &&rest = nullptr)
{
    if (list == nullptr)
        return std::move(rest);
    //return reverse2(list->next, std::make_unique<typename ListType::element_type>(list->data, std::move(rest)));
    return reverse2(list->next, make_link(list->data, std::move(rest)));
}

int main()
{
    auto list = make_list({ 42, 43, 44, 45, 46, 47 });
    std::cout << list << std::endl;
    list = reverse(std::move(list));
    std::cout << list << std::endl;
    auto list2 = reverse2(list);
    std::cout << list2 << std::endl;
    return 0;
}

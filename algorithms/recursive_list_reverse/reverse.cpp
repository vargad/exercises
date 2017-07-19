// 2017 Daniel Varga (vargad88@gmail.com)

#include <iostream>
#include <memory>
#include <iterator>

struct LinkedList
{
    using NodePtr = std::unique_ptr<LinkedList>;

    LinkedList(int data, NodePtr &&next=nullptr)
        : data(data)
        , next(std::move(next))
    {}

    int data;
    NodePtr next;
};

std::ostream& operator<<(std::ostream &os, const std::unique_ptr<LinkedList> &list)
{
    os << list->data;
    if (list->next)
        os << ", " << list->next;
    return os;
}

LinkedList::NodePtr make_list(const std::initializer_list<int> &init_list)
{
    LinkedList::NodePtr list = nullptr;
    for (auto it = std::rbegin(init_list); it != std::rend(init_list); ++it)
        list = std::make_unique<LinkedList>(*it, std::move(list));
    return std::move(list);
}

LinkedList::NodePtr reverse(const LinkedList::NodePtr &list, LinkedList::NodePtr &&rest = nullptr)
{
    if (list == nullptr)
        return std::move(rest);
    return reverse(list->next, std::make_unique<LinkedList>(list->data, std::move(rest)));
}

int main()
{
    auto list = make_list({ 42, 43, 44, 45, 46, 47 });
    std::cout << list << std::endl;
    auto list2 = reverse(std::move(list));
    std::cout << list2 << std::endl;
    return 0;
}

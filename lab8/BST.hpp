//Author: Chris Watkins
//Assignment: EECS268 lab8
//Description: Implementation of BST class
//Date: 4/6/17


template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST()
{
    m_root = nullptr;
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST(const BST<ItemType,KeyType>& other)
{
    if (other.isEmpty())
    {
        m_root = nullptr;
        return;
    }
    else
    {
        m_root = new Node<ItemType>(*(other.m_root));
    }
}
//
// template <typename ItemType, typename KeyType>
// BSTI<ItemType, KeyType>* BST<ItemType, KeyType>::clone()
// {
//     BSTI<ItemType, KeyType>*  temp =  new BST(*(this));
//     return temp;
// }
//
// template <typename ItemType, typename KeyType>
// ItemType BST<ItemType, KeyType>::addAll(Node<ItemType>* subTree)
// {
//     if (subTree == nullptr)
//     {
//         return 0;
//     }
//     return subTree->getValue() + addAll(subTree->getLeft()) + addAll(subTree->getRight());
// }
//
// template <typename ItemType, typename KeyType>
// ItemType BST<ItemType, KeyType>::addAll()
// {
//     return addAll(m_root);
// }

template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::add(ItemType value, Node<ItemType>* subTree)
{
    if (value < subTree->getValue() )
    {
        if (subTree->getLeft()==nullptr)
        {
            Node<ItemType>* temp = subTree->getLeft();
            temp = new Node<ItemType>();
            temp->setValue(value);
            subTree->setRight(temp);
            return true;
        }
        else
        {
            add(value, subTree->getLeft());
        }
    }
    else if (value > subTree->getValue() )
    {
        if (subTree->getRight()==nullptr)
        {
            Node<ItemType>* temp = subTree->getRight();
            temp = new Node<ItemType>();
            temp->setValue(value);
            subTree->setRight(temp);
            return true;
        }
        else
        {
            add(value, subTree->getRight());
        }
    }
    return false;
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::deleteTree(Node<ItemType>* subTree)
{
    if(subTree->getLeft() != nullptr)
    {
        deleteTree(subTree->getLeft());
    }
    if(subTree->getRight() != nullptr)
    {
        deleteTree(subTree->getRight());
    }
    delete subTree;
}
//
// template <typename ItemType, typename KeyType>
// T BST<ItemType>::search(T value, Node<ItemType> *subTree) const throw (ValueNotFoundException)
// {
//     if (subTree != nullptr)
//     {
//         if (value == subTree->getValue())
//         {
//             return value;
//         }
//         else if (value < subTree->getValue())
//         {
//             search(value, subTree->getLeft());
//         }
//         else
//         {
//             search(value, subTree->getRight());
//         }
//     }
//    else
//    {
//         throw (ValueNotFoundException("Value not found in tree"));
//    }
// }

// template <typename ItemType, typename KeyType>
// ItemType BST<ItemType>::search(ItemType value) const throw(ValueNotFoundException)
// {
//    return search(value, m_root);
// }

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::printTree(Node<ItemType>* subTree, Order order) const
{
    if (subTree == nullptr) return;
    switch (order)
    {
    case Order::PRE_ORDER:
            std::cout<<(subTree->getValue()).getUSname() <<" ";
            printTree(subTree->getLeft(), order);
            printTree(subTree->getRight(), order);
            break;
     case Order::IN_ORDER:
            printTree(subTree->getLeft(), order);
            std::cout<< (subTree->getValue()).getUSname()<<" ";
            printTree(subTree->getRight(), order);
            break;
     case Order::POST_ORDER:
            printTree(subTree->getLeft(), order);
            printTree(subTree->getRight(), order);
            std::cout<<(subTree->getValue()).getUSname()<<" ";
            break;
     }
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::~BST()
{
    //uses delete tree method
    BST<ItemType, KeyType>::deleteTree(m_root);
}

template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::isEmpty() const
{
    if (m_root == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::add(ItemType value)
{
    if(m_root == nullptr)
    {
        Node<ItemType>* temp = new Node<ItemType>();
        temp->setValue(value);
        m_root = temp;
        return true;
    }
    else
    {
        return add(value, m_root);
    }
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::printTree(Order order) const
{
    printTree(m_root, order);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::sortedPrint() const
{
    printTree(IN_ORDER);
}

template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::operator <(const Pokemon& p) const
{
  if((this->USname) < (p.USname))
    {
      return true;
    }
    else
    {
      return false;
    }
}

template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::operator >(const Pokemon& p) const
{
  if((this->USname) > (p.USname ))
    {
      return true;
    }
    else
    {
      return false;
    }
}

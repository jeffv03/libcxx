//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_multiset
// {
// public:
//     // types
//     typedef Value                                                      value_type;
//     typedef value_type                                                 key_type;
//     typedef Hash                                                       hasher;
//     typedef Pred                                                       key_equal;
//     typedef Alloc                                                      allocator_type;
//     typedef value_type&                                                reference;
//     typedef const value_type&                                          const_reference;
//     typedef typename allocator_traits<allocator_type>::pointer         pointer;
//     typedef typename allocator_traits<allocator_type>::const_pointer   const_pointer;
//     typedef typename allocator_traits<allocator_type>::size_type       size_type;
//     typedef typename allocator_traits<allocator_type>::difference_type difference_type;

#include <unordered_set>
#include <type_traits>

#include "../../min_allocator.h"

int main()
{
    {
        typedef std::unordered_multiset<short> C;
        static_assert((std::is_same<C::value_type, short>::value), "");
        static_assert((std::is_same<C::key_type, short>::value), "");
        static_assert((std::is_same<C::hasher, std::hash<C::key_type> >::value), "");
        static_assert((std::is_same<C::key_equal, std::equal_to<C::key_type> >::value), "");
        static_assert((std::is_same<C::allocator_type, std::allocator<C::value_type> >::value), "");
        static_assert((std::is_same<C::reference, C::value_type&>::value), "");
        static_assert((std::is_same<C::const_reference, const C::value_type&>::value), "");
        static_assert((std::is_same<C::pointer, C::value_type*>::value), "");
        static_assert((std::is_same<C::const_pointer, const C::value_type*>::value), "");
//        static_assert((std::is_same<C::size_type, std::size_t>::value), "");
        static_assert(sizeof(C::size_type) == sizeof(std::size_t), "");
        static_assert((std::is_same<C::difference_type, std::ptrdiff_t>::value), "");
    }
#if __cplusplus >= 201103L
    {
        typedef std::unordered_multiset<short, std::hash<short>,
                                  std::equal_to<short>, min_allocator<short>> C;
        static_assert((std::is_same<C::value_type, short>::value), "");
        static_assert((std::is_same<C::key_type, short>::value), "");
        static_assert((std::is_same<C::hasher, std::hash<C::key_type> >::value), "");
        static_assert((std::is_same<C::key_equal, std::equal_to<C::key_type> >::value), "");
        static_assert((std::is_same<C::allocator_type, min_allocator<C::value_type> >::value), "");
        static_assert((std::is_same<C::reference, C::value_type&>::value), "");
        static_assert((std::is_same<C::const_reference, const C::value_type&>::value), "");
        static_assert((std::is_same<C::pointer, min_pointer<C::value_type>>::value), "");
        static_assert((std::is_same<C::const_pointer, min_pointer<const C::value_type>>::value), "");
//        static_assert((std::is_same<C::size_type, std::size_t>::value), "");
        static_assert(sizeof(C::size_type) == sizeof(std::size_t), "");
        static_assert((std::is_same<C::difference_type, std::ptrdiff_t>::value), "");
    }
#endif
}

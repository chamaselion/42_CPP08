/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:42:17 by bszikora          #+#    #+#             */
/*   Updated: 2026/02/17 16:23:09 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <set>

int main() {
    std::cout << "=== MutantStack Tests ===" << std::endl;
    
    // Test 1: Basic stack operations
    std::cout << "\n1. Basic stack operations:" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    std::cout << "Stack size: " << mstack.size() << std::endl;
    
    mstack.pop();
    std::cout << "After pop, size: " << mstack.size() << std::endl;
    std::cout << "After pop, top: " << mstack.top() << std::endl;
    
    // Test 2: Iterator functionality (the main feature!)
    std::cout << "\n2. Iterator functionality:" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Stack contents (using iterators): ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    // Test 3: Copy constructor and assignment
    std::cout << "\n3. Copy constructor test:" << std::endl;
    MutantStack<int> s(mstack);
    std::cout << "Copied stack contents: ";
    for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test 4: Assignment operator
    std::cout << "\n4. Assignment operator test:" << std::endl;
    MutantStack<int> s2;
    s2.push(42);
    s2 = mstack;
    std::cout << "Assigned stack contents: ";
    for (MutantStack<int>::iterator it = s2.begin(); it != s2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test 5: Reverse iterators
    std::cout << "\n5. Reverse iterator test:" << std::endl;
    std::cout << "Stack contents (reverse): ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    // Test 6: Const iterators
    std::cout << "\n6. Const iterator test:" << std::endl;
    const MutantStack<int> const_stack(mstack);
    std::cout << "Const stack contents: ";
    for (MutantStack<int>::const_iterator cit = const_stack.begin(); cit != const_stack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    // Test 7: Comparison with std::list (which has similar interface)
    std::cout << "\n7. Comparison with std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "List contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test 8: Different data types
    std::cout << "\n8. String MutantStack test:" << std::endl;
    MutantStack<std::string> str_stack;
    str_stack.push("Hello");
    str_stack.push("World");
    str_stack.push("42");
    
    std::cout << "String stack contents: ";
    for (MutantStack<std::string>::iterator it = str_stack.begin(); it != str_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test 9: Empty stack
    std::cout << "\n9. Empty stack test:" << std::endl;
    MutantStack<int> empty_stack;
    std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
    std::cout << "Empty stack empty(): " << (empty_stack.empty() ? "true" : "false") << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;

    // Test 10: Fill MutantStack from std::set
    std::cout << "\n10. Fill from std::set:" << std::endl;
    std::set<int> set_values;
    set_values.insert(42);
    set_values.insert(17);
    set_values.insert(99);
    set_values.insert(3);
    set_values.insert(58);
    set_values.insert(17); // duplicate ignored by set

    MutantStack<int> set_stack;
    for (std::set<int>::const_iterator it = set_values.begin(); it != set_values.end(); ++it) {
        set_stack.push(*it);
    }

    std::cout << "Set size: " << set_values.size() << ", MutantStack size: " << set_stack.size() << std::endl;
    std::cout << "MutantStack contents (in insertion order from set): ";
    for (MutantStack<int>::iterator it = set_stack.begin(); it != set_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "MutantStack contents (reverse): ";
    for (MutantStack<int>::reverse_iterator rit = set_stack.rbegin(); rit != set_stack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:18:17 by sanghwal          #+#    #+#             */
/*   Updated: 2023/12/16 19:41:20 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
 public:
  MutantStack() : std::stack<T, std::deque<T> >() {}
  MutantStack(const MutantStack& origin)
      : std::stack<T, std::deque<T> >(origin) {}
  MutantStack& operator=(const MutantStack& origin) {
    if (this != &origin) std::stack<T, std::deque<T> >::operator=(origin);
    return (*this);
  }

  typedef typename std::deque<T>::iterator iterator;
  typedef typename std::deque<T>::const_iterator const_iterator;

  iterator begin() { return (this->c.begin()); }
  iterator end() { return (this->c.end()); }

  const_iterator begin() const { return (this->c.begin()); }
  const_iterator end() const { return (this->c.end()); }

  ~MutantStack() { std::cout << "[MutantStack] Destructor called\n"; }
};

#endif

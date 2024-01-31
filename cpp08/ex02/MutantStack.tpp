#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
  return MutantStack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
  return MutantStack<T>::c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
  return MutantStack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
  return MutantStack<T>::c.end();
}

#endif // MUTANTSTACK_TPP
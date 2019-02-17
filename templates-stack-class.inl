

// Stack<T> constructor
template <typename T>
Stack<T>::Stack(int s) {
	if (s > m_maxSize || s < 1) throw StackExeption("invalid stack size");
	else m_size = s;
	m_stackPtr = new T[m_size];
	m_top = -1;
}

template <typename T>
T & Stack<T>::push(const T & i) {
	if (isFull()) throw StackExeption("stack full");
	return m_stackPtr[++m_top] = i;
}

template <typename T>
T & Stack<T>::pop() {
	if (isEmpty()) throw StackExeption("stack empty");
	return m_stackPtr[m_top--];
}

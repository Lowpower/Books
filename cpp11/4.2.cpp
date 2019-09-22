template<class T, class... Args> inline
typename enable_if<!is_array<T>::value, unique_prt<T>>::type
make_unique(Args&&,,, args) {
	return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

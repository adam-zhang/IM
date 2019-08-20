#ifndef __PROPERTY__H
#define __PROPERTY__H

#define char_tolower(c)      (u_char) ((c >= 'A' && c <= 'Z') ? (c | 0x20) : c) 
#define char_toupper(c)      (u_char) ((c >= 'a' && c <= 'z') ? (c & ~0x20) : c)
#define capitalize(name) \
	name[0] = char_toupper(name[0]);


#define PROPERTY(type, name, method) \
        private: \
                type name##_; \
        public: \
                const type& name()const \
                { return name##_; } \
                void method(const type& value) \
		{ name##_ = value; }

#define SIMPLE(type, name) \
	private: \
		type name##_; \
	public: \
		const type& name()const \
		{ return name##_; } \
		void set##capitalize(name)(const type& value) \
		{ name##_ = value; }

#endif//__PROPERTY__H

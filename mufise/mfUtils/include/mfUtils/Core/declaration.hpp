#ifndef _MF_DECLARATION_H
#define _MF_DECLARATION_H


#define DECL_IT_END(_Type, _arr, _var)		\
_Type::iterator _var##It = _arr.begin();	\
_Type::iterator _var##End = _arr.end();		\

#define DECL_IT_ONLY(_Type, _arr, _var)		\
_Type::iterator _var##It = _arr.begin();	\

#define FIND_IT(_arr, _val)			std::find(_arr.begin(), _arr.end(), _val)

#define DECL_SHARED(Class)			typedef std::shared_ptr<Class>	Class##Ptr
#define MAKE_SHARED(Class, var)		Class##Ptr var = std::make_shared<Class>


#endif // !_MF_DECLARATION_H

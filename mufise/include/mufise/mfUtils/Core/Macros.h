#ifndef MFU_MACRO_H
#define MFU_MACRO_H


#define DECL_IT(_Type, _arr, _var)			\
_Type::iterator _var##It = _arr.begin();	\

#define DECL_IT_END(_Type, _arr, _var)		\
DECL_IT(_Type, _arr, _var);					\
_Type::iterator _var##End = _arr.end();		\

#define FIND_IT(_arr, _val)			std::find(_arr.begin(), _arr.end(), _val)

#define MAKE_SHARED(Class)			typedef std::shared_ptr<Class>	Class##SPtr;
#define MAKE_UNIQUE(Class)			typedef std::unique_ptr<Class>	Class##UPtr;
#define MAKE_WEAK(Class)			typedef std::weak_ptr<Class>	Class##WPtr;

#define MAKE_SMART_PTR(Class)	\
MAKE_SHARED(Class)				\
MAKE_UNIQUE(Class)				\
MAKE_WEAK(Class)				\

#define DECL_SHARED(Class, var)		Class##SPtr var = std::make_shared<Class>

/* Including File
*/
#define MakeHeader(path, file)		MakeHeader1(path, file)
#define MakeHeader1(path, file)		MakeHeader2(path##/##file##.h)
#define MakeHeader2(file)			#file


#endif // !MFU_MACRO_H

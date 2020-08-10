#include "mfUtils/pch.h"
#include "mfUtils/File/File.h"

#define RETURN_IF_NOT_OPENED(VALUE)\
if(!m_bIsOpened)\
{\
	return VALUE;\
}\

#define ASSERT_IF_NOT_OPENED(VALUE)\
if(!m_bIsOpened)\
{\
	MF_ASSERT(m_bIsOpened);\
	return VALUE;\
}\

namespace mufise
{
namespace utils
{

File::File()
	: m_bIsOpened(false)
{
}

File::~File()
{
	MF_ASSERT(!m_bIsOpened);
}

void File::Close()
{
	ASSERT_IF_NOT_OPENED();

	m_bIsOpened = false;
	m_pFile.close();
}

void File::Open(const char* filename, sbit8 mode, ui8 loc, const char* path)
{
	if (m_bIsOpened)
	{
		MF_ASSERT(!m_bIsOpened);
		return;
	}

	m_filename = filename;
	m_mode = mode;
	m_loc = loc;

	switch (loc)
	{
	case File::Loc_User:
		// set to C://User/<username>/AppData/Roaming
		m_path = "";
		break;
	case File::Loc_Custom:
		m_path = path;
		break;
	default:
		break;
	}

	int _mode = 0;
	string full = "";
	full += path;
	full += filename;

	m_bIsOpened = true;

	if (mode & File::Mode_Write)	_mode |= fstream::out;
	if (mode & File::Mode_Read)		_mode |= fstream::in;
	if (mode & File::Mode_Append)	_mode |= fstream::app;
	if (mode & File::Mode_Discard)	_mode |= fstream::trunc;
	if (mode & File::Mode_Binary)	_mode |= fstream::binary;

	m_pFile.open(full.c_str(), _mode);
}

void File::Read(char* buffer, usize size)
{
	ASSERT_IF_NOT_OPENED();

	if (size == usize(-1))
	{
		size = m_pFile.tellg();
	}

	m_pFile.read(buffer, size);
}

void File::Write(char* buffer, usize size)
{
	ASSERT_IF_NOT_OPENED();

	m_pFile.write(buffer, size);
}

usize File::Length()
{
	RETURN_IF_NOT_OPENED(usize(-1));

	return m_pFile.tellg();
}

void File::SeekR(int pos)
{
	m_pFile.seekg(pos);
}

void File::SeekR(int offset, int seekDir)
{
	m_pFile.seekg(offset, seekDir);
}

void File::SeekW(int pos)
{
	m_pFile.seekp(pos);
}

void File::SeekW(int offset, int seekDir)
{
	m_pFile.seekp(offset, seekDir);
}

void File::Rewind()
{
	RETURN_IF_NOT_OPENED();

	m_pFile.seekp(0);
	m_pFile.seekg(0);
}

}
}

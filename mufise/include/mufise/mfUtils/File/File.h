#ifndef MF_FILE_H
#define MF_FILE_H

#include <fstream>

namespace mufise
{
	class File
	{
	public:
		enum ELocation
		{
			Loc_User,
			Loc_Custom,
		};

		enum EMode
		{
			Mode_Write = 1 << 0,
			Mode_Read = 1 << 1,
			Mode_Append = 1 << 2,
			Mode_Discard = 1 << 3,
			Mode_Binary = 1 << 4,

			Mode_ReadWrite = Mode_Read | Mode_Write,
			Mode_ReadBin = Mode_Read | Mode_Binary,
			Mode_WriteBin = Mode_Write | Mode_Binary,
		};

		File();
		~File();

		void	Close();
		void	Open(const char* filename, sbit8 mode, ui8 loc = Loc_User, const char* path = "");
		void	Read(char* buffer, usize size = usize(-1));
		void	Write(char* buffer, usize size);

		usize	Length();
		void	SeekR(int pos);
		void	SeekR(int offset, int seekDir);
		void	SeekW(int pos);
		void	SeekW(int offset, int seekDir);
		void	Rewind();

	private:
		string	m_filename;
		string	m_path;
		ui8		m_loc;
		ui8		m_mode;

		fstream	m_pFile;
		bool	m_bIsOpened;
	};
} // mufise

#endif // !MF_FILE_H

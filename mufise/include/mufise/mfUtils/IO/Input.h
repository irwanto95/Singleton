#ifndef MFU_INPUT_H
#define MFU_INPUT_H

namespace mufise
{
	class Input
	{
	public:
		enum IType
		{
			NONE = -1,
			MOUSE,
			KEY
		};

		Input();
		virtual ~Input() {};

		virtual si16 GetType() const = 0;

	protected:
		si16 m_id;
	};
} // mufise

#endif // !MFU_INPUT_H

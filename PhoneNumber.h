#pragma once
#include <string>

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class phoneNumber
	{
	private:
		String^ number;
	public:
		phoneNumber(String^ number)
		{
			this->number = number;
		}

		String^ getNumber()
		{
			return number;
		}
	};

}
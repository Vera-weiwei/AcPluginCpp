#pragma once
#include "StdAfx.h"
#include <type_traits>
#include <string>
#include <limits>
#include <stdexcept>

template <typename T>
class POLADLL_INTERACTIVE_API InputValidator
{
public:
	static bool Validate(CEdit& editControl, T& targetVariable, const CString& fieldName, bool needValidation = true, T defaultValue = T(6496));
};

template<typename T>
inline bool InputValidator<T>::Validate(CEdit& editControl, T& targetVariable, const CString& fieldName, bool needValidation, T defaultValue)
{
	if (!needValidation)
	{
		targetVariable = defaultValue;
		return true;
	}

	CString temp;
	editControl.GetWindowTextW(temp);

	if (temp.IsEmpty())
	{
		::MessageBox(editControl.GetParent()->GetSafeHwnd(),
			(fieldName + _T(" cannot be empty.")).GetString(),
			_T("Validation Error"), MB_OK | MB_ICONEXCLAMATION);
		editControl.SetFocus();
		return false;
	}

	try
	{
		if constexpr (std::is_same_v<T, int> || std::is_same_v<T, long> || std::is_same_v<T, short> || std::is_same_v<T, LONG>)
		{
			wchar_t* end_ptr = nullptr;
			errno = 0;
			long value = wcstol(temp, &end_ptr, 10);

			if (errno == ERANGE || end_ptr == temp || *end_ptr != L'\0' ||
				value > (std::numeric_limits<T>::max)() ||
				value < (std::numeric_limits<T>::min)()) 
			{
				throw std::invalid_argument("Invalid integer");
			}

			targetVariable = static_cast<T>(value);
		}
		else if constexpr (std::is_same_v<T, double> || std::is_same_v<T, float>)
		{
			wchar_t* end_ptr = nullptr;
			errno = 0;
			double value = wcstod(temp, &end_ptr);

			if (errno == ERANGE || end_ptr == temp || *end_ptr != L'\0')
			{
				throw std::invalid_argument("Invalid floating point number");
			}

			targetVariable = static_cast<T>(value);
		}
		else
		{
			static_assert(std::is_arithmetic_v<T>, "Unsupported type for validation");
		}
		return true;
	}
	catch (const std::exception&)
	{
		CString typeStr = std::is_integral_v<T> ? _T("integer") : _T("number");
		::MessageBox(editControl.GetParent()->GetSafeHwnd(),
			(_T("Please enter a valid ") + typeStr + _T(" for ") + fieldName).GetString(),
			_T("Validation Error"), MB_OK | MB_ICONEXCLAMATION);
		editControl.SetFocus();
		editControl.SetSel(0, -1);
		targetVariable = defaultValue;
		return false;
	}
}

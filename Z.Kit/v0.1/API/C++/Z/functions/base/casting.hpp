/* Z Kit C++ API - functions/base/casting.hpp
 _____  _______________
/_   /_/  -_/_   _/  _ |
 /____/\___/ /__//___/_| Kit
Copyright (C) 2006-2017 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_casting_HPP__
#define __Z_functions_base_casting_HPP__

#include <Z/traits/Type.hpp>

#if Z_LANGUAGE_HAS(CPP, RVALUE_REFERENCE)

	namespace Zeta {


		template <class T>
		Z_CT(CPP14) T &&forwardable(typename Type<T>::remove_reference &what) Z_NO_EXCEPTION
			{return static_cast<T &&>(what);}


		template <class T>
		Z_CT(CPP14) T &&forwardable(typename Type<T>::remove_reference &&what) Z_NO_EXCEPTION
			{return static_cast<T &&>(what);}


		template <class T>
		Z_CT(CPP14) typename Type<T>::remove_reference &&movable(T &&what) Z_NO_EXCEPTION
			{return static_cast<typename Type<T>::remove_reference &&>(what);}


	}

#endif

#endif // __Z_functions_base_casting_HPP__

/* Q API - hardware/CPU/architecture/x86-64.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Q_hardware_CPU_architecture_x86_64_Ha__
#define __Q_hardware_CPU_architecture_x86_64_Ha__

#include <Q/keys/endianness.h>

#define Q_X86_64_HAS_MMU
#define Q_X86_64_HAS_FPU
#define Q_X86_64_HAS_64BIT_ARITHMETIC
#define Q_X86_64_HAS_128BIT_ARITHMETIC
#define Q_X86_64_IS_CAPABLE_OF_8BIT_ATOMICS
#define Q_X86_64_IS_CAPABLE_OF_16BIT_ATOMICS
#define Q_X86_64_IS_CAPABLE_OF_32BIT_ATOMICS
#define Q_X86_64_IS_CAPABLE_OF_64BIT_ATOMICS
#define Q_X86_64_MINIMUM_LOAD_BITS		  8
#define Q_X86_64_MINIMUM_STORE_BITS		  8
#define Q_X86_64_MINIMUM_COPY_BITS		  8
#define Q_X86_64_MAXIMUM_LOAD_BITS		128
#define Q_X86_64_MAXIMUM_STORE_BITS		128
#define Q_X86_64_MAXIMUM_COPY_BITS		 64
#define Q_X86_64_ADDRESSING_BITS		 64
#define Q_X86_64_ENDIANNESS			Q_ENDIANNESS_LITTLE

#endif /* __Q_hardware_CPU_architecture_x86_64_Ha__ */

#ifdef Q_INSPECTING

#	undef X86_64
#	undef X8664
#	undef x86_64

#	define Q_CPU_ARCHITECTURE_NAME X86_64
#	define Q_CPU_ARCHITECTURE_Name X8664
#	define Q_CPU_ARCHITECTURE_name x86_64

#else

#	ifndef __Q_hardware_CPU_architecture_x86_64_Hb__
#	define __Q_hardware_CPU_architecture_x86_64_Hb__

#	endif /* __Q_hardware_CPU_architecture_x86_64_Hb__ */

#endif
/* Z Kit C API - functions/base/value.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2015 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_base_value_H__
#define __Z_functions_base_value_H__

#include <Z/macros/value.h>


/* MARK: - Reversion */


#define Z_IMPLEMENTATION_VALUE_REVERSED(bits, level)				\
										\
Z_INLINE zuint##bits z_uint##bits##_reversed_in_##level##bit(zuint##bits value)	\
	{return Z_##bits##BIT_REVERSED_IN_##level##BIT(value);}			\
										\
Z_INLINE zint##bits z_int##bits##_reversed_in_##level##bit(zint##bits value)	\
	{return Z_##bits##BIT_REVERSED_IN_##level##BIT(value);}


Z_IMPLEMENTATION_VALUE_REVERSED( 8,  1)
Z_IMPLEMENTATION_VALUE_REVERSED( 8,  2)
Z_IMPLEMENTATION_VALUE_REVERSED( 8,  4)
Z_IMPLEMENTATION_VALUE_REVERSED(16,  1)
Z_IMPLEMENTATION_VALUE_REVERSED(16,  2)
Z_IMPLEMENTATION_VALUE_REVERSED(16,  4)
Z_IMPLEMENTATION_VALUE_REVERSED(16,  8)
Z_IMPLEMENTATION_VALUE_REVERSED(32,  1)
Z_IMPLEMENTATION_VALUE_REVERSED(32,  2)
Z_IMPLEMENTATION_VALUE_REVERSED(32,  4)
Z_IMPLEMENTATION_VALUE_REVERSED(32,  8)
Z_IMPLEMENTATION_VALUE_REVERSED(32, 16)
Z_IMPLEMENTATION_VALUE_REVERSED(64,  1)
Z_IMPLEMENTATION_VALUE_REVERSED(64,  2)
Z_IMPLEMENTATION_VALUE_REVERSED(64,  4)
Z_IMPLEMENTATION_VALUE_REVERSED(64,  8)
Z_IMPLEMENTATION_VALUE_REVERSED(64, 16)
Z_IMPLEMENTATION_VALUE_REVERSED(64, 32)

#define z_uint8_reversed  Z_SAME
#define z_uint16_reversed z_uint16_reversed_in_8bit
#define z_uint32_reversed z_uint32_reversed_in_8bit
#define z_uint64_reversed z_uint64_reversed_in_8bit
#define z_int8_reversed   Z_SAME
#define z_int16_reversed  z_int16_reversed_in_8bit
#define z_int32_reversed  z_int32_reversed_in_8bit
#define z_int64_reversed  z_int64_reversed_in_8bit

#if Z_IS_AVAILABLE(UINT128)

	Z_IMPLEMENTATION_VALUE_REVERSED(128,  1)
	Z_IMPLEMENTATION_VALUE_REVERSED(128,  2)
	Z_IMPLEMENTATION_VALUE_REVERSED(128,  4)
	Z_IMPLEMENTATION_VALUE_REVERSED(128,  8)
	Z_IMPLEMENTATION_VALUE_REVERSED(128, 16)
	Z_IMPLEMENTATION_VALUE_REVERSED(128, 32)
	Z_IMPLEMENTATION_VALUE_REVERSED(128, 64)

#	define z_uint128_reversed z_uint128_reversed_in_8bit
#	define z_int128_reversed  z_int128_reversed_in_8bit

#endif


#define Z_JOIN_type_reversed(type) Z_PASTE_3(z_, type, _reversed)

#define z_value_reversed(TYPE) Z_JOIN_type_reversed(Z_##TYPE##_FIXED_TYPE_name)


/* MARK: - Rotation */


#define Z_IMPLEMENTATION_VALUE_ROTATED(bits)						\
											\
Z_INLINE zuint##bits z_uint##bits##_rotated_left(zuint##bits value, zuint rotation)	\
	{return Z_##bits##BIT_ROTATE_LEFT(value, rotation);}				\
											\
Z_INLINE zuint##bits z_uint##bits##_rotated_right(zuint##bits value, zuint rotation)	\
	{return Z_##bits##BIT_ROTATE_RIGHT(value, rotation);}				\
											\
Z_INLINE zint##bits z_int##bits##_rotated_left(zint##bits value, zuint rotation)	\
	{return Z_##bits##BIT_ROTATE_LEFT(value, rotation);}				\
											\
Z_INLINE zint##bits z_int##bits##_rotated_right(zint##bits value, zuint rotation)	\
	{return Z_##bits##BIT_ROTATE_RIGHT(value, rotation);}				\


Z_IMPLEMENTATION_VALUE_ROTATED( 8)
Z_IMPLEMENTATION_VALUE_ROTATED(16)
Z_IMPLEMENTATION_VALUE_ROTATED(32)
Z_IMPLEMENTATION_VALUE_ROTATED(64)


#define Z_JOIN_type_rotated_left( type) Z_PASTE_3(z_, type, _rotated_left )
#define Z_JOIN_type_rotated_right(type) Z_PASTE_3(z_, type, _rotated_right)

#define z_value_rotated_left( TYPE) Z_JOIN_type_rotated_left (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_rotated_right(TYPE) Z_JOIN_type_rotated_right(Z_##TYPE##_FIXED_TYPE_name)


/* MARK: - Endianness */


#if Z_INT16_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint16_big_endian    Z_SAME
#	define z_int16_big_endian     Z_SAME
#	define z_uint16_little_endian z_uint16_reversed
#	define z_int16_little_endian  z_int16_reversed

#elif Z_INT16_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint16_big_endian    z_uint16_reversed
#	define z_int16_big_endian     z_int16_reversed
#	define z_uint16_little_endian Z_SAME
#	define z_int16_little_endian  Z_SAME

#endif

#if Z_INT32_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint32_big_endian    Z_SAME
#	define z_int32_big_endian     Z_SAME
#	define z_uint32_little_endian z_uint32_reversed
#	define z_int32_little_endian  z_int32_reversed

#elif Z_INT32_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint32_big_endian    z_uint32_reversed
#	define z_int32_big_endian     z_int32_reversed
#	define z_uint32_little_endian Z_SAME
#	define z_int32_little_endian  Z_SAME

#endif

#if Z_INT64_ENDIANNESS == Z_ENDIANNESS_BIG

#	define z_uint64_big_endian    Z_SAME
#	define z_int64_big_endian     Z_SAME
#	define z_uint64_little_endian z_uint64_reversed
#	define z_int64_little_endian  z_int64_reversed

#elif Z_INT64_ENDIANNESS == Z_ENDIANNESS_LITTLE

#	define z_uint64_big_endian    z_uint64_reversed
#	define z_int64_big_endian     z_int64_reversed
#	define z_uint64_little_endian Z_SAME
#	define z_int64_little_endian  Z_SAME

#endif

#if Z_IS_AVAILABLE(UINT128)
#	if Z_UINT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_uint128_big_endian    Z_SAME
#		define z_uint128_little_endian z_uint128_reversed

#	elif Z_UINT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_uint128_big_endian    z_uint128_reversed
#		define z_uint128_little_endian Z_SAME

#	endif
#endif

#if Z_IS_AVAILABLE(INT128)
#	if Z_INT128_ENDIANNESS == Z_ENDIANNESS_BIG

#		define z_int128_big_endian     Z_SAME
#		define z_int128_little_endian  z_int128_reversed

#	elif Z_INT128_ENDIANNESS == Z_ENDIANNESS_LITTLE

#		define z_int128_big_endian     z_int128_reversed
#		define z_int128_little_endian  Z_SAME

#	endif
#endif


#define Z_JOIN_type_big_endian(	  type) Z_PASTE_3(z_, type, _big_endian	  )
#define Z_JOIN_type_little_endian(type) Z_PASTE_3(z_, type, _little_endian)

#define z_value_big_endian(   TYPE) Z_JOIN_type_big_endian   (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_little_endian(TYPE) Z_JOIN_type_little_endian(Z_##TYPE##_FIXED_TYPE_name)


/* MARK: - Mirroring */


Z_INLINE zuinttop z_uint8_top_mirror(zuint8 value)
	{return Z_8BIT_TOP_MIRROR(value);}


#if Z_UINTTOP_BITS > 16

	Z_INLINE zuinttop z_uint16_top_mirror(zuint16 value)
		{return Z_16BIT_TOP_MIRROR(value);}

#	if Z_UINTTOP_ENDIANNESS == Z_UINT16_ENDIANNESS

#		define z_uint16_top_packet z_uint16_top_mirror

#	elif	(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_UINT16_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_UINT16_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zuinttop z_uint16_top_packet(zuint16 value)
			{return Z_16BIT_TOP_MIRROR(z_uint16_reversed(value));}
#	endif
#endif


#if Z_UINTTOP_BITS > 32

	Z_INLINE zuinttop z_uint32_top_mirror(zuint32 value)
		{return Z_32BIT_TOP_MIRROR(value);}

#	if Z_UINTTOP_ENDIANNESS == Z_UINT32_ENDIANNESS

#		define z_uint32_top_packet z_uint32_top_mirror

#	elif	(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_UINT32_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_UINT32_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zuinttop z_uint32_top_packet(zuint32 value)
			{return Z_32BIT_TOP_MIRROR(z_uint32_reversed(value));}
#	endif
#endif


#if Z_UINTTOP_BITS > 64

	Z_INLINE zuinttop z_uint64_top_mirror(zuint64 value)
		{return Z_64BIT_TOP_MIRROR(value);}

#	if Z_UINTTOP_ENDIANNESS == Z_UINT64_ENDIANNESS

#		define z_uint64_top_packet z_uint64_top_mirror

#	elif	(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_BIG     && \
		 Z_UINT64_ENDIANNESS  == Z_ENDIANNESS_LITTLE) || \
		(Z_UINTTOP_ENDIANNESS == Z_ENDIANNESS_LITTLE  && \
		 Z_UINT64_ENDIANNESS  == Z_ENDIANNESS_BIG)

		Z_INLINE zuinttop z_uint64_top_packet(zuint64 value)
			{return Z_64BIT_TOP_MIRROR(z_uint64_reversed(value));}
#	endif
#endif


/* MARK: - Binary codified decimal */


Z_INLINE zuint32 z_uint32_to_bcd(zuint32 value)
	{
	zuint32 result = 0;
	zuint	shift  = 0;

	for (; value; value /= 10, shift += 4) result |= (value % 10) << shift;
	return result;
	}


Z_INLINE zuint32 z_bcd_to_uint32(zuint32 value)
	{
	zuint32 result = 0;
	zuint32 scale  = 1;

	for (; value; value >>= 4, scale *= 10) result += (value & 0x0F) * scale;
	return result;
	}


/* MARK: - Operations for natural, integer and real types */


#define Z_IMPLEMENTATION_VALUE_NATURAL(type)						\
											\
											\
Z_INLINE void z_##type##_swap(void *a, void *b)						\
	{										\
	z##type t = *(z##type *)a;							\
											\
	*(z##type *)a = *(z##type *)b;							\
	*(z##type *)b = t;								\
	}										\
											\
											\
Z_INLINE z##type z_##type##_minimum(z##type a, z##type b)				\
	{return Z_MINIMUM(a, b);}							\
											\
											\
Z_INLINE z##type z_##type##_maximum(z##type a, z##type b)				\
	{return Z_MAXIMUM(a, b);}							\
											\
											\
Z_INLINE z##type z_##type##_clamp(z##type value, z##type minimum, z##type maximum)	\
	{return z_##type##_minimum(z_##type##_maximum(value, minimum), maximum);}


Z_IMPLEMENTATION_VALUE_NATURAL(uint8  )
Z_IMPLEMENTATION_VALUE_NATURAL(uint16 )
Z_IMPLEMENTATION_VALUE_NATURAL(uint32 )
Z_IMPLEMENTATION_VALUE_NATURAL(uint64 )
Z_IMPLEMENTATION_VALUE_NATURAL(int8   )
Z_IMPLEMENTATION_VALUE_NATURAL(int16  )
Z_IMPLEMENTATION_VALUE_NATURAL(int32  )
Z_IMPLEMENTATION_VALUE_NATURAL(int64  )
Z_IMPLEMENTATION_VALUE_NATURAL(float  )
Z_IMPLEMENTATION_VALUE_NATURAL(double )
Z_IMPLEMENTATION_VALUE_NATURAL(ldouble)


#define Z_JOIN_type_swap(   type) Z_PASTE_3(z_, type, _swap   )
#define Z_JOIN_type_minimum(type) Z_PASTE_3(z_, type, _minimum)
#define Z_JOIN_type_maximum(type) Z_PASTE_3(z_, type, _maximum)
#define Z_JOIN_type_clamp(  type) Z_PASTE_3(z_, type, _clamp  )

#define z_value_swap(	TYPE) Z_JOIN_type_swap	 (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_minimum(TYPE) Z_JOIN_type_minimum(Z_##TYPE##_FIXED_TYPE_name)
#define z_value_maximum(TYPE) Z_JOIN_type_maximum(Z_##TYPE##_FIXED_TYPE_name)
#define z_value_clamp(	TYPE) Z_JOIN_type_clamp	 (Z_##TYPE##_FIXED_TYPE_name)


/* MARK: - Operations for integer and real types */


#define Z_IMPLEMENTATION_VALUE_INTEGER(type)			 \
								 \
Z_INLINE z##type z_##type##_absolute(z##type value)		 \
	{return value < (z##type)0 ? -value : value;}		 \
								 \
Z_INLINE z##type z_##type##_sign(z##type value)			 \
	{return value >= (z##type)0 ? (z##type)1 : -(z##type)1;}


Z_IMPLEMENTATION_VALUE_INTEGER(int8   )
Z_IMPLEMENTATION_VALUE_INTEGER(int16  )
Z_IMPLEMENTATION_VALUE_INTEGER(int32  )
Z_IMPLEMENTATION_VALUE_INTEGER(int64  )
Z_IMPLEMENTATION_VALUE_INTEGER(ssize  )
Z_IMPLEMENTATION_VALUE_INTEGER(float  )
Z_IMPLEMENTATION_VALUE_INTEGER(double )
Z_IMPLEMENTATION_VALUE_INTEGER(ldouble)


#define Z_JOIN_type_absolute(type) Z_PASTE_3(z_, type, _absolute)
#define Z_JOIN_type_sign(    type) Z_PASTE_3(z_, type, _sign	)

#define z_value_absolute(TYPE) Z_JOIN_type_absolute(Z_##TYPE##_FIXED_TYPE_name)
#define z_value_sign(	 TYPE) Z_JOIN_type_sign	   (Z_##TYPE##_FIXED_TYPE_name)


/* MARK: - Operations for real types only */


#define Z_IMPLEMENTATION_VALUE_REAL(type, _, epsilon, infinity)			\
										\
										\
Z_INLINE zboolean z_##type##_are_almost_equal(z##type a, z##type b)		\
	{return z_##type##_absolute(a - b) <= epsilon;}				\
										\
										\
Z_INLINE z##type z_##type##_lerp(z##type a, z##type b, z##type t)		\
	{return a + t * (b - a);}						\
										\
										\
Z_INLINE z##type z_##type##_inverse_lerp(z##type a, z##type b, z##type t)	\
	{return (t - a) / (b - a);}						\
										\
										\
Z_INLINE z##type z_##type##_smoothstep(z##type a, z##type b, z##type t)		\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * (_(3.0) - _(2.0) * t);					\
	}									\
										\
										\
Z_INLINE z##type z_##type##_smootherstep(z##type a, z##type b, z##type t)	\
	{									\
	if (t <= a) return _(0.0);						\
	if (t >= b) return _(1.0);						\
	t = (t - a) / (b - a);							\
	return t * t * t * (t * (t * _(6.0) - _(15.0)) + _(10.0));		\
	}									\
										\
										\
Z_INLINE zboolean z_##type##_is_almost_zero(z##type value)			\
	{return z_##type##_absolute(value) <= epsilon;}				\
										\
										\
Z_INLINE zboolean z_##type##_is_finite(z##type value)				\
	{return value == value && value != infinity && value != -infinity;}	\
										\
										\
Z_INLINE zboolean z_##type##_is_infinity(z##type value)				\
	{return value == infinity || value == -infinity;}			\
										\
										\
Z_INLINE zboolean z_##type##_is_nan(z##type value)				\
	{return !(value == value);}						\
										\
										\
Z_INLINE z##type z_##type##_sign_or_zero(z##type value)				\
	{									\
	return z_##type##_absolute(value) <= epsilon				\
		? _(0.0)							\
		: z_##type##_sign(value);					\
	}									\
										\
										\
Z_INLINE z##type z_##type##_clamp_01(z##type value)				\
	{return z_##type##_minimum(z_##type##_maximum(value, _(0.0)), _(1.0));}


Z_IMPLEMENTATION_VALUE_REAL(float,   Z_FLOAT,	Z_FLOAT_EPSILON,   Z_FLOAT_INFINITY  )
Z_IMPLEMENTATION_VALUE_REAL(double,  Z_DOUBLE,	Z_DOUBLE_EPSILON,  Z_DOUBLE_INFINITY )
Z_IMPLEMENTATION_VALUE_REAL(ldouble, Z_LDOUBLE, Z_LDOUBLE_EPSILON, Z_LDOUBLE_INFINITY)


#define Z_JOIN_type_are_almost_equal(type) Z_PASTE_3(z_, type, _almost_equal  )
#define Z_JOIN_type_lerp(	     type) Z_PASTE_3(z_, type, _lerp	      )
#define Z_JOIN_type_inverse_lerp(    type) Z_PASTE_3(z_, type, _inverse_lerp  )
#define Z_JOIN_type_smoothstep(      type) Z_PASTE_3(z_, type, _smoothstep    )
#define Z_JOIN_type_smootherstep(    type) Z_PASTE_3(z_, type, _smootherstep  )
#define Z_JOIN_type_is_almost_zero(  type) Z_PASTE_3(z_, type, _is_almost_zero)
#define Z_JOIN_type_is_finite(	     type) Z_PASTE_3(z_, type, _is_finite     )
#define Z_JOIN_type_is_infinity(     type) Z_PASTE_3(z_, type, _is_infinity   )
#define Z_JOIN_type_is_nan(	     type) Z_PASTE_3(z_, type, _is_nan	      )
#define Z_JOIN_type_sign_or_zero(    type) Z_PASTE_3(z_, type, _sign_or_zero  )
#define Z_JOIN_type_clamp_01(	     type) Z_PASTE_3(z_, type, _clamp_01      )


/* MARK: - Default real type definitions */


#define z_are_almost_equal Z_JOIN_type_almost_equal  (Z_REAL_FIXED_TYPE_name)
#define z_minimum	   Z_JOIN_type_minimum	     (Z_REAL_FIXED_TYPE_name)
#define z_maximum	   Z_JOIN_type_maximum	     (Z_REAL_FIXED_TYPE_name)
#define z_lerp		   Z_JOIN_type_lerp	     (Z_REAL_FIXED_TYPE_name)
#define z_inverse_lerp	   Z_JOIN_type_inverse_lerp  (Z_REAL_FIXED_TYPE_name)
#define z_smoothstep	   Z_JOIN_type_smoothstep    (Z_REAL_FIXED_TYPE_name)
#define z_smootherstep	   Z_JOIN_type_smootherstep  (Z_REAL_FIXED_TYPE_name)
#define z_is_almost_zero   Z_JOIN_type_is_almost_zero(Z_REAL_FIXED_TYPE_name)
#define z_is_finite	   Z_JOIN_type_is_finite     (Z_REAL_FIXED_TYPE_name)
#define z_is_infinity	   Z_JOIN_type_is_infinity   (Z_REAL_FIXED_TYPE_name)
#define z_is_nan	   Z_JOIN_type_is_nan	     (Z_REAL_FIXED_TYPE_name)
#define z_absolute	   Z_JOIN_type_absolute      (Z_REAL_FIXED_TYPE_name)
#define z_sign		   Z_JOIN_type_sign	     (Z_REAL_FIXED_TYPE_name)
#define z_sign_or_zero	   Z_JOIN_type_sign_or_zero  (Z_REAL_FIXED_TYPE_name)
#define z_clamp		   Z_JOIN_type_clamp	     (Z_REAL_FIXED_TYPE_name)
#define z_clamp_01	   Z_JOIN_type_clamp_01      (Z_REAL_FIXED_TYPE_name)


/* MARK: - Atomic operations */


#if Z_CPU_IS_CAPABLE_OF(8BIT_ATOMICS)

	/* zuint8 z_uint8_atomic_set_if_equal(zuint8 *value, zuint8 old_value, zuint8 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT8_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_SET_IF_EQUAL)
#		define z_uint8_atomic_set_if_equal Z_COMPILER_FUNCTION_UINT8_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT8_ATOMIC_SET_IF_EQUAL
#	endif

	/* zuint8 z_uint8_atomic_get_then_set(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_SET)
#		define z_uint8_atomic_get_then_set Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_SET
#	endif

	/* zuint8 z_uint8_atomic_get_then_increment(zuint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint8_atomic_get_then_increment Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zuint8 z_uint8_atomic_get_then_decrement(zuint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint8_atomic_get_then_decrement Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zuint8 z_uint8_atomic_get_then_add(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_ADD)
#		define z_uint8_atomic_get_then_add Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_ADD
#	endif

	/* zuint8 z_uint8_atomic_get_then_subtract(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint8_atomic_get_then_subtract Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zuint8 z_uint8_atomic_get_then_and(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_AND)
#		define z_uint8_atomic_get_then_and Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_AND
#	endif

	/* zuint8 z_uint8_atomic_get_then_or(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_OR)
#		define z_uint8_atomic_get_then_or Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_OR
#	endif

	/* zuint8 z_uint8_atomic_get_then_xor(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_XOR)
#		define z_uint8_atomic_get_then_xor Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_XOR
#	endif

	/* zuint8 z_uint8_atomic_get_then_nand(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_NAND)
#		define z_uint8_atomic_get_then_nand Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_NAND
#	endif

	/* zuint8 z_uint8_atomic_get_then_not(zuint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_GET_THEN_NOT)
#		define z_uint8_atomic_get_then_not Z_COMPILER_FUNCTION_UINT8_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT8_ATOMIC_GET_THEN_NOT
#	endif

	/* zuint8 z_uint8_atomic_increment_then_get(zuint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint8_atomic_increment_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_decrement_then_get(zuint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint8_atomic_decrement_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_add_then_get(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_ADD_THEN_GET)
#		define z_uint8_atomic_add_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_ADD_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_subtract_then_get(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint8_atomic_subtract_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_and_then_get(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_AND_THEN_GET)
#		define z_uint8_atomic_and_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_AND_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_or_then_get(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_OR_THEN_GET)
#		define z_uint8_atomic_or_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_OR_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_xor_then_get(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_XOR_THEN_GET)
#		define z_uint8_atomic_xor_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_XOR_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_nand_then_get(zuint8 *value, zuint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_NAND_THEN_GET)
#		define z_uint8_atomic_nand_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_NAND_THEN_GET
#	endif

	/* zuint8 z_uint8_atomic_not_then_get(zuint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT8_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT8_ATOMIC_NOT_THEN_GET)
#		define z_uint8_atomic_not_then_get Z_COMPILER_FUNCTION_UINT8_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT8_ATOMIC_NOT_THEN_GET
#	endif

	/* zint8 z_int8_atomic_set_if_equal(zint8 *value, zint8 old_value, zint8 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT8_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_SET_IF_EQUAL)
#		define z_int8_atomic_set_if_equal Z_COMPILER_FUNCTION_INT8_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT8_ATOMIC_SET_IF_EQUAL
#	endif

	/* zint8 z_int8_atomic_get_then_set(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_SET)
#		define z_int8_atomic_get_then_set Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_SET
#	endif

	/* zint8 z_int8_atomic_get_then_increment(zint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_INCREMENT)
#		define z_int8_atomic_get_then_increment Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zint8 z_int8_atomic_get_then_decrement(zint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_DECREMENT)
#		define z_int8_atomic_get_then_decrement Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zint8 z_int8_atomic_get_then_add(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_ADD)
#		define z_int8_atomic_get_then_add Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_ADD
#	endif

	/* zint8 z_int8_atomic_get_then_subtract(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int8_atomic_get_then_subtract Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zint8 z_int8_atomic_get_then_and(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_AND)
#		define z_int8_atomic_get_then_and Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_AND
#	endif

	/* zint8 z_int8_atomic_get_then_or(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_OR)
#		define z_int8_atomic_get_then_or Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_OR
#	endif

	/* zint8 z_int8_atomic_get_then_xor(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_XOR)
#		define z_int8_atomic_get_then_xor Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_XOR
#	endif

	/* zint8 z_int8_atomic_get_then_nand(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_NAND)
#		define z_int8_atomic_get_then_nand Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_NAND
#	endif

	/* zint8 z_int8_atomic_get_then_not(zint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_GET_THEN_NOT)
#		define z_int8_atomic_get_then_not Z_COMPILER_FUNCTION_INT8_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT8_ATOMIC_GET_THEN_NOT
#	endif

	/* zint8 z_int8_atomic_increment_then_get(zint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_INCREMENT_THEN_GET)
#		define z_int8_atomic_increment_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zint8 z_int8_atomic_decrement_then_get(zint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_DECREMENT_THEN_GET)
#		define z_int8_atomic_decrement_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zint8 z_int8_atomic_add_then_get(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_ADD_THEN_GET)
#		define z_int8_atomic_add_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_ADD_THEN_GET
#	endif

	/* zint8 z_int8_atomic_subtract_then_get(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int8_atomic_subtract_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zint8 z_int8_atomic_and_then_get(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_AND_THEN_GET)
#		define z_int8_atomic_and_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_AND_THEN_GET
#	endif

	/* zint8 z_int8_atomic_or_then_get(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_OR_THEN_GET)
#		define z_int8_atomic_or_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_OR_THEN_GET
#	endif

	/* zint8 z_int8_atomic_xor_then_get(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_XOR_THEN_GET)
#		define z_int8_atomic_xor_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_XOR_THEN_GET
#	endif

	/* zint8 z_int8_atomic_nand_then_get(zint8 *value, zint8 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_NAND_THEN_GET)
#		define z_int8_atomic_nand_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_NAND_THEN_GET
#	endif

	/* zint8 z_int8_atomic_not_then_get(zint8 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT8_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT8_ATOMIC_NOT_THEN_GET)
#		define z_int8_atomic_not_then_get Z_COMPILER_FUNCTION_INT8_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT8_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Z_CPU_IS_CAPABLE_OF(16BIT_ATOMICS)

	/* zuint16 z_uint16_atomic_set_if_equal(zuint16 *value, zuint16 old_value, zuint16 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT16_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_SET_IF_EQUAL)
#		define z_uint16_atomic_set_if_equal Z_COMPILER_FUNCTION_UINT16_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT16_ATOMIC_SET_IF_EQUAL
#	endif

	/* zuint16 z_uint16_atomic_get_then_set(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_SET)
#		define z_uint16_atomic_get_then_set Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_SET
#	endif

	/* zuint16 z_uint16_atomic_get_then_increment(zuint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint16_atomic_get_then_increment Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zuint16 z_uint16_atomic_get_then_decrement(zuint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint16_atomic_get_then_decrement Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zuint16 z_uint16_atomic_get_then_add(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_ADD)
#		define z_uint16_atomic_get_then_add Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_ADD
#	endif

	/* zuint16 z_uint16_atomic_get_then_subtract(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint16_atomic_get_then_subtract Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zuint16 z_uint16_atomic_get_then_and(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_AND)
#		define z_uint16_atomic_get_then_and Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_AND
#	endif

	/* zuint16 z_uint16_atomic_get_then_or(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_OR)
#		define z_uint16_atomic_get_then_or Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_OR
#	endif

	/* zuint16 z_uint16_atomic_get_then_xor(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_XOR)
#		define z_uint16_atomic_get_then_xor Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_XOR
#	endif

	/* zuint16 z_uint16_atomic_get_then_nand(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_NAND)
#		define z_uint16_atomic_get_then_nand Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_NAND
#	endif

	/* zuint16 z_uint16_atomic_get_then_not(zuint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_GET_THEN_NOT)
#		define z_uint16_atomic_get_then_not Z_COMPILER_FUNCTION_UINT16_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT16_ATOMIC_GET_THEN_NOT
#	endif

	/* zuint16 z_uint16_atomic_increment_then_get(zuint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint16_atomic_increment_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_decrement_then_get(zuint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint16_atomic_decrement_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_add_then_get(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_ADD_THEN_GET)
#		define z_uint16_atomic_add_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_ADD_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_subtract_then_get(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint16_atomic_subtract_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_and_then_get(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_AND_THEN_GET)
#		define z_uint16_atomic_and_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_AND_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_or_then_get(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_OR_THEN_GET)
#		define z_uint16_atomic_or_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_OR_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_xor_then_get(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_XOR_THEN_GET)
#		define z_uint16_atomic_xor_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_XOR_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_nand_then_get(zuint16 *value, zuint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_NAND_THEN_GET)
#		define z_uint16_atomic_nand_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_NAND_THEN_GET
#	endif

	/* zuint16 z_uint16_atomic_not_then_get(zuint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT16_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT16_ATOMIC_NOT_THEN_GET)
#		define z_uint16_atomic_not_then_get Z_COMPILER_FUNCTION_UINT16_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT16_ATOMIC_NOT_THEN_GET
#	endif

	/* zint16 z_int16_atomic_set_if_equal(zint16 *value, zint16 old_value, zint16 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT16_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_SET_IF_EQUAL)
#		define z_int16_atomic_set_if_equal Z_COMPILER_FUNCTION_INT16_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT16_ATOMIC_SET_IF_EQUAL
#	endif

	/* zint16 z_int16_atomic_get_then_set(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_SET)
#		define z_int16_atomic_get_then_set Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_SET
#	endif

	/* zint16 z_int16_atomic_get_then_increment(zint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_INCREMENT)
#		define z_int16_atomic_get_then_increment Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zint16 z_int16_atomic_get_then_decrement(zint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_DECREMENT)
#		define z_int16_atomic_get_then_decrement Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zint16 z_int16_atomic_get_then_add(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_ADD)
#		define z_int16_atomic_get_then_add Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_ADD
#	endif

	/* zint16 z_int16_atomic_get_then_subtract(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int16_atomic_get_then_subtract Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zint16 z_int16_atomic_get_then_and(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_AND)
#		define z_int16_atomic_get_then_and Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_AND
#	endif

	/* zint16 z_int16_atomic_get_then_or(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_OR)
#		define z_int16_atomic_get_then_or Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_OR
#	endif

	/* zint16 z_int16_atomic_get_then_xor(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_XOR)
#		define z_int16_atomic_get_then_xor Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_XOR
#	endif

	/* zint16 z_int16_atomic_get_then_nand(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_NAND)
#		define z_int16_atomic_get_then_nand Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_NAND
#	endif

	/* zint16 z_int16_atomic_get_then_not(zint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_GET_THEN_NOT)
#		define z_int16_atomic_get_then_not Z_COMPILER_FUNCTION_INT16_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT16_ATOMIC_GET_THEN_NOT
#	endif

	/* zint16 z_int16_atomic_increment_then_get(zint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_INCREMENT_THEN_GET)
#		define z_int16_atomic_increment_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zint16 z_int16_atomic_decrement_then_get(zint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_DECREMENT_THEN_GET)
#		define z_int16_atomic_decrement_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zint16 z_int16_atomic_add_then_get(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_ADD_THEN_GET)
#		define z_int16_atomic_add_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_ADD_THEN_GET
#	endif

	/* zint16 z_int16_atomic_subtract_then_get(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int16_atomic_subtract_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zint16 z_int16_atomic_and_then_get(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_AND_THEN_GET)
#		define z_int16_atomic_and_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_AND_THEN_GET
#	endif

	/* zint16 z_int16_atomic_or_then_get(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_OR_THEN_GET)
#		define z_int16_atomic_or_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_OR_THEN_GET
#	endif

	/* zint16 z_int16_atomic_xor_then_get(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_XOR_THEN_GET)
#		define z_int16_atomic_xor_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_XOR_THEN_GET
#	endif

	/* zint16 z_int16_atomic_nand_then_get(zint16 *value, zint16 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_NAND_THEN_GET)
#		define z_int16_atomic_nand_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_NAND_THEN_GET
#	endif

	/* zint16 z_int16_atomic_not_then_get(zint16 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT16_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT16_ATOMIC_NOT_THEN_GET)
#		define z_int16_atomic_not_then_get Z_COMPILER_FUNCTION_INT16_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT16_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Z_CPU_IS_CAPABLE_OF(32BIT_ATOMICS)

	/* zuint32 z_uint32_atomic_set_if_equal(zuint32 *value, zuint32 old_value, zuint32 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT32_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_SET_IF_EQUAL)
#		define z_uint32_atomic_set_if_equal Z_COMPILER_FUNCTION_UINT32_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT32_ATOMIC_SET_IF_EQUAL
#	endif

	/* zuint32 z_uint32_atomic_get_then_set(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_SET)
#		define z_uint32_atomic_get_then_set Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_SET
#	endif

	/* zuint32 z_uint32_atomic_get_then_increment(zuint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint32_atomic_get_then_increment Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zuint32 z_uint32_atomic_get_then_decrement(zuint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint32_atomic_get_then_decrement Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zuint32 z_uint32_atomic_get_then_add(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_ADD)
#		define z_uint32_atomic_get_then_add Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_ADD
#	endif

	/* zuint32 z_uint32_atomic_get_then_subtract(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint32_atomic_get_then_subtract Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zuint32 z_uint32_atomic_get_then_and(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_AND)
#		define z_uint32_atomic_get_then_and Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_AND
#	endif

	/* zuint32 z_uint32_atomic_get_then_or(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_OR)
#		define z_uint32_atomic_get_then_or Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_OR
#	endif

	/* zuint32 z_uint32_atomic_get_then_xor(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_XOR)
#		define z_uint32_atomic_get_then_xor Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_XOR
#	endif

	/* zuint32 z_uint32_atomic_get_then_nand(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_NAND)
#		define z_uint32_atomic_get_then_nand Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_NAND
#	endif

	/* zuint32 z_uint32_atomic_get_then_not(zuint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_GET_THEN_NOT)
#		define z_uint32_atomic_get_then_not Z_COMPILER_FUNCTION_UINT32_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT32_ATOMIC_GET_THEN_NOT
#	endif

	/* zuint32 z_uint32_atomic_increment_then_get(zuint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint32_atomic_increment_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_decrement_then_get(zuint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint32_atomic_decrement_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_add_then_get(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_ADD_THEN_GET)
#		define z_uint32_atomic_add_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_ADD_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_subtract_then_get(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint32_atomic_subtract_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_and_then_get(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_AND_THEN_GET)
#		define z_uint32_atomic_and_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_AND_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_or_then_get(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_OR_THEN_GET)
#		define z_uint32_atomic_or_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_OR_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_xor_then_get(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_XOR_THEN_GET)
#		define z_uint32_atomic_xor_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_XOR_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_nand_then_get(zuint32 *value, zuint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_NAND_THEN_GET)
#		define z_uint32_atomic_nand_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_NAND_THEN_GET
#	endif

	/* zuint32 z_uint32_atomic_not_then_get(zuint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT32_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT32_ATOMIC_NOT_THEN_GET)
#		define z_uint32_atomic_not_then_get Z_COMPILER_FUNCTION_UINT32_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT32_ATOMIC_NOT_THEN_GET
#	endif

	/* zint32 z_int32_atomic_set_if_equal(zint32 *value, zint32 old_value, zint32 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT32_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_SET_IF_EQUAL)
#		define z_int32_atomic_set_if_equal Z_COMPILER_FUNCTION_INT32_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT32_ATOMIC_SET_IF_EQUAL
#	endif

	/* zint32 z_int32_atomic_get_then_set(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_SET)
#		define z_int32_atomic_get_then_set Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_SET
#	endif

	/* zint32 z_int32_atomic_get_then_increment(zint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_INCREMENT)
#		define z_int32_atomic_get_then_increment Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zint32 z_int32_atomic_get_then_decrement(zint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_DECREMENT)
#		define z_int32_atomic_get_then_decrement Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zint32 z_int32_atomic_get_then_add(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_ADD)
#		define z_int32_atomic_get_then_add Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_ADD
#	endif

	/* zint32 z_int32_atomic_get_then_subtract(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int32_atomic_get_then_subtract Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zint32 z_int32_atomic_get_then_and(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_AND)
#		define z_int32_atomic_get_then_and Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_AND
#	endif

	/* zint32 z_int32_atomic_get_then_or(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_OR)
#		define z_int32_atomic_get_then_or Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_OR
#	endif

	/* zint32 z_int32_atomic_get_then_xor(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_XOR)
#		define z_int32_atomic_get_then_xor Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_XOR
#	endif

	/* zint32 z_int32_atomic_get_then_nand(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_NAND)
#		define z_int32_atomic_get_then_nand Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_NAND
#	endif

	/* zint32 z_int32_atomic_get_then_not(zint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_GET_THEN_NOT)
#		define z_int32_atomic_get_then_not Z_COMPILER_FUNCTION_INT32_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT32_ATOMIC_GET_THEN_NOT
#	endif

	/* zint32 z_int32_atomic_increment_then_get(zint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_INCREMENT_THEN_GET)
#		define z_int32_atomic_increment_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zint32 z_int32_atomic_decrement_then_get(zint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_DECREMENT_THEN_GET)
#		define z_int32_atomic_decrement_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zint32 z_int32_atomic_add_then_get(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_ADD_THEN_GET)
#		define z_int32_atomic_add_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_ADD_THEN_GET
#	endif

	/* zint32 z_int32_atomic_subtract_then_get(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int32_atomic_subtract_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zint32 z_int32_atomic_and_then_get(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_AND_THEN_GET)
#		define z_int32_atomic_and_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_AND_THEN_GET
#	endif

	/* zint32 z_int32_atomic_or_then_get(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_OR_THEN_GET)
#		define z_int32_atomic_or_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_OR_THEN_GET
#	endif

	/* zint32 z_int32_atomic_xor_then_get(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_XOR_THEN_GET)
#		define z_int32_atomic_xor_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_XOR_THEN_GET
#	endif

	/* zint32 z_int32_atomic_nand_then_get(zint32 *value, zint32 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_NAND_THEN_GET)
#		define z_int32_atomic_nand_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_NAND_THEN_GET
#	endif

	/* zint32 z_int32_atomic_not_then_get(zint32 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT32_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT32_ATOMIC_NOT_THEN_GET)
#		define z_int32_atomic_not_then_get Z_COMPILER_FUNCTION_INT32_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT32_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Z_CPU_IS_CAPABLE_OF(64BIT_ATOMICS)

	/* zuint64 z_uint64_atomic_set_if_equal(zuint64 *value, zuint64 old_value, zuint64 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT64_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_SET_IF_EQUAL)
#		define z_uint64_atomic_set_if_equal Z_COMPILER_FUNCTION_UINT64_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT64_ATOMIC_SET_IF_EQUAL
#	endif

	/* zuint64 z_uint64_atomic_get_then_set(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_SET)
#		define z_uint64_atomic_get_then_set Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_SET
#	endif

	/* zuint64 z_uint64_atomic_get_then_increment(zuint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint64_atomic_get_then_increment Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zuint64 z_uint64_atomic_get_then_decrement(zuint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint64_atomic_get_then_decrement Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zuint64 z_uint64_atomic_get_then_add(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_ADD)
#		define z_uint64_atomic_get_then_add Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_ADD
#	endif

	/* zuint64 z_uint64_atomic_get_then_subtract(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint64_atomic_get_then_subtract Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zuint64 z_uint64_atomic_get_then_and(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_AND)
#		define z_uint64_atomic_get_then_and Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_AND
#	endif

	/* zuint64 z_uint64_atomic_get_then_or(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_OR)
#		define z_uint64_atomic_get_then_or Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_OR
#	endif

	/* zuint64 z_uint64_atomic_get_then_xor(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_XOR)
#		define z_uint64_atomic_get_then_xor Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_XOR
#	endif

	/* zuint64 z_uint64_atomic_get_then_nand(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_NAND)
#		define z_uint64_atomic_get_then_nand Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_NAND
#	endif

	/* zuint64 z_uint64_atomic_get_then_not(zuint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_GET_THEN_NOT)
#		define z_uint64_atomic_get_then_not Z_COMPILER_FUNCTION_UINT64_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT64_ATOMIC_GET_THEN_NOT
#	endif

	/* zuint64 z_uint64_atomic_increment_then_get(zuint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint64_atomic_increment_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_decrement_then_get(zuint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint64_atomic_decrement_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_add_then_get(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_ADD_THEN_GET)
#		define z_uint64_atomic_add_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_ADD_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_subtract_then_get(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint64_atomic_subtract_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_and_then_get(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_AND_THEN_GET)
#		define z_uint64_atomic_and_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_AND_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_or_then_get(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_OR_THEN_GET)
#		define z_uint64_atomic_or_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_OR_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_xor_then_get(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_XOR_THEN_GET)
#		define z_uint64_atomic_xor_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_XOR_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_nand_then_get(zuint64 *value, zuint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_NAND_THEN_GET)
#		define z_uint64_atomic_nand_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_NAND_THEN_GET
#	endif

	/* zuint64 z_uint64_atomic_not_then_get(zuint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT64_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT64_ATOMIC_NOT_THEN_GET)
#		define z_uint64_atomic_not_then_get Z_COMPILER_FUNCTION_UINT64_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT64_ATOMIC_NOT_THEN_GET
#	endif

	/* zint64 z_int64_atomic_set_if_equal(zint64 *value, zint64 old_value, zint64 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT64_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_SET_IF_EQUAL)
#		define z_int64_atomic_set_if_equal Z_COMPILER_FUNCTION_INT64_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT64_ATOMIC_SET_IF_EQUAL
#	endif

	/* zint64 z_int64_atomic_get_then_set(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_SET)
#		define z_int64_atomic_get_then_set Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_SET
#	endif

	/* zint64 z_int64_atomic_get_then_increment(zint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_INCREMENT)
#		define z_int64_atomic_get_then_increment Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zint64 z_int64_atomic_get_then_decrement(zint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_DECREMENT)
#		define z_int64_atomic_get_then_decrement Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zint64 z_int64_atomic_get_then_add(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_ADD)
#		define z_int64_atomic_get_then_add Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_ADD
#	endif

	/* zint64 z_int64_atomic_get_then_subtract(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int64_atomic_get_then_subtract Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zint64 z_int64_atomic_get_then_and(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_AND)
#		define z_int64_atomic_get_then_and Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_AND
#	endif

	/* zint64 z_int64_atomic_get_then_or(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_OR)
#		define z_int64_atomic_get_then_or Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_OR
#	endif

	/* zint64 z_int64_atomic_get_then_xor(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_XOR)
#		define z_int64_atomic_get_then_xor Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_XOR
#	endif

	/* zint64 z_int64_atomic_get_then_nand(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_NAND)
#		define z_int64_atomic_get_then_nand Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_NAND
#	endif

	/* zint64 z_int64_atomic_get_then_not(zint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_GET_THEN_NOT)
#		define z_int64_atomic_get_then_not Z_COMPILER_FUNCTION_INT64_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT64_ATOMIC_GET_THEN_NOT
#	endif

	/* zint64 z_int64_atomic_increment_then_get(zint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_INCREMENT_THEN_GET)
#		define z_int64_atomic_increment_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zint64 z_int64_atomic_decrement_then_get(zint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_DECREMENT_THEN_GET)
#		define z_int64_atomic_decrement_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zint64 z_int64_atomic_add_then_get(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_ADD_THEN_GET)
#		define z_int64_atomic_add_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_ADD_THEN_GET
#	endif

	/* zint64 z_int64_atomic_subtract_then_get(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int64_atomic_subtract_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zint64 z_int64_atomic_and_then_get(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_AND_THEN_GET)
#		define z_int64_atomic_and_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_AND_THEN_GET
#	endif

	/* zint64 z_int64_atomic_or_then_get(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_OR_THEN_GET)
#		define z_int64_atomic_or_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_OR_THEN_GET
#	endif

	/* zint64 z_int64_atomic_xor_then_get(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_XOR_THEN_GET)
#		define z_int64_atomic_xor_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_XOR_THEN_GET
#	endif

	/* zint64 z_int64_atomic_nand_then_get(zint64 *value, zint64 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_NAND_THEN_GET)
#		define z_int64_atomic_nand_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_NAND_THEN_GET
#	endif

	/* zint64 z_int64_atomic_not_then_get(zint64 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT64_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT64_ATOMIC_NOT_THEN_GET)
#		define z_int64_atomic_not_then_get Z_COMPILER_FUNCTION_INT64_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT64_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Z_IS_AVAILABLE(UINT128) && Z_CPU_IS_CAPABLE_OF(128BIT_ATOMICS)

	/* zuint128 z_uint128_atomic_set_if_equal(zuint128 *value, zuint128 old_value, zuint128 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT128_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_SET_IF_EQUAL)
#		define z_uint128_atomic_set_if_equal Z_COMPILER_FUNCTION_UINT128_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_UINT128_ATOMIC_SET_IF_EQUAL
#	endif

	/* zuint128 z_uint128_atomic_get_then_set(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_SET)
#		define z_uint128_atomic_get_then_set Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_SET
#	endif

	/* zuint128 z_uint128_atomic_get_then_increment(zuint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_INCREMENT)
#		define z_uint128_atomic_get_then_increment Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zuint128 z_uint128_atomic_get_then_decrement(zuint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_DECREMENT)
#		define z_uint128_atomic_get_then_decrement Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zuint128 z_uint128_atomic_get_then_add(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_ADD)
#		define z_uint128_atomic_get_then_add Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_ADD
#	endif

	/* zuint128 z_uint128_atomic_get_then_subtract(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_SUBTRACT)
#		define z_uint128_atomic_get_then_subtract Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zuint128 z_uint128_atomic_get_then_and(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_AND)
#		define z_uint128_atomic_get_then_and Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_AND
#	endif

	/* zuint128 z_uint128_atomic_get_then_or(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_OR)
#		define z_uint128_atomic_get_then_or Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_OR
#	endif

	/* zuint128 z_uint128_atomic_get_then_xor(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_XOR)
#		define z_uint128_atomic_get_then_xor Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_XOR
#	endif

	/* zuint128 z_uint128_atomic_get_then_nand(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_NAND)
#		define z_uint128_atomic_get_then_nand Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_NAND
#	endif

	/* zuint128 z_uint128_atomic_get_then_not(zuint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_GET_THEN_NOT)
#		define z_uint128_atomic_get_then_not Z_COMPILER_FUNCTION_UINT128_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_UINT128_ATOMIC_GET_THEN_NOT
#	endif

	/* zuint128 z_uint128_atomic_increment_then_get(zuint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_INCREMENT_THEN_GET)
#		define z_uint128_atomic_increment_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_decrement_then_get(zuint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_DECREMENT_THEN_GET)
#		define z_uint128_atomic_decrement_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_add_then_get(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_ADD_THEN_GET)
#		define z_uint128_atomic_add_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_ADD_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_subtract_then_get(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_SUBTRACT_THEN_GET)
#		define z_uint128_atomic_subtract_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_and_then_get(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_AND_THEN_GET)
#		define z_uint128_atomic_and_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_AND_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_or_then_get(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_OR_THEN_GET)
#		define z_uint128_atomic_or_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_OR_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_xor_then_get(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_XOR_THEN_GET)
#		define z_uint128_atomic_xor_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_XOR_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_nand_then_get(zuint128 *value, zuint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_NAND_THEN_GET)
#		define z_uint128_atomic_nand_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_NAND_THEN_GET
#	endif

	/* zuint128 z_uint128_atomic_not_then_get(zuint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_UINT128_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(UINT128_ATOMIC_NOT_THEN_GET)
#		define z_uint128_atomic_not_then_get Z_COMPILER_FUNCTION_UINT128_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_UINT128_ATOMIC_NOT_THEN_GET
#	endif

#endif

#if Z_IS_AVAILABLE(INT128) && Z_CPU_IS_CAPABLE_OF(128BIT_ATOMICS)

	/* zint128 z_int128_atomic_set_if_equal(zint128 *value, zint128 old_value, zint128 new_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SET_IF_EQUAL)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT128_ATOMIC_SET_IF_EQUAL
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_SET_IF_EQUAL)
#		define z_int128_atomic_set_if_equal Z_COMPILER_FUNCTION_INT128_ATOMIC_SET_IF_EQUAL
#		define Z_AVAILABLE_INT128_ATOMIC_SET_IF_EQUAL
#	endif

	/* zint128 z_int128_atomic_get_then_set(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_SET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_SET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_SET)
#		define z_int128_atomic_get_then_set Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SET
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_SET
#	endif

	/* zint128 z_int128_atomic_get_then_increment(zint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_INCREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_INCREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_INCREMENT)
#		define z_int128_atomic_get_then_increment Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_INCREMENT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_INCREMENT
#	endif

	/* zint128 z_int128_atomic_get_then_decrement(zint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_DECREMENT)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_DECREMENT
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_DECREMENT)
#		define z_int128_atomic_get_then_decrement Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_DECREMENT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_DECREMENT
#	endif

	/* zint128 z_int128_atomic_get_then_add(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_ADD)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_ADD
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_ADD)
#		define z_int128_atomic_get_then_add Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_ADD
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_ADD
#	endif

	/* zint128 z_int128_atomic_get_then_subtract(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_SUBTRACT)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_SUBTRACT
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_SUBTRACT)
#		define z_int128_atomic_get_then_subtract Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_SUBTRACT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_SUBTRACT
#	endif

	/* zint128 z_int128_atomic_get_then_and(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_AND)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_AND
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_AND)
#		define z_int128_atomic_get_then_and Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_AND
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_AND
#	endif

	/* zint128 z_int128_atomic_get_then_or(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_OR)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_OR
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_OR)
#		define z_int128_atomic_get_then_or Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_OR
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_OR
#	endif

	/* zint128 z_int128_atomic_get_then_xor(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_XOR)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_XOR
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_XOR)
#		define z_int128_atomic_get_then_xor Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_XOR
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_XOR
#	endif

	/* zint128 z_int128_atomic_get_then_nand(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_NAND)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_NAND
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_NAND)
#		define z_int128_atomic_get_then_nand Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_NAND
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_NAND
#	endif

	/* zint128 z_int128_atomic_get_then_not(zint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_NOT)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_NOT
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_GET_THEN_NOT)
#		define z_int128_atomic_get_then_not Z_COMPILER_FUNCTION_INT128_ATOMIC_GET_THEN_NOT
#		define Z_AVAILABLE_INT128_ATOMIC_GET_THEN_NOT
#	endif

	/* zint128 z_int128_atomic_increment_then_get(zint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_INCREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_INCREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_INCREMENT_THEN_GET)
#		define z_int128_atomic_increment_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_INCREMENT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_INCREMENT_THEN_GET
#	endif

	/* zint128 z_int128_atomic_decrement_then_get(zint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_DECREMENT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_DECREMENT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_DECREMENT_THEN_GET)
#		define z_int128_atomic_decrement_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_DECREMENT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_DECREMENT_THEN_GET
#	endif

	/* zint128 z_int128_atomic_add_then_get(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_ADD_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_ADD_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_ADD_THEN_GET)
#		define z_int128_atomic_add_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_ADD_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_ADD_THEN_GET
#	endif

	/* zint128 z_int128_atomic_subtract_then_get(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SUBTRACT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_SUBTRACT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_SUBTRACT_THEN_GET)
#		define z_int128_atomic_subtract_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_SUBTRACT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_SUBTRACT_THEN_GET
#	endif

	/* zint128 z_int128_atomic_and_then_get(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_AND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_AND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_AND_THEN_GET)
#		define z_int128_atomic_and_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_AND_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_AND_THEN_GET
#	endif

	/* zint128 z_int128_atomic_or_then_get(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_OR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_OR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_OR_THEN_GET)
#		define z_int128_atomic_or_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_OR_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_OR_THEN_GET
#	endif

	/* zint128 z_int128_atomic_xor_then_get(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_XOR_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_XOR_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_XOR_THEN_GET)
#		define z_int128_atomic_xor_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_XOR_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_XOR_THEN_GET
#	endif

	/* zint128 z_int128_atomic_nand_then_get(zint128 *value, zint128 other_value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_NAND_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_NAND_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_NAND_THEN_GET)
#		define z_int128_atomic_nand_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_NAND_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_NAND_THEN_GET
#	endif

	/* zint128 z_int128_atomic_not_then_get(zint128 *value); */

#	if defined(Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_NOT_THEN_GET)
		Z_ASSEMBLY_IMPLEMENTATION_INT128_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_NOT_THEN_GET
#	elif Z_COMPILER_HAS_FUNCTION(INT128_ATOMIC_NOT_THEN_GET)
#		define z_int128_atomic_not_then_get Z_COMPILER_FUNCTION_INT128_ATOMIC_NOT_THEN_GET
#		define Z_AVAILABLE_INT128_ATOMIC_NOT_THEN_GET
#	endif

#endif


#define Z_JOIN_type_atomic_set_if_equal(      type) Z_PASTE_3(z_, type, _atomic_set_if_equal	  )
#define Z_JOIN_type_atomic_get_then_set(      type) Z_PASTE_3(z_, type, _atomic_get_then_set	  )
#define Z_JOIN_type_atomic_get_then_increment(type) Z_PASTE_3(z_, type, _atomic_get_then_increment)
#define Z_JOIN_type_atomic_get_then_decrement(type) Z_PASTE_3(z_, type, _atomic_get_then_decrement)
#define Z_JOIN_type_atomic_get_then_add(      type) Z_PASTE_3(z_, type, _atomic_get_then_add	  )
#define Z_JOIN_type_atomic_get_then_subtract( type) Z_PASTE_3(z_, type, _atomic_get_then_subtract )
#define Z_JOIN_type_atomic_get_then_and(      type) Z_PASTE_3(z_, type, _atomic_get_then_and	  )
#define Z_JOIN_type_atomic_get_then_or(	      type) Z_PASTE_3(z_, type, _atomic_get_then_or	  )
#define Z_JOIN_type_atomic_get_then_xor(      type) Z_PASTE_3(z_, type, _atomic_get_then_xor	  )
#define Z_JOIN_type_atomic_get_then_nand(     type) Z_PASTE_3(z_, type, _atomic_get_then_nand	  )
#define Z_JOIN_type_atomic_get_then_not(      type) Z_PASTE_3(z_, type, _atomic_get_then_not	  )
#define Z_JOIN_type_atomic_increment_then_get(type) Z_PASTE_3(z_, type, _atomic_increment_then_get)
#define Z_JOIN_type_atomic_decrement_then_get(type) Z_PASTE_3(z_, type, _atomic_decrement_then_get)
#define Z_JOIN_type_atomic_add_then_get(      type) Z_PASTE_3(z_, type, _atomic_add_then_get	  )
#define Z_JOIN_type_atomic_subtract_then_get( type) Z_PASTE_3(z_, type, _atomic_subtract_then_get )
#define Z_JOIN_type_atomic_and_then_get(      type) Z_PASTE_3(z_, type, _atomic_and_then_get	  )
#define Z_JOIN_type_atomic_or_then_get(	      type) Z_PASTE_3(z_, type, _atomic_or_then_get	  )
#define Z_JOIN_type_atomic_xor_then_get(      type) Z_PASTE_3(z_, type, _atomic_xor_then_get	  )
#define Z_JOIN_type_atomic_nand_then_get(     type) Z_PASTE_3(z_, type, _atomic_nand_then_get	  )
#define Z_JOIN_type_atomic_not_then_get(      type) Z_PASTE_3(z_, type, _atomic_not_then_get	  )

#define z_value_atomic_set_if_equal(	  TYPE) Z_JOIN_type_atomic_set_if_equal	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_set(	  TYPE) Z_JOIN_type_atomic_get_then_set	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_increment(TYPE) Z_JOIN_type_atomic_get_then_increment(Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_decrement(TYPE) Z_JOIN_type_atomic_get_then_decrement(Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_add(	  TYPE) Z_JOIN_type_atomic_get_then_add	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_subtract( TYPE) Z_JOIN_type_atomic_get_then_subtract (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_and(	  TYPE) Z_JOIN_type_atomic_get_then_and	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_or(	  TYPE) Z_JOIN_type_atomic_get_then_or	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_xor(	  TYPE) Z_JOIN_type_atomic_get_then_xor	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_nand(	  TYPE) Z_JOIN_type_atomic_get_then_nand     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_get_then_not(	  TYPE) Z_JOIN_type_atomic_get_then_not	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_increment_then_get(TYPE) Z_JOIN_type_atomic_increment_then_get(Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_decrement_then_get(TYPE) Z_JOIN_type_atomic_decrement_then_get(Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_add_then_get(	  TYPE) Z_JOIN_type_atomic_add_then_get	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_subtract_then_get( TYPE) Z_JOIN_type_atomic_subtract_then_get (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_and_then_get(	  TYPE) Z_JOIN_type_atomic_and_then_get	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_or_then_get(	  TYPE) Z_JOIN_type_atomic_or_then_get	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_xor_then_get(	  TYPE) Z_JOIN_type_atomic_xor_then_get	     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_nand_then_get(	  TYPE) Z_JOIN_type_atomic_nand_then_get     (Z_##TYPE##_FIXED_TYPE_name)
#define z_value_atomic_not_then_get(	  TYPE) Z_JOIN_type_atomic_not_then_get	     (Z_##TYPE##_FIXED_TYPE_name)


#endif /* __Z_functions_base_value_H__ */

/* Z Kit C API - functions/mathematics/geometry/euclidean/ZSphere.h
	      __	   __
  _______ ___/ /______ ___/ /__
 / __/ -_) _  / __/ _ \ _  / -_)
/_/  \__/\_,_/\__/\___/_,_/\__/
Copyright © 2006-2016 Manuel Sainz de Baranda y Goñi.
Released under the terms of the GNU Lesser General Public License v3. */

#ifndef __Z_functions_mathematics_geometry_euclidean_ZSphere_H__
#define __Z_functions_mathematics_geometry_euclidean_ZSphere_H__

#include <Z/functions/mathematics/geometry/euclidean/constructors.h>
#include <Z/functions/base/Z3DValue.h>
#include <Z/constants/numbers.h>


/* MARK: - Template */


#define Z_TEMPLATE_SPHERE(Type, type, _)						\
											\
											\
Z_INLINE zboolean z_sphere_##type##_are_equal(ZSphere##Type a, ZSphere##Type b)		\
	{return a.radius == b.radius && z_3d_##type##_are_equal(a.point, b.point);}	\
											\
											\
Z_INLINE zboolean z_sphere_##type##_is_zero(ZSphere##Type object)			\
	{return object.radius == _(0.0) && z_3d_##type##_is_zero(object.point);}	\
											\
											\
Z_INLINE ZBox##Type z_sphere_##type##_inner_box(ZSphere##Type object)			\
	{										\
	z##type half_size = object.radius / _(Z_SQUARE_ROOT_3);				\
	z##type size = half_size * _(2.0);						\
											\
	return z_box_##type								\
		(object.point.x - half_size,						\
		 object.point.y - half_size,						\
		 object.point.z - half_size,						\
		 size, size, size);							\
	}										\
											\
											\
Z_INLINE ZBox##Type z_sphere_##type##_outer_box(ZSphere##Type object)			\
	{										\
	z##type size = object.radius * _(2.0);						\
											\
	return z_box_##type								\
		(object.point.x - object.radius,					\
		 object.point.y - object.radius,					\
		 object.point.z - object.radius,					\
		 size, size, size);							\
	}


#define z_sphere_type_are_equal(TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _are_equal)
#define z_sphere_type_is_zero(	TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _is_zero	)
#define z_sphere_type_inner_box(TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _inner_box)
#define z_sphere_type_outer_box(TYPE) Z_INSERT_##TYPE##_fixed_type(z_sphere_, _outer_box)


/* MARK: - Template implementations */


#if Z_IS_AVAILABLE(FLOAT16)
	Z_TEMPLATE_SPHERE(Float16, float16, Z_FLOAT16)
#endif

#if Z_IS_AVAILABLE(FLOAT24)
	Z_TEMPLATE_SPHERE(Float24, float24, Z_FLOAT24)
#endif

#if Z_IS_AVAILABLE(FLOAT32)
	Z_TEMPLATE_SPHERE(Float32, float32, Z_FLOAT32)
#endif

#if Z_IS_AVAILABLE(FLOAT48)
	Z_TEMPLATE_SPHERE(Float48, float48, Z_FLOAT48)
#endif

#if Z_IS_AVAILABLE(FLOAT64)
	Z_TEMPLATE_SPHERE(Float64, float64, Z_FLOAT64)
#endif

#if Z_IS_AVAILABLE(FLOAT72)
	Z_TEMPLATE_SPHERE(Float72, float72, Z_FLOAT72)
#endif

#if Z_IS_AVAILABLE(FLOAT80)
	Z_TEMPLATE_SPHERE(Float80, float80, Z_FLOAT80)
#endif

#if Z_IS_AVAILABLE(FLOAT96)
	Z_TEMPLATE_SPHERE(Float96, float96, Z_FLOAT96)
#endif

#if Z_IS_AVAILABLE(FLOAT128)
	Z_TEMPLATE_SPHERE(Float128, float128, Z_FLOAT128)
#endif


/* MARK: - Default real type definitions */


#define z_sphere_are_equal z_sphere_type_are_equal(REAL)
#define z_sphere_is_zero   z_sphere_type_is_zero  (REAL)
#define z_sphere_inner_box z_sphere_type_inner_box(REAL)
#define z_sphere_outer_box z_sphere_type_outer_box(REAL)


#endif /* __Z_functions_mathematics_geometry_euclidean_ZSphere_H__ */
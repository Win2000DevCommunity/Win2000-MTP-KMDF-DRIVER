#pragma once
#ifndef SPECSTRINGS_H
#define SPECSTRINGS_H

// Minimal SpecStrings/SAL stubs for legacy builds
#define __annotation(x)
#define __ANNOTATION(x)
#define __ANNOTATION_VOID(x)
#define __analysis_assume(x)
#define __analysis_assert(x)
#define __analysis_noreturn
#define __analysis_typecheck

#define _Analysis_assume_(x)
#define _Analysis_assert_(x)
#define _Analysis_noreturn_
#define _Analysis_assume_lock_held_(x)
#define _Analysis_assume_lock_not_held_(x)

// SAL parameter annotations
#define __pre
#define __post
#define __checkReturn
#define __checkReturn_wat
#define __in
#define __in_opt
#define __out
#define __out_opt
#define __inout
#define __inout_opt
#define __deref_out
#define __deref_out_opt
#define __deref_inout
#define __deref_inout_opt
#define __deref_inout_z_opt
#define __success(x)

// SAL size/count annotations - deref variants
#define __deref_out_bcount(x)
#define __deref_out_bcount_opt(x)
#define __deref_out_ecount(x)
#define __deref_out_ecount_opt(x)

// SAL size/count annotations
#define __xcount(x)
#define __ecount(x)
#define __bcount(x)
#define __in_xcount(x)
#define __in_ecount(x)
#define __in_ecount_opt(x)
#define __out_ecount(x)
#define __out_ecount_opt(x)
#define __in_bcount(x)
#define __in_bcount_opt(x)
#define __out_bcount(x)
#define __out_bcount_opt(x)
#define __out_bcount_full_opt(x)
#define __out_bcount_part(x,y)
#define __out_bcount_part_opt(x,y)
#define __inout_bcount(x)
#define __inout_bcount_opt(x)
#define __range(min,max)

// SAL field annotations
#define __field_bcount(x)
#define __field_bcount_opt(x)
#define __field_bcount_part(x,y)
#define __field_bcount_part_opt(x,y)
#define __field_ecount(x)
#define __field_ecount_opt(x)
#define __field_xcount(x)
#define __field_xcount_opt(x)

// In/out count annotations
#define __inout_ecount(x)
#define __inout_ecount_opt(x)
#define __inout_ecount_z(x)
#define __out_ecount_part_opt(x,y)

// SAL string/pointer qualifiers
#define __nullnullterminated
#define __possibly_notnullterminated
#define __maybevalid

// SAL string buffer annotations
#define __in_z
#define __in_z_opt
#define __out_z
#define __out_z_opt
#define __inout_z
#define __inout_z_opt
#define __in_ecount_z(x)
#define __out_ecount_z(x)
#define __out_ecount_part_z(x,y)
#define __in_bcount_z(x)
#define __out_bcount_z(x)
#define __in_bcount_z_opt(x)
#define __out_bcount_z_opt(x)
#define __out_bcount_part_z(x,y)

// SAL formatting annotations
#define __format_string
#define __nullterminated

// Pointer annotations
#define __ptr64
#define __ptr32

// SAL 2.0 annotations - Advanced annotations for deref and out parameters
#define __deref_opt_out
#define __deref_opt_inout
#define __out_ecount_part(x,y)
#define __in_range(min,max)
#define __deref_out_range(min,max)
#define __struct_bcount(x)
#define __volatile
#define __inexpressible_readableTo(x)
#define __out_bcount_full(x)
#define __out_bcount_full_opt(x)

// SAL 2.0 Driver annotations
#define __drv_neverHold(x)
#define __drv_acquiresResource(x)
#define __drv_releasesResource(x)
#define __drv_mustHold(x)
#define __drv_neverHoldCancelIrql
#define __drv_heldCancelSpinLock
#define __drv_valueIs(x)
#define __drv_nonConstant
#define __drv_strictTypeMatch(x)
#define __drv_strictType(x,y)

#endif // SPECSTRINGS_H

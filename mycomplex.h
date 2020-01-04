// complex standard header
#pragma once
#ifndef _COMPLEX_
#define _COMPLEX_
#ifndef RC_INVOKED
#include <ymath.h>
#include <ccomplex>	/* dummy if not C99 library */
#include <cmath>
#include <sstream>

 #pragma pack(push,_CRT_PACKING)
 #pragma warning(push,3)

 #pragma warning(disable: 4244)

_C_STD_BEGIN
 #ifndef _C_COMPLEX_T
  #define _C_COMPLEX_T

typedef value struct _C_double_complex
	{	/* double complex */
		double _real;
		double _img;
//		double _Val[2];
	} _C_double_complex;

typedef value struct _C_float_complex
	{	/* float complex */
		float _real;
		float _img;
//	float _Val[2];
	} _C_float_complex;

typedef value struct _C_ldouble_complex
	{	/* long double complex */
		long double _real;
		long double _img;
//	long double _Val[2];
	} _C_ldouble_complex;
 #endif /* _C_COMPLEX_T */
_C_STD_END

	// COMPLEX _Val OFFSETS
 #define _RE	0
 #define _IM	1

_STD_BEGIN
typedef _CSTD _C_double_complex _Dcomplex_value;
typedef _CSTD _C_float_complex _Fcomplex_value;
typedef _CSTD _C_ldouble_complex _Lcomplex_value;

template<class _Ty>
	class complex;
template<> class complex<float>;
template<> class complex<double>;
template<> class complex<long double>;

		// TEMPLATE CLASS _Ctraits
template<class _Ty>
	class _Ctraits
	{	// complex traits for _Ty
public:
	static _Ty _Cosh(_Ty _Left, _Ty _Right)
		{	// return cosh(_Left) * _Right
		return (_CSTD _Cosh((double)_Left, (double)_Right));
		}

	static short _Exp(_Ty *_Pleft, _Ty _Right, short _Exponent)
		{	// compute exp(*_Pleft) * _Right * 2 ^ _Exponent
		double _Tmp = (double)*_Pleft;
		short _Ans = _CSTD _Exp(&_Tmp, (double)_Right, _Exponent);
		*_Pleft = (_Ty)_Tmp;
		return (_Ans);
		}

	static _Ty _Infv(_Ty)
		{	// return infinity
		return (_CSTD _Inf._Double);
		}

	static bool _Isinf(_Ty _Left)
		{	// test for infinity
		double _Tmp = (double)_Left;
		return (_CSTD _Dtest(&_Tmp) == _INFCODE);
		}

	static bool _Isnan(_Ty _Left)
		{	// test for NaN
		double _Tmp = (double)_Left;
		return (_CSTD _Dtest(&_Tmp) == _NANCODE);
		}

	static _Ty _Nanv(_Ty)
		{	// return NaN
		return (_CSTD _Nan._Double);
		}

	static _Ty _Sinh(_Ty _Left, _Ty _Right)
		{	// return sinh(_Left) * _Right
		return (_CSTD _Sinh((double)_Left, (double)_Right));
		}

	static _Ty atan2(_Ty _Yval, _Ty _Xval)
		{	// return atan(_Yval / _Xval)
		return (_CSTD atan2((double)_Yval, (double)_Xval));
		}

	static _Ty cos(_Ty _Left)
		{	// return cos(_Left)
		return (_CSTD cos((double)_Left));
		}

	static _Ty exp(_Ty _Left)
		{	// return exp(_Left)
		return (_CSTD exp((double)_Left));
		}

	static _Ty ldexp(_Ty _Left, int _Exponent)
		{	// return _Left * 2 ^ _Exponent
		return (_CSTD ldexp((double)_Left, _Exponent));
		}

	static _Ty log(_Ty _Left)
		{	// return log(_Left)
		return (_CSTD log((double)_Left));
		}

	static _Ty pow(_Ty _Left, _Ty _Right)
		{	// return _Left ^ _Right
		return (_CSTD pow((double)_Left, (double)_Right));
		}

	static _Ty sin(_Ty _Left)
		{	// return sin(_Left)
		return (_CSTD sin((double)_Left));
		}

	static _Ty sqrt(_Ty _Left)
		{	// return sqrt(_Left)
		return (_CSTD sqrt((double)_Left));
		}

	static _Ty tan(_Ty _Left)
		{	// return tan(_Left)
		return (_CSTD tan((double)_Left));
		}
	};

		// CLASS _Ctraits<long double>
template<> class _Ctraits<long double>
	{	// complex traits for long double
public:
	typedef long double _Ty;

	static _Ty _Cosh(_Ty _Left, _Ty _Right)
		{	// return cosh(_Left) * _Right
		return (_CSTD _LCosh(_Left, _Right));
		}

	static short _Exp(_Ty *_Pleft, _Ty _Right, short _Exponent)
		{	// compute exp(*_Pleft) * _Right * 2 ^ _Exponent
		return (_CSTD _LExp(_Pleft, _Right, _Exponent));
		}

	static _Ty _Infv(_Ty)
		{	// return infinity
		return (_CSTD _LInf._Long_double);
		}

	static bool _Isinf(_Ty _Left)
		{	// test for infinity
		return (_CSTD _LDtest(&_Left) == _INFCODE);
		}

	static bool _Isnan(_Ty _Left)
		{	// test for NaN
		return (_CSTD _LDtest(&_Left) == _NANCODE);
		}

	static _Ty _Nanv(_Ty)
		{	// return NaN
		return (_CSTD _LNan._Long_double);
		}

	static _Ty _Sinh(_Ty _Left, _Ty _Right)
		{	// return sinh(_Left) * _Right
		return (_CSTD _LSinh(_Left, _Right));
		}

	static _Ty atan2(_Ty _Yval, _Ty _Xval)
		{	// return atan(_Yval / _Xval)
		return (_CSTD atan2l(_Yval, _Xval));
		}

	static _Ty cos(_Ty _Left)
		{	// return cos(_Left)
		return (_CSTD cosl(_Left));
		}

	static _Ty exp(_Ty _Left)
		{	// return exp(_Left)
		return (_CSTD expl(_Left));
		}

	static _Ty ldexp(_Ty _Left, int _Exponent)
		{	// return _Left * 2 ^ _Exponent
		return (_CSTD ldexpl(_Left, _Exponent));
		}

	static _Ty log(_Ty _Left)
		{	// return log(_Left)
		return (_CSTD logl(_Left));
		}

	static _Ty pow(_Ty _Left, _Ty _Right)
		{	// return _Left ^ _Right
		return (_CSTD powl(_Left, _Right));
		}

	static _Ty sin(_Ty _Left)
		{	// return sin(_Left)
		return (_CSTD sinl(_Left));
		}

	static _Ty sqrt(_Ty _Left)
		{	// return sqrt(_Left)
		return (_CSTD sqrtl(_Left));
		}

	static _Ty tan(_Ty _Left)
		{	// return tan(_Left)
		return (_CSTD tanl(_Left));
		}
	};

		// CLASS _Ctraits<double>
template<> class _Ctraits<double>
	{	// complex traits for double
public:
	typedef double _Ty;

	static _Ty _Cosh(_Ty _Left, _Ty _Right)
		{	// return cosh(_Left) * _Right
		return (_CSTD _Cosh(_Left, _Right));
		}

	static short _Exp(_Ty *_Pleft, _Ty _Right, short _Exponent)
		{	// compute exp(*_Pleft) * _Right * 2 ^ _Exponent
		return (_CSTD _Exp(_Pleft, _Right, _Exponent));
		}

	static _Ty _Infv(_Ty)
		{	// return infinity
		return (_CSTD _Inf._Double);
		}

	static bool _Isinf(_Ty _Left)
		{	// test for infinity
		return (_CSTD _Dtest(&_Left) == _INFCODE);
		}

	static bool _Isnan(_Ty _Left)
		{	// test for NaN
		return (_CSTD _Dtest(&_Left) == _NANCODE);
		}

	static _Ty _Nanv(_Ty)
		{	// return NaN
		return (_CSTD _Nan._Double);
		}

	static _Ty _Sinh(_Ty _Left, _Ty _Right)
		{	// return sinh(_Left) * _Right
		return (_CSTD _Sinh(_Left, _Right));
		}

	static _Ty atan2(_Ty _Yval, _Ty _Xval)
		{	// return atan(_Yval / _Xval)
		return (_CSTD atan2(_Yval, _Xval));
		}

	static _Ty cos(_Ty _Left)
		{	// return cos(_Left)
		return (_CSTD cos(_Left));
		}

	static _Ty exp(_Ty _Left)
		{	// return exp(_Left)
		return (_CSTD exp(_Left));
		}

	static _Ty ldexp(_Ty _Left, int _Exponent)
		{	// return _Left * 2 ^ _Exponent
		return (_CSTD ldexp(_Left, _Exponent));
		}

	static _Ty log(_Ty _Left)
		{	// return log(_Left)
		return (_CSTD log(_Left));
		}

	static _Ty pow(_Ty _Left, _Ty _Right)
		{	// return _Left ^ _Right
		return (_CSTD pow(_Left, _Right));
		}

	static _Ty sin(_Ty _Left)
		{	// return sin(_Left)
		return (_CSTD sin(_Left));
		}

	static _Ty sqrt(_Ty _Left)
		{	// return sqrt(_Left)
		return (_CSTD sqrt(_Left));
		}

	static _Ty tan(_Ty _Left)
		{	// return tan(_Left)
		return (_CSTD tan(_Left));
		}
	};

		// CLASS _Ctraits<float>
template<> class _Ctraits<float>
	{	// complex traits for float
public:
	typedef float _Ty;

	static _Ty _Cosh(_Ty _Left, _Ty _Right)
		{	// return cosh(_Left) * _Right
		return (_CSTD _FCosh(_Left, _Right));
		}

	static short _Exp(_Ty *_Pleft, _Ty _Right, short _Exponent)
		{	// compute exp(*_Pleft) * _Right * 2 ^ _Exponent
		return (_CSTD _FExp(_Pleft, _Right, _Exponent));
		}

	static _Ty _Infv(_Ty)
		{	// return infinity
		return (_CSTD _FInf._Float);
		}

	static bool _Isinf(_Ty _Left)
		{	// test for infinity
		return (_CSTD _FDtest(&_Left) == _INFCODE);
		}

	static bool _Isnan(_Ty _Left)
		{	// test for NaN
		return (_CSTD _FDtest(&_Left) == _NANCODE);
		}

	static _Ty _Nanv(_Ty)
		{	// return NaN
		return (_CSTD _FNan._Float);
		}

	static _Ty _Sinh(_Ty _Left, _Ty _Right)
		{	// return sinh(_Left) * _Right
		return (_CSTD _FSinh(_Left, _Right));
		}

	static _Ty atan2(_Ty _Yval, _Ty _Xval)
		{	// return atan(_Yval / _Xval)
		return (_CSTD atan2f(_Yval, _Xval));
		}

	static _Ty cos(_Ty _Left)
		{	// return cos(_Left)
		return (_CSTD cosf(_Left));
		}

	static _Ty exp(_Ty _Left)
		{	// return exp(_Left)
		return (_CSTD expf(_Left));
		}

	static _Ty ldexp(_Ty _Left, int _Exponent)
		{	// return _Left * 2 ^ _Exponent
		return (_CSTD ldexpf(_Left, _Exponent));
		}

	static _Ty log(_Ty _Left)
		{	// return log(_Left)
		return (_CSTD logf(_Left));
		}

	static _Ty pow(_Ty _Left, _Ty _Right)
		{	// return _Left ^ _Right
		return (_CSTD powf(_Left, _Right));
		}

	static _Ty sin(_Ty _Left)
		{	// return sin(_Left)
		return (_CSTD sinf(_Left));
		}

	static _Ty sqrt(_Ty _Left)
		{	// return sqrt(_Left)
		return (_CSTD sqrtf(_Left));
		}

	static _Ty tan(_Ty _Left)
		{	// return tan(_Left)
		return (_CSTD tanf(_Left));
		}
	};

		// TEMPLATE CLASS _Complex_value
template<class _Ty>
	value struct _Complex_value
	{	/* templatized complex value */
//	enum {_Re = 0, _Im = 1};
	_Ty _real;
	_Ty _imag;
	};

		// TEMPLATE CLASS _Complex_base
template<class _Ty,
	class _Valbase>
	class _Complex_base
		: public _Valbase
	{	// base for all complex types
public:
	typedef _Ctraits<_Ty> _Myctraits;
	typedef _Complex_base<_Ty, _Valbase> _Myt;
	typedef _Ty value_type;

	_Complex_base(const _Ty& _Realval, const _Ty& _Imagval)
		{	// construct from components of same type
		this->_real = _Realval;
		this->_imag = _Imagval;
		}

	_Ty real(const _Ty& _Right)
		{	// set real component
		return (this->_real = _Right);
		}

	_Ty imag(const _Ty& _Right)
		{	// set imaginary component
		return (this->_imag = _Right);
		}

	_Ty real() const
		{	// return real component
		return (this->_real);
		}

	_Ty imag() const
		{	// return imaginary component
		return (this->_imag);
		}

protected:
	template<class _Other> inline
		void _Add(const complex<_Other>& _Right)
		{	// add other complex
		this->_real = this->_real + (_Ty)_Right.real();
		this->_imag = this->_imag + (_Ty)_Right.imag();
		}

	template<class _Other> inline
		void _Sub(const complex<_Other>& _Right)
		{	// subtract other complex
		this->_real = this->_real - (_Ty)_Right.real();
		this->_imag = this->_imag - (_Ty)_Right.imag();
		}

	template<class _Other> inline
		void _Mul(const complex<_Other>& _Right)
		{	// multiply by other complex
		_Ty _Rightreal = (_Ty)_Right.real();
		_Ty _Rightimag = (_Ty)_Right.imag();

		_Ty _Tmp = this->_real * _Rightreal
			- this->_imag * _Rightimag;
		this->_imag = this->_real * _Rightimag
			+ this->_imag * _Rightreal;
		this->_real = _Tmp;
		}

	template<class _Other> inline
		void _Div(const complex<_Other>& _Right)
		{	// divide by other complex
		typedef _Ctraits<_Ty> _Myctraits;
		_Ty _Rightreal = (_Ty)_Right.real();
		_Ty _Rightimag = (_Ty)_Right.imag();

		if (_Myctraits::_Isnan(_Rightreal) || _Myctraits::_Isnan(_Rightimag))
			{	// set NaN result
			this->_real = _Myctraits::_Nanv(_Rightreal);
			this->_imag = this->_real;
			}
		else if ((_Rightimag < 0 ? -_Rightimag : +_Rightimag)
			< (_Rightreal < 0 ? -_Rightreal : +_Rightreal))
			{	// |_Right.imag()| < |_Right.real()|
			_Ty _Wr = _Rightimag / _Rightreal;
			_Ty _Wd = _Rightreal + _Wr * _Rightimag;

			if (_Myctraits::_Isnan(_Wd) || _Wd == 0)
				{	// set NaN result
				this->_real = _Myctraits::_Nanv(_Rightreal);
				this->_imag = this->_real;
				}
			else
				{	// compute representable result
				_Ty _Tmp = (this->_real
					+ this->_imag * _Wr) / _Wd;
				this->_imag = (this->_imag
					- this->_real * _Wr) / _Wd;
				this->_real = _Tmp;
				}
			}
		else if (_Rightimag == 0)
			{	// set NaN result
			this->_real = _Myctraits::_Nanv(_Rightreal);
			this->_imag = this->_real;
			}
		else
			{	// 0 < |_Right.real()| <= |_Right.imag()|
			_Ty _Wr = _Rightreal / _Rightimag;
			_Ty _Wd = _Rightimag + _Wr * _Rightreal;

			if (_Myctraits::_Isnan(_Wd) || _Wd == 0)
				{	// set NaN result
				this->_real = _Myctraits::_Nanv(_Rightreal);
				this->_imag = this->_real;
				}
			else
				{	// compute representable result
				_Ty _Tmp = (this->_real * _Wr + this->_imag) / _Wd;
				this->_imag = (this->_imag * _Wr
					- this->_real) / _Wd;
				this->_real = _Tmp;
				}
			}
		}
	};

		// CLASS complex<float>
template<> class complex<float>
	: public _Complex_base<float, _Fcomplex_value>
	{	// complex with float components
public:
	typedef float _Ty;
	typedef complex<_Ty> _Myt;

	explicit complex(
		const complex<double>&);	// defined below
	explicit complex(
		const complex<long double>&);	// defined below

	complex(const _Ty& _Realval = 0,
		const _Ty& _Imagval = 0)
		: _Complex_base<float, _Fcomplex_value>(_Realval, _Imagval)
		{	// construct from float components
		}

	complex(const _Fcomplex_value& _Right)
		: _Complex_base<float, _Fcomplex_value>(_Right._real,
			_Right._imag)
		{	// construct from float complex value
		}

	complex(const _Dcomplex_value& _Right)
		: _Complex_base<float, _Fcomplex_value>(_Right._real,
			_Right._imag)
		{	// construct from double complex value
		}

	complex(const _Lcomplex_value& _Right)
		: _Complex_base<float, _Fcomplex_value>(_Right._real,
			_Right._imag)
		{	// construct from long double complex value
		}

	complex<_Ty>& operator=(const _Ty& _Right)
		{	// assign real
		_real = _Right;
		_imag = 0;
		return (*this);
		}

	_Myt& operator+=(const _Ty& _Right)
		{	// add real
		_real = _real + _Right;
		return (*this);
		}

	_Myt& operator-=(const _Ty& _Right)
		{	// subtract real
		_real = _real - _Right;
		return (*this);
		}

	_Myt& operator*=(const _Ty& _Right)
		{	// multiply by real
		_real = _real * _Right;
		_imag = _imag * _Right;
		return (*this);
		}

	_Myt& operator/=(const _Ty& _Right)
		{	// divide by real
		_real = _real / _Right;
		_imag = _imag / _Right;
		return (*this);
		}

	_Myt& operator+=(const _Myt& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	_Myt& operator-=(const _Myt& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	_Myt& operator*=(const _Myt& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	_Myt& operator/=(const _Myt& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator=(const complex<_Other>& _Right)
		{	// assign another complex
		_real = (_Ty)_Right._real;
		_imag = (_Ty)_Right._imag;
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator+=(const complex<_Other>& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator-=(const complex<_Other>& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator*=(const complex<_Other>& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator/=(const complex<_Other>& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}
	};

		// CLASS complex<double>
template<> class complex<double>
	: public _Complex_base<double, _Dcomplex_value>
	{	// complex with double components
public:
	typedef double _Ty;
	typedef complex<_Ty> _Myt;

	complex(
		const complex<float>&);	// defined below
	explicit complex(
		const complex<long double>&);	// defined below

	complex(const _Ty& _Realval = 0,
		const _Ty& _Imagval = 0)
		: _Complex_base<double, _Dcomplex_value>(_Realval, _Imagval)
		{	// construct from double components
		}

	complex(const _Dcomplex_value& _Right)
		: _Complex_base<double, _Dcomplex_value>(_Right._real,
			_Right._imag)
		{	// construct from double complex value
		}

	complex(const _Lcomplex_value& _Right)
		: _Complex_base<double, _Dcomplex_value>(_Right._real,
			_Right._imag)
		{	// construct from long double complex value
		}

	complex<_Ty>& operator=(const _Ty& _Right)
		{	// assign real
		_real = _Right;
		_imag = 0;
		return (*this);
		}

	_Myt& operator+=(const _Ty& _Right)
		{	// add real
		_real = _real + _Right;
		return (*this);
		}

	_Myt& operator-=(const _Ty& _Right)
		{	// subtract real
		_real = _real - _Right;
		return (*this);
		}

	_Myt& operator*=(const _Ty& _Right)
		{	// multiply by real
		_real = _real * _Right;
		_imag = _imag * _Right;
		return (*this);
		}

	_Myt& operator/=(const _Ty& _Right)
		{	// divide by real
		_real = _real / _Right;
		_imag = _imag / _Right;
		return (*this);
		}

	_Myt& operator+=(const _Myt& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	_Myt& operator-=(const _Myt& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	_Myt& operator*=(const _Myt& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	_Myt& operator/=(const _Myt& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator=(const complex<_Other>& _Right)
		{	// assign another complex
		_real = (_Ty)_Right._real;
		_imag = (_Ty)_Right._imag;
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator+=(const complex<_Other>& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator-=(const complex<_Other>& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator*=(const complex<_Other>& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator/=(const complex<_Other>& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}
	};

		// CLASS complex<long double>
template<> class complex<long double>
	: public _Complex_base<long double, _Lcomplex_value>
	{	// complex with long double components
public:
	typedef long double _Ty;
	typedef complex<_Ty> _Myt;

	complex(
		const complex<float>&);	// defined below
	complex(
		const complex<double>&);	// defined below

	complex(const _Ty& _Realval = 0,
		const _Ty& _Imagval = 0)
		: _Complex_base<long double, _Lcomplex_value>(_Realval, _Imagval)
		{	// construct from long double components
		}

	complex(const _Lcomplex_value& _Right)
		: _Complex_base<long double, _Lcomplex_value>(_Right._real,
			_Right._imag)
		{	// construct from long double complex value
		}

	complex<_Ty>& operator=(const _Ty& _Right)
		{	// assign real
		_real = _Right;
		_imag = 0;
		return (*this);
		}

	_Myt& operator+=(const _Ty& _Right)
		{	// add real
		_real = _real + _Right;
		return (*this);
		}

	_Myt& operator-=(const _Ty& _Right)
		{	// subtract real
		_real = _real - _Right;
		return (*this);
		}

	_Myt& operator*=(const _Ty& _Right)
		{	// multiply by real
		_real = _real * _Right;
		_imag = _imag * _Right;
		return (*this);
		}

	_Myt& operator/=(const _Ty& _Right)
		{	// divide by real
		_real = _real / _Right;
		_imag = _imag / _Right;
		return (*this);
		}

	_Myt& operator+=(const _Myt& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	_Myt& operator-=(const _Myt& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	_Myt& operator*=(const _Myt& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	_Myt& operator/=(const _Myt& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator=(const complex<_Other>& _Right)
		{	// assign another complex
		_real = (_Ty)_Right._real;
		_imag = (_Ty)_Right._imag;
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator+=(const complex<_Other>& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator-=(const complex<_Other>& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator*=(const complex<_Other>& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator/=(const complex<_Other>& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}
	};

		// CONSTRUCTORS FOR complex SPECIALIZATIONS
inline complex<float>::complex(
	const complex<double>& _Right)
		: _Complex_base<float, _Fcomplex_value>(
			(_Ty)_Right.real(), (_Ty)_Right.imag())
	{	// construct complex<float> from complex<double>
	}

inline complex<float>::complex(
	const complex<long double>& _Right)
		: _Complex_base<float, _Fcomplex_value>(
			(_Ty)_Right.real(), (_Ty)_Right.imag())
	{	// construct complex<float> from complex<long double>
	}

inline complex<double>::complex(
	const complex<float>& _Right)
		: _Complex_base<double, _Dcomplex_value>(
			(_Ty)_Right.real(), (_Ty)_Right.imag())
	{	// construct complex<double> from complex<float>
	}

inline complex<double>::complex(
	const complex<long double>& _Right)
		: _Complex_base<double, _Dcomplex_value>(
			(_Ty)_Right.real(), (_Ty)_Right.imag())
	{	// construct complex<double> from complex<long double>
	}

inline complex<long double>::complex(
	const complex<float>& _Right)
		: _Complex_base<long double, _Lcomplex_value>(
			(_Ty)_Right.real(), (_Ty)_Right.imag())
	{	// construct complex<long double> from complex<float>
	}

inline complex<long double>::complex(
	const complex<double>& _Right)
		: _Complex_base<long double, _Lcomplex_value>(
			(_Ty)_Right.real(), (_Ty)_Right.imag())
	{	// construct complex<long double> from complex<double>
	}

		// TEMPLATE CLASS complex
template<class _Ty>
	class complex
		: public _Complex_base<_Ty, _Complex_value<_Ty> >
	{	// complex with _Ty components
public:
	typedef complex<_Ty> _Myt;
	typedef _Complex_base<_Ty, _Complex_value<_Ty> > _Mybase;

	complex(const _Ty& _Realval = _Ty(), const _Ty& _Imagval = _Ty())
		: _Mybase(_Realval, _Imagval)
		{	// construct from components of same type
		}

	_Myt& operator=(const _Ty& _Right)
		{	// assign real
		this->_real = _Right;
		this->_imag = _Ty();
		return (*this);
		}

	template<class _Other>
		complex(const complex<_Other>& _Right)
		: _Mybase((_Ty)_Right.real(), (_Ty)_Right.imag())
		{	// construct from other complex type
		}

	template<class _Other>
		_Myt& operator=(const complex<_Other>& _Right)
		{	// assign other complex type
		this->_real = (_Ty)_Right.real();
		this->_imag = (_Ty)_Right.imag();
		return (*this);
		}

	_Myt& operator+=(const _Ty& _Right)
		{	// add real
		this->_real = this->_real + _Right;
		return (*this);
		}

	_Myt& operator-=(const _Ty& _Right)
		{	// subtract real
		this->_real = this->_real - _Right;
		return (*this);
		}

	_Myt& operator*=(const _Ty& _Right)
		{	// multiply by real
		this->_real = this->_real * _Right;
		this->_imag = this->_imag * _Right;
		return (*this);
		}

	_Myt& operator/=(const _Ty& _Right)
		{	// divide by real
		this->_real = this->_real / _Right;
		this->_imag = this->_imag / _Right;
		return (*this);
		}

	_Myt& operator+=(const _Myt& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	_Myt& operator-=(const _Myt& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	_Myt& operator*=(const _Myt& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	_Myt& operator/=(const _Myt& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator+=(const complex<_Other>& _Right)
		{	// add other complex
		this->_Add(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator-=(const complex<_Other>& _Right)
		{	// subtract other complex
		this->_Sub(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator*=(const complex<_Other>& _Right)
		{	// multiply by other complex
		this->_Mul(_Right);
		return (*this);
		}

	template<class _Other> inline
		_Myt& operator/=(const complex<_Other>& _Right)
		{	// divide by other complex
		this->_Div(_Right);
		return (*this);
		}
	};

 #define _CMPLX(T)	complex<T >
 #define _CTR(T)	_Ctraits<T >
 #define _TMPLT(T)	template<class T >
 #include <xcomplex>	/* define all complex template functions */

		// TEMPLATE FUNCTION operator>>
template<class _Ty,
	class _Elem,
	class _Tr> inline
	basic_istream<_Elem, _Tr>& operator>>(
		basic_istream<_Elem, _Tr>& _Istr, complex<_Ty>& _Right)
	{	// extract a complex<_Ty>
	typedef complex<_Ty> _Myt;
	const ctype<_Elem>& _Ctype_fac = _USE(_Istr.getloc(), ctype<_Elem>);
	_Elem _Ch = 0;
	long double _Real = 0;
	long double _Imag = 0;

	if (_Istr >> _Ch && _Ch != _Ctype_fac.widen('('))
		{	// no leading '(', treat as real only
		_Istr.putback(_Ch);
		_Istr >> _Real;
		_Imag = 0;
		}
	else if (_Istr >> _Real >> _Ch && _Ch != _Ctype_fac.widen(','))
		if (_Ch == _Ctype_fac.widen(')'))
			_Imag = 0;	// (real)
		else
			{	// no trailing ')' after real, treat as bad field
			_Istr.putback(_Ch);
			_Istr.setstate(ios_base::failbit);
			}
	else if (_Istr >> _Imag >> _Ch && _Ch != _Ctype_fac.widen(')'))
			{	// no imag or trailing ')', treat as bad field
			_Istr.putback(_Ch);
			_Istr.setstate(ios_base::failbit);
			}

	if (!_Istr.fail())
		{	// store valid result
		_Ty _Tyreal((_Ty)_Real), _Tyimag((_Ty)_Imag);
		_Right = _Myt(_Tyreal, _Tyimag);
		}
	return (_Istr);
	}

		// TEMPLATE FUNCTION operator<<
template<class _Ty,
	class _Elem,
	class _Tr> inline
	basic_ostream<_Elem, _Tr>& operator<<(
		basic_ostream<_Elem, _Tr>& _Ostr, const complex<_Ty>& _Right)
	{	// insert a complex<_Ty>
	const ctype<_Elem>& _Ctype_fac = _USE(_Ostr.getloc(), ctype<_Elem>);
	basic_ostringstream<_Elem, _Tr, allocator<_Elem> > _Sstr;

	_Sstr.flags(_Ostr.flags());
	_Sstr.imbue(_Ostr.getloc());
	_Sstr.precision(_Ostr.precision());
	_Sstr << _Ctype_fac.widen('(') << real(_Right)
		<< _Ctype_fac.widen(',') << imag(_Right)
		<< _Ctype_fac.widen(')');

	basic_string<_Elem, _Tr, allocator<_Elem> > _Str = _Sstr.str();
	return (_Ostr << _Str.c_str());
	}
_STD_END

 #pragma warning(pop)
 #pragma pack(pop)

#endif /* RC_INVOKED */
#endif /* _COMPLEX_ */

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.20:0009 */

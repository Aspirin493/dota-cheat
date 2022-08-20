#pragma once

#include <array>
#include <cstdint>

enum Color : int
{
	Red = 0,
	Green,
	Blue,
	Alpha
};

struct Color_t
{
	Color_t( ) = default;

	constexpr Color_t( std::uint8_t uRed, std::uint8_t uGreen, std::uint8_t uBlue, std::uint8_t uAlpha )
	{
		m_arrColors[ Color::Red ] = uRed;
		m_arrColors[ Color::Green ] = uGreen;
		m_arrColors[ Color::Blue ] = uBlue;
		m_arrColors[ Color::Alpha ] = uAlpha;
	}

	int r() const { return m_arrColors[Color::Red]; }
	int g() const { return m_arrColors[Color::Green]; }
	int b() const { return m_arrColors[Color::Blue]; }
	int a() const { return m_arrColors[Color::Alpha]; }

	void SetColor(int _r, int _g, int _b, int _a)
	{
		m_arrColors[Color::Red] = (unsigned char)_r;
		m_arrColors[Color::Green] = (unsigned char)_g;
		m_arrColors[Color::Blue] = (unsigned char)_b;
		m_arrColors[Color::Alpha] = (unsigned char)_a;
	}
	void SetColor(float _r, float _g, float _b, float _a)
	{
		m_arrColors[Color::Red] = static_cast<unsigned char>(_r * 255.0f);
		m_arrColors[Color::Green] = static_cast<unsigned char>(_g * 255.0f);
		m_arrColors[Color::Blue] = static_cast<unsigned char>(_b * 255.0f);
		m_arrColors[Color::Alpha] = static_cast<unsigned char>(_a * 255.0f);
	}

	Color_t( std::uint32_t unColor )
	{
		*reinterpret_cast< std::uint32_t* >( m_arrColors.data( ) ) = unColor;
	}

	operator std::uint32_t& ( )
	{
		return *reinterpret_cast< std::uint32_t* >( m_arrColors.data( ) );
	}

	operator const std::uint32_t& ( ) const
	{
		return *reinterpret_cast< const std::uint32_t* >( m_arrColors.data( ) );
	}

	std::uint8_t& operator[]( std::size_t nIndex )
	{
		return m_arrColors[ nIndex ];
	}

	const std::uint8_t& operator[]( std::size_t nIndex ) const
	{
		return m_arrColors[ nIndex ];
	}
private:
	std::array< std::uint8_t, 4 > m_arrColors = { };
};
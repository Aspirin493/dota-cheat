#pragma once

#include <optional>

#include "..\core\types\color_t.hpp"

namespace CTX
{
	struct Config_t
	{
		struct Visuals_t
		{
			bool m_bHighlighIllusions = false;
			bool m_bVisibleByEnemy = false;

			Color_t m_fIllusionCol = Color_t(255, 0, 0, 255);
		} Visuals;
	};

	inline std::optional< Config_t > Config = std::nullopt; // @note xnxkzeu: std::optional is used here to delay initialization.
}
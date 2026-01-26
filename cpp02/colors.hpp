/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:43:16 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/12 13:59:47 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>

/* =========================
   Basic ANSI Color Wrappers
   ========================= */

inline std::string BLK(const std::string& msg) { return (std::string("\033[30m") + msg + "\033[0m"); }
inline std::string RED(const std::string& msg) { return (std::string("\033[31m") + msg + "\033[0m"); }
inline std::string GRN(const std::string& msg) { return (std::string("\033[32m") + msg + "\033[0m"); }
inline std::string YEL(const std::string& msg) { return (std::string("\033[33m") + msg + "\033[0m"); }
inline std::string BLU(const std::string& msg) { return (std::string("\033[34m") + msg + "\033[0m"); }
inline std::string MAG(const std::string& msg) { return (std::string("\033[35m") + msg + "\033[0m"); }
inline std::string CYN(const std::string& msg) { return (std::string("\033[36m") + msg + "\033[0m"); }
inline std::string WHT(const std::string& msg) { return (std::string("\033[37m") + msg + "\033[0m"); }

/* ==========================
   Bright ANSI Color Wrappers
   ========================== */

inline std::string brBLK(const std::string& msg) { return (std::string("\033[1;30m") + msg + "\033[0m"); }
inline std::string brRED(const std::string& msg) { return (std::string("\033[1;31m") + msg + "\033[0m"); }
inline std::string brGRN(const std::string& msg) { return (std::string("\033[1;32m") + msg + "\033[0m"); }
inline std::string brYEL(const std::string& msg) { return (std::string("\033[1;33m") + msg + "\033[0m"); }
inline std::string brBLU(const std::string& msg) { return (std::string("\033[1;34m") + msg + "\033[0m"); }
inline std::string brMAG(const std::string& msg) { return (std::string("\033[1;35m") + msg + "\033[0m"); }
inline std::string brCYN(const std::string& msg) { return (std::string("\033[1;36m") + msg + "\033[0m"); }
inline std::string brWHT(const std::string& msg) { return (std::string("\033[1;37m") + msg + "\033[0m"); }

/* =========================
   Color ON helpers (no reset)
   ========================= */

inline std::string BLK_ON() { return "\033[30m"; }
inline std::string RED_ON() { return "\033[31m"; }
inline std::string GRN_ON() { return "\033[32m"; }
inline std::string YEL_ON() { return "\033[33m"; }
inline std::string BLU_ON() { return "\033[34m"; }
inline std::string MAG_ON() { return "\033[35m"; }
inline std::string CYN_ON() { return "\033[36m"; }
inline std::string WHT_ON() { return "\033[37m"; }

/* ==========================
   Bright Color ON helpers
   ========================== */

inline std::string brBLK_ON() { return "\033[1;30m"; }
inline std::string brRED_ON() { return "\033[1;31m"; }
inline std::string brGRN_ON() { return "\033[1;32m"; }
inline std::string brYEL_ON() { return "\033[1;33m"; }
inline std::string brBLU_ON() { return "\033[1;34m"; }
inline std::string brMAG_ON() { return "\033[1;35m"; }
inline std::string brCYN_ON() { return "\033[1;36m"; }
inline std::string brWHT_ON() { return "\033[1;37m"; }

/* =========================
   Reset helper
   ========================= */

inline std::string RESET() { return "\033[0m"; }
#endif

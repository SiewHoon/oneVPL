/*############################################################################
  # Copyright (C) 2005 Intel Corporation
  #
  # SPDX-License-Identifier: MIT
  ############################################################################*/

#ifndef __SAMPLE_TYPES_H__
#define __SAMPLE_TYPES_H__

#ifdef UNICODE
    #define msdk_cout std::wcout
    #define msdk_err  std::wcerr
#else
    #define msdk_cout std::cout
    #define msdk_err  std::cerr
#endif

typedef std::basic_string<msdk_char> msdk_string;
typedef std::basic_stringstream<msdk_char> msdk_stringstream;
typedef std::basic_ostream<msdk_char, std::char_traits<msdk_char>> msdk_ostream;
typedef std::basic_istream<msdk_char, std::char_traits<msdk_char>> msdk_istream;
typedef std::basic_fstream<msdk_char, std::char_traits<msdk_char>> msdk_fstream;

#if defined(_UNICODE)
    #define MSDK_MAKE_BYTE_STRING(dest, src, count)                               \
        {                                                                         \
            std::wstring wstr(src);                                               \
            std::string str(wstr.length(), 0);                                    \
            std::transform(wstr.begin(), wstr.end(), str.begin(), [](wchar_t c) { \
                return (char)c;                                                   \
            });                                                                   \
            strncpy(dest, str.c_str(), count);                                    \
            dest[count - 1] = '\0';                                               \
        }
#else
    #define MSDK_MAKE_BYTE_STRING(dest, src, count) \
        {                                           \
            strncpy(dest, src, count);              \
            dest[count - 1] = '\0';                 \
        }

#endif

#endif //__SAMPLE_TYPES_H__

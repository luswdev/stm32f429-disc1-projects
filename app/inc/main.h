/**
 * @file    main.h
 * @brief   main entry point define
 *
 * @author  LuSkywalker <callumlu@gmail.com>
 * @note    Copyright (c) 2023, LuSkywalker
 */

#ifndef __MAIN_H__
#define __MAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

#undef EXT
#ifdef MAIN_SET
#define EXT
#else
#define EXT extern
#endif

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

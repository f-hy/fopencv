//
// Created by f on 2023/11/19.
//

#ifndef SHARED_LIB_H
#define SHARED_LIB_H

#ifdef SHARED_LIB_BUILD

#ifdef _WIN32

#ifdef SHARED_LIB_EXPORT
#define SHARED_LIB_API __declspec(dllexport)
#else
#define SHARED_LIB_API __declspec(dllimport)
#endif  // SHARED_LIB_EXPORT

#else
#define SHARED_LIB_API
#endif  // _WIN32

#else
#define SHARED_LIB_API
#endif  // SHARED_LIB_BUILD

#endif //SHARED_LIB_H

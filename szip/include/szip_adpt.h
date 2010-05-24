/*
 * This files has neccesary definitions to provide SZIP DLL 
 * support on Windows platfroms, both MSVC and CodeWarrior 
 * compilers
 */

#ifndef SZAPI_ADPT_H
#define SZAPI_ADPT_H

#include <SZconfig.h>
/* Cmake will define SZip_EXPORTS on Windows when it
configures to build a shared library. If you are going to use
another build system on windows or create the visual studio
projects by hand you need to define SZip_EXPORTS when
building the SZip DLL on windows.
*/

#if defined (SZIP_BUILT_AS_DYNAMIC_LIB)
  #if defined (SZip_EXPORTS)  /* Compiling the SZip DLL/Dylib */
    #if defined (_MSC_VER) && !defined(__MWERKS__) /* MSVC Compiler Case */
      #define  __SZ_DLL__ __declspec(dllexport)
    #elif (__GNUC__ >= 4)  /* GCC 4.x has support for visibility options */
      #define __SZ_DLL__ __attribute__ ((visibility("default")))
    #endif
  #else  /* Importing the DLL into another project */
    #if defined (_MSC_VER)  /* MSVC Compiler Case */
      #define  __SZ_DLL__ __declspec(dllimport)
    #elif (__GNUC__ >= 4)  /* GCC 4.x has support for visibility options */
      #define __SZ_DLL__ __attribute__ ((visibility("default")))
    #endif
  #endif
#endif

/* If __SZ_DLL__ was never defined, define it here */
#ifndef __SZ_DLL__
  #define __SZ_DLL__
#endif

#endif

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SQUAREROOT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SQUAREROOT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SQUAREROOT_EXPORTS
#define SQUAREROOT_API __declspec(dllexport)
#else
#define SQUAREROOT_API __declspec(dllimport)
#endif

// This class is exported from the SquareRoot.dll
class SQUAREROOT_API CSquareRoot {
public:
	CSquareRoot(void);
	// TODO: add your methods here.

    double GetSquareRoot(double value);
};

extern SQUAREROOT_API int nSquareRoot;

SQUAREROOT_API int fnSquareRoot(void);

#include "EventFilterApp.h"
#include "Testor.h"


int main( int argc, char* argv[] )
{
	CEventFilterApp a( argc, argv );

	CTestor testor;
	testor.Test();


	return a.exec();
}
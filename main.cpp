///////////////////////////////////////////////////
//
//	Hamish Carr
//	January, 2018
//
//	------------------------
//	main.cpp
//	------------------------
//	
///////////////////////////////////////////////////

#include <QApplication>
#include "GeometricWindow.h"
#include "GeometricController.h"
#include <stdio.h>

int main(int argc, char **argv)
	{ // main()
	// initialize QT
	QApplication app(argc, argv);

	// the geometric surface
	GeometricSurfaceDirectedEdge surface;

	// check the args to make sure there's an input file
	if (argc == 2)
		{ // two parameters - read a file
		if (!surface.ReadFileDirEdge(argv[1]))
			{ // surface read failed 
			printf("Read failed for file %s\n", argv[1]);
			exit(0);
			} // surface read failed
		else
			{ // surface read succeeded
			// create the root widget (window)
			surface.fillQueue();
			GeometricWindow theWindow(&surface, NULL);
	
			// create the controller
			GeometricController *theController = new GeometricController(&surface, &theWindow);

			// 	set the initial size
			theWindow.resize(600, 640);

			// show the window
			theWindow.show();

			// and reset the interface
			theWindow.ResetInterfaceElements();

			// set QT running
			return app.exec();
			} // surface read succeeded			
		} // two parameters - read a file
	else 
		{ // too many parameters 
		printf("Usage: %s filename\n", argv[0]); 
		exit (0);
		} // too many parameters 

	// paranoid return value
	exit(0);
	} // main()
